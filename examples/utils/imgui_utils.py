from array import array

from bgfx import bgfx, ImGui


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
    style = ImGui.get_style()

    hovered_color = ImGui.Vec4(
        color.x + color.x * 0.1,
        color.y + color.y * 0.1,
        color.z + color.z * 0.1,
        color.w + color.w * 0.1,
    )

    ImGui.push_style_color(ImGui.Colors.Button, color)
    ImGui.push_style_color(ImGui.Colors.ButtonHovered, hovered_color)
    ImGui.push_style_color(ImGui.Colors.ButtonActive, color)
    ImGui.push_style_var(ImGui.Style.FrameRounding, 0.0)
    ImGui.push_style_var(ImGui.Style.ItemSpacing, ImGui.Vec2(0.0, style.item_spacing.y))

    item_hovered = False

    ImGui.button("", ImGui.Vec2(width, height))
    item_hovered |= ImGui.is_item_hovered(0)

    ImGui.same_line()
    ImGui.invisible_button("", ImGui.Vec2(max(1.0, max_width - width), height))
    item_hovered |= ImGui.is_item_hovered(0)

    ImGui.pop_style_var(2)
    ImGui.pop_style_color(3)

    return item_hovered


s_resourceColor = ImGui.Vec4(0.5, 0.5, 0.5, 1.0)
s_frame_time = SampleData()


def resource_bar(name, tooltip, num, _max, max_width, height):
    item_hovered = False

    ImGui.text(f"{name}: {num:4d} / {_max:4d}")
    item_hovered |= ImGui.is_item_hovered(0)
    ImGui.same_line()

    percentage = float(num) / float(_max)

    item_hovered |= bar(
        max(1.0, percentage * max_width), max_width, height, s_resourceColor
    )
    ImGui.same_line()

    ImGui.text(f"{(percentage * 100.0):5.2f}%")

    if item_hovered:
        ImGui.set_tooltip(f"{tooltip} {(percentage * 100.0):5.2f}%")


def show_example_dialog():
    ImGui.set_next_window_pos(ImGui.Vec2(10.0, 70.0), ImGui.Condition.FirstUseEver)
    ImGui.set_next_window_size(ImGui.Vec2(300.0, 500.0), ImGui.Condition.FirstUseEver)

    ImGui.begin("\uf080 Statistics")
    renderer_name = bgfx.get_renderer_name(bgfx.get_renderer_type())
    ImGui.text_wrapped(f"Current renderer: {renderer_name}")
    ImGui.separator()

    stats = bgfx.get_stats()
    to_ms_cpu = 1000.0 / stats.cpu_timer_freq
    to_ms_gpu = 1000.0 / stats.gpu_timer_freq
    frame_ms = max(float(stats.cpu_time_end - stats.cpu_time_begin), 1.0e-9)

    s_frame_time.push_sample(frame_ms * to_ms_cpu)

    frame_text_overlay = f"\uf063{s_frame_time.m_min:7.3f}ms, \uf062{s_frame_time.m_max:7.3f}ms\nAvg: {s_frame_time.m_avg:7.3f}ms, {(stats.cpu_timer_freq / frame_ms):6.2f} FPS"
    ImGui.push_style_color(ImGui.Colors.PlotHistogram, ImGui.Vec4(0.0, 0.5, 0.15, 1.0))
    ImGui.push_item_width(-1)
    ImGui.plot_histogram(
        "",
        array("f", s_frame_time.m_values)[0],
        100,
        s_frame_time.m_offset,
        frame_text_overlay,
        0.0,
        60.0,
        ImGui.Vec2(0.0, 45.0),
    )
    ImGui.pop_item_width()
    ImGui.pop_style_color()

    ImGui.text(
        f"Submit CPU {(stats.cpu_time_end - stats.cpu_time_begin) * to_ms_cpu:.3f}, GPU {(stats.gpu_time_end - stats.gpu_time_begin) * to_ms_gpu:.3f} (L: {stats.max_gpu_latency})"
    )

    if stats.gpu_memory_max > 0:
        ImGui.text(f"GPU mem: {stats.gpu_memory_used} / {stats.gpu_memory_max}")

    if ImGui.collapsing_header("\uf12e Resources", 1 << 5):
        caps = bgfx.get_caps()
        item_height = ImGui.get_text_line_height_with_spacing()
        max_width = 90.0
        ImGui.push_font(ImGui.Font.Mono)
        ImGui.text("Res: Num  / Max")
        resource_bar(
            "DIB",
            "Dynamic index buffers",
            stats.num_dynamic_index_buffers,
            caps.limits.max_dynamic_index_buffers,
            max_width,
            item_height,
        )
        resource_bar(
            "DVB",
            "Dynamic vertex buffers",
            stats.num_dynamic_vertex_buffers,
            caps.limits.max_dynamic_vertex_buffers,
            max_width,
            item_height,
        )
        resource_bar(
            " FB",
            "Frame buffers",
            stats.num_frame_buffers,
            caps.limits.max_frame_buffers,
            max_width,
            item_height,
        )
        resource_bar(
            " IB",
            "Index buffers",
            stats.num_index_buffers,
            caps.limits.max_index_buffers,
            max_width,
            item_height,
        )
        resource_bar(
            " OQ",
            "Occlusion queries",
            stats.num_occlusion_queries,
            caps.limits.max_occlusion_queries,
            max_width,
            item_height,
        )
        resource_bar(
            "  P",
            "Programs",
            stats.num_programs,
            caps.limits.max_programs,
            max_width,
            item_height,
        )
        resource_bar(
            "  S",
            "Shaders",
            stats.num_shaders,
            caps.limits.max_shaders,
            max_width,
            item_height,
        )
        resource_bar(
            "  T",
            "Textures",
            stats.num_textures,
            caps.limits.max_textures,
            max_width,
            item_height,
        )
        resource_bar(
            "  U",
            "Uniforms",
            stats.num_uniforms,
            caps.limits.max_uniforms,
            max_width,
            item_height,
        )
        resource_bar(
            " VB",
            "Vertex buffers",
            stats.num_vertex_buffers,
            caps.limits.max_vertex_buffers,
            max_width,
            item_height,
        )
        resource_bar(
            " VL",
            "Vertex layouts",
            stats.num_vertex_layouts,
            caps.limits.max_vertex_layouts,
            max_width,
            item_height,
        )
        ImGui.pop_font()

    ImGui.end()
