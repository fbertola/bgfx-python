from array import array

from bgfx import bgfx, ImGui, ImVec2, ImVec4


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
        self.m_avg = avg_val / 100


def bar(width, max_width, height, color):
    style = ImGui.GetStyle()

    hovered_color = ImVec4(
        color.x + color.x * 0.1,
        color.y + color.y * 0.1,
        color.z + color.z * 0.1,
        color.w + color.w * 0.1,
    )

    ImGui.PushStyleColor(21, color)
    ImGui.PushStyleColor(22, hovered_color)
    ImGui.PushStyleColor(23, color)
    ImGui.PushStyleVar(12, 0.0)
    ImGui.PushStyleVar(14, ImVec2(0.0, style.ItemSpacing.y))

    item_hovered = False

    ImGui.Button("", ImVec2(width, height))
    item_hovered |= ImGui.IsItemHovered()

    ImGui.SameLine()
    ImGui.InvisibleButton("", ImVec2(max(1.0, max_width - width), height))
    item_hovered |= ImGui.IsItemHovered()

    ImGui.PopStyleVar(2)
    ImGui.PopStyleColor(3)

    return item_hovered


s_resourceColor = ImVec4(0.5, 0.5, 0.5, 1.0)


def resource_bar(name, tooltip, num, _max, max_width, height):
    item_hovered = False

    ImGui.Text(f"{name}: {num:4d} / {_max:4d}")
    item_hovered |= ImGui.IsItemHovered()
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
    ImGui.SetNextWindowPos(ImVec2(10.0, 50.0), 1 << 2)
    ImGui.SetNextWindowSize(ImVec2(300.0, 210.0), 1 << 2)

    ImGui.Begin("Hello World")
    ImGui.TextWrapped("A simple Hello World example")
    ImGui.Separator()

    s_frame_time = SampleData()

    stats = bgfx.getStats()
    to_ms_cpu = 1000.0 / stats.cpuTimerFreq
    to_ms_gpu = 1000.0 / stats.gpuTimerFreq
    frame_ms = stats.cpuTimeFrame * to_ms_cpu

    s_frame_time.push_sample(frame_ms)

    frame_text_overlay = f"\uf063{s_frame_time.m_min:.3f}ms, \uf062{s_frame_time.m_max:.3f}ms\nAvg: {s_frame_time.m_avg:.3f}ms, {(1000.0 / s_frame_time.m_avg):.1f} FPS"
    ImGui.PushStyleColor(40, ImVec4(0.0, 0.5, 0.15, 1.0))
    ImGui.PlotHistogram(
        "Frame",
        array("f", s_frame_time.m_values)[0],
        100,
        s_frame_time.m_offset,
        frame_text_overlay,
        0.0,
        60.0,
        ImVec2(0.0, 45.0),
    )
    ImGui.PopStyleColor()

    ImGui.Text(
        f"Submit CPU {(stats.cpuTimeEnd - stats.cpuTimeBegin) * to_ms_cpu:.3f}, GPU {(stats.gpuTimeEnd - stats.gpuTimeBegin) * to_ms_gpu:.3f} (L: {stats.maxGpuLatency})"
    )
    # ImGui.Text(f"GPU mem: {stats.gpuMemoryUsed} / {stats.gpuMemoryMax}")

    if ImGui.CollapsingHeader("\uf12e Resources"):
        caps = bgfx.getCaps()
        itemHeight = ImGui.GetTextLineHeightWithSpacing()
        maxWidth = 90.0
        ImGui.PushFont(ImGui.Font.Mono)
        ImGui.Text("Res: Num  / Max")
        resource_bar(
            "DIB",
            "Dynamic index buffers",
            stats.numDynamicIndexBuffers,
            caps.limits.maxDynamicIndexBuffers,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            "DVB",
            "Dynamic vertex buffers",
            stats.numDynamicVertexBuffers,
            caps.limits.maxDynamicVertexBuffers,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            " FB",
            "Frame buffers",
            stats.numFrameBuffers,
            caps.limits.maxFrameBuffers,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            " IB",
            "Index buffers",
            stats.numIndexBuffers,
            caps.limits.maxIndexBuffers,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            " OQ",
            "Occlusion queries",
            stats.numOcclusionQueries,
            caps.limits.maxOcclusionQueries,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            "  P",
            "Programs",
            stats.numPrograms,
            caps.limits.maxPrograms,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            "  S",
            "Shaders",
            stats.numShaders,
            caps.limits.maxShaders,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            "  T",
            "Textures",
            stats.numTextures,
            caps.limits.maxTextures,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            "  U",
            "Uniforms",
            stats.numUniforms,
            caps.limits.maxUniforms,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            " VB",
            "Vertex buffers",
            stats.numVertexBuffers,
            caps.limits.maxVertexBuffers,
            maxWidth,
            itemHeight,
        )
        resource_bar(
            " VL",
            "Vertex layouts",
            stats.numVertexLayouts,
            caps.limits.maxVertexLayouts,
            maxWidth,
            itemHeight,
        )
        ImGui.PopFont()
    ImGui.End()
