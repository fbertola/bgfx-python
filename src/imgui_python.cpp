// File: imgui.cpp
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>
#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_internal.h>
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <memory>
#include <mutex>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

namespace py = pybind11;

typedef py::array_t<uint8_t, py::array::c_style> ndarray_uint8;


struct Bool
{
	Bool(): value(false) {}
	Bool(bool v): value(v) {}

	bool value;
	bool null = false;
};

struct Float
{
	Float(): value(0.0f) {}
	Float(float v): value(v) {}

	float value;
};

struct Int
{
	Int(): value(0) {}
	Int(int v): value(v) {}

	int value;
};

struct String
{
	String(): value("") {}
	String(const std::string& v): value(v) {}

	std::string value;
};


void  AddLine(const ImVec2& a, const ImVec2& b, ImU32 col, float thickness){ ImGui::GetWindowDrawList()->AddLine(a, b, col, thickness); }
void  AddRect(const ImVec2& a, const ImVec2& b, ImU32 col, float rounding, int rounding_corners_flags, float thickness){ ImGui::GetWindowDrawList()->AddRect(a, b, col, rounding, rounding_corners_flags, thickness); }
void  AddRectFilled(const ImVec2& a, const ImVec2& b, ImU32 col, float rounding, int rounding_corners_flags){ ImGui::GetWindowDrawList()->AddRectFilled(a, b, col, rounding, rounding_corners_flags); }
void  AddRectFilledMultiColor(const ImVec2& a, const ImVec2& b, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_lefs){ ImGui::GetWindowDrawList()->AddRectFilledMultiColor(a, b, col_upr_left, col_upr_right, col_bot_right, col_bot_lefs); }
void  AddQuad(const ImVec2& a, const ImVec2& b, const ImVec2& c, const ImVec2& d, ImU32 col, float thickness){ ImGui::GetWindowDrawList()->AddQuad(a, b, c, d, col, thickness); }
void  AddQuadFilled(const ImVec2& a, const ImVec2& b, const ImVec2& c, const ImVec2& d, ImU32 col){ ImGui::GetWindowDrawList()->AddQuadFilled(a, b, c, d, col); }
void  AddTriangle(const ImVec2& a, const ImVec2& b, const ImVec2& c, ImU32 col, float thickness){ ImGui::GetWindowDrawList()->AddTriangle(a, b, c, col, thickness); }
void  AddTriangleFilled(const ImVec2& a, const ImVec2& b, const ImVec2& c, ImU32 col){ ImGui::GetWindowDrawList()->AddTriangleFilled(a, b, c, col); }
void  AddCircle(const ImVec2& centre, float radius, ImU32 col, int num_segments, float thickness){ ImGui::GetWindowDrawList()->AddCircle(centre, radius, col, num_segments, thickness); }
void  AddCircleFilled(const ImVec2& centre, float radius, ImU32 col, int num_segments){ ImGui::GetWindowDrawList()->AddCircleFilled(centre, radius, col, num_segments); }
void  AddBezierCurve(const ImVec2& pos0, const ImVec2& cp0, const ImVec2& cp1, const ImVec2& pos1, ImU32 col, float thickness, int num_segments){ ImGui::GetWindowDrawList()->AddBezierCurve(pos0, cp0, cp1, pos1, col, thickness, num_segments); }

void  PathClear(){ ImGui::GetWindowDrawList()->PathClear(); }
void  PathLineTo(const ImVec2& pos){ ImGui::GetWindowDrawList()->PathLineTo(pos); }
void  PathFillConvex(ImU32 col){ ImGui::GetWindowDrawList()->PathFillConvex(col); }
void  PathStroke(ImU32 col, bool closed, float thickness){ ImGui::GetWindowDrawList()->PathStroke(col, closed, thickness); }

