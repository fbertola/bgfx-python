from array import array

# noinspection PyUnresolvedReferences
from pybgfx import bgfx, ImGui


class SampleData:
    m_values = []
    m_offset = 0
    m_min = 0.0
    m_max = 0.0
    m_avg = 0.0

    def __init__(self):
        self.reset()

    def reset(self):
        self.m_values = [0.0] * 100
        self.m_offset = 0
        self.m_min = 0.0
        self.m_max = 0.0
        self.m_avg = 0.0

    def push_sample(self, value: float):
        self.m_values[self.m_offset] = value
        self.m_offset = (self.m_offset + 1) % 100

        min_val = float("inf")
        max_val = float("-inf")
        avg_val = 0.0

        for val in self.m_values:
            min_val = min(min_val, val)
            max_val = max(max_val, val)
            avg_val += val

        self.m_min = min_val
        self.m_max = max_val
        self.m_avg = avg_val / 100.0


def bar(width, max_width, height, color):
    style = ImGui.GetStyle()

    hovered_color = ImGui.ImVec4(
        color.x + color.x * 0.1,
        color.y + color.y * 0.1,
        color.z + color.z * 0.1,
        color.w + color.w * 0.1,
    )

    ImGui.PushStyleColor(ImGui.ImGuiCol_Button, color)
    ImGui.PushStyleColor(ImGui.ImGuiCol_ButtonHovered, hovered_color)
    ImGui.PushStyleColor(ImGui.ImGuiCol_ButtonActive, color)
    ImGui.PushStyleVar(ImGui.ImGuiStyleVar_FrameRounding, 0.0)
    ImGui.PushStyleVar(
        ImGui.ImGuiStyleVar_ItemSpacing, ImGui.ImVec2(0.0, style.ItemSpacing.y)
    )

    item_hovered = False

    ImGui.Button("", ImGui.ImVec2(width, height))
    item_hovered |= ImGui.IsItemHovered(0)

    ImGui.SameLine()
    ImGui.InvisibleButton("", ImGui.ImVec2(max(1.0, max_width - width), height), 0)
    item_hovered |= ImGui.IsItemHovered(0)

    ImGui.PopStyleVar(2)
    ImGui.PopStyleColor(3)

    return item_hovered


s_resourceColor = ImGui.ImVec4(0.5, 0.5, 0.5, 1.0)
s_frame_time = SampleData()


def resource_bar(name, tooltip, num, _max, max_width, height):
    item_hovered = False

    ImGui.Text(f"{name}: {num:4d} / {_max:4d}")
    item_hovered |= ImGui.IsItemHovered(0)
    ImGui.SameLine()

    percentage = float(num) / float(_max)

    item_hovered |= bar(
        max(1.0, percentage * max_width), max_width, height, s_resourceColor
    )
    ImGui.SameLine()

    ImGui.Text(f"{(percentage * 100.0):5.2f}%")

    if item_hovered:
        ImGui.SetTooltip(f"{tooltip} {(percentage * 100.0):5.2f}%")


def show_example_dialog():
    ImGui.SetNextWindowPos(ImGui.ImVec2(10.0, 70.0), ImGui.ImGuiCond_FirstUseEver)
    ImGui.SetNextWindowSize(ImGui.ImVec2(300.0, 500.0), ImGui.ImGuiCond_FirstUseEver)

    ImGui.Begin("\uf080 Statistics")
    renderer_name = bgfx.getRendererName(bgfx.getRendererType())
    ImGui.TextWrapped("Current renderer: {}".format(renderer_name))
    ImGui.Separator()

    stats = bgfx.getStats()
    to_ms_cpu = 1000.0 / stats.cpuTimerFreq
    to_ms_gpu = 1000.0 / stats.gpuTimerFreq
    frame_ms = max(float(stats.cpuTimeEnd - stats.cpuTimeBegin), 1.0e-9)

    s_frame_time.push_sample(frame_ms * to_ms_cpu)

    frame_text_overlay = f"\uf063{s_frame_time.m_min:7.3f}ms, \uf062{s_frame_time.m_max:7.3f}ms\nAvg: {s_frame_time.m_avg:7.3f}ms, {(stats.cpuTimerFreq / frame_ms):6.2f} FPS"
    ImGui.PushStyleColor(
        ImGui.ImGuiCol_PlotHistogram, ImGui.ImVec4(0.0, 0.5, 0.15, 1.0)
    )
    ImGui.PushItemWidth(-1)
    ImGui.PlotHistogram(
        "",
        array("f", s_frame_time.m_values),
        100,
        s_frame_time.m_offset,
        frame_text_overlay,
        0.0,
        60.0,
        ImGui.ImVec2(0.0, 45.0),
    )
    ImGui.PopItemWidth()
    ImGui.PopStyleColor()

    ImGui.Text(
        f"Submit CPU {(stats.cpuTimeEnd - stats.cpuTimeBegin) * to_ms_cpu:.3f}, GPU {(stats.gpuTimeEnd - stats.gpuTimeBegin) * to_ms_gpu:.3f} (L: {stats.maxGpuLatency})"
    )

    if stats.gpuMemoryMax > 0:
        ImGui.Text(f"GPU mem: {stats.gpuMemoryUsed} / {stats.gpuMemoryMax}")

    if ImGui.CollapsingHeader("\uf12e Resources", ImGui.ImGuiTreeNodeFlags_DefaultOpen):
        caps = bgfx.getCaps()
        item_height = ImGui.GetTextLineHeightWithSpacing()
        max_width = 90.0
        ImGui.PushFont(ImGui.Font.Mono)
        ImGui.Text("Res: Num  / Max")
        resource_bar(
            "DIB",
            "Dynamic index buffers",
            stats.numDynamicIndexBuffers,
            caps.limits.maxDynamicIndexBuffers,
            max_width,
            item_height,
        )
        resource_bar(
            "DVB",
            "Dynamic vertex buffers",
            stats.numDynamicVertexBuffers,
            caps.limits.maxDynamicVertexBuffers,
            max_width,
            item_height,
        )
        resource_bar(
            " FB",
            "Frame buffers",
            stats.numFrameBuffers,
            caps.limits.maxFrameBuffers,
            max_width,
            item_height,
        )
        resource_bar(
            " IB",
            "Index buffers",
            stats.numIndexBuffers,
            caps.limits.maxIndexBuffers,
            max_width,
            item_height,
        )
        resource_bar(
            " OQ",
            "Occlusion queries",
            stats.numOcclusionQueries,
            caps.limits.maxOcclusionQueries,
            max_width,
            item_height,
        )
        resource_bar(
            "  P",
            "Programs",
            stats.numPrograms,
            caps.limits.maxPrograms,
            max_width,
            item_height,
        )
        resource_bar(
            "  S",
            "Shaders",
            stats.numShaders,
            caps.limits.maxShaders,
            max_width,
            item_height,
        )
        resource_bar(
            "  T",
            "Textures",
            stats.numTextures,
            caps.limits.maxTextures,
            max_width,
            item_height,
        )
        resource_bar(
            "  U",
            "Uniforms",
            stats.numUniforms,
            caps.limits.maxUniforms,
            max_width,
            item_height,
        )
        resource_bar(
            " VB",
            "Vertex buffers",
            stats.numVertexBuffers,
            caps.limits.maxVertexBuffers,
            max_width,
            item_height,
        )
        resource_bar(
            " VL",
            "Vertex layouts",
            stats.numVertexLayouts,
            caps.limits.maxVertexLayouts,
            max_width,
            item_height,
        )
        ImGui.PopFont()

    ImGui.End()