void bind_imgui(std::function< pybind11::module &(std::string const &namespace_) > &M) {
	static Bool null;
	null.null = true;


	py::enum_<ImGuiCond_>(M("ImGui"), "Condition", py::arithmetic())
		.value("Always", ImGuiCond_::ImGuiCond_Always)
		.value("Once", ImGuiCond_::ImGuiCond_Once)
		.value("FirstUseEver", ImGuiCond_::ImGuiCond_FirstUseEver)
		.value("Appearing", ImGuiCond_::ImGuiCond_Appearing)
		.export_values();

	py::enum_<ImGuiWindowFlags_>(M("ImGui"), "WindowFlags", py::arithmetic())
		.value("NoTitleBar", ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar)
		.value("NoResize", ImGuiWindowFlags_::ImGuiWindowFlags_NoResize)
		.value("NoMove", ImGuiWindowFlags_::ImGuiWindowFlags_NoMove)
		.value("NoScrollbar", ImGuiWindowFlags_::ImGuiWindowFlags_NoScrollbar)
		.value("NoScrollWithMouse", ImGuiWindowFlags_::ImGuiWindowFlags_NoScrollWithMouse)
		.value("NoCollapse", ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse)
		.value("AlwaysAutoResize", ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize)
		// obsolete --> Set style.FrameBorderSize=1.0f / style.WindowBorderSize=1.0f to enable borders around windows and items
		// .value("ShowBorders", ImGuiWindowFlags_::ImGuiWindowFlags_ShowBorders)
		.value("NoSavedSettings", ImGuiWindowFlags_::ImGuiWindowFlags_NoSavedSettings)
		.value("NoInputs", ImGuiWindowFlags_::ImGuiWindowFlags_NoInputs)
		.value("MenuBar", ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar)
		.value("HorizontalScrollbar", ImGuiWindowFlags_::ImGuiWindowFlags_HorizontalScrollbar)
		.value("NoFocusOnAppearing", ImGuiWindowFlags_::ImGuiWindowFlags_NoFocusOnAppearing)
		.value("NoBringToFrontOnFocus", ImGuiWindowFlags_::ImGuiWindowFlags_NoBringToFrontOnFocus)
		.value("AlwaysVerticalScrollbar", ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysVerticalScrollbar)
		.value("AlwaysHorizontalScrollbar", ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysHorizontalScrollbar)
		.value("AlwaysUseWindowPadding", ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysUseWindowPadding)
		.export_values();

	py::enum_<ImGuiInputTextFlags_>(M("ImGui"), "InputTextFlags", py::arithmetic())
		.value("CharsDecimal", ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsDecimal)
		.value("CharsHexadecimal", ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsHexadecimal)
		.value("CharsUppercase", ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsUppercase)
		.value("CharsNoBlank", ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsNoBlank)
		.value("AutoSelectAll", ImGuiInputTextFlags_::ImGuiInputTextFlags_AutoSelectAll)
		.value("EnterReturnsTrue", ImGuiInputTextFlags_::ImGuiInputTextFlags_EnterReturnsTrue)
		//.value("CallbackCompletion", ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackCompletion)
		//.value("CallbackHistory", ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackHistory)
		//.value("CallbackAlways", ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackAlways)
		//.value("CallbackCharFilter", ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackCharFilter)
		.value("AllowTabInput", ImGuiInputTextFlags_::ImGuiInputTextFlags_AllowTabInput)
		.value("CtrlEnterForNewLine", ImGuiInputTextFlags_::ImGuiInputTextFlags_CtrlEnterForNewLine)
		.value("NoHorizontalScroll", ImGuiInputTextFlags_::ImGuiInputTextFlags_NoHorizontalScroll)
		.value("AlwaysInsertMode", ImGuiInputTextFlags_::ImGuiInputTextFlags_AlwaysInsertMode)
		.value("ReadOnly", ImGuiInputTextFlags_::ImGuiInputTextFlags_ReadOnly)
		.value("Password", ImGuiInputTextFlags_::ImGuiInputTextFlags_Password)
		//.value("NoUndoRedo", ImGuiInputTextFlags_::ImGuiInputTextFlags_NoUndoRedo)
		.value("Multiline", ImGuiInputTextFlags_::ImGuiInputTextFlags_Multiline)
		.export_values();

	py::enum_<ImGuiCol_>(M("ImGui"), "Colors")
		.value("Text", ImGuiCol_::ImGuiCol_Text)
		.value("TextDisabled", ImGuiCol_::ImGuiCol_TextDisabled)
		.value("WindowBg", ImGuiCol_::ImGuiCol_WindowBg)
		.value("ChildBg", ImGuiCol_::ImGuiCol_ChildBg)
		.value("PopupBg", ImGuiCol_::ImGuiCol_PopupBg)
		.value("Border", ImGuiCol_::ImGuiCol_Border)
		.value("BorderShadow", ImGuiCol_::ImGuiCol_BorderShadow)
		.value("FrameBg", ImGuiCol_::ImGuiCol_FrameBg)
		.value("FrameBgHovered", ImGuiCol_::ImGuiCol_FrameBgHovered)
		.value("FrameBgActive", ImGuiCol_::ImGuiCol_FrameBgActive)
		.value("TitleBg", ImGuiCol_::ImGuiCol_TitleBg)
		.value("TitleBgActive", ImGuiCol_::ImGuiCol_TitleBgActive)
		.value("TitleBgCollapsed", ImGuiCol_::ImGuiCol_TitleBgCollapsed)
		.value("MenuBarBg", ImGuiCol_::ImGuiCol_MenuBarBg)
		.value("ScrollbarBg", ImGuiCol_::ImGuiCol_ScrollbarBg)
		.value("ScrollbarGrab", ImGuiCol_::ImGuiCol_ScrollbarGrab)
		.value("ScrollbarGrabHovered", ImGuiCol_::ImGuiCol_ScrollbarGrabHovered)
		.value("ScrollbarGrabActive", ImGuiCol_::ImGuiCol_ScrollbarGrabActive)
		.value("CheckMark", ImGuiCol_::ImGuiCol_CheckMark)
		.value("SliderGrab", ImGuiCol_::ImGuiCol_SliderGrab)
		.value("SliderGrabActive", ImGuiCol_::ImGuiCol_SliderGrabActive)
		.value("Button", ImGuiCol_::ImGuiCol_Button)
		.value("ButtonHovered", ImGuiCol_::ImGuiCol_ButtonHovered)
		.value("ButtonActive", ImGuiCol_::ImGuiCol_ButtonActive)
		.value("Header", ImGuiCol_::ImGuiCol_Header)
		.value("HeaderHovered", ImGuiCol_::ImGuiCol_HeaderHovered)
		.value("HeaderActive", ImGuiCol_::ImGuiCol_HeaderActive)
		.value("Separator", ImGuiCol_::ImGuiCol_Separator)
		.value("SeparatorHovered", ImGuiCol_::ImGuiCol_SeparatorHovered)
		.value("SeparatorActive", ImGuiCol_::ImGuiCol_SeparatorActive)
		.value("ResizeGrip", ImGuiCol_::ImGuiCol_ResizeGrip)
		.value("ResizeGripHovered", ImGuiCol_::ImGuiCol_ResizeGripHovered)
		.value("ResizeGripActive", ImGuiCol_::ImGuiCol_ResizeGripActive)
		.value("PlotLines", ImGuiCol_::ImGuiCol_PlotLines)
		.value("PlotLinesHovered", ImGuiCol_::ImGuiCol_PlotLinesHovered)
		.value("PlotHistogram", ImGuiCol_::ImGuiCol_PlotHistogram)
		.value("PlotHistogramHovered", ImGuiCol_::ImGuiCol_PlotHistogramHovered)
		.value("TextSelectedBg", ImGuiCol_::ImGuiCol_TextSelectedBg)
		.value("DragDropTarget", ImGuiCol_::ImGuiCol_DragDropTarget)
		.value("NavHighlight", ImGuiCol_::ImGuiCol_NavHighlight)
		.value("NavWindowingHighlight", ImGuiCol_::ImGuiCol_NavWindowingHighlight)
		.value("NavWindowingDimBg", ImGuiCol_::ImGuiCol_NavWindowingDimBg)
		.value("ModalWindowDimBg", ImGuiCol_::ImGuiCol_ModalWindowDimBg)
		// Obsolete names (will be removed)
//		.value("WindowBg", ImGuiCol_::ImGuiCol_WindowBg)
//		.value("Column", ImGuiCol_::ImGuiCol_Column)
//		.value("ColumnHovered", ImGuiCol_::ImGuiCol_ColumnHovered)
//		.value("ColumnActive", ImGuiCol_::ImGuiCol_ColumnActive)
//		.value("ModalWindowDimBg", ImGuiCol_::ImGuiCol_ModalWindowDimBg)
		// [unused since 1.60+] the close button now uses regular button colors.
		//.value("CloseButton", ImGuiCol_::ImGuiCol_CloseButton)
		//.value("CloseButtonHovered", ImGuiCol_::ImGuiCol_CloseButtonHovered)
		//.value("CloseButtonActive", ImGuiCol_::ImGuiCol_CloseButtonActive)
		// [unused since 1.53+] ComboBg has been merged with PopupBg, so a redirect isn't accurate.
		//.value("ComboBg", ImGuiCol_::ImGuiCol_ComboBg)
		.export_values();

	py::enum_<ImGuiStyleVar_>(M("ImGui"), "Style")
		.value("Alpha", ImGuiStyleVar_::ImGuiStyleVar_Alpha)
		.value("WindowPadding", ImGuiStyleVar_::ImGuiStyleVar_WindowPadding)
		.value("WindowRounding", ImGuiStyleVar_::ImGuiStyleVar_WindowRounding)
		.value("WindowBorderSize", ImGuiStyleVar_::ImGuiStyleVar_WindowBorderSize)
		.value("WindowMinSize", ImGuiStyleVar_::ImGuiStyleVar_WindowMinSize)
		.value("WindowTitleAlign", ImGuiStyleVar_::ImGuiStyleVar_WindowTitleAlign)
		//.value("ChildWindowRounding", ImGuiStyleVar_::ImGuiStyleVar_ChildWindowRounding)
		.value("ChildRounding", ImGuiStyleVar_::ImGuiStyleVar_ChildRounding)
		.value("ChildBorderSize", ImGuiStyleVar_::ImGuiStyleVar_ChildBorderSize)
		.value("PopupRounding", ImGuiStyleVar_::ImGuiStyleVar_PopupRounding)
		.value("PopupBorderSize", ImGuiStyleVar_::ImGuiStyleVar_PopupBorderSize)
		.value("FramePadding", ImGuiStyleVar_::ImGuiStyleVar_FramePadding)
		.value("FrameRounding", ImGuiStyleVar_::ImGuiStyleVar_FrameRounding)
		.value("FrameBorderSize", ImGuiStyleVar_::ImGuiStyleVar_FrameBorderSize)
		.value("ItemSpacing", ImGuiStyleVar_::ImGuiStyleVar_ItemSpacing)
		.value("ItemInnerSpacing", ImGuiStyleVar_::ImGuiStyleVar_ItemInnerSpacing)
		.value("IndentSpacing", ImGuiStyleVar_::ImGuiStyleVar_IndentSpacing)
		.value("ScrollbarSize", ImGuiStyleVar_::ImGuiStyleVar_ScrollbarSize)
		.value("ScrollbarRounding", ImGuiStyleVar_::ImGuiStyleVar_ScrollbarRounding)
		.value("GrabMinSize", ImGuiStyleVar_::ImGuiStyleVar_GrabMinSize)
		.value("GrabRounding", ImGuiStyleVar_::ImGuiStyleVar_GrabRounding)
		.value("ButtonTextAlign", ImGuiStyleVar_::ImGuiStyleVar_ButtonTextAlign)
		.export_values();

		py::enum_<ImGuiFocusedFlags_>(M("ImGui"),"FocusedFlags")
			.value("None", ImGuiFocusedFlags_None)
			.value("ChildWindows", ImGuiFocusedFlags_ChildWindows)
			.value("RootWindow", ImGuiFocusedFlags_RootWindow)
			.value("AnyWindow", ImGuiFocusedFlags_AnyWindow)
			.value("RootAndChildWindows", ImGuiFocusedFlags_RootAndChildWindows)
			.export_values();

		py::enum_<ImGuiHoveredFlags_>(M("ImGui"),"HoveredFlags")
			.value("None",ImGuiHoveredFlags_None)
			.value("ChildWindows",ImGuiHoveredFlags_ChildWindows)
			.value("RootWindow",ImGuiHoveredFlags_RootWindow)
			.value("AnyWindow",ImGuiHoveredFlags_AnyWindow)
			.value("AllowWhenBlockedByPopup",ImGuiHoveredFlags_AllowWhenBlockedByPopup)
			.value("AllowWhenBlockedByActiveItem",ImGuiHoveredFlags_AllowWhenBlockedByActiveItem)
			.value("AllowWhenOverlapped",ImGuiHoveredFlags_AllowWhenOverlapped)
			.value("AllowWhenDisabled",ImGuiHoveredFlags_AllowWhenDisabled)
			.value("RectOnly",ImGuiHoveredFlags_RectOnly)
			.export_values();

	py::enum_<ImDrawCornerFlags_>(M("ImGui"), "Corner")
		.value("TopLeft", ImDrawCornerFlags_TopLeft)
		.value("TopRight", ImDrawCornerFlags_TopRight)
		.value("BotRight", ImDrawCornerFlags_BotRight)
		.value("BotLeft", ImDrawCornerFlags_BotLeft)
		.value("All", ImDrawCornerFlags_All)
		.export_values();

	py::class_<Bool>(M("ImGui"), "Bool")
		.def(py::init())
		.def(py::init<bool>())
		.def_readwrite("value", &Bool::value);

	py::class_<Float>(M("ImGui"), "Float")
		.def(py::init())
		.def(py::init<float>())
		.def_readwrite("value", &Float::value);

	py::class_<Int>(M("ImGui"), "Int")
		.def(py::init())
		.def(py::init<int>())
		.def_readwrite("value", &Int::value);

	py::class_<String>(M("ImGui"), "String")
		.def(py::init())
		.def(py::init<std::string>())
		.def_readwrite("value", &String::value);

	py::class_<ImVec2>(M("ImGui"), "Vec2")
		.def(py::init())
		.def(py::init<float, float>())
		.def_readwrite("x", &ImVec2::x)
		.def_readwrite("y", &ImVec2::y)
		.def(py::self * float())
		.def(py::self / float())
		.def(py::self + py::self)
		.def(py::self - py::self)
		.def(py::self * py::self)
		.def(py::self / py::self)
		.def(py::self += py::self)
		.def(py::self -= py::self)
		.def(py::self *= float())
		.def(py::self /= float())
		.def("__mul__", [](float b, const ImVec2 &a) {
			return a * b;
		}, py::is_operator());

	py::class_<ImVec4>(M("ImGui"), "Vec4")
		.def(py::init())
		.def(py::init<float, float, float, float>())
		.def_readwrite("x", &ImVec4::x)
		.def_readwrite("y", &ImVec4::y)
		.def_readwrite("z", &ImVec4::z)
		.def_readwrite("w", &ImVec4::w);

//  FIXME: Use ImGui::Image
//	py::class_<Image>(M("ImGui"), "Image")
//			.def(py::init<ndarray_uint8>(), "Constructs Image object from ndarray, PIL Image, numpy array, etc.")
//			.def("grayscale_to_alpha", &Image::GrayScaleToAlpha, "For grayscale images, uses values as alpha")
//			.def_readonly("width", &Image::m_width)
//			.def_readonly("height", &Image::m_height);

	py::class_<ImGuiStyle>(M("ImGui"), "GuiStyle")
		.def(py::init())
			.def_readwrite("alpha", &ImGuiStyle::Alpha)
			.def_readwrite("window_padding", &ImGuiStyle::WindowPadding)
			.def_readwrite("window_rounding", &ImGuiStyle::WindowRounding)
			.def_readwrite("window_border_size", &ImGuiStyle::WindowBorderSize)
			.def_readwrite("window_min_size", &ImGuiStyle::WindowMinSize)
			.def_readwrite("window_title_align", &ImGuiStyle::WindowTitleAlign)
			.def_readwrite("child_rounding", &ImGuiStyle::ChildRounding)
			.def_readwrite("child_border_size", &ImGuiStyle::ChildBorderSize)
			.def_readwrite("popup_rounding", &ImGuiStyle::PopupRounding)
			.def_readwrite("popup_border_size", &ImGuiStyle::PopupBorderSize)
			.def_readwrite("frame_padding", &ImGuiStyle::FramePadding)
			.def_readwrite("frame_rounding", &ImGuiStyle::FrameRounding)
			.def_readwrite("frame_border_size", &ImGuiStyle::FrameBorderSize)
			.def_readwrite("item_spacing", &ImGuiStyle::ItemSpacing)
			.def_readwrite("item_inner_spacing", &ImGuiStyle::ItemInnerSpacing)
			.def_readwrite("touch_extra_spacing", &ImGuiStyle::TouchExtraPadding)
			.def_readwrite("indent_spacing", &ImGuiStyle::IndentSpacing)
			.def_readwrite("columns_min_spacing", &ImGuiStyle::ColumnsMinSpacing)
			.def_readwrite("scroll_bar_size", &ImGuiStyle::ScrollbarSize)
			.def_readwrite("scroll_bar_rounding", &ImGuiStyle::ScrollbarRounding)
			.def_readwrite("grab_min_size", &ImGuiStyle::GrabMinSize)
			.def_readwrite("grab_rounding", &ImGuiStyle::GrabRounding)
			.def_readwrite("button_text_align", &ImGuiStyle::ButtonTextAlign)
			.def_readwrite("display_window_padding", &ImGuiStyle::DisplayWindowPadding)
			.def_readwrite("display_safe_area_padding", &ImGuiStyle::DisplaySafeAreaPadding)
			.def_readwrite("mouse_cursor_scale", &ImGuiStyle::MouseCursorScale)
			.def_readwrite("anti_aliased_lines", &ImGuiStyle::AntiAliasedLines)
			.def_readwrite("anti_aliased_fill", &ImGuiStyle::AntiAliasedFill)
			.def_readwrite("curve_tessellation_tol", &ImGuiStyle::CurveTessellationTol)
		.def("get_color",[](ImGuiStyle& self, ImGuiCol_ a)
			{
				return self.Colors[(int)a];
			})
		.def("set_color",[](ImGuiStyle& self, ImGuiCol_ a, ImVec4 c)
			{
				self.Colors[(int)a] = c;
			});

	M("ImGui").def("get_style", &ImGui::GetStyle);
	M("ImGui").def("set_style", [](const ImGuiStyle& a)
		{
			ImGui::GetStyle() = a;
		});

	M("ImGui").def("style_color_classic", []()
		{
			ImGui::StyleColorsClassic();
		});
	M("ImGui").def("style_color_dark", []()
		{
			ImGui::StyleColorsDark();
		});
	M("ImGui").def("style_color_light", []()
		{
			ImGui::StyleColorsLight();
		});

	M("ImGui").def("show_test_window", [](){ ImGui::ShowDemoWindow(); }, "create demo/test window (previously called ShowTestWindow). demonstrate most ImGui features.");	// deprecated
	M("ImGui").def("show_demo_window", [](){ ImGui::ShowDemoWindow(); }, "create demo/test window (previously called ShowTestWindow). demonstrate most ImGui features.");
	M("ImGui").def("show_metrics_window", [](){ ImGui::ShowMetricsWindow(); }, "create metrics window. display ImGui internals: draw commands (with individual draw calls and vertices), window list, basic internal state, etc.");
	M("ImGui").def("show_style_editor", [](){ ImGui::ShowStyleEditor(); }, "add style editor block (not a window). you can pass in a reference ImGuiStyle structure to compare to, revert to and save to (else it uses the default style)");
	M("ImGui").def("show_style_selector", [](const char* label){ ImGui::ShowStyleSelector(label); }, "add style selector block (not a window), essentially a combo listing the default styles.");
	M("ImGui").def("show_font_selector", [](const char* label){ ImGui::ShowFontSelector(label); }, "add font selector block (not a window), essentially a combo listing the loaded fonts.");
	M("ImGui").def("show_user_guide", [](){ ImGui::ShowUserGuide(); }, "add basic help/info block (not a window): how to manipulate ImGui as a end-user (mouse/keyboard controls).");


	M("ImGui").def("begin",[](const std::string& name, Bool& opened, ImGuiWindowFlags flags) -> bool
		{
			return ImGui::Begin(name.c_str(), opened.null ? nullptr : &opened.value, flags);
		},
		"Push a new ImGui window to add widgets to",
		py::arg("name"), py::arg("opened") = null, py::arg("flags") = ImGuiWindowFlags_(0));

	M("ImGui").def("end", &ImGui::End);

	M("ImGui").def("begin_child",[](const std::string& str_id, const ImVec2& size, bool border, ImGuiWindowFlags extra_flags) -> bool
		{
			return ImGui::BeginChild(str_id.c_str(), size, border);
		},
		"begin a scrolling region. size==0.0f: use remaining window size, size<0.0f: use remaining window size minus abs(size). size>0.0f: fixed size. each axis can use a different mode, e.g. ImVec2(0,400).",
		py::arg("str_id"), py::arg("size") = ImVec2(0,0), py::arg("border") = false, py::arg("extra_flags") = ImGuiWindowFlags_(0));

	M("ImGui").def("end_child", &ImGui::EndChild);

	M("ImGui").def("begin_main_menu_bar", &ImGui::BeginMainMenuBar, "create and append to a full screen menu-bar. only call EndMainMenuBar() if this returns true!");
	M("ImGui").def("end_main_menu_bar", &ImGui::EndMainMenuBar);
	M("ImGui").def("begin_menu_bar", &ImGui::BeginMenuBar, "append to menu-bar of current window (requires ImGuiWindowFlags_MenuBar flag set on parent window). only call EndMenuBar() if this returns true!");
	M("ImGui").def("end_menu_bar", &ImGui::EndMenuBar);
	M("ImGui").def("begin_menu",[](const std::string& name, Bool& enabled) -> bool
		{
			return ImGui::BeginMenu(name.c_str(), (bool *) (enabled.null ? nullptr : &enabled.value));
		},
		"create a sub-menu entry. only call EndMenu() if this returns true!",
		py::arg("name"), py::arg("enabled") = Bool(true));
	M("ImGui").def("menu_item",[](const std::string& label, const std::string& shortcut, Bool& selected, bool enabled) -> bool
		{
			return ImGui::MenuItem(label.c_str(), shortcut.c_str(), selected.null ? nullptr : &selected.value, enabled);
		},
		"return true when activated + toggle (*p_selected) if p_selected != NULL",
		py::arg("name"), py::arg("shortcut"), py::arg("selected") = Bool(false), py::arg("enabled") = true);
	M("ImGui").def("end_menu", &ImGui::EndMenu);

	M("ImGui").def("begin_tooltip", &ImGui::BeginTooltip);
	M("ImGui").def("end_tooltip", &ImGui::EndTooltip);
	M("ImGui").def("set_tooltip", [](const char* text){ ImGui::SetTooltip("%s", text); });


	M("ImGui").def("open_popup", [](std::string str_id)
		{
			ImGui::OpenPopup(str_id.c_str());
		},
		"call to mark popup as open (don't call every frame!). popups are closed when user click outside, or if CloseCurrentPopup() is called within a BeginPopup()/EndPopup() block. By default, Selectable()/MenuItem() are calling CloseCurrentPopup(). Popup identifiers are relative to the current ID-stack (so OpenPopup and BeginPopup needs to be at the same level)."
	);
	M("ImGui").def("open_popup_on_item_click", [](std::string str_id = "", int mouse_button = 1)
		{
			ImGui::OpenPopupOnItemClick(str_id.c_str(), mouse_button);
		},
		"helper to open popup when clicked on last item. return true when just opened."
	);
	M("ImGui").def("begin_popup", [](std::string str_id, ImGuiWindowFlags flags)->bool
		{
			return ImGui::BeginPopup(str_id.c_str(), flags);
		},
		"",
          py::arg("name"), py::arg("flags") = ImGuiWindowFlags_(0)
	);
	M("ImGui").def("begin_popup_modal", [](std::string name = "")->bool
		{
			return ImGui::BeginPopupModal(name.c_str());
		},
		""
	);

	// add more arguments later:
	M("ImGui").def("begin_popup_context_item", []()
		{
			ImGui::BeginPopupContextItem();
		},
		"helper to open and begin popup when clicked on last item. if you can pass a NULL str_id only if the previous item had an id. If you want to use that on a non-interactive item such as Text() you need to pass in an explicit ID here."
	);
	M("ImGui").def("begin_popup_context_window", []()
		{
			ImGui::BeginPopupContextWindow();
		},
		"helper to open and begin popup when clicked on current window."
	);
	M("ImGui").def("begin_popup_context_void", []()
		{
			ImGui::BeginPopupContextVoid();
		},
		"helper to open and begin popup when clicked in void (where there are no imgui windows)."
	);

	M("ImGui").def("end_popup", &ImGui::EndPopup);
	M("ImGui").def("is_popup_open", [](std::string str_id = "")->bool
		{
			return ImGui::IsPopupOpen(str_id.c_str());
		},
		""
	);
	M("ImGui").def("close_current_popup", &ImGui::CloseCurrentPopup);

	M("ImGui").def("get_content_region_max", &ImGui::GetContentRegionMax);
	M("ImGui").def("get_content_region_avail", &ImGui::GetContentRegionAvail);
//	M("ImGui").def("get_content_region_avail_width", &ImGui::GetContentRegionAvailWidth);
	M("ImGui").def("get_window_content_region_min", &ImGui::GetWindowContentRegionMin);
	M("ImGui").def("get_window_content_region_max", &ImGui::GetWindowContentRegionMax);
	M("ImGui").def("get_window_content_region_width", &ImGui::GetWindowContentRegionWidth);
	// M("ImGui").def("get_window_font_size", &ImGui::GetWindowFontSize);
	M("ImGui").def("get_font_size", &ImGui::GetFontSize);
	M("ImGui").def("set_window_font_scale", &ImGui::SetWindowFontScale);
	M("ImGui").def("get_window_pos", &ImGui::GetWindowPos);
	M("ImGui").def("get_window_size", &ImGui::GetWindowSize);
	M("ImGui").def("get_window_width", &ImGui::GetWindowWidth);
	M("ImGui").def("get_window_height", &ImGui::GetWindowHeight);
	M("ImGui").def("is_window_collapsed", &ImGui::IsWindowCollapsed);
	M("ImGui").def("is_window_appearing", &ImGui::IsWindowAppearing);
	M("ImGui").def("is_window_focused", &ImGui::IsWindowFocused);
	M("ImGui").def("is_window_hovered", &ImGui::IsWindowHovered);

	M("ImGui").def("set_window_font_scale", &ImGui::SetWindowFontScale);

	M("ImGui").def("set_next_window_pos", &ImGui::SetNextWindowPos, py::arg("pos"), py::arg("cond") = 0, py::arg("pivot") = ImVec2(0,0));
	M("ImGui").def("set_next_window_size", &ImGui::SetNextWindowSize, py::arg("size"), py::arg("cond") = 0);
	M("ImGui").def("set_next_window_size_constraints", [](const ImVec2& size_min, const ImVec2& size_max){ ImGui::SetNextWindowSizeConstraints(size_min, size_max); }, py::arg("size_min"), py::arg("size_max") = 0);
	M("ImGui").def("set_next_window_content_size", &ImGui::SetNextWindowContentSize, py::arg("size"));
//	M("ImGui").def("set_next_window_content_width", &ImGui::SetNextWindowContentWidth, py::arg("width"));
	M("ImGui").def("set_next_window_collapsed", &ImGui::SetNextWindowCollapsed, py::arg("collapsed"), py::arg("cond") = 0);
	M("ImGui").def("set_next_window_focus", &ImGui::SetNextWindowFocus);
	M("ImGui").def("set_window_pos", [](const char* name, const ImVec2& pos, ImGuiCond cond){ ImGui::SetWindowPos(name, pos, cond); }, py::arg("name"), py::arg("pos"), py::arg("cond") = 0);
	M("ImGui").def("set_window_size", [](const char* name, const ImVec2& size, ImGuiCond cond){ ImGui::SetWindowSize(name, size, cond); }, py::arg("name"), py::arg("size"), py::arg("cond") = 0);
	M("ImGui").def("set_window_collapsed", [](const char* name, bool collapsed, ImGuiCond cond){ ImGui::SetWindowCollapsed(name, collapsed, cond); }, py::arg("name"), py::arg("collapsed"), py::arg("cond") = 0);
	M("ImGui").def("set_window_focus", [](const char* name){ ImGui::SetWindowFocus(name); }, py::arg("name"));

	M("ImGui").def("get_scroll_x", &ImGui::GetScrollX);
	M("ImGui").def("get_scroll_y", &ImGui::GetScrollY);
	M("ImGui").def("get_scroll_max_x", &ImGui::GetScrollMaxX);
	M("ImGui").def("get_scroll_max_y", &ImGui::GetScrollMaxY);
//	M("ImGui").def("set_scroll_x", &ImGui::SetScrollX);
//	M("ImGui").def("set_scroll_y", &ImGui::SetScrollY);
//	M("ImGui").def("set_scroll_here", &ImGui::SetScrollHere, py::arg("center_y_ratio") = 0.5f);
//	M("ImGui").def("set_scroll_from_pos_y", &ImGui::SetScrollFromPosY, py::arg("pos_y"), py::arg("center_y_ratio") = 0.5f);
	M("ImGui").def("set_keyboard_focus_here", &ImGui::SetKeyboardFocusHere, py::arg("offset") = 0.0f);

	M("ImGui").def("push_style_color", [](ImGuiCol_ idx, const ImVec4& col){ ImGui::PushStyleColor((ImGuiCol)idx, col); });
	M("ImGui").def("pop_style_color", &ImGui::PopStyleColor, py::arg("count") = 1);

	M("ImGui").def("push_style_var", [](ImGuiStyleVar_ idx, float val){ ImGui::PushStyleVar((ImGuiStyleVar)idx, val); });
	M("ImGui").def("push_style_var", [](ImGuiStyleVar_ idx, ImVec2 val){ ImGui::PushStyleVar((ImGuiStyleVar)idx, val); });
	M("ImGui").def("pop_style_var", &ImGui::PopStyleVar, py::arg("count") = 1);

	M("ImGui").def("push_item_width", &ImGui::PushItemWidth);
	M("ImGui").def("pop_item_width", &ImGui::PopItemWidth);
	M("ImGui").def("calc_item_width", &ImGui::CalcItemWidth);
	M("ImGui").def("calc_text_size", &ImGui::CalcTextSize, py::arg("text"), py::arg("text_end") = nullptr, py::arg("hide_text_after_double_hash") = false, py::arg("wrap_width") = 0.0f);
	M("ImGui").def("push_text_wrap_pos", &ImGui::PushTextWrapPos, py::arg("wrap_pos_x") = 0.0f);
	M("ImGui").def("pop_text_wrap_pos", &ImGui::PopTextWrapPos);
	M("ImGui").def("push_allow_keyboard_focus", &ImGui::PushAllowKeyboardFocus);
	M("ImGui").def("pop_allow_keyboard_focus", &ImGui::PopAllowKeyboardFocus);
	M("ImGui").def("push_button_repeat", &ImGui::PushButtonRepeat);
	M("ImGui").def("pop_button_repeat", &ImGui::PopButtonRepeat);


	M("ImGui").def("separator", &ImGui::Separator);
	M("ImGui").def("same_line", &ImGui::SameLine, py::arg("local_pos_x") = 0.0f, py::arg("spacing_w") = -1.0f);
	M("ImGui").def("new_line", &ImGui::NewLine);
	M("ImGui").def("spacing", &ImGui::Spacing);
	M("ImGui").def("dummy", &ImGui::Dummy);
	M("ImGui").def("indent", &ImGui::Indent, py::arg("indent_w") = 0.0f);
	M("ImGui").def("unindent", &ImGui::Unindent, py::arg("indent_w") = 0.0f);
	M("ImGui").def("begin_group", &ImGui::BeginGroup);
	M("ImGui").def("end_group", &ImGui::EndGroup);
	M("ImGui").def("get_cursor_pos", &ImGui::GetCursorPos);
	M("ImGui").def("get_cursor_pos_x", &ImGui::GetCursorPosX);
	M("ImGui").def("get_cursor_pos_y", &ImGui::GetCursorPosY);
	M("ImGui").def("set_cursor_pos", &ImGui::SetCursorPos);
	M("ImGui").def("set_cursor_pos_x", &ImGui::SetCursorPosX);
	M("ImGui").def("set_cursor_pos_y", &ImGui::SetCursorPosY);
	M("ImGui").def("get_cursor_start_pos", &ImGui::GetCursorStartPos);
	M("ImGui").def("get_cursor_screen_pos", &ImGui::GetCursorScreenPos);
	M("ImGui").def("set_cursor_screen_pos", &ImGui::SetCursorScreenPos);
//	M("ImGui").def("align_first_text_height_to_widgets", &ImGui::AlignFirstTextHeightToWidgets);
	M("ImGui").def("get_text_line_height", &ImGui::GetTextLineHeight);
	M("ImGui").def("get_text_line_height_with_spacing", &ImGui::GetTextLineHeightWithSpacing);
//	M("ImGui").def("get_items_line_height_with_spacing", &ImGui::GetItemsLineHeightWithSpacing);

	M("ImGui").def("columns", &ImGui::Columns, py::arg("count") = 1, py::arg("id") = nullptr, py::arg("border") = true);
	M("ImGui").def("next_column", &ImGui::NextColumn);
	M("ImGui").def("get_column_index", &ImGui::GetColumnIndex);
	M("ImGui").def("get_column_offset", &ImGui::GetColumnOffset, py::arg("column_index") = -1);
	M("ImGui").def("set_column_offset", &ImGui::SetColumnOffset, py::arg("column_index"), py::arg("offset_x"));
	M("ImGui").def("get_column_width", &ImGui::GetColumnWidth, py::arg("column_index") = -1);
    M("ImGui").def("set_column_width", &ImGui::SetColumnWidth, py::arg("column_index"), py::arg("column_width"));
	M("ImGui").def("get_columns_count", &ImGui::GetColumnsCount);

	M("ImGui").def("push_id_str", [](const char* str_id_begin, const char* str_id_end){ ImGui::PushID(str_id_begin, str_id_end); }, py::arg("str_id_begin"), py::arg("str_id_end") = nullptr);
	M("ImGui").def("push_id_int", [](int int_id){ ImGui::PushID(int_id); } );
	M("ImGui").def("pop_id", &ImGui::PopID);
	M("ImGui").def("get_id_str", [](const char* str_id_begin, const char* str_id_end){ ImGui::GetID(str_id_begin, str_id_end); }, py::arg("str_id_begin"), py::arg("str_id_end") = nullptr);

	M("ImGui").def("text", [](const char* text){ ImGui::Text("%s", text); });
	M("ImGui").def("text_colored", [](const ImVec4& col, const char* text){ ImGui::TextColored(col, "%s", text); });
	M("ImGui").def("text_disabled", [](const char* text){ ImGui::TextDisabled("%s", text); });
	M("ImGui").def("text_wrapped", [](const char* text){ ImGui::TextWrapped("%s", text); });
	M("ImGui").def("label_text", [](const char* label, const char* text){ ImGui::LabelText(label, "%s", text); });
	M("ImGui").def("bullet_text", [](const char* text){ ImGui::BulletText("%s", text); });
	M("ImGui").def("bullet", &ImGui::Bullet);

	M("ImGui").def("button", &ImGui::Button, py::arg("label"), py::arg("size") = ImVec2(0,0));
	M("ImGui").def("small_button", &ImGui::SmallButton);
	M("ImGui").def("invisible_button", &ImGui::InvisibleButton);
	M("ImGui").def("tree_node", [](const char* label){ return ImGui::TreeNode(label); }, py::arg("label"));
	M("ImGui").def("tree_pop", &ImGui::TreePop);
	M("ImGui").def("set_next_item_open", &ImGui::SetNextItemOpen, py::arg("is_open"), py::arg("cond") = 0);
	M("ImGui").def("collapsing_header", [](const char* label, ImGuiTreeNodeFlags flags){ return ImGui::CollapsingHeader(label, flags); }, py::arg("label"), py::arg("flags") = 0);
	M("ImGui").def("checkbox", [](const char* label, Bool& v){ return ImGui::Checkbox(label, &v.value); });
	M("ImGui").def("radio_button", [](const char* label, bool active){ return ImGui::RadioButton(label, active); });

	M("ImGui").def("begin_combo", &ImGui::BeginCombo, py::arg("label"), py::arg("preview_value"), py::arg("flags") = 0);
	M("ImGui").def("end_combo", &ImGui::EndCombo, "only call EndCombo() if BeginCombo() returns true!");
	M("ImGui").def("combo", [](const char* label, Int& current_item, const std::vector<std::string>& items)
	{
		if (items.size() < 10)
		{
			const char* items_[10];
			for (int i = 0; i < (int)items.size(); ++i)
			{
				items_[i] = items[i].c_str();
			}
			return ImGui::Combo(label, &current_item.value, items_, (int)items.size());
		}
		else
		{
			const char** items_= new const char*[items.size()];
			for (int i = 0; i < (int)items.size(); ++i)
			{
				items_[i] = items[i].c_str();
			}
			bool result = ImGui::Combo(label, &current_item.value, items_, (int)items.size());
			delete[] items_;
			return result;
		}
	});

	M("ImGui").def("input_text", [](const char* label, String& text, size_t buf_size, ImGuiInputTextFlags flags)
	{
		bool result = false;
		if (buf_size > 255)
		{
			char* buff = new char[buf_size + 1];
			strncpy(buff, text.value.c_str(), buf_size);
			result = ImGui::InputText(label, buff, buf_size, flags);
			if (result)
			{
				text.value = buff;
			}
			delete[] buff;
		}
		else
		{
			char buff[256];
			strncpy(buff, text.value.c_str(), 255);
			result = ImGui::InputText(label, buff, buf_size, flags);
			if (result)
			{
				text.value = buff;
			}
		}
		return result;
	}, py::arg("label"), py::arg("text"), py::arg("buf_size"), py::arg("flags") = 0);
	M("ImGui").def("input_text_multiline", [](const char* label, String& text, size_t buf_size, const ImVec2& size, ImGuiInputTextFlags flags)
	{
		bool result = false;
		if (buf_size > 255)
		{
			char* buff = new char[buf_size + 1];
			strncpy(buff, text.value.c_str(), buf_size);
			result = ImGui::InputTextMultiline(label, buff, buf_size, size, flags);
			if (result)
			{
				text.value = buff;
			}
			delete[] buff;
		}
		else
		{
			char buff[256];
			strncpy(buff, text.value.c_str(), 255);
			result = ImGui::InputTextMultiline(label, buff, buf_size, size, flags);
			if (result)
			{
				text.value = buff;
			}
		}
		return result;
	}, py::arg("label"), py::arg("text"), py::arg("buf_size"), py::arg("size") = ImVec2(0,0), py::arg("flags") = 0);
	M("ImGui").def("input_float", [](const char* label, Float& v, float step, float step_fast, const char * decimal_precision, ImGuiInputTextFlags flags)
	{
		return ImGui::InputFloat(label, &v.value, step, step_fast, decimal_precision, flags);
	}, py::arg("label"), py::arg("v"), py::arg("step") = 0.0f, py::arg("step_fast") = 0.0f, py::arg("decimal_precision") = -1, py::arg("flags") = 0);
	M("ImGui").def("input_float2", [](const char* label, Float& v1, Float& v2, const char * decimal_precision, ImGuiInputTextFlags flags)
	{
		float v[2] = {v1.value, v2.value};
		bool result = ImGui::InputFloat2(label, v, decimal_precision, flags);
		v1.value = v[0];
		v2.value = v[1];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("decimal_precision") = -1, py::arg("flags") = 0);
	M("ImGui").def("input_float3", [](const char* label, Float& v1, Float& v2, Float& v3, const char * decimal_precision, ImGuiInputTextFlags flags)
	{
		float v[3] = {v1.value, v2.value, v3.value};
		bool result = ImGui::InputFloat3(label, v, decimal_precision, flags);
		v1.value = v[0];
		v2.value = v[1];
		v3.value = v[2];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("decimal_precision") = -1, py::arg("flags") = 0);
	M("ImGui").def("input_float4", [](const char* label, Float& v1, Float& v2, Float& v3, Float& v4, const char * decimal_precision, ImGuiInputTextFlags flags)
	{
		float v[4] = {v1.value, v2.value, v3.value, v4.value};
		bool result = ImGui::InputFloat4(label, v, decimal_precision, flags);
		v1.value = v[0];
		v2.value = v[1];
		v3.value = v[2];
		v4.value = v[3];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v4"), py::arg("decimal_precision") = -1, py::arg("flags") = 0);
	M("ImGui").def("input_int", [](const char* label, Int& v, int step, int step_fast, ImGuiInputTextFlags flags)
	{
		return ImGui::InputInt(label, &v.value, step, step_fast, flags);
	}, py::arg("label"), py::arg("v"), py::arg("step") = 1, py::arg("step_fast") = 100, py::arg("flags") = 0);
	M("ImGui").def("input_int2", [](const char* label, Int& v1, Int& v2, ImGuiInputTextFlags flags)
	{
		int v[2] = {v1.value, v2.value};
		bool result = ImGui::InputInt2(label, v, flags);
		v1.value = v[0];
		v2.value = v[1];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("flags") = 0);
	M("ImGui").def("input_int3", [](const char* label, Int& v1, Int& v2, Int& v3, ImGuiInputTextFlags flags)
	{
		int v[3] = {v1.value, v2.value, v3.value};
		bool result = ImGui::InputInt3(label, v, flags);
		v1.value = v[0];
		v2.value = v[1];
		v3.value = v[2];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("flags") = 0);
	M("ImGui").def("input_int4", [](const char* label, Int& v1, Int& v2, Int& v3, Int& v4, ImGuiInputTextFlags flags)
	{
		int v[4] = {v1.value, v2.value, v3.value, v4.value};
		bool result = ImGui::InputInt4(label, v, flags);
		v1.value = v[0];
		v2.value = v[1];
		v3.value = v[2];
		v4.value = v[3];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v4"), py::arg("flags") = 0);


	M("ImGui").def("color_edit", [](const char* label, ImVec4& col)->bool
	{
		return ImGui::ColorEdit4(label, &col.x);
	});
	M("ImGui").def("color_picker", [](const char* label, ImVec4& col)->bool
	{
		return ImGui::ColorPicker4(label, &col.x);
	});


	M("ImGui").def("slider_float", [](const char* label, Float& v, float v_min, float v_max, const char* display_format, float power)
	{
		return ImGui::SliderFloat(label, &v.value, v_min, v_max, display_format, power);
	}, py::arg("label"), py::arg("v"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.3f", py::arg("power") = 1.0f);
	M("ImGui").def("slider_float2", [](const char* label, Float& v1, Float& v2, float v_min, float v_max, const char* display_format, float power)
	{
		float v[2] = {v1.value, v2.value};
		bool result = ImGui::SliderFloat2(label, v, v_min, v_max, display_format, power);
		v1.value = v[0];
		v2.value = v[1];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.3f", py::arg("power") = 1.0f);
	M("ImGui").def("slider_float3", [](const char* label, Float& v1, Float& v2, Float& v3, float v_min, float v_max, const char* display_format, float power)
	{
		float v[3] = {v1.value, v2.value, v3.value};
		bool result = ImGui::SliderFloat3(label, v, v_min, v_max, display_format, power);
		v1.value = v[0];
		v2.value = v[1];
		v3.value = v[2];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.3f", py::arg("power") = 1.0f);
	M("ImGui").def("slider_float4", [](const char* label, Float& v1, Float& v2, Float& v3, Float& v4, float v_min, float v_max, const char* display_format, float power)
	{
		float v[4] = {v1.value, v2.value, v3.value, v4.value};
		bool result = ImGui::SliderFloat4(label, v, v_min, v_max, display_format, power);
		v1.value = v[0];
		v2.value = v[1];
		v3.value = v[2];
		v4.value = v[3];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v4"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.3f", py::arg("power") = 1.0f);

	M("ImGui").def("v_slider_float", [](const char* label, const ImVec2& size, Float& v, float v_min, float v_max, const char* display_format, float power)
	{
		return ImGui::VSliderFloat(label, size, &v.value, v_min, v_max, display_format, power);
	}, py::arg("label"), py::arg("size"), py::arg("v"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.3f", py::arg("power") = 1.0f);

	M("ImGui").def("slider_angle", [](const char* label, Float& v_rad, float v_degrees_min, float v_degrees_max)
	{
		return ImGui::SliderAngle(label, &v_rad.value, v_degrees_min, v_degrees_max);
	}, py::arg("label"), py::arg("v_rad"), py::arg("v_degrees_min")=-360.0f, py::arg("v_degrees_max")=+360.0f);

	M("ImGui").def("slider_int", [](const char* label, Int& v, int v_min, int v_max, const char* display_format)
	{
		return ImGui::SliderInt(label, &v.value, v_min, v_max, display_format);
	}, py::arg("label"), py::arg("v"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.0f");
	M("ImGui").def("slider_int2", [](const char* label, Int& v1, Int& v2, int v_min, int v_max, const char* display_format)
	{
		int v[2] = {v1.value, v2.value};
		bool result = ImGui::SliderInt2(label, v, v_min, v_max, display_format);
		v1.value = v[0];
		v2.value = v[1];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.0f");
	M("ImGui").def("slider_int3", [](const char* label, Int& v1, Int& v2, Int& v3, int v_min, int v_max, const char* display_format)
	{
		int v[3] = {v1.value, v2.value, v3.value};
		bool result = ImGui::SliderInt3(label, v, v_min, v_max, display_format);
		v1.value = v[0];
		v2.value = v[1];
		v3.value = v[2];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.0f");
	M("ImGui").def("slider_int4", [](const char* label, Int& v1, Int& v2, Int& v3, Int& v4, int v_min, int v_max, const char* display_format)
	{
		int v[4] = {v1.value, v2.value, v3.value, v4.value};
		bool result = ImGui::SliderInt4(label, v, v_min, v_max, display_format);
		v1.value = v[0];
		v2.value = v[1];
		v3.value = v[2];
		v4.value = v[3];
		return result;
	}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v4"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.0f");


	M("ImGui").def("v_slider_int", [](const char* label, const ImVec2& size, Int& v, int v_min, int v_max, const char* display_format)
	{
		return ImGui::VSliderInt(label, size, &v.value,  v_min, v_max, display_format);
	}, py::arg("label"), py::arg("size"), py::arg("v"), py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.0f");

	//
	M("ImGui").def("drag_float", [](const char* label, Float& v, float v_speed, float v_min, float v_max, const char* display_format, float power)
		{
			return ImGui::DragFloat(label, &v.value, v_speed, v_min, v_max, display_format, power);
		}, py::arg("label"), py::arg("v"), py::arg("v_speed") = 1.0f, py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.3f", py::arg("power") = 1.0f);
	M("ImGui").def("drag_float2", [](const char* label, Float& v1, Float& v2, float v_speed, float v_min, float v_max, const char* display_format, float power)
		{
			float v[2] = {v1.value, v2.value};
			bool result = ImGui::DragFloat2(label, v, v_speed, v_min, v_max, display_format, power);
			v1.value = v[0];
			v2.value = v[1];
			return result;
		}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v_speed") = 1.0f, py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.3f", py::arg("power") = 1.0f);
	M("ImGui").def("drag_float3", [](const char* label, Float& v1, Float& v2, Float& v3, float v_speed, float v_min, float v_max, const char* display_format, float power)
		{
			float v[3] = {v1.value, v2.value, v3.value};
			bool result = ImGui::DragFloat3(label, v, v_speed, v_min, v_max, display_format, power);
			v1.value = v[0];
			v2.value = v[1];
			v3.value = v[2];
			return result;
		}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v_speed") = 1.0f, py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.3f", py::arg("power") = 1.0f);
	M("ImGui").def("drag_float4", [](const char* label, Float& v1, Float& v2, Float& v3, Float& v4, float v_speed, float v_min, float v_max, const char* display_format, float power)
		{
			float v[4] = {v1.value, v2.value, v3.value, v4.value};
			bool result = ImGui::DragFloat4(label, v, v_speed, v_min, v_max, display_format, power);
			v1.value = v[0];
			v2.value = v[1];
			v3.value = v[2];
			v4.value = v[3];
			return result;
		}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v4"), py::arg("v_speed") = 1.0f, py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.3f", py::arg("power") = 1.0f);

	M("ImGui").def("drag_int", [](const char* label, Int& v, float v_speed, int v_min, int v_max, const char* display_format)
		{
			return ImGui::DragInt(label, &v.value, v_speed, v_min, v_max, display_format);
		}, py::arg("label"), py::arg("v"), py::arg("v_speed") = 1.0f, py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.0f");
	M("ImGui").def("drag_int2", [](const char* label, Int& v1, Int& v2, float v_speed, int v_min, int v_max, const char* display_format)
		{
			int v[2] = {v1.value, v2.value};
			bool result = ImGui::DragInt2(label, v, v_speed, v_min, v_max, display_format);
			v1.value = v[0];
			v2.value = v[1];
			return result;
		}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v_speed") = 1.0f, py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.0f");
	M("ImGui").def("drag_int3", [](const char* label, Int& v1, Int& v2, Int& v3, float v_speed, int v_min, int v_max, const char* display_format)
		{
			int v[3] = {v1.value, v2.value, v3.value};
			bool result = ImGui::DragInt3(label, v, v_speed, v_min, v_max, display_format);
			v1.value = v[0];
			v2.value = v[1];
			v3.value = v[2];
			return result;
		}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v_speed") = 1.0f, py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.0f");
	M("ImGui").def("drag_int4", [](const char* label, Int& v1, Int& v2, Int& v3, Int& v4, float v_speed, int v_min, int v_max, const char* display_format)
		{
			int v[4] = {v1.value, v2.value, v3.value, v4.value};
			bool result = ImGui::DragInt4(label, v, v_speed, v_min, v_max, display_format);
			v1.value = v[0];
			v2.value = v[1];
			v3.value = v[2];
			v4.value = v[3];
			return result;
		}, py::arg("label"), py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v4"), py::arg("v_speed") = 1.0f, py::arg("v_min"), py::arg("v_max"), py::arg("display_format") = "%.0f");

	M("ImGui").def("plot_lines", [](
		const char* label,
		const std::vector<float>& values,
		int values_offset = 0,
		const char* overlay_text = NULL,
		float scale_min = FLT_MAX,
		float scale_max = FLT_MAX,
		ImVec2 graph_size = ImVec2(0,0),
		int stride = sizeof(float))
		{
			ImGui::PlotLines(label, values.data(), (int)values.size(), values_offset, overlay_text, scale_min, scale_max, graph_size, stride);
		}
		, py::arg("label")
		, py::arg("values")
		, py::arg("values_offset") = 0
		, py::arg("overlay_text") = nullptr
		, py::arg("scale_min") = FLT_MAX
		, py::arg("scale_max") = FLT_MAX
		, py::arg("graph_size") = ImVec2(0,0)
		, py::arg("stride") = sizeof(float)
		);

	// ImGui::PlotHistogram(const char *, const float *, int, int, const char *, float, float, struct ImVec2, int) file:imgui.h line:528
	M("ImGui").def("plot_histogram", [](const char * a0, const float * a1, int const & a2) -> void { return ImGui::PlotHistogram(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("plot_histogram", [](const char * a0, const float * a1, int const & a2, int const & a3) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("plot_histogram", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("plot_histogram", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4, float const & a5) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("plot_histogram", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4, float const & a5, float const & a6) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::arg("scale_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("plot_histogram", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4, float const & a5, float const & a6, struct ImVec2 const & a7) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::arg("scale_max"), pybind11::arg("graph_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("plot_histogram", (void (*)(const char *, const float *, int, int, const char *, float, float, struct ImVec2, int)) &ImGui::PlotHistogram, "C++: ImGui::PlotHistogram(const char *, const float *, int, int, const char *, float, float, struct ImVec2, int) --> void", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::arg("scale_max"), pybind11::arg("graph_size"), pybind11::arg("stride"), pybind11::call_guard<pybind11::gil_scoped_release>());

	M("ImGui").def("progress_bar", &ImGui::ProgressBar, py::arg("fraction"), py::arg("size_arg") = ImVec2(-1,0), py::arg("overlay") = nullptr);

	M("ImGui").def("color_button", &ImGui::ColorButton, py::arg("desc_id"), py::arg("col"), py::arg("flags") = 0, py::arg("size") = ImVec2(0,0), "display a colored square/button, hover for details, return true when pressed.");

	M("ImGui").def("selectable", [](
		std::string label,
		bool selected = false,
		ImGuiSelectableFlags flags = 0,
		ImVec2 size = ImVec2(0,0))->bool
		{
			return ImGui::Selectable(label.c_str(), selected, flags, size);
		}
		, py::arg("label")
		, py::arg("selected") = false
		, py::arg("flags") = 0
		, py::arg("size") = ImVec2(0,0)
		);

	M("ImGui").def("selectable", [](
		std::string label,
		Bool& selected,
		ImGuiSelectableFlags flags = 0,
		ImVec2 size = ImVec2(0,0))->bool
		{
			return ImGui::Selectable(label.c_str(), &selected.value, flags, size);
		}
		, py::arg("label")
		, py::arg("selected")
		, py::arg("flags") = 0
		, py::arg("size") = ImVec2(0,0)
		);

	M("ImGui").def("list_box_header", [](
			std::string label,
			ImVec2 size = ImVec2(0,0))
			{
				ImGui::ListBoxHeader(label.c_str(), size);
			}
			, py::arg("label")
			, py::arg("size")
			);

	M("ImGui").def("list_box_footer", &ImGui::ListBoxFooter);

	M("ImGui").def("set_item_default_focus", &ImGui::SetItemDefaultFocus);
	M("ImGui").def("set_keyboard_focus_here", &ImGui::SetKeyboardFocusHere);

	M("ImGui").def("is_item_hovered", &ImGui::IsItemHovered);
	M("ImGui").def("is_item_active", &ImGui::IsItemActive);
	M("ImGui").def("is_item_focused", &ImGui::IsItemFocused);
	M("ImGui").def("is_item_clicked", &ImGui::IsItemClicked);
	M("ImGui").def("is_item_visible", &ImGui::IsItemVisible);
	M("ImGui").def("is_item_edited", &ImGui::IsItemEdited);
	M("ImGui").def("is_item_deactivated", &ImGui::IsItemDeactivated);
	M("ImGui").def("is_item_deactivated_after_edit", &ImGui::IsItemDeactivatedAfterEdit);
	M("ImGui").def("is_any_item_hovered", &ImGui::IsAnyItemHovered);
	M("ImGui").def("is_any_item_active", &ImGui::IsAnyItemActive);
	M("ImGui").def("is_any_item_focused", &ImGui::IsAnyItemFocused);

	M("ImGui").def("get_item_rect_min", &ImGui::GetItemRectMin);
	M("ImGui").def("get_item_rect_max", &ImGui::GetItemRectMax);
	M("ImGui").def("get_item_rect_size", &ImGui::GetItemRectSize);

	M("ImGui").def("set_item_allow_overlap", &ImGui::SetItemAllowOverlap);

	M("ImGui").def("get_time", &ImGui::GetTime);
	M("ImGui").def("get_frame_count", &ImGui::GetFrameCount);

	M("ImGui").def("get_key_index", &ImGui::GetKeyIndex);
	M("ImGui").def("is_key_down", &ImGui::IsKeyDown);
	M("ImGui").def("is_key_pressed", &ImGui::IsKeyPressed);
	M("ImGui").def("is_key_released", &ImGui::IsKeyReleased);
	M("ImGui").def("get_key_pressed_amount", &ImGui::GetKeyPressedAmount);
	M("ImGui").def("is_mouse_down", &ImGui::IsMouseDown);
	M("ImGui").def("is_any_mouse_down", &ImGui::IsAnyMouseDown);
	M("ImGui").def("is_mouse_clicked", &ImGui::IsMouseClicked);
	M("ImGui").def("is_mouse_double_clicked", &ImGui::IsMouseDoubleClicked);
	M("ImGui").def("is_mouse_released", &ImGui::IsMouseReleased);
	M("ImGui").def("is_mouse_dragging", &ImGui::IsMouseDragging);
	M("ImGui").def("is_mouse_hovering_rect", &ImGui::IsMouseHoveringRect);
	M("ImGui").def("is_mouse_pos_valid", &ImGui::IsMousePosValid);
	M("ImGui").def("get_mouse_pos", &ImGui::GetMousePos);
	M("ImGui").def("get_mouse_pos_on_opening_current_popup", &ImGui::GetMousePosOnOpeningCurrentPopup);
	M("ImGui").def("get_mouse_drag_delta", &ImGui::GetMouseDragDelta);
	M("ImGui").def("reset_mouse_drag_delta", &ImGui::ResetMouseDragDelta);

	M("ImGui").def("capture_keyboard_from_app", &ImGui::CaptureKeyboardFromApp);
	M("ImGui").def("capture_mouse_from_app", &ImGui::CaptureMouseFromApp);

	py::enum_<ImGuiDragDropFlags_>(M("ImGui"), "DragDropFlags")
		.value("SourceNoPreviewTooltip", ImGuiDragDropFlags_SourceNoPreviewTooltip)
		.value("SourceNoDisableHover", ImGuiDragDropFlags_SourceNoDisableHover)
		.value("SourceNoHoldToOpenOthers", ImGuiDragDropFlags_SourceNoHoldToOpenOthers)
		.value("SourceAllowNullID", ImGuiDragDropFlags_SourceAllowNullID)
		.value("SourceExtern", ImGuiDragDropFlags_SourceExtern)
		.value("SourceAutoExpirePayload", ImGuiDragDropFlags_SourceAutoExpirePayload)

		.value("AcceptBeforeDelivery", ImGuiDragDropFlags_AcceptBeforeDelivery)
		.value("AcceptNoDrawDefaultRect", ImGuiDragDropFlags_AcceptNoDrawDefaultRect)
		.value("AcceptNoPreviewTooltip", ImGuiDragDropFlags_AcceptNoPreviewTooltip)
		.value("AcceptPeekOnly", ImGuiDragDropFlags_AcceptPeekOnly)

		.export_values();

	M("ImGui").def("begin_drag_drop_source", &ImGui::BeginDragDropSource);
	// todo:
	//M("ImGui").def("set_drag_drop_payload", &ImGui::SetDragDropPayload);
	M("ImGui").def("set_drag_drop_payload_string", [](std::string data){ImGui::SetDragDropPayload("string",data.c_str(), data.size());});
	M("ImGui").def("end_drag_drop_source", &ImGui::EndDragDropSource);
	M("ImGui").def("begin_drag_drop_target", &ImGui::BeginDragDropTarget);
	// todo:
	//M("ImGui").def("accept_drag_drop_payload", &ImGui::AcceptDragDropPayload);
	M("ImGui").def("accept_drag_drop_payload_string_preview", [](ImGuiDragDropFlags flags = 0)->std::string{
		auto payload = ImGui::AcceptDragDropPayload("string", flags);
		if (!payload->IsDataType("string") || !payload->Data)
			return "";
		if (payload->IsPreview())
			return std::string(static_cast<char*>(payload->Data), payload->DataSize);
		else
			return "";
	});
	M("ImGui").def("accept_drag_drop_payload_string", [](ImGuiDragDropFlags flags = 0)->std::string{
		auto payload = ImGui::AcceptDragDropPayload("string", flags);
		if (!payload->IsDataType("string") || !payload->Data)
			return "";
		if (payload->IsDelivery())
			return std::string(static_cast<char*>(payload->Data), payload->DataSize);
		else
			return "";
	});

	M("ImGui").def("end_drag_drop_target", &ImGui::EndDragDropTarget);

	M("ImGui").def("push_clip_rect", &ImGui::PushClipRect);
	M("ImGui").def("pop_clip_rect", &ImGui::PopClipRect);

	M("ImGui").def("add_line", &AddLine, py::arg("a"), py::arg("b"), py::arg("col"), py::arg("thickness") = 1.0f);
	M("ImGui").def("add_rect", &AddRect, py::arg("a"), py::arg("b"), py::arg("col"), py::arg("rounding") = 0.0f, py::arg("rounding_corners_flags") = ImDrawCornerFlags_All, py::arg("thickness") = 1.0f);
	M("ImGui").def("add_rect_filled", &AddRectFilled, py::arg("a"), py::arg("b"), py::arg("col"), py::arg("rounding") = 0.0f, py::arg("rounding_corners_flags") = ImDrawCornerFlags_All);
	M("ImGui").def("add_rect_filled_multicolor", &AddRectFilledMultiColor, py::arg("a"), py::arg("b"), py::arg("col_upr_left"), py::arg("col_upr_right"), py::arg("col_bot_right"), py::arg("col_bot_lefs"));
	M("ImGui").def("add_quad", &AddQuad, py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"), py::arg("col"), py::arg("thickness") = 1.0f);
	M("ImGui").def("add_quad_filled", &AddQuadFilled, py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"), py::arg("col"));
	M("ImGui").def("add_triangle", &AddTriangle, py::arg("a"), py::arg("b"), py::arg("c"), py::arg("col"), py::arg("thickness") = 1.0f);
	M("ImGui").def("add_triangle_filled", &AddTriangleFilled, py::arg("a"), py::arg("b"), py::arg("c"), py::arg("col"));
	M("ImGui").def("add_circle", &AddCircle, py::arg("centre"), py::arg("radius"), py::arg("col"), py::arg("num_segments") = 12, py::arg("thickness") = 1.0f);
	M("ImGui").def("add_circle_filled", &AddCircleFilled, py::arg("centre"), py::arg("radius"), py::arg("col"), py::arg("num_segments") = 12);
	M("ImGui").def("add_bezier_curve", &AddBezierCurve, py::arg("pos0"), py::arg("cp0"), py::arg("cp1"), py::arg("pos1"), py::arg("col"), py::arg("thickness"), py::arg("num_segments") = 0);

	M("ImGui").def("path_clear", &PathClear);
	M("ImGui").def("path_line_to", &PathLineTo, py::arg("pos"));
	M("ImGui").def("path_fill_convex", &PathFillConvex, py::arg("col"));
	M("ImGui").def("path_stroke", &PathStroke, py::arg("col"), py::arg("closed"), py::arg("thickness"));

	M("ImGui").def("add_font_from_file_ttf", [](
		std::string filename,
		int size_pixels = 32)
		{
			return ImGui::GetIO().Fonts->AddFontFromFileTTF(filename.c_str(), size_pixels);
		}
		, py::arg("filename")
		, py::arg("size_pixels"), py::return_value_policy::reference);

//	M("ImGui").def("push_font", &ImGui::PushFont);
	M("ImGui").def("pop_font", &ImGui::PopFont);
	M("ImGui").def("get_font", &ImGui::GetFont);

    pybind11::class_<ImGui::Font, std::shared_ptr<ImGui::Font>> cl(M("ImGui"), "Font", "");
    pybind11::handle cl_type = cl;

    cl.def( pybind11::init( [](){ return new ImGui::Font(); } ) );

    pybind11::enum_<ImGui::Font::Enum>(cl, "Enum", pybind11::arithmetic(), "")
        .value("Regular", ImGui::Font::Enum::Regular)
        .value("Mono", ImGui::Font::Enum::Mono)
        .value("Count", ImGui::Font::Enum::Count)
        .export_values();

	M("ImGui").def("push_font", (void (*)(enum ImGui::Font::Enum)) &ImGui::PushFont, "C++: ImGui::PushFont(enum ImGui::Font::Enum) --> void", pybind11::arg("_font"), pybind11::call_guard<pybind11::gil_scoped_release>());


	M("ImGui").def("set_display_framebuffer_scale",[](float scale){
		ImGui::GetIO().DisplayFramebufferScale = ImVec2(scale,scale);
	}, py::arg("scale"));
	M("ImGui").def("get_display_framebuffer_scale",[](){
		return ImGui::GetIO().DisplayFramebufferScale;
	});

	M("ImGui").def("set_font_global_scale",[](float scale){
		ImGui::GetIO().FontGlobalScale = scale;
	}, py::arg("scale"));
	M("ImGui").def("get_font_global_scale",[](){
		return ImGui::GetIO().FontGlobalScale;
	});
//	typedef void (*FImage_texId_wSize)(GLuint, ImVec2&);
//	M("ImGui").def("image", (FImage_texId_wSize)([](GLuint textureId, ImVec2& size)
//	{
//		ImGui::Image(reinterpret_cast<ImTextureID>(textureId), size);
//	}));
//	typedef void (*FImage_wSize)(Image*, ImVec2&);
//	M("ImGui").def("image", (FImage_wSize)([](Image* im, ImVec2& size)
//	{
//		ImGui::Image(reinterpret_cast<ImTextureID>(im->GetHandle()), size);
//	}));
//	typedef void (*FImage)(Image*);
//	M("ImGui").def("image", (FImage)([](Image* im)
//	{
//		ImGui::Image(reinterpret_cast<ImTextureID>(im->GetHandle()), ImVec2(im->m_width, im->m_height));
//	}));

	M("ImGui").def("image_button", &ImGui::ImageButton);

//	M("ImGui").attr("key_left_shift") = py::int_(GLFW_KEY_LEFT_SHIFT);
//	M("ImGui").attr("key_left_control") = py::int_(GLFW_KEY_LEFT_CONTROL);
//	M("ImGui").attr("key_left_alt") = py::int_(GLFW_KEY_LEFT_ALT);
//	M("ImGui").attr("key_left_super") = py::int_(GLFW_KEY_LEFT_SUPER);
//	M("ImGui").attr("key_right_shift") = py::int_(GLFW_KEY_RIGHT_SHIFT);
//	M("ImGui").attr("key_right_control") = py::int_(GLFW_KEY_RIGHT_CONTROL);
//	M("ImGui").attr("key_right_alt") = py::int_(GLFW_KEY_RIGHT_ALT);
//	M("ImGui").attr("key_right_super") = py::int_(GLFW_KEY_RIGHT_SUPER);
}