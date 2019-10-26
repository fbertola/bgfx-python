// File: imgui.cpp
#include <imgui.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // ImVec2 file:imgui.h line:180
		pybind11::class_<ImVec2, std::shared_ptr<ImVec2>> cl(M(""), "ImVec2", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImVec2(); } ) );
		cl.def( pybind11::init<float, float>(), pybind11::arg("_x"), pybind11::arg("_y") );

		cl.def( pybind11::init( [](ImVec2 const &o){ return new ImVec2(o); } ) );
		cl.def_readwrite("x", &ImVec2::x);
		cl.def_readwrite("y", &ImVec2::y);
		cl.def("__getitem__", (float & (ImVec2::*)(unsigned long)) &ImVec2::operator[], "C++: ImVec2::operator[](unsigned long) --> float &", pybind11::return_value_policy::reference_internal, pybind11::arg("idx"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct ImVec2 & (ImVec2::*)(const struct ImVec2 &)) &ImVec2::operator=, "C++: ImVec2::operator=(const struct ImVec2 &) --> struct ImVec2 &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImVec4 file:imgui.h line:193
		pybind11::class_<ImVec4, std::shared_ptr<ImVec4>> cl(M(""), "ImVec4", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImVec4(); } ) );
		cl.def( pybind11::init<float, float, float, float>(), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_z"), pybind11::arg("_w") );

		cl.def( pybind11::init( [](ImVec4 const &o){ return new ImVec4(o); } ) );
		cl.def_readwrite("x", &ImVec4::x);
		cl.def_readwrite("y", &ImVec4::y);
		cl.def_readwrite("z", &ImVec4::z);
		cl.def_readwrite("w", &ImVec4::w);
		cl.def("assign", (struct ImVec4 & (ImVec4::*)(const struct ImVec4 &)) &ImVec4::operator=, "C++: ImVec4::operator=(const struct ImVec4 &) --> struct ImVec4 &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
}


// File: imgui_1.cpp
#include <imgui.h>
#include <imgui_internal.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::CreateContext(struct ImFontAtlas *) file:imgui.h line:213
	M("ImGui").def("CreateContext", []() -> ImGuiContext * { return ImGui::CreateContext(); }, "", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("CreateContext", (struct ImGuiContext * (*)(struct ImFontAtlas *)) &ImGui::CreateContext, "C++: ImGui::CreateContext(struct ImFontAtlas *) --> struct ImGuiContext *", pybind11::return_value_policy::reference, pybind11::arg("shared_font_atlas"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DestroyContext(struct ImGuiContext *) file:imgui.h line:214
	M("ImGui").def("DestroyContext", []() -> void { return ImGui::DestroyContext(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DestroyContext", (void (*)(struct ImGuiContext *)) &ImGui::DestroyContext, "C++: ImGui::DestroyContext(struct ImGuiContext *) --> void", pybind11::arg("ctx"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetCurrentContext() file:imgui.h line:215
	M("ImGui").def("GetCurrentContext", (struct ImGuiContext * (*)()) &ImGui::GetCurrentContext, "C++: ImGui::GetCurrentContext() --> struct ImGuiContext *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetCurrentContext(struct ImGuiContext *) file:imgui.h line:216
	M("ImGui").def("SetCurrentContext", (void (*)(struct ImGuiContext *)) &ImGui::SetCurrentContext, "C++: ImGui::SetCurrentContext(struct ImGuiContext *) --> void", pybind11::arg("ctx"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DebugCheckVersionAndDataLayout(const char *, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long) file:imgui.h line:217
	M("ImGui").def("DebugCheckVersionAndDataLayout", (bool (*)(const char *, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)) &ImGui::DebugCheckVersionAndDataLayout, "C++: ImGui::DebugCheckVersionAndDataLayout(const char *, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long) --> bool", pybind11::arg("version_str"), pybind11::arg("sz_io"), pybind11::arg("sz_style"), pybind11::arg("sz_vec2"), pybind11::arg("sz_vec4"), pybind11::arg("sz_drawvert"), pybind11::arg("sz_drawidx"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetIO() file:imgui.h line:220
	M("ImGui").def("GetIO", (struct ImGuiIO & (*)()) &ImGui::GetIO, "C++: ImGui::GetIO() --> struct ImGuiIO &", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetStyle() file:imgui.h line:221
	M("ImGui").def("GetStyle", (struct ImGuiStyle & (*)()) &ImGui::GetStyle, "C++: ImGui::GetStyle() --> struct ImGuiStyle &", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::NewFrame() file:imgui.h line:222
	M("ImGui").def("NewFrame", (void (*)()) &ImGui::NewFrame, "C++: ImGui::NewFrame() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndFrame() file:imgui.h line:223
	M("ImGui").def("EndFrame", (void (*)()) &ImGui::EndFrame, "C++: ImGui::EndFrame() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Render() file:imgui.h line:224
	M("ImGui").def("Render", (void (*)()) &ImGui::Render, "C++: ImGui::Render() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetDrawData() file:imgui.h line:225
	M("ImGui").def("GetDrawData", (struct ImDrawData * (*)()) &ImGui::GetDrawData, "C++: ImGui::GetDrawData() --> struct ImDrawData *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShowDemoWindow(bool *) file:imgui.h line:228
	M("ImGui").def("ShowDemoWindow", []() -> void { return ImGui::ShowDemoWindow(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ShowDemoWindow", (void (*)(bool *)) &ImGui::ShowDemoWindow, "C++: ImGui::ShowDemoWindow(bool *) --> void", pybind11::arg("p_open"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShowAboutWindow(bool *) file:imgui.h line:229
	M("ImGui").def("ShowAboutWindow", []() -> void { return ImGui::ShowAboutWindow(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ShowAboutWindow", (void (*)(bool *)) &ImGui::ShowAboutWindow, "C++: ImGui::ShowAboutWindow(bool *) --> void", pybind11::arg("p_open"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShowMetricsWindow(bool *) file:imgui.h line:230
	M("ImGui").def("ShowMetricsWindow", []() -> void { return ImGui::ShowMetricsWindow(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ShowMetricsWindow", (void (*)(bool *)) &ImGui::ShowMetricsWindow, "C++: ImGui::ShowMetricsWindow(bool *) --> void", pybind11::arg("p_open"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShowStyleEditor(struct ImGuiStyle *) file:imgui.h line:231
	M("ImGui").def("ShowStyleEditor", []() -> void { return ImGui::ShowStyleEditor(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ShowStyleEditor", (void (*)(struct ImGuiStyle *)) &ImGui::ShowStyleEditor, "C++: ImGui::ShowStyleEditor(struct ImGuiStyle *) --> void", pybind11::arg("ref"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShowStyleSelector(const char *) file:imgui.h line:232
	M("ImGui").def("ShowStyleSelector", (bool (*)(const char *)) &ImGui::ShowStyleSelector, "C++: ImGui::ShowStyleSelector(const char *) --> bool", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShowFontSelector(const char *) file:imgui.h line:233
	M("ImGui").def("ShowFontSelector", (void (*)(const char *)) &ImGui::ShowFontSelector, "C++: ImGui::ShowFontSelector(const char *) --> void", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShowUserGuide() file:imgui.h line:234
	M("ImGui").def("ShowUserGuide", (void (*)()) &ImGui::ShowUserGuide, "C++: ImGui::ShowUserGuide() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetVersion() file:imgui.h line:235
	M("ImGui").def("GetVersion", (const char * (*)()) &ImGui::GetVersion, "C++: ImGui::GetVersion() --> const char *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::StyleColorsDark(struct ImGuiStyle *) file:imgui.h line:238
	M("ImGui").def("StyleColorsDark", []() -> void { return ImGui::StyleColorsDark(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("StyleColorsDark", (void (*)(struct ImGuiStyle *)) &ImGui::StyleColorsDark, "C++: ImGui::StyleColorsDark(struct ImGuiStyle *) --> void", pybind11::arg("dst"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::StyleColorsClassic(struct ImGuiStyle *) file:imgui.h line:239
	M("ImGui").def("StyleColorsClassic", []() -> void { return ImGui::StyleColorsClassic(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("StyleColorsClassic", (void (*)(struct ImGuiStyle *)) &ImGui::StyleColorsClassic, "C++: ImGui::StyleColorsClassic(struct ImGuiStyle *) --> void", pybind11::arg("dst"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::StyleColorsLight(struct ImGuiStyle *) file:imgui.h line:240
	M("ImGui").def("StyleColorsLight", []() -> void { return ImGui::StyleColorsLight(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("StyleColorsLight", (void (*)(struct ImGuiStyle *)) &ImGui::StyleColorsLight, "C++: ImGui::StyleColorsLight(struct ImGuiStyle *) --> void", pybind11::arg("dst"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Begin(const char *, bool *, int) file:imgui.h line:252
	M("ImGui").def("Begin", [](const char * a0) -> bool { return ImGui::Begin(a0); }, "", pybind11::arg("name"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Begin", [](const char * a0, bool * a1) -> bool { return ImGui::Begin(a0, a1); }, "", pybind11::arg("name"), pybind11::arg("p_open"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Begin", (bool (*)(const char *, bool *, int)) &ImGui::Begin, "C++: ImGui::Begin(const char *, bool *, int) --> bool", pybind11::arg("name"), pybind11::arg("p_open"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::End() file:imgui.h line:253
	M("ImGui").def("End", (void (*)()) &ImGui::End, "C++: ImGui::End() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginChild(const char *, const struct ImVec2 &, bool, int) file:imgui.h line:260
	M("ImGui").def("BeginChild", [](const char * a0) -> bool { return ImGui::BeginChild(a0); }, "", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginChild", [](const char * a0, const struct ImVec2 & a1) -> bool { return ImGui::BeginChild(a0, a1); }, "", pybind11::arg("str_id"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginChild", [](const char * a0, const struct ImVec2 & a1, bool const & a2) -> bool { return ImGui::BeginChild(a0, a1, a2); }, "", pybind11::arg("str_id"), pybind11::arg("size"), pybind11::arg("border"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginChild", (bool (*)(const char *, const struct ImVec2 &, bool, int)) &ImGui::BeginChild, "C++: ImGui::BeginChild(const char *, const struct ImVec2 &, bool, int) --> bool", pybind11::arg("str_id"), pybind11::arg("size"), pybind11::arg("border"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginChild(unsigned int, const struct ImVec2 &, bool, int) file:imgui.h line:261
	M("ImGui").def("BeginChild", [](unsigned int const & a0) -> bool { return ImGui::BeginChild(a0); }, "", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginChild", [](unsigned int const & a0, const struct ImVec2 & a1) -> bool { return ImGui::BeginChild(a0, a1); }, "", pybind11::arg("id"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginChild", [](unsigned int const & a0, const struct ImVec2 & a1, bool const & a2) -> bool { return ImGui::BeginChild(a0, a1, a2); }, "", pybind11::arg("id"), pybind11::arg("size"), pybind11::arg("border"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginChild", (bool (*)(unsigned int, const struct ImVec2 &, bool, int)) &ImGui::BeginChild, "C++: ImGui::BeginChild(unsigned int, const struct ImVec2 &, bool, int) --> bool", pybind11::arg("id"), pybind11::arg("size"), pybind11::arg("border"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndChild() file:imgui.h line:262
	M("ImGui").def("EndChild", (void (*)()) &ImGui::EndChild, "C++: ImGui::EndChild() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsWindowAppearing() file:imgui.h line:266
	M("ImGui").def("IsWindowAppearing", (bool (*)()) &ImGui::IsWindowAppearing, "C++: ImGui::IsWindowAppearing() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsWindowCollapsed() file:imgui.h line:267
	M("ImGui").def("IsWindowCollapsed", (bool (*)()) &ImGui::IsWindowCollapsed, "C++: ImGui::IsWindowCollapsed() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsWindowFocused(int) file:imgui.h line:268
	M("ImGui").def("IsWindowFocused", []() -> bool { return ImGui::IsWindowFocused(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsWindowFocused", (bool (*)(int)) &ImGui::IsWindowFocused, "C++: ImGui::IsWindowFocused(int) --> bool", pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsWindowHovered(int) file:imgui.h line:269
	M("ImGui").def("IsWindowHovered", []() -> bool { return ImGui::IsWindowHovered(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsWindowHovered", (bool (*)(int)) &ImGui::IsWindowHovered, "C++: ImGui::IsWindowHovered(int) --> bool", pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetWindowDrawList() file:imgui.h line:270
	M("ImGui").def("GetWindowDrawList", (struct ImDrawList * (*)()) &ImGui::GetWindowDrawList, "C++: ImGui::GetWindowDrawList() --> struct ImDrawList *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetWindowPos() file:imgui.h line:271
	M("ImGui").def("GetWindowPos", (struct ImVec2 (*)()) &ImGui::GetWindowPos, "C++: ImGui::GetWindowPos() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetWindowSize() file:imgui.h line:272
	M("ImGui").def("GetWindowSize", (struct ImVec2 (*)()) &ImGui::GetWindowSize, "C++: ImGui::GetWindowSize() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetWindowWidth() file:imgui.h line:273
	M("ImGui").def("GetWindowWidth", (float (*)()) &ImGui::GetWindowWidth, "C++: ImGui::GetWindowWidth() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetWindowHeight() file:imgui.h line:274
	M("ImGui").def("GetWindowHeight", (float (*)()) &ImGui::GetWindowHeight, "C++: ImGui::GetWindowHeight() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetNextWindowPos(const struct ImVec2 &, int, const struct ImVec2 &) file:imgui.h line:277
	M("ImGui").def("SetNextWindowPos", [](const struct ImVec2 & a0) -> void { return ImGui::SetNextWindowPos(a0); }, "", pybind11::arg("pos"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetNextWindowPos", [](const struct ImVec2 & a0, int const & a1) -> void { return ImGui::SetNextWindowPos(a0, a1); }, "", pybind11::arg("pos"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetNextWindowPos", (void (*)(const struct ImVec2 &, int, const struct ImVec2 &)) &ImGui::SetNextWindowPos, "C++: ImGui::SetNextWindowPos(const struct ImVec2 &, int, const struct ImVec2 &) --> void", pybind11::arg("pos"), pybind11::arg("cond"), pybind11::arg("pivot"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetNextWindowSize(const struct ImVec2 &, int) file:imgui.h line:278
	M("ImGui").def("SetNextWindowSize", [](const struct ImVec2 & a0) -> void { return ImGui::SetNextWindowSize(a0); }, "", pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetNextWindowSize", (void (*)(const struct ImVec2 &, int)) &ImGui::SetNextWindowSize, "C++: ImGui::SetNextWindowSize(const struct ImVec2 &, int) --> void", pybind11::arg("size"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetNextWindowContentSize(const struct ImVec2 &) file:imgui.h line:280
	M("ImGui").def("SetNextWindowContentSize", (void (*)(const struct ImVec2 &)) &ImGui::SetNextWindowContentSize, "C++: ImGui::SetNextWindowContentSize(const struct ImVec2 &) --> void", pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetNextWindowCollapsed(bool, int) file:imgui.h line:281
	M("ImGui").def("SetNextWindowCollapsed", [](bool const & a0) -> void { return ImGui::SetNextWindowCollapsed(a0); }, "", pybind11::arg("collapsed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetNextWindowCollapsed", (void (*)(bool, int)) &ImGui::SetNextWindowCollapsed, "C++: ImGui::SetNextWindowCollapsed(bool, int) --> void", pybind11::arg("collapsed"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetNextWindowFocus() file:imgui.h line:282
	M("ImGui").def("SetNextWindowFocus", (void (*)()) &ImGui::SetNextWindowFocus, "C++: ImGui::SetNextWindowFocus() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetNextWindowBgAlpha(float) file:imgui.h line:283
	M("ImGui").def("SetNextWindowBgAlpha", (void (*)(float)) &ImGui::SetNextWindowBgAlpha, "C++: ImGui::SetNextWindowBgAlpha(float) --> void", pybind11::arg("alpha"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_2.cpp
#include <imgui.h>
#include <imgui_internal.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::SetWindowPos(const struct ImVec2 &, int) file:imgui.h line:284
	M("ImGui").def("SetWindowPos", [](const struct ImVec2 & a0) -> void { return ImGui::SetWindowPos(a0); }, "", pybind11::arg("pos"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetWindowPos", (void (*)(const struct ImVec2 &, int)) &ImGui::SetWindowPos, "C++: ImGui::SetWindowPos(const struct ImVec2 &, int) --> void", pybind11::arg("pos"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowSize(const struct ImVec2 &, int) file:imgui.h line:285
	M("ImGui").def("SetWindowSize", [](const struct ImVec2 & a0) -> void { return ImGui::SetWindowSize(a0); }, "", pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetWindowSize", (void (*)(const struct ImVec2 &, int)) &ImGui::SetWindowSize, "C++: ImGui::SetWindowSize(const struct ImVec2 &, int) --> void", pybind11::arg("size"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowCollapsed(bool, int) file:imgui.h line:286
	M("ImGui").def("SetWindowCollapsed", [](bool const & a0) -> void { return ImGui::SetWindowCollapsed(a0); }, "", pybind11::arg("collapsed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetWindowCollapsed", (void (*)(bool, int)) &ImGui::SetWindowCollapsed, "C++: ImGui::SetWindowCollapsed(bool, int) --> void", pybind11::arg("collapsed"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowFocus() file:imgui.h line:287
	M("ImGui").def("SetWindowFocus", (void (*)()) &ImGui::SetWindowFocus, "C++: ImGui::SetWindowFocus() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowFontScale(float) file:imgui.h line:288
	M("ImGui").def("SetWindowFontScale", (void (*)(float)) &ImGui::SetWindowFontScale, "C++: ImGui::SetWindowFontScale(float) --> void", pybind11::arg("scale"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowPos(const char *, const struct ImVec2 &, int) file:imgui.h line:289
	M("ImGui").def("SetWindowPos", [](const char * a0, const struct ImVec2 & a1) -> void { return ImGui::SetWindowPos(a0, a1); }, "", pybind11::arg("name"), pybind11::arg("pos"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetWindowPos", (void (*)(const char *, const struct ImVec2 &, int)) &ImGui::SetWindowPos, "C++: ImGui::SetWindowPos(const char *, const struct ImVec2 &, int) --> void", pybind11::arg("name"), pybind11::arg("pos"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowSize(const char *, const struct ImVec2 &, int) file:imgui.h line:290
	M("ImGui").def("SetWindowSize", [](const char * a0, const struct ImVec2 & a1) -> void { return ImGui::SetWindowSize(a0, a1); }, "", pybind11::arg("name"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetWindowSize", (void (*)(const char *, const struct ImVec2 &, int)) &ImGui::SetWindowSize, "C++: ImGui::SetWindowSize(const char *, const struct ImVec2 &, int) --> void", pybind11::arg("name"), pybind11::arg("size"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowCollapsed(const char *, bool, int) file:imgui.h line:291
	M("ImGui").def("SetWindowCollapsed", [](const char * a0, bool const & a1) -> void { return ImGui::SetWindowCollapsed(a0, a1); }, "", pybind11::arg("name"), pybind11::arg("collapsed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetWindowCollapsed", (void (*)(const char *, bool, int)) &ImGui::SetWindowCollapsed, "C++: ImGui::SetWindowCollapsed(const char *, bool, int) --> void", pybind11::arg("name"), pybind11::arg("collapsed"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowFocus(const char *) file:imgui.h line:292
	M("ImGui").def("SetWindowFocus", (void (*)(const char *)) &ImGui::SetWindowFocus, "C++: ImGui::SetWindowFocus(const char *) --> void", pybind11::arg("name"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetContentRegionMax() file:imgui.h line:296
	M("ImGui").def("GetContentRegionMax", (struct ImVec2 (*)()) &ImGui::GetContentRegionMax, "C++: ImGui::GetContentRegionMax() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetContentRegionAvail() file:imgui.h line:297
	M("ImGui").def("GetContentRegionAvail", (struct ImVec2 (*)()) &ImGui::GetContentRegionAvail, "C++: ImGui::GetContentRegionAvail() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetWindowContentRegionMin() file:imgui.h line:298
	M("ImGui").def("GetWindowContentRegionMin", (struct ImVec2 (*)()) &ImGui::GetWindowContentRegionMin, "C++: ImGui::GetWindowContentRegionMin() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetWindowContentRegionMax() file:imgui.h line:299
	M("ImGui").def("GetWindowContentRegionMax", (struct ImVec2 (*)()) &ImGui::GetWindowContentRegionMax, "C++: ImGui::GetWindowContentRegionMax() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetWindowContentRegionWidth() file:imgui.h line:300
	M("ImGui").def("GetWindowContentRegionWidth", (float (*)()) &ImGui::GetWindowContentRegionWidth, "C++: ImGui::GetWindowContentRegionWidth() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetScrollX() file:imgui.h line:303
	M("ImGui").def("GetScrollX", (float (*)()) &ImGui::GetScrollX, "C++: ImGui::GetScrollX() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetScrollY() file:imgui.h line:304
	M("ImGui").def("GetScrollY", (float (*)()) &ImGui::GetScrollY, "C++: ImGui::GetScrollY() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetScrollMaxX() file:imgui.h line:305
	M("ImGui").def("GetScrollMaxX", (float (*)()) &ImGui::GetScrollMaxX, "C++: ImGui::GetScrollMaxX() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetScrollMaxY() file:imgui.h line:306
	M("ImGui").def("GetScrollMaxY", (float (*)()) &ImGui::GetScrollMaxY, "C++: ImGui::GetScrollMaxY() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollX(float) file:imgui.h line:307
	M("ImGui").def("SetScrollX", (void (*)(float)) &ImGui::SetScrollX, "C++: ImGui::SetScrollX(float) --> void", pybind11::arg("scroll_x"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollY(float) file:imgui.h line:308
	M("ImGui").def("SetScrollY", (void (*)(float)) &ImGui::SetScrollY, "C++: ImGui::SetScrollY(float) --> void", pybind11::arg("scroll_y"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollHereX(float) file:imgui.h line:309
	M("ImGui").def("SetScrollHereX", []() -> void { return ImGui::SetScrollHereX(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetScrollHereX", (void (*)(float)) &ImGui::SetScrollHereX, "C++: ImGui::SetScrollHereX(float) --> void", pybind11::arg("center_x_ratio"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollHereY(float) file:imgui.h line:310
	M("ImGui").def("SetScrollHereY", []() -> void { return ImGui::SetScrollHereY(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetScrollHereY", (void (*)(float)) &ImGui::SetScrollHereY, "C++: ImGui::SetScrollHereY(float) --> void", pybind11::arg("center_y_ratio"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollFromPosX(float, float) file:imgui.h line:311
	M("ImGui").def("SetScrollFromPosX", [](float const & a0) -> void { return ImGui::SetScrollFromPosX(a0); }, "", pybind11::arg("local_x"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetScrollFromPosX", (void (*)(float, float)) &ImGui::SetScrollFromPosX, "C++: ImGui::SetScrollFromPosX(float, float) --> void", pybind11::arg("local_x"), pybind11::arg("center_x_ratio"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollFromPosY(float, float) file:imgui.h line:312
	M("ImGui").def("SetScrollFromPosY", [](float const & a0) -> void { return ImGui::SetScrollFromPosY(a0); }, "", pybind11::arg("local_y"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetScrollFromPosY", (void (*)(float, float)) &ImGui::SetScrollFromPosY, "C++: ImGui::SetScrollFromPosY(float, float) --> void", pybind11::arg("local_y"), pybind11::arg("center_y_ratio"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushFont(struct ImFont *) file:imgui.h line:315
	M("ImGui").def("PushFont", (void (*)(struct ImFont *)) &ImGui::PushFont, "C++: ImGui::PushFont(struct ImFont *) --> void", pybind11::arg("font"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopFont() file:imgui.h line:316
	M("ImGui").def("PopFont", (void (*)()) &ImGui::PopFont, "C++: ImGui::PopFont() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushStyleColor(int, unsigned int) file:imgui.h line:317
	M("ImGui").def("PushStyleColor", (void (*)(int, unsigned int)) &ImGui::PushStyleColor, "C++: ImGui::PushStyleColor(int, unsigned int) --> void", pybind11::arg("idx"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushStyleColor(int, const struct ImVec4 &) file:imgui.h line:318
	M("ImGui").def("PushStyleColor", (void (*)(int, const struct ImVec4 &)) &ImGui::PushStyleColor, "C++: ImGui::PushStyleColor(int, const struct ImVec4 &) --> void", pybind11::arg("idx"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopStyleColor(int) file:imgui.h line:319
	M("ImGui").def("PopStyleColor", []() -> void { return ImGui::PopStyleColor(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PopStyleColor", (void (*)(int)) &ImGui::PopStyleColor, "C++: ImGui::PopStyleColor(int) --> void", pybind11::arg("count"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushStyleVar(int, float) file:imgui.h line:320
	M("ImGui").def("PushStyleVar", (void (*)(int, float)) &ImGui::PushStyleVar, "C++: ImGui::PushStyleVar(int, float) --> void", pybind11::arg("idx"), pybind11::arg("val"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushStyleVar(int, const struct ImVec2 &) file:imgui.h line:321
	M("ImGui").def("PushStyleVar", (void (*)(int, const struct ImVec2 &)) &ImGui::PushStyleVar, "C++: ImGui::PushStyleVar(int, const struct ImVec2 &) --> void", pybind11::arg("idx"), pybind11::arg("val"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopStyleVar(int) file:imgui.h line:322
	M("ImGui").def("PopStyleVar", []() -> void { return ImGui::PopStyleVar(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PopStyleVar", (void (*)(int)) &ImGui::PopStyleVar, "C++: ImGui::PopStyleVar(int) --> void", pybind11::arg("count"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetStyleColorVec4(int) file:imgui.h line:323
	M("ImGui").def("GetStyleColorVec4", (const struct ImVec4 & (*)(int)) &ImGui::GetStyleColorVec4, "C++: ImGui::GetStyleColorVec4(int) --> const struct ImVec4 &", pybind11::return_value_policy::reference_internal, pybind11::arg("idx"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetFont() file:imgui.h line:324
	M("ImGui").def("GetFont", (struct ImFont * (*)()) &ImGui::GetFont, "C++: ImGui::GetFont() --> struct ImFont *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetFontSize() file:imgui.h line:325
	M("ImGui").def("GetFontSize", (float (*)()) &ImGui::GetFontSize, "C++: ImGui::GetFontSize() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetFontTexUvWhitePixel() file:imgui.h line:326
	M("ImGui").def("GetFontTexUvWhitePixel", (struct ImVec2 (*)()) &ImGui::GetFontTexUvWhitePixel, "C++: ImGui::GetFontTexUvWhitePixel() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColorU32(int, float) file:imgui.h line:327
	M("ImGui").def("GetColorU32", [](int const & a0) -> unsigned int { return ImGui::GetColorU32(a0); }, "", pybind11::arg("idx"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("GetColorU32", (unsigned int (*)(int, float)) &ImGui::GetColorU32, "C++: ImGui::GetColorU32(int, float) --> unsigned int", pybind11::arg("idx"), pybind11::arg("alpha_mul"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColorU32(const struct ImVec4 &) file:imgui.h line:328
	M("ImGui").def("GetColorU32", (unsigned int (*)(const struct ImVec4 &)) &ImGui::GetColorU32, "C++: ImGui::GetColorU32(const struct ImVec4 &) --> unsigned int", pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColorU32(unsigned int) file:imgui.h line:329
	M("ImGui").def("GetColorU32", (unsigned int (*)(unsigned int)) &ImGui::GetColorU32, "C++: ImGui::GetColorU32(unsigned int) --> unsigned int", pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushItemWidth(float) file:imgui.h line:332
	M("ImGui").def("PushItemWidth", (void (*)(float)) &ImGui::PushItemWidth, "C++: ImGui::PushItemWidth(float) --> void", pybind11::arg("item_width"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopItemWidth() file:imgui.h line:333
	M("ImGui").def("PopItemWidth", (void (*)()) &ImGui::PopItemWidth, "C++: ImGui::PopItemWidth() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetNextItemWidth(float) file:imgui.h line:334
	M("ImGui").def("SetNextItemWidth", (void (*)(float)) &ImGui::SetNextItemWidth, "C++: ImGui::SetNextItemWidth(float) --> void", pybind11::arg("item_width"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CalcItemWidth() file:imgui.h line:335
	M("ImGui").def("CalcItemWidth", (float (*)()) &ImGui::CalcItemWidth, "C++: ImGui::CalcItemWidth() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushTextWrapPos(float) file:imgui.h line:336
	M("ImGui").def("PushTextWrapPos", []() -> void { return ImGui::PushTextWrapPos(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PushTextWrapPos", (void (*)(float)) &ImGui::PushTextWrapPos, "C++: ImGui::PushTextWrapPos(float) --> void", pybind11::arg("wrap_local_pos_x"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopTextWrapPos() file:imgui.h line:337
	M("ImGui").def("PopTextWrapPos", (void (*)()) &ImGui::PopTextWrapPos, "C++: ImGui::PopTextWrapPos() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushAllowKeyboardFocus(bool) file:imgui.h line:338
	M("ImGui").def("PushAllowKeyboardFocus", (void (*)(bool)) &ImGui::PushAllowKeyboardFocus, "C++: ImGui::PushAllowKeyboardFocus(bool) --> void", pybind11::arg("allow_keyboard_focus"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopAllowKeyboardFocus() file:imgui.h line:339
	M("ImGui").def("PopAllowKeyboardFocus", (void (*)()) &ImGui::PopAllowKeyboardFocus, "C++: ImGui::PopAllowKeyboardFocus() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushButtonRepeat(bool) file:imgui.h line:340
	M("ImGui").def("PushButtonRepeat", (void (*)(bool)) &ImGui::PushButtonRepeat, "C++: ImGui::PushButtonRepeat(bool) --> void", pybind11::arg("repeat"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopButtonRepeat() file:imgui.h line:341
	M("ImGui").def("PopButtonRepeat", (void (*)()) &ImGui::PopButtonRepeat, "C++: ImGui::PopButtonRepeat() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Separator() file:imgui.h line:346
	M("ImGui").def("Separator", (void (*)()) &ImGui::Separator, "C++: ImGui::Separator() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SameLine(float, float) file:imgui.h line:347
	M("ImGui").def("SameLine", []() -> void { return ImGui::SameLine(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SameLine", [](float const & a0) -> void { return ImGui::SameLine(a0); }, "", pybind11::arg("offset_from_start_x"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SameLine", (void (*)(float, float)) &ImGui::SameLine, "C++: ImGui::SameLine(float, float) --> void", pybind11::arg("offset_from_start_x"), pybind11::arg("spacing"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_3.cpp
#include <imgui.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_3(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::NewLine() file:imgui.h line:348
	M("ImGui").def("NewLine", (void (*)()) &ImGui::NewLine, "C++: ImGui::NewLine() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Spacing() file:imgui.h line:349
	M("ImGui").def("Spacing", (void (*)()) &ImGui::Spacing, "C++: ImGui::Spacing() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Dummy(const struct ImVec2 &) file:imgui.h line:350
	M("ImGui").def("Dummy", (void (*)(const struct ImVec2 &)) &ImGui::Dummy, "C++: ImGui::Dummy(const struct ImVec2 &) --> void", pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Indent(float) file:imgui.h line:351
	M("ImGui").def("Indent", []() -> void { return ImGui::Indent(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Indent", (void (*)(float)) &ImGui::Indent, "C++: ImGui::Indent(float) --> void", pybind11::arg("indent_w"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Unindent(float) file:imgui.h line:352
	M("ImGui").def("Unindent", []() -> void { return ImGui::Unindent(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Unindent", (void (*)(float)) &ImGui::Unindent, "C++: ImGui::Unindent(float) --> void", pybind11::arg("indent_w"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginGroup() file:imgui.h line:353
	M("ImGui").def("BeginGroup", (void (*)()) &ImGui::BeginGroup, "C++: ImGui::BeginGroup() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndGroup() file:imgui.h line:354
	M("ImGui").def("EndGroup", (void (*)()) &ImGui::EndGroup, "C++: ImGui::EndGroup() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetCursorPos() file:imgui.h line:355
	M("ImGui").def("GetCursorPos", (struct ImVec2 (*)()) &ImGui::GetCursorPos, "C++: ImGui::GetCursorPos() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetCursorPosX() file:imgui.h line:356
	M("ImGui").def("GetCursorPosX", (float (*)()) &ImGui::GetCursorPosX, "C++: ImGui::GetCursorPosX() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetCursorPosY() file:imgui.h line:357
	M("ImGui").def("GetCursorPosY", (float (*)()) &ImGui::GetCursorPosY, "C++: ImGui::GetCursorPosY() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetCursorPos(const struct ImVec2 &) file:imgui.h line:358
	M("ImGui").def("SetCursorPos", (void (*)(const struct ImVec2 &)) &ImGui::SetCursorPos, "C++: ImGui::SetCursorPos(const struct ImVec2 &) --> void", pybind11::arg("local_pos"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetCursorPosX(float) file:imgui.h line:359
	M("ImGui").def("SetCursorPosX", (void (*)(float)) &ImGui::SetCursorPosX, "C++: ImGui::SetCursorPosX(float) --> void", pybind11::arg("local_x"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetCursorPosY(float) file:imgui.h line:360
	M("ImGui").def("SetCursorPosY", (void (*)(float)) &ImGui::SetCursorPosY, "C++: ImGui::SetCursorPosY(float) --> void", pybind11::arg("local_y"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetCursorStartPos() file:imgui.h line:361
	M("ImGui").def("GetCursorStartPos", (struct ImVec2 (*)()) &ImGui::GetCursorStartPos, "C++: ImGui::GetCursorStartPos() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetCursorScreenPos() file:imgui.h line:362
	M("ImGui").def("GetCursorScreenPos", (struct ImVec2 (*)()) &ImGui::GetCursorScreenPos, "C++: ImGui::GetCursorScreenPos() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetCursorScreenPos(const struct ImVec2 &) file:imgui.h line:363
	M("ImGui").def("SetCursorScreenPos", (void (*)(const struct ImVec2 &)) &ImGui::SetCursorScreenPos, "C++: ImGui::SetCursorScreenPos(const struct ImVec2 &) --> void", pybind11::arg("pos"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::AlignTextToFramePadding() file:imgui.h line:364
	M("ImGui").def("AlignTextToFramePadding", (void (*)()) &ImGui::AlignTextToFramePadding, "C++: ImGui::AlignTextToFramePadding() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetTextLineHeight() file:imgui.h line:365
	M("ImGui").def("GetTextLineHeight", (float (*)()) &ImGui::GetTextLineHeight, "C++: ImGui::GetTextLineHeight() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetTextLineHeightWithSpacing() file:imgui.h line:366
	M("ImGui").def("GetTextLineHeightWithSpacing", (float (*)()) &ImGui::GetTextLineHeightWithSpacing, "C++: ImGui::GetTextLineHeightWithSpacing() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetFrameHeight() file:imgui.h line:367
	M("ImGui").def("GetFrameHeight", (float (*)()) &ImGui::GetFrameHeight, "C++: ImGui::GetFrameHeight() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetFrameHeightWithSpacing() file:imgui.h line:368
	M("ImGui").def("GetFrameHeightWithSpacing", (float (*)()) &ImGui::GetFrameHeightWithSpacing, "C++: ImGui::GetFrameHeightWithSpacing() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushID(const char *) file:imgui.h line:377
	M("ImGui").def("PushID", (void (*)(const char *)) &ImGui::PushID, "C++: ImGui::PushID(const char *) --> void", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushID(const char *, const char *) file:imgui.h line:378
	M("ImGui").def("PushID", (void (*)(const char *, const char *)) &ImGui::PushID, "C++: ImGui::PushID(const char *, const char *) --> void", pybind11::arg("str_id_begin"), pybind11::arg("str_id_end"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushID(const void *) file:imgui.h line:379
	M("ImGui").def("PushID", (void (*)(const void *)) &ImGui::PushID, "C++: ImGui::PushID(const void *) --> void", pybind11::arg("ptr_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushID(int) file:imgui.h line:380
	M("ImGui").def("PushID", (void (*)(int)) &ImGui::PushID, "C++: ImGui::PushID(int) --> void", pybind11::arg("int_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopID() file:imgui.h line:381
	M("ImGui").def("PopID", (void (*)()) &ImGui::PopID, "C++: ImGui::PopID() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetID(const char *) file:imgui.h line:382
	M("ImGui").def("GetID", (unsigned int (*)(const char *)) &ImGui::GetID, "C++: ImGui::GetID(const char *) --> unsigned int", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetID(const char *, const char *) file:imgui.h line:383
	M("ImGui").def("GetID", (unsigned int (*)(const char *, const char *)) &ImGui::GetID, "C++: ImGui::GetID(const char *, const char *) --> unsigned int", pybind11::arg("str_id_begin"), pybind11::arg("str_id_end"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetID(const void *) file:imgui.h line:384
	M("ImGui").def("GetID", (unsigned int (*)(const void *)) &ImGui::GetID, "C++: ImGui::GetID(const void *) --> unsigned int", pybind11::arg("ptr_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TextUnformatted(const char *, const char *) file:imgui.h line:387
	M("ImGui").def("TextUnformatted", [](const char * a0) -> void { return ImGui::TextUnformatted(a0); }, "", pybind11::arg("text"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("TextUnformatted", (void (*)(const char *, const char *)) &ImGui::TextUnformatted, "C++: ImGui::TextUnformatted(const char *, const char *) --> void", pybind11::arg("text"), pybind11::arg("text_end"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Text(const char *) file:imgui.h line:388
	M("ImGui").def("Text", [](const char * a0) -> void { return ImGui::Text(a0); }, "", pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TextColored(const struct ImVec4 &, const char *) file:imgui.h line:390
	M("ImGui").def("TextColored", [](const struct ImVec4 & a0, const char * a1) -> void { return ImGui::TextColored(a0, a1); }, "", pybind11::arg("col"), pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TextDisabled(const char *) file:imgui.h line:392
	M("ImGui").def("TextDisabled", [](const char * a0) -> void { return ImGui::TextDisabled(a0); }, "", pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TextWrapped(const char *) file:imgui.h line:394
	M("ImGui").def("TextWrapped", [](const char * a0) -> void { return ImGui::TextWrapped(a0); }, "", pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LabelText(const char *, const char *) file:imgui.h line:396
	M("ImGui").def("LabelText", [](const char * a0, const char * a1) -> void { return ImGui::LabelText(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BulletText(const char *) file:imgui.h line:398
	M("ImGui").def("BulletText", [](const char * a0) -> void { return ImGui::BulletText(a0); }, "", pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Button(const char *, const struct ImVec2 &) file:imgui.h line:403
	M("ImGui").def("Button", [](const char * a0) -> bool { return ImGui::Button(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Button", (bool (*)(const char *, const struct ImVec2 &)) &ImGui::Button, "C++: ImGui::Button(const char *, const struct ImVec2 &) --> bool", pybind11::arg("label"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SmallButton(const char *) file:imgui.h line:404
	M("ImGui").def("SmallButton", (bool (*)(const char *)) &ImGui::SmallButton, "C++: ImGui::SmallButton(const char *) --> bool", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::InvisibleButton(const char *, const struct ImVec2 &) file:imgui.h line:405
	M("ImGui").def("InvisibleButton", (bool (*)(const char *, const struct ImVec2 &)) &ImGui::InvisibleButton, "C++: ImGui::InvisibleButton(const char *, const struct ImVec2 &) --> bool", pybind11::arg("str_id"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ArrowButton(const char *, int) file:imgui.h line:406
	M("ImGui").def("ArrowButton", (bool (*)(const char *, int)) &ImGui::ArrowButton, "C++: ImGui::ArrowButton(const char *, int) --> bool", pybind11::arg("str_id"), pybind11::arg("dir"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Image(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec4 &, const struct ImVec4 &) file:imgui.h line:407
	M("ImGui").def("Image", [](void * a0, const struct ImVec2 & a1) -> void { return ImGui::Image(a0, a1); }, "", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Image", [](void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2) -> void { return ImGui::Image(a0, a1, a2); }, "", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::arg("uv0"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Image", [](void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3) -> void { return ImGui::Image(a0, a1, a2, a3); }, "", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::arg("uv0"), pybind11::arg("uv1"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Image", [](void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, const struct ImVec4 & a4) -> void { return ImGui::Image(a0, a1, a2, a3, a4); }, "", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::arg("uv0"), pybind11::arg("uv1"), pybind11::arg("tint_col"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Image", (void (*)(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec4 &, const struct ImVec4 &)) &ImGui::Image, "C++: ImGui::Image(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec4 &, const struct ImVec4 &) --> void", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::arg("uv0"), pybind11::arg("uv1"), pybind11::arg("tint_col"), pybind11::arg("border_col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ImageButton(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int, const struct ImVec4 &, const struct ImVec4 &) file:imgui.h line:408
	M("ImGui").def("ImageButton", [](void * a0, const struct ImVec2 & a1) -> bool { return ImGui::ImageButton(a0, a1); }, "", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ImageButton", [](void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2) -> bool { return ImGui::ImageButton(a0, a1, a2); }, "", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::arg("uv0"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ImageButton", [](void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3) -> bool { return ImGui::ImageButton(a0, a1, a2, a3); }, "", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::arg("uv0"), pybind11::arg("uv1"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ImageButton", [](void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, int const & a4) -> bool { return ImGui::ImageButton(a0, a1, a2, a3, a4); }, "", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::arg("uv0"), pybind11::arg("uv1"), pybind11::arg("frame_padding"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ImageButton", [](void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, int const & a4, const struct ImVec4 & a5) -> bool { return ImGui::ImageButton(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::arg("uv0"), pybind11::arg("uv1"), pybind11::arg("frame_padding"), pybind11::arg("bg_col"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ImageButton", (bool (*)(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int, const struct ImVec4 &, const struct ImVec4 &)) &ImGui::ImageButton, "C++: ImGui::ImageButton(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int, const struct ImVec4 &, const struct ImVec4 &) --> bool", pybind11::arg("user_texture_id"), pybind11::arg("size"), pybind11::arg("uv0"), pybind11::arg("uv1"), pybind11::arg("frame_padding"), pybind11::arg("bg_col"), pybind11::arg("tint_col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Checkbox(const char *, bool *) file:imgui.h line:409
	M("ImGui").def("Checkbox", (bool (*)(const char *, bool *)) &ImGui::Checkbox, "C++: ImGui::Checkbox(const char *, bool *) --> bool", pybind11::arg("label"), pybind11::arg("v"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CheckboxFlags(const char *, unsigned int *, unsigned int) file:imgui.h line:410
	M("ImGui").def("CheckboxFlags", (bool (*)(const char *, unsigned int *, unsigned int)) &ImGui::CheckboxFlags, "C++: ImGui::CheckboxFlags(const char *, unsigned int *, unsigned int) --> bool", pybind11::arg("label"), pybind11::arg("flags"), pybind11::arg("flags_value"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RadioButton(const char *, bool) file:imgui.h line:411
	M("ImGui").def("RadioButton", (bool (*)(const char *, bool)) &ImGui::RadioButton, "C++: ImGui::RadioButton(const char *, bool) --> bool", pybind11::arg("label"), pybind11::arg("active"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RadioButton(const char *, int *, int) file:imgui.h line:412
	M("ImGui").def("RadioButton", (bool (*)(const char *, int *, int)) &ImGui::RadioButton, "C++: ImGui::RadioButton(const char *, int *, int) --> bool", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_button"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_4.cpp
#include <imgui.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::ProgressBar(float, const struct ImVec2 &, const char *) file:imgui.h line:413
	M("ImGui").def("ProgressBar", [](float const & a0) -> void { return ImGui::ProgressBar(a0); }, "", pybind11::arg("fraction"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ProgressBar", [](float const & a0, const struct ImVec2 & a1) -> void { return ImGui::ProgressBar(a0, a1); }, "", pybind11::arg("fraction"), pybind11::arg("size_arg"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ProgressBar", (void (*)(float, const struct ImVec2 &, const char *)) &ImGui::ProgressBar, "C++: ImGui::ProgressBar(float, const struct ImVec2 &, const char *) --> void", pybind11::arg("fraction"), pybind11::arg("size_arg"), pybind11::arg("overlay"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Bullet() file:imgui.h line:414
	M("ImGui").def("Bullet", (void (*)()) &ImGui::Bullet, "C++: ImGui::Bullet() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginCombo(const char *, const char *, int) file:imgui.h line:419
	M("ImGui").def("BeginCombo", [](const char * a0, const char * a1) -> bool { return ImGui::BeginCombo(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("preview_value"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginCombo", (bool (*)(const char *, const char *, int)) &ImGui::BeginCombo, "C++: ImGui::BeginCombo(const char *, const char *, int) --> bool", pybind11::arg("label"), pybind11::arg("preview_value"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndCombo() file:imgui.h line:420
	M("ImGui").def("EndCombo", (void (*)()) &ImGui::EndCombo, "C++: ImGui::EndCombo() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Combo(const char *, int *, const char *, int) file:imgui.h line:422
	M("ImGui").def("Combo", [](const char * a0, int * a1, const char * a2) -> bool { return ImGui::Combo(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("current_item"), pybind11::arg("items_separated_by_zeros"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Combo", (bool (*)(const char *, int *, const char *, int)) &ImGui::Combo, "C++: ImGui::Combo(const char *, int *, const char *, int) --> bool", pybind11::arg("label"), pybind11::arg("current_item"), pybind11::arg("items_separated_by_zeros"), pybind11::arg("popup_max_height_in_items"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DragFloat(const char *, float *, float, float, float, const char *, float) file:imgui.h line:432
	M("ImGui").def("DragFloat", [](const char * a0, float * a1) -> bool { return ImGui::DragFloat(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloat", [](const char * a0, float * a1, float const & a2) -> bool { return ImGui::DragFloat(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_speed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloat", [](const char * a0, float * a1, float const & a2, float const & a3) -> bool { return ImGui::DragFloat(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloat", [](const char * a0, float * a1, float const & a2, float const & a3, float const & a4) -> bool { return ImGui::DragFloat(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloat", [](const char * a0, float * a1, float const & a2, float const & a3, float const & a4, const char * a5) -> bool { return ImGui::DragFloat(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloat", (bool (*)(const char *, float *, float, float, float, const char *, float)) &ImGui::DragFloat, "C++: ImGui::DragFloat(const char *, float *, float, float, float, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DragFloatRange2(const char *, float *, float *, float, float, float, const char *, const char *, float) file:imgui.h line:436
	M("ImGui").def("DragFloatRange2", [](const char * a0, float * a1, float * a2) -> bool { return ImGui::DragFloatRange2(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloatRange2", [](const char * a0, float * a1, float * a2, float const & a3) -> bool { return ImGui::DragFloatRange2(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloatRange2", [](const char * a0, float * a1, float * a2, float const & a3, float const & a4) -> bool { return ImGui::DragFloatRange2(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloatRange2", [](const char * a0, float * a1, float * a2, float const & a3, float const & a4, float const & a5) -> bool { return ImGui::DragFloatRange2(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloatRange2", [](const char * a0, float * a1, float * a2, float const & a3, float const & a4, float const & a5, const char * a6) -> bool { return ImGui::DragFloatRange2(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloatRange2", [](const char * a0, float * a1, float * a2, float const & a3, float const & a4, float const & a5, const char * a6, const char * a7) -> bool { return ImGui::DragFloatRange2(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::arg("format_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragFloatRange2", (bool (*)(const char *, float *, float *, float, float, float, const char *, const char *, float)) &ImGui::DragFloatRange2, "C++: ImGui::DragFloatRange2(const char *, float *, float *, float, float, float, const char *, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::arg("format_max"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DragInt(const char *, int *, float, int, int, const char *) file:imgui.h line:437
	M("ImGui").def("DragInt", [](const char * a0, int * a1) -> bool { return ImGui::DragInt(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragInt", [](const char * a0, int * a1, float const & a2) -> bool { return ImGui::DragInt(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_speed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragInt", [](const char * a0, int * a1, float const & a2, int const & a3) -> bool { return ImGui::DragInt(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragInt", [](const char * a0, int * a1, float const & a2, int const & a3, int const & a4) -> bool { return ImGui::DragInt(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragInt", (bool (*)(const char *, int *, float, int, int, const char *)) &ImGui::DragInt, "C++: ImGui::DragInt(const char *, int *, float, int, int, const char *) --> bool", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DragIntRange2(const char *, int *, int *, float, int, int, const char *, const char *) file:imgui.h line:441
	M("ImGui").def("DragIntRange2", [](const char * a0, int * a1, int * a2) -> bool { return ImGui::DragIntRange2(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragIntRange2", [](const char * a0, int * a1, int * a2, float const & a3) -> bool { return ImGui::DragIntRange2(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragIntRange2", [](const char * a0, int * a1, int * a2, float const & a3, int const & a4) -> bool { return ImGui::DragIntRange2(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragIntRange2", [](const char * a0, int * a1, int * a2, float const & a3, int const & a4, int const & a5) -> bool { return ImGui::DragIntRange2(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragIntRange2", [](const char * a0, int * a1, int * a2, float const & a3, int const & a4, int const & a5, const char * a6) -> bool { return ImGui::DragIntRange2(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragIntRange2", (bool (*)(const char *, int *, int *, float, int, int, const char *, const char *)) &ImGui::DragIntRange2, "C++: ImGui::DragIntRange2(const char *, int *, int *, float, int, int, const char *, const char *) --> bool", pybind11::arg("label"), pybind11::arg("v_current_min"), pybind11::arg("v_current_max"), pybind11::arg("v_speed"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::arg("format_max"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DragScalar(const char *, int, void *, float, const void *, const void *, const char *, float) file:imgui.h line:442
	M("ImGui").def("DragScalar", [](const char * a0, int const & a1, void * a2, float const & a3) -> bool { return ImGui::DragScalar(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("v_speed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragScalar", [](const char * a0, int const & a1, void * a2, float const & a3, const void * a4) -> bool { return ImGui::DragScalar(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("v_speed"), pybind11::arg("p_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragScalar", [](const char * a0, int const & a1, void * a2, float const & a3, const void * a4, const void * a5) -> bool { return ImGui::DragScalar(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("v_speed"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragScalar", [](const char * a0, int const & a1, void * a2, float const & a3, const void * a4, const void * a5, const char * a6) -> bool { return ImGui::DragScalar(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("v_speed"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragScalar", (bool (*)(const char *, int, void *, float, const void *, const void *, const char *, float)) &ImGui::DragScalar, "C++: ImGui::DragScalar(const char *, int, void *, float, const void *, const void *, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("v_speed"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DragScalarN(const char *, int, void *, int, float, const void *, const void *, const char *, float) file:imgui.h line:443
	M("ImGui").def("DragScalarN", [](const char * a0, int const & a1, void * a2, int const & a3, float const & a4) -> bool { return ImGui::DragScalarN(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("v_speed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragScalarN", [](const char * a0, int const & a1, void * a2, int const & a3, float const & a4, const void * a5) -> bool { return ImGui::DragScalarN(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("v_speed"), pybind11::arg("p_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragScalarN", [](const char * a0, int const & a1, void * a2, int const & a3, float const & a4, const void * a5, const void * a6) -> bool { return ImGui::DragScalarN(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("v_speed"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragScalarN", [](const char * a0, int const & a1, void * a2, int const & a3, float const & a4, const void * a5, const void * a6, const char * a7) -> bool { return ImGui::DragScalarN(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("v_speed"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DragScalarN", (bool (*)(const char *, int, void *, int, float, const void *, const void *, const char *, float)) &ImGui::DragScalarN, "C++: ImGui::DragScalarN(const char *, int, void *, int, float, const void *, const void *, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("v_speed"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SliderFloat(const char *, float *, float, float, const char *, float) file:imgui.h line:448
	M("ImGui").def("SliderFloat", [](const char * a0, float * a1, float const & a2, float const & a3) -> bool { return ImGui::SliderFloat(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderFloat", [](const char * a0, float * a1, float const & a2, float const & a3, const char * a4) -> bool { return ImGui::SliderFloat(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderFloat", (bool (*)(const char *, float *, float, float, const char *, float)) &ImGui::SliderFloat, "C++: ImGui::SliderFloat(const char *, float *, float, float, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_5.cpp
#include <imgui.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::SliderAngle(const char *, float *, float, float, const char *) file:imgui.h line:452
	M("ImGui").def("SliderAngle", [](const char * a0, float * a1) -> bool { return ImGui::SliderAngle(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("v_rad"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderAngle", [](const char * a0, float * a1, float const & a2) -> bool { return ImGui::SliderAngle(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("v_rad"), pybind11::arg("v_degrees_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderAngle", [](const char * a0, float * a1, float const & a2, float const & a3) -> bool { return ImGui::SliderAngle(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v_rad"), pybind11::arg("v_degrees_min"), pybind11::arg("v_degrees_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderAngle", (bool (*)(const char *, float *, float, float, const char *)) &ImGui::SliderAngle, "C++: ImGui::SliderAngle(const char *, float *, float, float, const char *) --> bool", pybind11::arg("label"), pybind11::arg("v_rad"), pybind11::arg("v_degrees_min"), pybind11::arg("v_degrees_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SliderInt(const char *, int *, int, int, const char *) file:imgui.h line:453
	M("ImGui").def("SliderInt", [](const char * a0, int * a1, int const & a2, int const & a3) -> bool { return ImGui::SliderInt(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderInt", (bool (*)(const char *, int *, int, int, const char *)) &ImGui::SliderInt, "C++: ImGui::SliderInt(const char *, int *, int, int, const char *) --> bool", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SliderScalar(const char *, int, void *, const void *, const void *, const char *, float) file:imgui.h line:457
	M("ImGui").def("SliderScalar", [](const char * a0, int const & a1, void * a2, const void * a3, const void * a4) -> bool { return ImGui::SliderScalar(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderScalar", [](const char * a0, int const & a1, void * a2, const void * a3, const void * a4, const char * a5) -> bool { return ImGui::SliderScalar(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderScalar", (bool (*)(const char *, int, void *, const void *, const void *, const char *, float)) &ImGui::SliderScalar, "C++: ImGui::SliderScalar(const char *, int, void *, const void *, const void *, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SliderScalarN(const char *, int, void *, int, const void *, const void *, const char *, float) file:imgui.h line:458
	M("ImGui").def("SliderScalarN", [](const char * a0, int const & a1, void * a2, int const & a3, const void * a4, const void * a5) -> bool { return ImGui::SliderScalarN(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderScalarN", [](const char * a0, int const & a1, void * a2, int const & a3, const void * a4, const void * a5, const char * a6) -> bool { return ImGui::SliderScalarN(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SliderScalarN", (bool (*)(const char *, int, void *, int, const void *, const void *, const char *, float)) &ImGui::SliderScalarN, "C++: ImGui::SliderScalarN(const char *, int, void *, int, const void *, const void *, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::VSliderFloat(const char *, const struct ImVec2 &, float *, float, float, const char *, float) file:imgui.h line:459
	M("ImGui").def("VSliderFloat", [](const char * a0, const struct ImVec2 & a1, float * a2, float const & a3, float const & a4) -> bool { return ImGui::VSliderFloat(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("size"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("VSliderFloat", [](const char * a0, const struct ImVec2 & a1, float * a2, float const & a3, float const & a4, const char * a5) -> bool { return ImGui::VSliderFloat(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("size"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("VSliderFloat", (bool (*)(const char *, const struct ImVec2 &, float *, float, float, const char *, float)) &ImGui::VSliderFloat, "C++: ImGui::VSliderFloat(const char *, const struct ImVec2 &, float *, float, float, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("size"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::VSliderInt(const char *, const struct ImVec2 &, int *, int, int, const char *) file:imgui.h line:460
	M("ImGui").def("VSliderInt", [](const char * a0, const struct ImVec2 & a1, int * a2, int const & a3, int const & a4) -> bool { return ImGui::VSliderInt(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("size"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("VSliderInt", (bool (*)(const char *, const struct ImVec2 &, int *, int, int, const char *)) &ImGui::VSliderInt, "C++: ImGui::VSliderInt(const char *, const struct ImVec2 &, int *, int, int, const char *) --> bool", pybind11::arg("label"), pybind11::arg("size"), pybind11::arg("v"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::VSliderScalar(const char *, const struct ImVec2 &, int, void *, const void *, const void *, const char *, float) file:imgui.h line:461
	M("ImGui").def("VSliderScalar", [](const char * a0, const struct ImVec2 & a1, int const & a2, void * a3, const void * a4, const void * a5) -> bool { return ImGui::VSliderScalar(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("size"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("VSliderScalar", [](const char * a0, const struct ImVec2 & a1, int const & a2, void * a3, const void * a4, const void * a5, const char * a6) -> bool { return ImGui::VSliderScalar(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("size"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("VSliderScalar", (bool (*)(const char *, const struct ImVec2 &, int, void *, const void *, const void *, const char *, float)) &ImGui::VSliderScalar, "C++: ImGui::VSliderScalar(const char *, const struct ImVec2 &, int, void *, const void *, const void *, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("size"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::InputFloat(const char *, float *, float, float, const char *, int) file:imgui.h line:469
	M("ImGui").def("InputFloat", [](const char * a0, float * a1) -> bool { return ImGui::InputFloat(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputFloat", [](const char * a0, float * a1, float const & a2) -> bool { return ImGui::InputFloat(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputFloat", [](const char * a0, float * a1, float const & a2, float const & a3) -> bool { return ImGui::InputFloat(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::arg("step_fast"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputFloat", [](const char * a0, float * a1, float const & a2, float const & a3, const char * a4) -> bool { return ImGui::InputFloat(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::arg("step_fast"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputFloat", (bool (*)(const char *, float *, float, float, const char *, int)) &ImGui::InputFloat, "C++: ImGui::InputFloat(const char *, float *, float, float, const char *, int) --> bool", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::arg("step_fast"), pybind11::arg("format"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::InputInt(const char *, int *, int, int, int) file:imgui.h line:473
	M("ImGui").def("InputInt", [](const char * a0, int * a1) -> bool { return ImGui::InputInt(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputInt", [](const char * a0, int * a1, int const & a2) -> bool { return ImGui::InputInt(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputInt", [](const char * a0, int * a1, int const & a2, int const & a3) -> bool { return ImGui::InputInt(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::arg("step_fast"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputInt", (bool (*)(const char *, int *, int, int, int)) &ImGui::InputInt, "C++: ImGui::InputInt(const char *, int *, int, int, int) --> bool", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::arg("step_fast"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::InputDouble(const char *, double *, double, double, const char *, int) file:imgui.h line:477
	M("ImGui").def("InputDouble", [](const char * a0, double * a1) -> bool { return ImGui::InputDouble(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputDouble", [](const char * a0, double * a1, double const & a2) -> bool { return ImGui::InputDouble(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputDouble", [](const char * a0, double * a1, double const & a2, double const & a3) -> bool { return ImGui::InputDouble(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::arg("step_fast"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputDouble", [](const char * a0, double * a1, double const & a2, double const & a3, const char * a4) -> bool { return ImGui::InputDouble(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::arg("step_fast"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputDouble", (bool (*)(const char *, double *, double, double, const char *, int)) &ImGui::InputDouble, "C++: ImGui::InputDouble(const char *, double *, double, double, const char *, int) --> bool", pybind11::arg("label"), pybind11::arg("v"), pybind11::arg("step"), pybind11::arg("step_fast"), pybind11::arg("format"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::InputScalar(const char *, int, void *, const void *, const void *, const char *, int) file:imgui.h line:478
	M("ImGui").def("InputScalar", [](const char * a0, int const & a1, void * a2) -> bool { return ImGui::InputScalar(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputScalar", [](const char * a0, int const & a1, void * a2, const void * a3) -> bool { return ImGui::InputScalar(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_step"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputScalar", [](const char * a0, int const & a1, void * a2, const void * a3, const void * a4) -> bool { return ImGui::InputScalar(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_step"), pybind11::arg("p_step_fast"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputScalar", [](const char * a0, int const & a1, void * a2, const void * a3, const void * a4, const char * a5) -> bool { return ImGui::InputScalar(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_step"), pybind11::arg("p_step_fast"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputScalar", (bool (*)(const char *, int, void *, const void *, const void *, const char *, int)) &ImGui::InputScalar, "C++: ImGui::InputScalar(const char *, int, void *, const void *, const void *, const char *, int) --> bool", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("p_step"), pybind11::arg("p_step_fast"), pybind11::arg("format"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::InputScalarN(const char *, int, void *, int, const void *, const void *, const char *, int) file:imgui.h line:479
	M("ImGui").def("InputScalarN", [](const char * a0, int const & a1, void * a2, int const & a3) -> bool { return ImGui::InputScalarN(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputScalarN", [](const char * a0, int const & a1, void * a2, int const & a3, const void * a4) -> bool { return ImGui::InputScalarN(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("p_step"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputScalarN", [](const char * a0, int const & a1, void * a2, int const & a3, const void * a4, const void * a5) -> bool { return ImGui::InputScalarN(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("p_step"), pybind11::arg("p_step_fast"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputScalarN", [](const char * a0, int const & a1, void * a2, int const & a3, const void * a4, const void * a5, const char * a6) -> bool { return ImGui::InputScalarN(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("p_step"), pybind11::arg("p_step_fast"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("InputScalarN", (bool (*)(const char *, int, void *, int, const void *, const void *, const char *, int)) &ImGui::InputScalarN, "C++: ImGui::InputScalarN(const char *, int, void *, int, const void *, const void *, const char *, int) --> bool", pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("components"), pybind11::arg("p_step"), pybind11::arg("p_step_fast"), pybind11::arg("format"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_6.cpp
#include <imgui.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_6(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::ColorButton(const char *, const struct ImVec4 &, int, struct ImVec2) file:imgui.h line:488
	M("ImGui").def("ColorButton", [](const char * a0, const struct ImVec4 & a1) -> bool { return ImGui::ColorButton(a0, a1); }, "", pybind11::arg("desc_id"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ColorButton", [](const char * a0, const struct ImVec4 & a1, int const & a2) -> bool { return ImGui::ColorButton(a0, a1, a2); }, "", pybind11::arg("desc_id"), pybind11::arg("col"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ColorButton", (bool (*)(const char *, const struct ImVec4 &, int, struct ImVec2)) &ImGui::ColorButton, "C++: ImGui::ColorButton(const char *, const struct ImVec4 &, int, struct ImVec2) --> bool", pybind11::arg("desc_id"), pybind11::arg("col"), pybind11::arg("flags"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetColorEditOptions(int) file:imgui.h line:489
	M("ImGui").def("SetColorEditOptions", (void (*)(int)) &ImGui::SetColorEditOptions, "C++: ImGui::SetColorEditOptions(int) --> void", pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreeNode(const char *) file:imgui.h line:493
	M("ImGui").def("TreeNode", (bool (*)(const char *)) &ImGui::TreeNode, "C++: ImGui::TreeNode(const char *) --> bool", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreeNode(const char *, const char *) file:imgui.h line:494
	M("ImGui").def("TreeNode", [](const char * a0, const char * a1) -> bool { return ImGui::TreeNode(a0, a1); }, "", pybind11::arg("str_id"), pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreeNode(const void *, const char *) file:imgui.h line:495
	M("ImGui").def("TreeNode", [](const void * a0, const char * a1) -> bool { return ImGui::TreeNode(a0, a1); }, "", pybind11::arg("ptr_id"), pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreeNodeEx(const char *, int) file:imgui.h line:498
	M("ImGui").def("TreeNodeEx", [](const char * a0) -> bool { return ImGui::TreeNodeEx(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("TreeNodeEx", (bool (*)(const char *, int)) &ImGui::TreeNodeEx, "C++: ImGui::TreeNodeEx(const char *, int) --> bool", pybind11::arg("label"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreeNodeEx(const char *, int, const char *) file:imgui.h line:499
	M("ImGui").def("TreeNodeEx", [](const char * a0, int const & a1, const char * a2) -> bool { return ImGui::TreeNodeEx(a0, a1, a2); }, "", pybind11::arg("str_id"), pybind11::arg("flags"), pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreeNodeEx(const void *, int, const char *) file:imgui.h line:500
	M("ImGui").def("TreeNodeEx", [](const void * a0, int const & a1, const char * a2) -> bool { return ImGui::TreeNodeEx(a0, a1, a2); }, "", pybind11::arg("ptr_id"), pybind11::arg("flags"), pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreePush(const char *) file:imgui.h line:503
	M("ImGui").def("TreePush", (void (*)(const char *)) &ImGui::TreePush, "C++: ImGui::TreePush(const char *) --> void", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreePush(const void *) file:imgui.h line:504
	M("ImGui").def("TreePush", []() -> void { return ImGui::TreePush(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("TreePush", (void (*)(const void *)) &ImGui::TreePush, "C++: ImGui::TreePush(const void *) --> void", pybind11::arg("ptr_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreePop() file:imgui.h line:505
	M("ImGui").def("TreePop", (void (*)()) &ImGui::TreePop, "C++: ImGui::TreePop() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetTreeNodeToLabelSpacing() file:imgui.h line:506
	M("ImGui").def("GetTreeNodeToLabelSpacing", (float (*)()) &ImGui::GetTreeNodeToLabelSpacing, "C++: ImGui::GetTreeNodeToLabelSpacing() --> float", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CollapsingHeader(const char *, int) file:imgui.h line:507
	M("ImGui").def("CollapsingHeader", [](const char * a0) -> bool { return ImGui::CollapsingHeader(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("CollapsingHeader", (bool (*)(const char *, int)) &ImGui::CollapsingHeader, "C++: ImGui::CollapsingHeader(const char *, int) --> bool", pybind11::arg("label"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CollapsingHeader(const char *, bool *, int) file:imgui.h line:508
	M("ImGui").def("CollapsingHeader", [](const char * a0, bool * a1) -> bool { return ImGui::CollapsingHeader(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("p_open"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("CollapsingHeader", (bool (*)(const char *, bool *, int)) &ImGui::CollapsingHeader, "C++: ImGui::CollapsingHeader(const char *, bool *, int) --> bool", pybind11::arg("label"), pybind11::arg("p_open"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetNextItemOpen(bool, int) file:imgui.h line:509
	M("ImGui").def("SetNextItemOpen", [](bool const & a0) -> void { return ImGui::SetNextItemOpen(a0); }, "", pybind11::arg("is_open"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetNextItemOpen", (void (*)(bool, int)) &ImGui::SetNextItemOpen, "C++: ImGui::SetNextItemOpen(bool, int) --> void", pybind11::arg("is_open"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Selectable(const char *, bool, int, const struct ImVec2 &) file:imgui.h line:514
	M("ImGui").def("Selectable", [](const char * a0) -> bool { return ImGui::Selectable(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Selectable", [](const char * a0, bool const & a1) -> bool { return ImGui::Selectable(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("selected"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Selectable", [](const char * a0, bool const & a1, int const & a2) -> bool { return ImGui::Selectable(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("selected"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Selectable", (bool (*)(const char *, bool, int, const struct ImVec2 &)) &ImGui::Selectable, "C++: ImGui::Selectable(const char *, bool, int, const struct ImVec2 &) --> bool", pybind11::arg("label"), pybind11::arg("selected"), pybind11::arg("flags"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Selectable(const char *, bool *, int, const struct ImVec2 &) file:imgui.h line:515
	M("ImGui").def("Selectable", [](const char * a0, bool * a1) -> bool { return ImGui::Selectable(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("p_selected"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Selectable", [](const char * a0, bool * a1, int const & a2) -> bool { return ImGui::Selectable(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("p_selected"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Selectable", (bool (*)(const char *, bool *, int, const struct ImVec2 &)) &ImGui::Selectable, "C++: ImGui::Selectable(const char *, bool *, int, const struct ImVec2 &) --> bool", pybind11::arg("label"), pybind11::arg("p_selected"), pybind11::arg("flags"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ListBoxHeader(const char *, const struct ImVec2 &) file:imgui.h line:521
	M("ImGui").def("ListBoxHeader", [](const char * a0) -> bool { return ImGui::ListBoxHeader(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ListBoxHeader", (bool (*)(const char *, const struct ImVec2 &)) &ImGui::ListBoxHeader, "C++: ImGui::ListBoxHeader(const char *, const struct ImVec2 &) --> bool", pybind11::arg("label"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ListBoxHeader(const char *, int, int) file:imgui.h line:522
	M("ImGui").def("ListBoxHeader", [](const char * a0, int const & a1) -> bool { return ImGui::ListBoxHeader(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("items_count"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ListBoxHeader", (bool (*)(const char *, int, int)) &ImGui::ListBoxHeader, "C++: ImGui::ListBoxHeader(const char *, int, int) --> bool", pybind11::arg("label"), pybind11::arg("items_count"), pybind11::arg("height_in_items"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ListBoxFooter() file:imgui.h line:523
	M("ImGui").def("ListBoxFooter", (void (*)()) &ImGui::ListBoxFooter, "C++: ImGui::ListBoxFooter() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PlotLines(const char *, const float *, int, int, const char *, float, float, struct ImVec2, int) file:imgui.h line:526
	M("ImGui").def("PlotLines", [](const char * a0, const float * a1, int const & a2) -> void { return ImGui::PlotLines(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotLines", [](const char * a0, const float * a1, int const & a2, int const & a3) -> void { return ImGui::PlotLines(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotLines", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4) -> void { return ImGui::PlotLines(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotLines", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4, float const & a5) -> void { return ImGui::PlotLines(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotLines", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4, float const & a5, float const & a6) -> void { return ImGui::PlotLines(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::arg("scale_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotLines", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4, float const & a5, float const & a6, struct ImVec2 const & a7) -> void { return ImGui::PlotLines(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::arg("scale_max"), pybind11::arg("graph_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotLines", (void (*)(const char *, const float *, int, int, const char *, float, float, struct ImVec2, int)) &ImGui::PlotLines, "C++: ImGui::PlotLines(const char *, const float *, int, int, const char *, float, float, struct ImVec2, int) --> void", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::arg("scale_max"), pybind11::arg("graph_size"), pybind11::arg("stride"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PlotHistogram(const char *, const float *, int, int, const char *, float, float, struct ImVec2, int) file:imgui.h line:528
	M("ImGui").def("PlotHistogram", [](const char * a0, const float * a1, int const & a2) -> void { return ImGui::PlotHistogram(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotHistogram", [](const char * a0, const float * a1, int const & a2, int const & a3) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotHistogram", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotHistogram", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4, float const & a5) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotHistogram", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4, float const & a5, float const & a6) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::arg("scale_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotHistogram", [](const char * a0, const float * a1, int const & a2, int const & a3, const char * a4, float const & a5, float const & a6, struct ImVec2 const & a7) -> void { return ImGui::PlotHistogram(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::arg("scale_max"), pybind11::arg("graph_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("PlotHistogram", (void (*)(const char *, const float *, int, int, const char *, float, float, struct ImVec2, int)) &ImGui::PlotHistogram, "C++: ImGui::PlotHistogram(const char *, const float *, int, int, const char *, float, float, struct ImVec2, int) --> void", pybind11::arg("label"), pybind11::arg("values"), pybind11::arg("values_count"), pybind11::arg("values_offset"), pybind11::arg("overlay_text"), pybind11::arg("scale_min"), pybind11::arg("scale_max"), pybind11::arg("graph_size"), pybind11::arg("stride"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Value(const char *, bool) file:imgui.h line:533
	M("ImGui").def("Value", (void (*)(const char *, bool)) &ImGui::Value, "C++: ImGui::Value(const char *, bool) --> void", pybind11::arg("prefix"), pybind11::arg("b"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Value(const char *, int) file:imgui.h line:534
	M("ImGui").def("Value", (void (*)(const char *, int)) &ImGui::Value, "C++: ImGui::Value(const char *, int) --> void", pybind11::arg("prefix"), pybind11::arg("v"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Value(const char *, unsigned int) file:imgui.h line:535
	M("ImGui").def("Value", (void (*)(const char *, unsigned int)) &ImGui::Value, "C++: ImGui::Value(const char *, unsigned int) --> void", pybind11::arg("prefix"), pybind11::arg("v"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_7.cpp
#include <imgui.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_7(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::Value(const char *, float, const char *) file:imgui.h line:536
	M("ImGui").def("Value", [](const char * a0, float const & a1) -> void { return ImGui::Value(a0, a1); }, "", pybind11::arg("prefix"), pybind11::arg("v"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Value", (void (*)(const char *, float, const char *)) &ImGui::Value, "C++: ImGui::Value(const char *, float, const char *) --> void", pybind11::arg("prefix"), pybind11::arg("v"), pybind11::arg("float_format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginMainMenuBar() file:imgui.h line:539
	M("ImGui").def("BeginMainMenuBar", (bool (*)()) &ImGui::BeginMainMenuBar, "C++: ImGui::BeginMainMenuBar() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndMainMenuBar() file:imgui.h line:540
	M("ImGui").def("EndMainMenuBar", (void (*)()) &ImGui::EndMainMenuBar, "C++: ImGui::EndMainMenuBar() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginMenuBar() file:imgui.h line:541
	M("ImGui").def("BeginMenuBar", (bool (*)()) &ImGui::BeginMenuBar, "C++: ImGui::BeginMenuBar() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndMenuBar() file:imgui.h line:542
	M("ImGui").def("EndMenuBar", (void (*)()) &ImGui::EndMenuBar, "C++: ImGui::EndMenuBar() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginMenu(const char *, bool) file:imgui.h line:543
	M("ImGui").def("BeginMenu", [](const char * a0) -> bool { return ImGui::BeginMenu(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginMenu", (bool (*)(const char *, bool)) &ImGui::BeginMenu, "C++: ImGui::BeginMenu(const char *, bool) --> bool", pybind11::arg("label"), pybind11::arg("enabled"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndMenu() file:imgui.h line:544
	M("ImGui").def("EndMenu", (void (*)()) &ImGui::EndMenu, "C++: ImGui::EndMenu() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::MenuItem(const char *, const char *, bool, bool) file:imgui.h line:545
	M("ImGui").def("MenuItem", [](const char * a0) -> bool { return ImGui::MenuItem(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("MenuItem", [](const char * a0, const char * a1) -> bool { return ImGui::MenuItem(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("shortcut"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("MenuItem", [](const char * a0, const char * a1, bool const & a2) -> bool { return ImGui::MenuItem(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("shortcut"), pybind11::arg("selected"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("MenuItem", (bool (*)(const char *, const char *, bool, bool)) &ImGui::MenuItem, "C++: ImGui::MenuItem(const char *, const char *, bool, bool) --> bool", pybind11::arg("label"), pybind11::arg("shortcut"), pybind11::arg("selected"), pybind11::arg("enabled"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::MenuItem(const char *, const char *, bool *, bool) file:imgui.h line:546
	M("ImGui").def("MenuItem", [](const char * a0, const char * a1, bool * a2) -> bool { return ImGui::MenuItem(a0, a1, a2); }, "", pybind11::arg("label"), pybind11::arg("shortcut"), pybind11::arg("p_selected"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("MenuItem", (bool (*)(const char *, const char *, bool *, bool)) &ImGui::MenuItem, "C++: ImGui::MenuItem(const char *, const char *, bool *, bool) --> bool", pybind11::arg("label"), pybind11::arg("shortcut"), pybind11::arg("p_selected"), pybind11::arg("enabled"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginTooltip() file:imgui.h line:549
	M("ImGui").def("BeginTooltip", (void (*)()) &ImGui::BeginTooltip, "C++: ImGui::BeginTooltip() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndTooltip() file:imgui.h line:550
	M("ImGui").def("EndTooltip", (void (*)()) &ImGui::EndTooltip, "C++: ImGui::EndTooltip() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetTooltip(const char *) file:imgui.h line:551
	M("ImGui").def("SetTooltip", [](const char * a0) -> void { return ImGui::SetTooltip(a0); }, "", pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::OpenPopup(const char *) file:imgui.h line:562
	M("ImGui").def("OpenPopup", (void (*)(const char *)) &ImGui::OpenPopup, "C++: ImGui::OpenPopup(const char *) --> void", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginPopup(const char *, int) file:imgui.h line:563
	M("ImGui").def("BeginPopup", [](const char * a0) -> bool { return ImGui::BeginPopup(a0); }, "", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopup", (bool (*)(const char *, int)) &ImGui::BeginPopup, "C++: ImGui::BeginPopup(const char *, int) --> bool", pybind11::arg("str_id"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginPopupContextItem(const char *, int) file:imgui.h line:564
	M("ImGui").def("BeginPopupContextItem", []() -> bool { return ImGui::BeginPopupContextItem(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopupContextItem", [](const char * a0) -> bool { return ImGui::BeginPopupContextItem(a0); }, "", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopupContextItem", (bool (*)(const char *, int)) &ImGui::BeginPopupContextItem, "C++: ImGui::BeginPopupContextItem(const char *, int) --> bool", pybind11::arg("str_id"), pybind11::arg("mouse_button"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginPopupContextWindow(const char *, int, bool) file:imgui.h line:565
	M("ImGui").def("BeginPopupContextWindow", []() -> bool { return ImGui::BeginPopupContextWindow(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopupContextWindow", [](const char * a0) -> bool { return ImGui::BeginPopupContextWindow(a0); }, "", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopupContextWindow", [](const char * a0, int const & a1) -> bool { return ImGui::BeginPopupContextWindow(a0, a1); }, "", pybind11::arg("str_id"), pybind11::arg("mouse_button"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopupContextWindow", (bool (*)(const char *, int, bool)) &ImGui::BeginPopupContextWindow, "C++: ImGui::BeginPopupContextWindow(const char *, int, bool) --> bool", pybind11::arg("str_id"), pybind11::arg("mouse_button"), pybind11::arg("also_over_items"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginPopupContextVoid(const char *, int) file:imgui.h line:566
	M("ImGui").def("BeginPopupContextVoid", []() -> bool { return ImGui::BeginPopupContextVoid(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopupContextVoid", [](const char * a0) -> bool { return ImGui::BeginPopupContextVoid(a0); }, "", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopupContextVoid", (bool (*)(const char *, int)) &ImGui::BeginPopupContextVoid, "C++: ImGui::BeginPopupContextVoid(const char *, int) --> bool", pybind11::arg("str_id"), pybind11::arg("mouse_button"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginPopupModal(const char *, bool *, int) file:imgui.h line:567
	M("ImGui").def("BeginPopupModal", [](const char * a0) -> bool { return ImGui::BeginPopupModal(a0); }, "", pybind11::arg("name"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopupModal", [](const char * a0, bool * a1) -> bool { return ImGui::BeginPopupModal(a0, a1); }, "", pybind11::arg("name"), pybind11::arg("p_open"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginPopupModal", (bool (*)(const char *, bool *, int)) &ImGui::BeginPopupModal, "C++: ImGui::BeginPopupModal(const char *, bool *, int) --> bool", pybind11::arg("name"), pybind11::arg("p_open"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndPopup() file:imgui.h line:568
	M("ImGui").def("EndPopup", (void (*)()) &ImGui::EndPopup, "C++: ImGui::EndPopup() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::OpenPopupOnItemClick(const char *, int) file:imgui.h line:569
	M("ImGui").def("OpenPopupOnItemClick", []() -> bool { return ImGui::OpenPopupOnItemClick(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("OpenPopupOnItemClick", [](const char * a0) -> bool { return ImGui::OpenPopupOnItemClick(a0); }, "", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("OpenPopupOnItemClick", (bool (*)(const char *, int)) &ImGui::OpenPopupOnItemClick, "C++: ImGui::OpenPopupOnItemClick(const char *, int) --> bool", pybind11::arg("str_id"), pybind11::arg("mouse_button"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsPopupOpen(const char *) file:imgui.h line:570
	M("ImGui").def("IsPopupOpen", (bool (*)(const char *)) &ImGui::IsPopupOpen, "C++: ImGui::IsPopupOpen(const char *) --> bool", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CloseCurrentPopup() file:imgui.h line:571
	M("ImGui").def("CloseCurrentPopup", (void (*)()) &ImGui::CloseCurrentPopup, "C++: ImGui::CloseCurrentPopup() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Columns(int, const char *, bool) file:imgui.h line:576
	M("ImGui").def("Columns", []() -> void { return ImGui::Columns(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Columns", [](int const & a0) -> void { return ImGui::Columns(a0); }, "", pybind11::arg("count"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Columns", [](int const & a0, const char * a1) -> void { return ImGui::Columns(a0, a1); }, "", pybind11::arg("count"), pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("Columns", (void (*)(int, const char *, bool)) &ImGui::Columns, "C++: ImGui::Columns(int, const char *, bool) --> void", pybind11::arg("count"), pybind11::arg("id"), pybind11::arg("border"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::NextColumn() file:imgui.h line:577
	M("ImGui").def("NextColumn", (void (*)()) &ImGui::NextColumn, "C++: ImGui::NextColumn() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColumnIndex() file:imgui.h line:578
	M("ImGui").def("GetColumnIndex", (int (*)()) &ImGui::GetColumnIndex, "C++: ImGui::GetColumnIndex() --> int", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColumnWidth(int) file:imgui.h line:579
	M("ImGui").def("GetColumnWidth", []() -> float { return ImGui::GetColumnWidth(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("GetColumnWidth", (float (*)(int)) &ImGui::GetColumnWidth, "C++: ImGui::GetColumnWidth(int) --> float", pybind11::arg("column_index"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetColumnWidth(int, float) file:imgui.h line:580
	M("ImGui").def("SetColumnWidth", (void (*)(int, float)) &ImGui::SetColumnWidth, "C++: ImGui::SetColumnWidth(int, float) --> void", pybind11::arg("column_index"), pybind11::arg("width"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColumnOffset(int) file:imgui.h line:581
	M("ImGui").def("GetColumnOffset", []() -> float { return ImGui::GetColumnOffset(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("GetColumnOffset", (float (*)(int)) &ImGui::GetColumnOffset, "C++: ImGui::GetColumnOffset(int) --> float", pybind11::arg("column_index"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetColumnOffset(int, float) file:imgui.h line:582
	M("ImGui").def("SetColumnOffset", (void (*)(int, float)) &ImGui::SetColumnOffset, "C++: ImGui::SetColumnOffset(int, float) --> void", pybind11::arg("column_index"), pybind11::arg("offset_x"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColumnsCount() file:imgui.h line:583
	M("ImGui").def("GetColumnsCount", (int (*)()) &ImGui::GetColumnsCount, "C++: ImGui::GetColumnsCount() --> int", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginTabBar(const char *, int) file:imgui.h line:587
	M("ImGui").def("BeginTabBar", [](const char * a0) -> bool { return ImGui::BeginTabBar(a0); }, "", pybind11::arg("str_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginTabBar", (bool (*)(const char *, int)) &ImGui::BeginTabBar, "C++: ImGui::BeginTabBar(const char *, int) --> bool", pybind11::arg("str_id"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndTabBar() file:imgui.h line:588
	M("ImGui").def("EndTabBar", (void (*)()) &ImGui::EndTabBar, "C++: ImGui::EndTabBar() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginTabItem(const char *, bool *, int) file:imgui.h line:589
	M("ImGui").def("BeginTabItem", [](const char * a0) -> bool { return ImGui::BeginTabItem(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginTabItem", [](const char * a0, bool * a1) -> bool { return ImGui::BeginTabItem(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("p_open"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginTabItem", (bool (*)(const char *, bool *, int)) &ImGui::BeginTabItem, "C++: ImGui::BeginTabItem(const char *, bool *, int) --> bool", pybind11::arg("label"), pybind11::arg("p_open"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndTabItem() file:imgui.h line:590
	M("ImGui").def("EndTabItem", (void (*)()) &ImGui::EndTabItem, "C++: ImGui::EndTabItem() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetTabItemClosed(const char *) file:imgui.h line:591
	M("ImGui").def("SetTabItemClosed", (void (*)(const char *)) &ImGui::SetTabItemClosed, "C++: ImGui::SetTabItemClosed(const char *) --> void", pybind11::arg("tab_or_docked_window_label"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LogToTTY(int) file:imgui.h line:595
	M("ImGui").def("LogToTTY", []() -> void { return ImGui::LogToTTY(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("LogToTTY", (void (*)(int)) &ImGui::LogToTTY, "C++: ImGui::LogToTTY(int) --> void", pybind11::arg("auto_open_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LogToFile(int, const char *) file:imgui.h line:596
	M("ImGui").def("LogToFile", []() -> void { return ImGui::LogToFile(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("LogToFile", [](int const & a0) -> void { return ImGui::LogToFile(a0); }, "", pybind11::arg("auto_open_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("LogToFile", (void (*)(int, const char *)) &ImGui::LogToFile, "C++: ImGui::LogToFile(int, const char *) --> void", pybind11::arg("auto_open_depth"), pybind11::arg("filename"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LogToClipboard(int) file:imgui.h line:597
	M("ImGui").def("LogToClipboard", []() -> void { return ImGui::LogToClipboard(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("LogToClipboard", (void (*)(int)) &ImGui::LogToClipboard, "C++: ImGui::LogToClipboard(int) --> void", pybind11::arg("auto_open_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LogFinish() file:imgui.h line:598
	M("ImGui").def("LogFinish", (void (*)()) &ImGui::LogFinish, "C++: ImGui::LogFinish() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LogButtons() file:imgui.h line:599
	M("ImGui").def("LogButtons", (void (*)()) &ImGui::LogButtons, "C++: ImGui::LogButtons() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_8.cpp
#include <imgui.h>
#include <imgui_internal.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_8(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::LogText(const char *) file:imgui.h line:600
	M("ImGui").def("LogText", [](const char * a0) -> void { return ImGui::LogText(a0); }, "", pybind11::arg("fmt"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginDragDropSource(int) file:imgui.h line:604
	M("ImGui").def("BeginDragDropSource", []() -> bool { return ImGui::BeginDragDropSource(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginDragDropSource", (bool (*)(int)) &ImGui::BeginDragDropSource, "C++: ImGui::BeginDragDropSource(int) --> bool", pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetDragDropPayload(const char *, const void *, unsigned long, int) file:imgui.h line:605
	M("ImGui").def("SetDragDropPayload", [](const char * a0, const void * a1, unsigned long const & a2) -> bool { return ImGui::SetDragDropPayload(a0, a1, a2); }, "", pybind11::arg("type"), pybind11::arg("data"), pybind11::arg("sz"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetDragDropPayload", (bool (*)(const char *, const void *, unsigned long, int)) &ImGui::SetDragDropPayload, "C++: ImGui::SetDragDropPayload(const char *, const void *, unsigned long, int) --> bool", pybind11::arg("type"), pybind11::arg("data"), pybind11::arg("sz"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndDragDropSource() file:imgui.h line:606
	M("ImGui").def("EndDragDropSource", (void (*)()) &ImGui::EndDragDropSource, "C++: ImGui::EndDragDropSource() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginDragDropTarget() file:imgui.h line:607
	M("ImGui").def("BeginDragDropTarget", (bool (*)()) &ImGui::BeginDragDropTarget, "C++: ImGui::BeginDragDropTarget() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::AcceptDragDropPayload(const char *, int) file:imgui.h line:608
	M("ImGui").def("AcceptDragDropPayload", [](const char * a0) -> const ImGuiPayload * { return ImGui::AcceptDragDropPayload(a0); }, "", pybind11::return_value_policy::reference, pybind11::arg("type"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("AcceptDragDropPayload", (const struct ImGuiPayload * (*)(const char *, int)) &ImGui::AcceptDragDropPayload, "C++: ImGui::AcceptDragDropPayload(const char *, int) --> const struct ImGuiPayload *", pybind11::return_value_policy::reference, pybind11::arg("type"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndDragDropTarget() file:imgui.h line:609
	M("ImGui").def("EndDragDropTarget", (void (*)()) &ImGui::EndDragDropTarget, "C++: ImGui::EndDragDropTarget() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetDragDropPayload() file:imgui.h line:610
	M("ImGui").def("GetDragDropPayload", (const struct ImGuiPayload * (*)()) &ImGui::GetDragDropPayload, "C++: ImGui::GetDragDropPayload() --> const struct ImGuiPayload *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushClipRect(const struct ImVec2 &, const struct ImVec2 &, bool) file:imgui.h line:613
	M("ImGui").def("PushClipRect", (void (*)(const struct ImVec2 &, const struct ImVec2 &, bool)) &ImGui::PushClipRect, "C++: ImGui::PushClipRect(const struct ImVec2 &, const struct ImVec2 &, bool) --> void", pybind11::arg("clip_rect_min"), pybind11::arg("clip_rect_max"), pybind11::arg("intersect_with_current_clip_rect"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopClipRect() file:imgui.h line:614
	M("ImGui").def("PopClipRect", (void (*)()) &ImGui::PopClipRect, "C++: ImGui::PopClipRect() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetItemDefaultFocus() file:imgui.h line:618
	M("ImGui").def("SetItemDefaultFocus", (void (*)()) &ImGui::SetItemDefaultFocus, "C++: ImGui::SetItemDefaultFocus() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetKeyboardFocusHere(int) file:imgui.h line:619
	M("ImGui").def("SetKeyboardFocusHere", []() -> void { return ImGui::SetKeyboardFocusHere(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetKeyboardFocusHere", (void (*)(int)) &ImGui::SetKeyboardFocusHere, "C++: ImGui::SetKeyboardFocusHere(int) --> void", pybind11::arg("offset"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemHovered(int) file:imgui.h line:624
	M("ImGui").def("IsItemHovered", []() -> bool { return ImGui::IsItemHovered(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsItemHovered", (bool (*)(int)) &ImGui::IsItemHovered, "C++: ImGui::IsItemHovered(int) --> bool", pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemActive() file:imgui.h line:625
	M("ImGui").def("IsItemActive", (bool (*)()) &ImGui::IsItemActive, "C++: ImGui::IsItemActive() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemFocused() file:imgui.h line:626
	M("ImGui").def("IsItemFocused", (bool (*)()) &ImGui::IsItemFocused, "C++: ImGui::IsItemFocused() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemClicked(int) file:imgui.h line:627
	M("ImGui").def("IsItemClicked", []() -> bool { return ImGui::IsItemClicked(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsItemClicked", (bool (*)(int)) &ImGui::IsItemClicked, "C++: ImGui::IsItemClicked(int) --> bool", pybind11::arg("mouse_button"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemVisible() file:imgui.h line:628
	M("ImGui").def("IsItemVisible", (bool (*)()) &ImGui::IsItemVisible, "C++: ImGui::IsItemVisible() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemEdited() file:imgui.h line:629
	M("ImGui").def("IsItemEdited", (bool (*)()) &ImGui::IsItemEdited, "C++: ImGui::IsItemEdited() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemActivated() file:imgui.h line:630
	M("ImGui").def("IsItemActivated", (bool (*)()) &ImGui::IsItemActivated, "C++: ImGui::IsItemActivated() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemDeactivated() file:imgui.h line:631
	M("ImGui").def("IsItemDeactivated", (bool (*)()) &ImGui::IsItemDeactivated, "C++: ImGui::IsItemDeactivated() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemDeactivatedAfterEdit() file:imgui.h line:632
	M("ImGui").def("IsItemDeactivatedAfterEdit", (bool (*)()) &ImGui::IsItemDeactivatedAfterEdit, "C++: ImGui::IsItemDeactivatedAfterEdit() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsAnyItemHovered() file:imgui.h line:633
	M("ImGui").def("IsAnyItemHovered", (bool (*)()) &ImGui::IsAnyItemHovered, "C++: ImGui::IsAnyItemHovered() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsAnyItemActive() file:imgui.h line:634
	M("ImGui").def("IsAnyItemActive", (bool (*)()) &ImGui::IsAnyItemActive, "C++: ImGui::IsAnyItemActive() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsAnyItemFocused() file:imgui.h line:635
	M("ImGui").def("IsAnyItemFocused", (bool (*)()) &ImGui::IsAnyItemFocused, "C++: ImGui::IsAnyItemFocused() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetItemRectMin() file:imgui.h line:636
	M("ImGui").def("GetItemRectMin", (struct ImVec2 (*)()) &ImGui::GetItemRectMin, "C++: ImGui::GetItemRectMin() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetItemRectMax() file:imgui.h line:637
	M("ImGui").def("GetItemRectMax", (struct ImVec2 (*)()) &ImGui::GetItemRectMax, "C++: ImGui::GetItemRectMax() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetItemRectSize() file:imgui.h line:638
	M("ImGui").def("GetItemRectSize", (struct ImVec2 (*)()) &ImGui::GetItemRectSize, "C++: ImGui::GetItemRectSize() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetItemAllowOverlap() file:imgui.h line:639
	M("ImGui").def("SetItemAllowOverlap", (void (*)()) &ImGui::SetItemAllowOverlap, "C++: ImGui::SetItemAllowOverlap() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsRectVisible(const struct ImVec2 &) file:imgui.h line:642
	M("ImGui").def("IsRectVisible", (bool (*)(const struct ImVec2 &)) &ImGui::IsRectVisible, "C++: ImGui::IsRectVisible(const struct ImVec2 &) --> bool", pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsRectVisible(const struct ImVec2 &, const struct ImVec2 &) file:imgui.h line:643
	M("ImGui").def("IsRectVisible", (bool (*)(const struct ImVec2 &, const struct ImVec2 &)) &ImGui::IsRectVisible, "C++: ImGui::IsRectVisible(const struct ImVec2 &, const struct ImVec2 &) --> bool", pybind11::arg("rect_min"), pybind11::arg("rect_max"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetTime() file:imgui.h line:644
	M("ImGui").def("GetTime", (double (*)()) &ImGui::GetTime, "C++: ImGui::GetTime() --> double", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetFrameCount() file:imgui.h line:645
	M("ImGui").def("GetFrameCount", (int (*)()) &ImGui::GetFrameCount, "C++: ImGui::GetFrameCount() --> int", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetBackgroundDrawList() file:imgui.h line:646
	M("ImGui").def("GetBackgroundDrawList", (struct ImDrawList * (*)()) &ImGui::GetBackgroundDrawList, "C++: ImGui::GetBackgroundDrawList() --> struct ImDrawList *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetForegroundDrawList() file:imgui.h line:647
	M("ImGui").def("GetForegroundDrawList", (struct ImDrawList * (*)()) &ImGui::GetForegroundDrawList, "C++: ImGui::GetForegroundDrawList() --> struct ImDrawList *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetDrawListSharedData() file:imgui.h line:648
	M("ImGui").def("GetDrawListSharedData", (struct ImDrawListSharedData * (*)()) &ImGui::GetDrawListSharedData, "C++: ImGui::GetDrawListSharedData() --> struct ImDrawListSharedData *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetStyleColorName(int) file:imgui.h line:649
	M("ImGui").def("GetStyleColorName", (const char * (*)(int)) &ImGui::GetStyleColorName, "C++: ImGui::GetStyleColorName(int) --> const char *", pybind11::return_value_policy::reference, pybind11::arg("idx"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetStateStorage(struct ImGuiStorage *) file:imgui.h line:650
	M("ImGui").def("SetStateStorage", (void (*)(struct ImGuiStorage *)) &ImGui::SetStateStorage, "C++: ImGui::SetStateStorage(struct ImGuiStorage *) --> void", pybind11::arg("storage"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetStateStorage() file:imgui.h line:651
	M("ImGui").def("GetStateStorage", (struct ImGuiStorage * (*)()) &ImGui::GetStateStorage, "C++: ImGui::GetStateStorage() --> struct ImGuiStorage *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CalcTextSize(const char *, const char *, bool, float) file:imgui.h line:652
	M("ImGui").def("CalcTextSize", [](const char * a0) -> ImVec2 { return ImGui::CalcTextSize(a0); }, "", pybind11::arg("text"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("CalcTextSize", [](const char * a0, const char * a1) -> ImVec2 { return ImGui::CalcTextSize(a0, a1); }, "", pybind11::arg("text"), pybind11::arg("text_end"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("CalcTextSize", [](const char * a0, const char * a1, bool const & a2) -> ImVec2 { return ImGui::CalcTextSize(a0, a1, a2); }, "", pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("hide_text_after_double_hash"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("CalcTextSize", (struct ImVec2 (*)(const char *, const char *, bool, float)) &ImGui::CalcTextSize, "C++: ImGui::CalcTextSize(const char *, const char *, bool, float) --> struct ImVec2", pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("hide_text_after_double_hash"), pybind11::arg("wrap_width"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CalcListClipping(int, float, int *, int *) file:imgui.h line:653
	M("ImGui").def("CalcListClipping", (void (*)(int, float, int *, int *)) &ImGui::CalcListClipping, "C++: ImGui::CalcListClipping(int, float, int *, int *) --> void", pybind11::arg("items_count"), pybind11::arg("items_height"), pybind11::arg("out_items_display_start"), pybind11::arg("out_items_display_end"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginChildFrame(unsigned int, const struct ImVec2 &, int) file:imgui.h line:654
	M("ImGui").def("BeginChildFrame", [](unsigned int const & a0, const struct ImVec2 & a1) -> bool { return ImGui::BeginChildFrame(a0, a1); }, "", pybind11::arg("id"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginChildFrame", (bool (*)(unsigned int, const struct ImVec2 &, int)) &ImGui::BeginChildFrame, "C++: ImGui::BeginChildFrame(unsigned int, const struct ImVec2 &, int) --> bool", pybind11::arg("id"), pybind11::arg("size"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndChildFrame() file:imgui.h line:655
	M("ImGui").def("EndChildFrame", (void (*)()) &ImGui::EndChildFrame, "C++: ImGui::EndChildFrame() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorConvertU32ToFloat4(unsigned int) file:imgui.h line:658
	M("ImGui").def("ColorConvertU32ToFloat4", (struct ImVec4 (*)(unsigned int)) &ImGui::ColorConvertU32ToFloat4, "C++: ImGui::ColorConvertU32ToFloat4(unsigned int) --> struct ImVec4", pybind11::arg("in"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorConvertFloat4ToU32(const struct ImVec4 &) file:imgui.h line:659
	M("ImGui").def("ColorConvertFloat4ToU32", (unsigned int (*)(const struct ImVec4 &)) &ImGui::ColorConvertFloat4ToU32, "C++: ImGui::ColorConvertFloat4ToU32(const struct ImVec4 &) --> unsigned int", pybind11::arg("in"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorConvertRGBtoHSV(float, float, float, float &, float &, float &) file:imgui.h line:660
	M("ImGui").def("ColorConvertRGBtoHSV", (void (*)(float, float, float, float &, float &, float &)) &ImGui::ColorConvertRGBtoHSV, "C++: ImGui::ColorConvertRGBtoHSV(float, float, float, float &, float &, float &) --> void", pybind11::arg("r"), pybind11::arg("g"), pybind11::arg("b"), pybind11::arg("out_h"), pybind11::arg("out_s"), pybind11::arg("out_v"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorConvertHSVtoRGB(float, float, float, float &, float &, float &) file:imgui.h line:661
	M("ImGui").def("ColorConvertHSVtoRGB", (void (*)(float, float, float, float &, float &, float &)) &ImGui::ColorConvertHSVtoRGB, "C++: ImGui::ColorConvertHSVtoRGB(float, float, float, float &, float &, float &) --> void", pybind11::arg("h"), pybind11::arg("s"), pybind11::arg("v"), pybind11::arg("out_r"), pybind11::arg("out_g"), pybind11::arg("out_b"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetKeyIndex(int) file:imgui.h line:664
	M("ImGui").def("GetKeyIndex", (int (*)(int)) &ImGui::GetKeyIndex, "C++: ImGui::GetKeyIndex(int) --> int", pybind11::arg("imgui_key"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsKeyDown(int) file:imgui.h line:665
	M("ImGui").def("IsKeyDown", (bool (*)(int)) &ImGui::IsKeyDown, "C++: ImGui::IsKeyDown(int) --> bool", pybind11::arg("user_key_index"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsKeyPressed(int, bool) file:imgui.h line:666
	M("ImGui").def("IsKeyPressed", [](int const & a0) -> bool { return ImGui::IsKeyPressed(a0); }, "", pybind11::arg("user_key_index"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsKeyPressed", (bool (*)(int, bool)) &ImGui::IsKeyPressed, "C++: ImGui::IsKeyPressed(int, bool) --> bool", pybind11::arg("user_key_index"), pybind11::arg("repeat"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_9.cpp
#include <imgui.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_9(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::IsKeyReleased(int) file:imgui.h line:667
	M("ImGui").def("IsKeyReleased", (bool (*)(int)) &ImGui::IsKeyReleased, "C++: ImGui::IsKeyReleased(int) --> bool", pybind11::arg("user_key_index"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetKeyPressedAmount(int, float, float) file:imgui.h line:668
	M("ImGui").def("GetKeyPressedAmount", (int (*)(int, float, float)) &ImGui::GetKeyPressedAmount, "C++: ImGui::GetKeyPressedAmount(int, float, float) --> int", pybind11::arg("key_index"), pybind11::arg("repeat_delay"), pybind11::arg("rate"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsMouseDown(int) file:imgui.h line:669
	M("ImGui").def("IsMouseDown", (bool (*)(int)) &ImGui::IsMouseDown, "C++: ImGui::IsMouseDown(int) --> bool", pybind11::arg("button"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsAnyMouseDown() file:imgui.h line:670
	M("ImGui").def("IsAnyMouseDown", (bool (*)()) &ImGui::IsAnyMouseDown, "C++: ImGui::IsAnyMouseDown() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsMouseClicked(int, bool) file:imgui.h line:671
	M("ImGui").def("IsMouseClicked", [](int const & a0) -> bool { return ImGui::IsMouseClicked(a0); }, "", pybind11::arg("button"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsMouseClicked", (bool (*)(int, bool)) &ImGui::IsMouseClicked, "C++: ImGui::IsMouseClicked(int, bool) --> bool", pybind11::arg("button"), pybind11::arg("repeat"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsMouseDoubleClicked(int) file:imgui.h line:672
	M("ImGui").def("IsMouseDoubleClicked", (bool (*)(int)) &ImGui::IsMouseDoubleClicked, "C++: ImGui::IsMouseDoubleClicked(int) --> bool", pybind11::arg("button"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsMouseReleased(int) file:imgui.h line:673
	M("ImGui").def("IsMouseReleased", (bool (*)(int)) &ImGui::IsMouseReleased, "C++: ImGui::IsMouseReleased(int) --> bool", pybind11::arg("button"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsMouseDragging(int, float) file:imgui.h line:674
	M("ImGui").def("IsMouseDragging", []() -> bool { return ImGui::IsMouseDragging(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsMouseDragging", [](int const & a0) -> bool { return ImGui::IsMouseDragging(a0); }, "", pybind11::arg("button"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsMouseDragging", (bool (*)(int, float)) &ImGui::IsMouseDragging, "C++: ImGui::IsMouseDragging(int, float) --> bool", pybind11::arg("button"), pybind11::arg("lock_threshold"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsMouseHoveringRect(const struct ImVec2 &, const struct ImVec2 &, bool) file:imgui.h line:675
	M("ImGui").def("IsMouseHoveringRect", [](const struct ImVec2 & a0, const struct ImVec2 & a1) -> bool { return ImGui::IsMouseHoveringRect(a0, a1); }, "", pybind11::arg("r_min"), pybind11::arg("r_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsMouseHoveringRect", (bool (*)(const struct ImVec2 &, const struct ImVec2 &, bool)) &ImGui::IsMouseHoveringRect, "C++: ImGui::IsMouseHoveringRect(const struct ImVec2 &, const struct ImVec2 &, bool) --> bool", pybind11::arg("r_min"), pybind11::arg("r_max"), pybind11::arg("clip"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsMousePosValid(const struct ImVec2 *) file:imgui.h line:676
	M("ImGui").def("IsMousePosValid", []() -> bool { return ImGui::IsMousePosValid(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsMousePosValid", (bool (*)(const struct ImVec2 *)) &ImGui::IsMousePosValid, "C++: ImGui::IsMousePosValid(const struct ImVec2 *) --> bool", pybind11::arg("mouse_pos"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetMousePos() file:imgui.h line:677
	M("ImGui").def("GetMousePos", (struct ImVec2 (*)()) &ImGui::GetMousePos, "C++: ImGui::GetMousePos() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetMousePosOnOpeningCurrentPopup() file:imgui.h line:678
	M("ImGui").def("GetMousePosOnOpeningCurrentPopup", (struct ImVec2 (*)()) &ImGui::GetMousePosOnOpeningCurrentPopup, "C++: ImGui::GetMousePosOnOpeningCurrentPopup() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetMouseDragDelta(int, float) file:imgui.h line:679
	M("ImGui").def("GetMouseDragDelta", []() -> ImVec2 { return ImGui::GetMouseDragDelta(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("GetMouseDragDelta", [](int const & a0) -> ImVec2 { return ImGui::GetMouseDragDelta(a0); }, "", pybind11::arg("button"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("GetMouseDragDelta", (struct ImVec2 (*)(int, float)) &ImGui::GetMouseDragDelta, "C++: ImGui::GetMouseDragDelta(int, float) --> struct ImVec2", pybind11::arg("button"), pybind11::arg("lock_threshold"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ResetMouseDragDelta(int) file:imgui.h line:680
	M("ImGui").def("ResetMouseDragDelta", []() -> void { return ImGui::ResetMouseDragDelta(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ResetMouseDragDelta", (void (*)(int)) &ImGui::ResetMouseDragDelta, "C++: ImGui::ResetMouseDragDelta(int) --> void", pybind11::arg("button"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetMouseCursor() file:imgui.h line:681
	M("ImGui").def("GetMouseCursor", (int (*)()) &ImGui::GetMouseCursor, "C++: ImGui::GetMouseCursor() --> int", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetMouseCursor(int) file:imgui.h line:682
	M("ImGui").def("SetMouseCursor", (void (*)(int)) &ImGui::SetMouseCursor, "C++: ImGui::SetMouseCursor(int) --> void", pybind11::arg("type"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CaptureKeyboardFromApp(bool) file:imgui.h line:683
	M("ImGui").def("CaptureKeyboardFromApp", []() -> void { return ImGui::CaptureKeyboardFromApp(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("CaptureKeyboardFromApp", (void (*)(bool)) &ImGui::CaptureKeyboardFromApp, "C++: ImGui::CaptureKeyboardFromApp(bool) --> void", pybind11::arg("want_capture_keyboard_value"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CaptureMouseFromApp(bool) file:imgui.h line:684
	M("ImGui").def("CaptureMouseFromApp", []() -> void { return ImGui::CaptureMouseFromApp(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("CaptureMouseFromApp", (void (*)(bool)) &ImGui::CaptureMouseFromApp, "C++: ImGui::CaptureMouseFromApp(bool) --> void", pybind11::arg("want_capture_mouse_value"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetClipboardText() file:imgui.h line:687
	M("ImGui").def("GetClipboardText", (const char * (*)()) &ImGui::GetClipboardText, "C++: ImGui::GetClipboardText() --> const char *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetClipboardText(const char *) file:imgui.h line:688
	M("ImGui").def("SetClipboardText", (void (*)(const char *)) &ImGui::SetClipboardText, "C++: ImGui::SetClipboardText(const char *) --> void", pybind11::arg("text"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LoadIniSettingsFromDisk(const char *) file:imgui.h line:693
	M("ImGui").def("LoadIniSettingsFromDisk", (void (*)(const char *)) &ImGui::LoadIniSettingsFromDisk, "C++: ImGui::LoadIniSettingsFromDisk(const char *) --> void", pybind11::arg("ini_filename"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LoadIniSettingsFromMemory(const char *, unsigned long) file:imgui.h line:694
	M("ImGui").def("LoadIniSettingsFromMemory", [](const char * a0) -> void { return ImGui::LoadIniSettingsFromMemory(a0); }, "", pybind11::arg("ini_data"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("LoadIniSettingsFromMemory", (void (*)(const char *, unsigned long)) &ImGui::LoadIniSettingsFromMemory, "C++: ImGui::LoadIniSettingsFromMemory(const char *, unsigned long) --> void", pybind11::arg("ini_data"), pybind11::arg("ini_size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SaveIniSettingsToDisk(const char *) file:imgui.h line:695
	M("ImGui").def("SaveIniSettingsToDisk", (void (*)(const char *)) &ImGui::SaveIniSettingsToDisk, "C++: ImGui::SaveIniSettingsToDisk(const char *) --> void", pybind11::arg("ini_filename"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SaveIniSettingsToMemory(unsigned long *) file:imgui.h line:696
	M("ImGui").def("SaveIniSettingsToMemory", []() -> const char * { return ImGui::SaveIniSettingsToMemory(); }, "", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SaveIniSettingsToMemory", (const char * (*)(unsigned long *)) &ImGui::SaveIniSettingsToMemory, "C++: ImGui::SaveIniSettingsToMemory(unsigned long *) --> const char *", pybind11::return_value_policy::reference, pybind11::arg("out_ini_size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::MemAlloc(unsigned long) file:imgui.h line:702
	M("ImGui").def("MemAlloc", (void * (*)(unsigned long)) &ImGui::MemAlloc, "C++: ImGui::MemAlloc(unsigned long) --> void *", pybind11::return_value_policy::reference, pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::MemFree(void *) file:imgui.h line:703
	M("ImGui").def("MemFree", (void (*)(void *)) &ImGui::MemFree, "C++: ImGui::MemFree(void *) --> void", pybind11::arg("ptr"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_10.cpp
#include <imgui.h>
#include <imgui_internal.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_10(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // ImGuiStyle file:imgui.h line:1290
		pybind11::class_<ImGuiStyle, std::shared_ptr<ImGuiStyle>> cl(M(""), "ImGuiStyle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiStyle(); } ) );
		cl.def( pybind11::init( [](ImGuiStyle const &o){ return new ImGuiStyle(o); } ) );
		cl.def_readwrite("Alpha", &ImGuiStyle::Alpha);
		cl.def_readwrite("WindowPadding", &ImGuiStyle::WindowPadding);
		cl.def_readwrite("WindowRounding", &ImGuiStyle::WindowRounding);
		cl.def_readwrite("WindowBorderSize", &ImGuiStyle::WindowBorderSize);
		cl.def_readwrite("WindowMinSize", &ImGuiStyle::WindowMinSize);
		cl.def_readwrite("WindowTitleAlign", &ImGuiStyle::WindowTitleAlign);
		cl.def_readwrite("WindowMenuButtonPosition", &ImGuiStyle::WindowMenuButtonPosition);
		cl.def_readwrite("ChildRounding", &ImGuiStyle::ChildRounding);
		cl.def_readwrite("ChildBorderSize", &ImGuiStyle::ChildBorderSize);
		cl.def_readwrite("PopupRounding", &ImGuiStyle::PopupRounding);
		cl.def_readwrite("PopupBorderSize", &ImGuiStyle::PopupBorderSize);
		cl.def_readwrite("FramePadding", &ImGuiStyle::FramePadding);
		cl.def_readwrite("FrameRounding", &ImGuiStyle::FrameRounding);
		cl.def_readwrite("FrameBorderSize", &ImGuiStyle::FrameBorderSize);
		cl.def_readwrite("ItemSpacing", &ImGuiStyle::ItemSpacing);
		cl.def_readwrite("ItemInnerSpacing", &ImGuiStyle::ItemInnerSpacing);
		cl.def_readwrite("TouchExtraPadding", &ImGuiStyle::TouchExtraPadding);
		cl.def_readwrite("IndentSpacing", &ImGuiStyle::IndentSpacing);
		cl.def_readwrite("ColumnsMinSpacing", &ImGuiStyle::ColumnsMinSpacing);
		cl.def_readwrite("ScrollbarSize", &ImGuiStyle::ScrollbarSize);
		cl.def_readwrite("ScrollbarRounding", &ImGuiStyle::ScrollbarRounding);
		cl.def_readwrite("GrabMinSize", &ImGuiStyle::GrabMinSize);
		cl.def_readwrite("GrabRounding", &ImGuiStyle::GrabRounding);
		cl.def_readwrite("TabRounding", &ImGuiStyle::TabRounding);
		cl.def_readwrite("TabBorderSize", &ImGuiStyle::TabBorderSize);
		cl.def_readwrite("ColorButtonPosition", &ImGuiStyle::ColorButtonPosition);
		cl.def_readwrite("ButtonTextAlign", &ImGuiStyle::ButtonTextAlign);
		cl.def_readwrite("SelectableTextAlign", &ImGuiStyle::SelectableTextAlign);
		cl.def_readwrite("DisplayWindowPadding", &ImGuiStyle::DisplayWindowPadding);
		cl.def_readwrite("DisplaySafeAreaPadding", &ImGuiStyle::DisplaySafeAreaPadding);
		cl.def_readwrite("MouseCursorScale", &ImGuiStyle::MouseCursorScale);
		cl.def_readwrite("AntiAliasedLines", &ImGuiStyle::AntiAliasedLines);
		cl.def_readwrite("AntiAliasedFill", &ImGuiStyle::AntiAliasedFill);
		cl.def_readwrite("CurveTessellationTol", &ImGuiStyle::CurveTessellationTol);
		cl.def("ScaleAllSizes", (void (ImGuiStyle::*)(float)) &ImGuiStyle::ScaleAllSizes, "C++: ImGuiStyle::ScaleAllSizes(float) --> void", pybind11::arg("scale_factor"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct ImGuiStyle & (ImGuiStyle::*)(const struct ImGuiStyle &)) &ImGuiStyle::operator=, "C++: ImGuiStyle::operator=(const struct ImGuiStyle &) --> struct ImGuiStyle &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImGuiIO file:imgui.h line:1338
		pybind11::class_<ImGuiIO, std::shared_ptr<ImGuiIO>> cl(M(""), "ImGuiIO", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiIO(); } ) );
		cl.def( pybind11::init( [](ImGuiIO const &o){ return new ImGuiIO(o); } ) );
		cl.def_readwrite("ConfigFlags", &ImGuiIO::ConfigFlags);
		cl.def_readwrite("BackendFlags", &ImGuiIO::BackendFlags);
		cl.def_readwrite("DisplaySize", &ImGuiIO::DisplaySize);
		cl.def_readwrite("DeltaTime", &ImGuiIO::DeltaTime);
		cl.def_readwrite("IniSavingRate", &ImGuiIO::IniSavingRate);
		cl.def_readwrite("MouseDoubleClickTime", &ImGuiIO::MouseDoubleClickTime);
		cl.def_readwrite("MouseDoubleClickMaxDist", &ImGuiIO::MouseDoubleClickMaxDist);
		cl.def_readwrite("MouseDragThreshold", &ImGuiIO::MouseDragThreshold);
		cl.def_readwrite("KeyRepeatDelay", &ImGuiIO::KeyRepeatDelay);
		cl.def_readwrite("KeyRepeatRate", &ImGuiIO::KeyRepeatRate);
		cl.def_readwrite("FontGlobalScale", &ImGuiIO::FontGlobalScale);
		cl.def_readwrite("FontAllowUserScaling", &ImGuiIO::FontAllowUserScaling);
		cl.def_readwrite("DisplayFramebufferScale", &ImGuiIO::DisplayFramebufferScale);
		cl.def_readwrite("MouseDrawCursor", &ImGuiIO::MouseDrawCursor);
		cl.def_readwrite("ConfigMacOSXBehaviors", &ImGuiIO::ConfigMacOSXBehaviors);
		cl.def_readwrite("ConfigInputTextCursorBlink", &ImGuiIO::ConfigInputTextCursorBlink);
		cl.def_readwrite("ConfigWindowsResizeFromEdges", &ImGuiIO::ConfigWindowsResizeFromEdges);
		cl.def_readwrite("ConfigWindowsMoveFromTitleBarOnly", &ImGuiIO::ConfigWindowsMoveFromTitleBarOnly);
		cl.def_readwrite("ConfigWindowsMemoryCompactTimer", &ImGuiIO::ConfigWindowsMemoryCompactTimer);
		cl.def_readwrite("MousePos", &ImGuiIO::MousePos);
		cl.def_readwrite("MouseWheel", &ImGuiIO::MouseWheel);
		cl.def_readwrite("MouseWheelH", &ImGuiIO::MouseWheelH);
		cl.def_readwrite("KeyCtrl", &ImGuiIO::KeyCtrl);
		cl.def_readwrite("KeyShift", &ImGuiIO::KeyShift);
		cl.def_readwrite("KeyAlt", &ImGuiIO::KeyAlt);
		cl.def_readwrite("KeySuper", &ImGuiIO::KeySuper);
		cl.def_readwrite("WantCaptureMouse", &ImGuiIO::WantCaptureMouse);
		cl.def_readwrite("WantCaptureKeyboard", &ImGuiIO::WantCaptureKeyboard);
		cl.def_readwrite("WantTextInput", &ImGuiIO::WantTextInput);
		cl.def_readwrite("WantSetMousePos", &ImGuiIO::WantSetMousePos);
		cl.def_readwrite("WantSaveIniSettings", &ImGuiIO::WantSaveIniSettings);
		cl.def_readwrite("NavActive", &ImGuiIO::NavActive);
		cl.def_readwrite("NavVisible", &ImGuiIO::NavVisible);
		cl.def_readwrite("Framerate", &ImGuiIO::Framerate);
		cl.def_readwrite("MetricsRenderVertices", &ImGuiIO::MetricsRenderVertices);
		cl.def_readwrite("MetricsRenderIndices", &ImGuiIO::MetricsRenderIndices);
		cl.def_readwrite("MetricsRenderWindows", &ImGuiIO::MetricsRenderWindows);
		cl.def_readwrite("MetricsActiveWindows", &ImGuiIO::MetricsActiveWindows);
		cl.def_readwrite("MetricsActiveAllocations", &ImGuiIO::MetricsActiveAllocations);
		cl.def_readwrite("MouseDelta", &ImGuiIO::MouseDelta);
		cl.def_readwrite("MousePosPrev", &ImGuiIO::MousePosPrev);
		cl.def_readwrite("InputQueueCharacters", &ImGuiIO::InputQueueCharacters);
		cl.def("AddInputCharacter", (void (ImGuiIO::*)(unsigned int)) &ImGuiIO::AddInputCharacter, "C++: ImGuiIO::AddInputCharacter(unsigned int) --> void", pybind11::arg("c"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddInputCharactersUTF8", (void (ImGuiIO::*)(const char *)) &ImGuiIO::AddInputCharactersUTF8, "C++: ImGuiIO::AddInputCharactersUTF8(const char *) --> void", pybind11::arg("str"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ClearInputCharacters", (void (ImGuiIO::*)()) &ImGuiIO::ClearInputCharacters, "C++: ImGuiIO::ClearInputCharacters() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct ImGuiIO & (ImGuiIO::*)(const struct ImGuiIO &)) &ImGuiIO::operator=, "C++: ImGuiIO::operator=(const struct ImGuiIO &) --> struct ImGuiIO &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImGuiPayload file:imgui.h line:1519
		pybind11::class_<ImGuiPayload, std::shared_ptr<ImGuiPayload>> cl(M(""), "ImGuiPayload", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiPayload(); } ) );
		cl.def( pybind11::init( [](ImGuiPayload const &o){ return new ImGuiPayload(o); } ) );
		cl.def_readwrite("DataSize", &ImGuiPayload::DataSize);
		cl.def_readwrite("SourceId", &ImGuiPayload::SourceId);
		cl.def_readwrite("SourceParentId", &ImGuiPayload::SourceParentId);
		cl.def_readwrite("DataFrameCount", &ImGuiPayload::DataFrameCount);
		cl.def_readwrite("Preview", &ImGuiPayload::Preview);
		cl.def_readwrite("Delivery", &ImGuiPayload::Delivery);
		cl.def("Clear", (void (ImGuiPayload::*)()) &ImGuiPayload::Clear, "C++: ImGuiPayload::Clear() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("IsDataType", (bool (ImGuiPayload::*)(const char *) const) &ImGuiPayload::IsDataType, "C++: ImGuiPayload::IsDataType(const char *) const --> bool", pybind11::arg("type"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("IsPreview", (bool (ImGuiPayload::*)() const) &ImGuiPayload::IsPreview, "C++: ImGuiPayload::IsPreview() const --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("IsDelivery", (bool (ImGuiPayload::*)() const) &ImGuiPayload::IsDelivery, "C++: ImGuiPayload::IsDelivery() const --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct ImGuiPayload & (ImGuiPayload::*)(const struct ImGuiPayload &)) &ImGuiPayload::operator=, "C++: ImGuiPayload::operator=(const struct ImGuiPayload &) --> struct ImGuiPayload &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImGuiStorage file:imgui.h line:1653
		pybind11::class_<ImGuiStorage, std::shared_ptr<ImGuiStorage>> cl(M(""), "ImGuiStorage", "");
		pybind11::handle cl_type = cl;

		{ // ImGuiStorage::ImGuiStoragePair file:imgui.h line:1656
			auto & enclosing_class = cl;
			pybind11::class_<ImGuiStorage::ImGuiStoragePair, std::shared_ptr<ImGuiStorage::ImGuiStoragePair>> cl(enclosing_class, "ImGuiStoragePair", "");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init<unsigned int, int>(), pybind11::arg("_key"), pybind11::arg("_val_i") );

			cl.def( pybind11::init<unsigned int, float>(), pybind11::arg("_key"), pybind11::arg("_val_f") );

			cl.def( pybind11::init<unsigned int, void *>(), pybind11::arg("_key"), pybind11::arg("_val_p") );

			cl.def_readwrite("key", &ImGuiStorage::ImGuiStoragePair::key);
//			cl.def_readwrite("", &ImGuiStorage::ImGuiStoragePair::);
		}

		cl.def( pybind11::init( [](ImGuiStorage const &o){ return new ImGuiStorage(o); } ) );
		cl.def( pybind11::init( [](){ return new ImGuiStorage(); } ) );
		cl.def_readwrite("Data", &ImGuiStorage::Data);
		cl.def("Clear", (void (ImGuiStorage::*)()) &ImGuiStorage::Clear, "C++: ImGuiStorage::Clear() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetInt", [](ImGuiStorage const &o, unsigned int const & a0) -> int { return o.GetInt(a0); }, "", pybind11::arg("key"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetInt", (int (ImGuiStorage::*)(unsigned int, int) const) &ImGuiStorage::GetInt, "C++: ImGuiStorage::GetInt(unsigned int, int) const --> int", pybind11::arg("key"), pybind11::arg("default_val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("SetInt", (void (ImGuiStorage::*)(unsigned int, int)) &ImGuiStorage::SetInt, "C++: ImGuiStorage::SetInt(unsigned int, int) --> void", pybind11::arg("key"), pybind11::arg("val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetBool", [](ImGuiStorage const &o, unsigned int const & a0) -> bool { return o.GetBool(a0); }, "", pybind11::arg("key"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetBool", (bool (ImGuiStorage::*)(unsigned int, bool) const) &ImGuiStorage::GetBool, "C++: ImGuiStorage::GetBool(unsigned int, bool) const --> bool", pybind11::arg("key"), pybind11::arg("default_val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("SetBool", (void (ImGuiStorage::*)(unsigned int, bool)) &ImGuiStorage::SetBool, "C++: ImGuiStorage::SetBool(unsigned int, bool) --> void", pybind11::arg("key"), pybind11::arg("val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetFloat", [](ImGuiStorage const &o, unsigned int const & a0) -> float { return o.GetFloat(a0); }, "", pybind11::arg("key"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetFloat", (float (ImGuiStorage::*)(unsigned int, float) const) &ImGuiStorage::GetFloat, "C++: ImGuiStorage::GetFloat(unsigned int, float) const --> float", pybind11::arg("key"), pybind11::arg("default_val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("SetFloat", (void (ImGuiStorage::*)(unsigned int, float)) &ImGuiStorage::SetFloat, "C++: ImGuiStorage::SetFloat(unsigned int, float) --> void", pybind11::arg("key"), pybind11::arg("val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetVoidPtr", (void * (ImGuiStorage::*)(unsigned int) const) &ImGuiStorage::GetVoidPtr, "C++: ImGuiStorage::GetVoidPtr(unsigned int) const --> void *", pybind11::return_value_policy::reference, pybind11::arg("key"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("SetVoidPtr", (void (ImGuiStorage::*)(unsigned int, void *)) &ImGuiStorage::SetVoidPtr, "C++: ImGuiStorage::SetVoidPtr(unsigned int, void *) --> void", pybind11::arg("key"), pybind11::arg("val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetIntRef", [](ImGuiStorage &o, unsigned int const & a0) -> int * { return o.GetIntRef(a0); }, "", pybind11::return_value_policy::reference, pybind11::arg("key"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetIntRef", (int * (ImGuiStorage::*)(unsigned int, int)) &ImGuiStorage::GetIntRef, "C++: ImGuiStorage::GetIntRef(unsigned int, int) --> int *", pybind11::return_value_policy::reference, pybind11::arg("key"), pybind11::arg("default_val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetBoolRef", [](ImGuiStorage &o, unsigned int const & a0) -> bool * { return o.GetBoolRef(a0); }, "", pybind11::return_value_policy::reference, pybind11::arg("key"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetBoolRef", (bool * (ImGuiStorage::*)(unsigned int, bool)) &ImGuiStorage::GetBoolRef, "C++: ImGuiStorage::GetBoolRef(unsigned int, bool) --> bool *", pybind11::return_value_policy::reference, pybind11::arg("key"), pybind11::arg("default_val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetFloatRef", [](ImGuiStorage &o, unsigned int const & a0) -> float * { return o.GetFloatRef(a0); }, "", pybind11::return_value_policy::reference, pybind11::arg("key"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetFloatRef", (float * (ImGuiStorage::*)(unsigned int, float)) &ImGuiStorage::GetFloatRef, "C++: ImGuiStorage::GetFloatRef(unsigned int, float) --> float *", pybind11::return_value_policy::reference, pybind11::arg("key"), pybind11::arg("default_val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("SetAllInt", (void (ImGuiStorage::*)(int)) &ImGuiStorage::SetAllInt, "C++: ImGuiStorage::SetAllInt(int) --> void", pybind11::arg("val"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("BuildSortByKey", (void (ImGuiStorage::*)()) &ImGuiStorage::BuildSortByKey, "C++: ImGuiStorage::BuildSortByKey() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct ImGuiStorage & (ImGuiStorage::*)(const struct ImGuiStorage &)) &ImGuiStorage::operator=, "C++: ImGuiStorage::operator=(const struct ImGuiStorage &) --> struct ImGuiStorage &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImDrawList file:imgui.h line:1881
		pybind11::class_<ImDrawList, std::shared_ptr<ImDrawList>> cl(M(""), "ImDrawList", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<const struct ImDrawListSharedData *>(), pybind11::arg("shared_data") );

		cl.def( pybind11::init( [](ImDrawList const &o){ return new ImDrawList(o); } ) );
		cl.def_readwrite("CmdBuffer", &ImDrawList::CmdBuffer);
		cl.def_readwrite("IdxBuffer", &ImDrawList::IdxBuffer);
		cl.def_readwrite("VtxBuffer", &ImDrawList::VtxBuffer);
		cl.def_readwrite("Flags", &ImDrawList::Flags);
		cl.def_readwrite("_VtxCurrentOffset", &ImDrawList::_VtxCurrentOffset);
		cl.def_readwrite("_VtxCurrentIdx", &ImDrawList::_VtxCurrentIdx);
		cl.def_readwrite("_ClipRectStack", &ImDrawList::_ClipRectStack);
		cl.def_readwrite("_TextureIdStack", &ImDrawList::_TextureIdStack);
		cl.def_readwrite("_Path", &ImDrawList::_Path);
		cl.def_readwrite("_Splitter", &ImDrawList::_Splitter);
		cl.def("PushClipRect", [](ImDrawList &o, struct ImVec2 const & a0, struct ImVec2 const & a1) -> void { return o.PushClipRect(a0, a1); }, "", pybind11::arg("clip_rect_min"), pybind11::arg("clip_rect_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PushClipRect", (void (ImDrawList::*)(struct ImVec2, struct ImVec2, bool)) &ImDrawList::PushClipRect, "C++: ImDrawList::PushClipRect(struct ImVec2, struct ImVec2, bool) --> void", pybind11::arg("clip_rect_min"), pybind11::arg("clip_rect_max"), pybind11::arg("intersect_with_current_clip_rect"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PushClipRectFullScreen", (void (ImDrawList::*)()) &ImDrawList::PushClipRectFullScreen, "C++: ImDrawList::PushClipRectFullScreen() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PopClipRect", (void (ImDrawList::*)()) &ImDrawList::PopClipRect, "C++: ImDrawList::PopClipRect() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PushTextureID", (void (ImDrawList::*)(void *)) &ImDrawList::PushTextureID, "C++: ImDrawList::PushTextureID(void *) --> void", pybind11::arg("texture_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PopTextureID", (void (ImDrawList::*)()) &ImDrawList::PopTextureID, "C++: ImDrawList::PopTextureID() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetClipRectMin", (struct ImVec2 (ImDrawList::*)() const) &ImDrawList::GetClipRectMin, "C++: ImDrawList::GetClipRectMin() const --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetClipRectMax", (struct ImVec2 (ImDrawList::*)() const) &ImDrawList::GetClipRectMax, "C++: ImDrawList::GetClipRectMax() const --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddLine", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, unsigned int const & a2) -> void { return o.AddLine(a0, a1, a2); }, "", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddLine", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, unsigned int, float)) &ImDrawList::AddLine, "C++: ImDrawList::AddLine(const struct ImVec2 &, const struct ImVec2 &, unsigned int, float) --> void", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("col"), pybind11::arg("thickness"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRect", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, unsigned int const & a2) -> void { return o.AddRect(a0, a1, a2); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRect", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, unsigned int const & a2, float const & a3) -> void { return o.AddRect(a0, a1, a2, a3); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("col"), pybind11::arg("rounding"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRect", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, unsigned int const & a2, float const & a3, int const & a4) -> void { return o.AddRect(a0, a1, a2, a3, a4); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("col"), pybind11::arg("rounding"), pybind11::arg("rounding_corners"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRect", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, unsigned int, float, int, float)) &ImDrawList::AddRect, "C++: ImDrawList::AddRect(const struct ImVec2 &, const struct ImVec2 &, unsigned int, float, int, float) --> void", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("col"), pybind11::arg("rounding"), pybind11::arg("rounding_corners"), pybind11::arg("thickness"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRectFilled", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, unsigned int const & a2) -> void { return o.AddRectFilled(a0, a1, a2); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRectFilled", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, unsigned int const & a2, float const & a3) -> void { return o.AddRectFilled(a0, a1, a2, a3); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("col"), pybind11::arg("rounding"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRectFilled", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, unsigned int, float, int)) &ImDrawList::AddRectFilled, "C++: ImDrawList::AddRectFilled(const struct ImVec2 &, const struct ImVec2 &, unsigned int, float, int) --> void", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("col"), pybind11::arg("rounding"), pybind11::arg("rounding_corners"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRectFilledMultiColor", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, unsigned int, unsigned int, unsigned int, unsigned int)) &ImDrawList::AddRectFilledMultiColor, "C++: ImDrawList::AddRectFilledMultiColor(const struct ImVec2 &, const struct ImVec2 &, unsigned int, unsigned int, unsigned int, unsigned int) --> void", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("col_upr_left"), pybind11::arg("col_upr_right"), pybind11::arg("col_bot_right"), pybind11::arg("col_bot_left"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddQuad", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, unsigned int const & a4) -> void { return o.AddQuad(a0, a1, a2, a3, a4); }, "", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("p4"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddQuad", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int, float)) &ImDrawList::AddQuad, "C++: ImDrawList::AddQuad(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int, float) --> void", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("p4"), pybind11::arg("col"), pybind11::arg("thickness"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddQuadFilled", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int)) &ImDrawList::AddQuadFilled, "C++: ImDrawList::AddQuadFilled(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int) --> void", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("p4"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddTriangle", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, const struct ImVec2 & a2, unsigned int const & a3) -> void { return o.AddTriangle(a0, a1, a2, a3); }, "", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddTriangle", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int, float)) &ImDrawList::AddTriangle, "C++: ImDrawList::AddTriangle(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int, float) --> void", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("col"), pybind11::arg("thickness"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddTriangleFilled", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int)) &ImDrawList::AddTriangleFilled, "C++: ImDrawList::AddTriangleFilled(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int) --> void", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddCircle", [](ImDrawList &o, const struct ImVec2 & a0, float const & a1, unsigned int const & a2) -> void { return o.AddCircle(a0, a1, a2); }, "", pybind11::arg("center"), pybind11::arg("radius"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddCircle", [](ImDrawList &o, const struct ImVec2 & a0, float const & a1, unsigned int const & a2, int const & a3) -> void { return o.AddCircle(a0, a1, a2, a3); }, "", pybind11::arg("center"), pybind11::arg("radius"), pybind11::arg("col"), pybind11::arg("num_segments"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddCircle", (void (ImDrawList::*)(const struct ImVec2 &, float, unsigned int, int, float)) &ImDrawList::AddCircle, "C++: ImDrawList::AddCircle(const struct ImVec2 &, float, unsigned int, int, float) --> void", pybind11::arg("center"), pybind11::arg("radius"), pybind11::arg("col"), pybind11::arg("num_segments"), pybind11::arg("thickness"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddCircleFilled", [](ImDrawList &o, const struct ImVec2 & a0, float const & a1, unsigned int const & a2) -> void { return o.AddCircleFilled(a0, a1, a2); }, "", pybind11::arg("center"), pybind11::arg("radius"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddCircleFilled", (void (ImDrawList::*)(const struct ImVec2 &, float, unsigned int, int)) &ImDrawList::AddCircleFilled, "C++: ImDrawList::AddCircleFilled(const struct ImVec2 &, float, unsigned int, int) --> void", pybind11::arg("center"), pybind11::arg("radius"), pybind11::arg("col"), pybind11::arg("num_segments"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddText", [](ImDrawList &o, const struct ImVec2 & a0, unsigned int const & a1, const char * a2) -> void { return o.AddText(a0, a1, a2); }, "", pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("text_begin"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddText", (void (ImDrawList::*)(const struct ImVec2 &, unsigned int, const char *, const char *)) &ImDrawList::AddText, "C++: ImDrawList::AddText(const struct ImVec2 &, unsigned int, const char *, const char *) --> void", pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("text_begin"), pybind11::arg("text_end"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddText", [](ImDrawList &o, const struct ImFont * a0, float const & a1, const struct ImVec2 & a2, unsigned int const & a3, const char * a4) -> void { return o.AddText(a0, a1, a2, a3, a4); }, "", pybind11::arg("font"), pybind11::arg("font_size"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("text_begin"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddText", [](ImDrawList &o, const struct ImFont * a0, float const & a1, const struct ImVec2 & a2, unsigned int const & a3, const char * a4, const char * a5) -> void { return o.AddText(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("font"), pybind11::arg("font_size"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("text_begin"), pybind11::arg("text_end"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddText", [](ImDrawList &o, const struct ImFont * a0, float const & a1, const struct ImVec2 & a2, unsigned int const & a3, const char * a4, const char * a5, float const & a6) -> void { return o.AddText(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("font"), pybind11::arg("font_size"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("text_begin"), pybind11::arg("text_end"), pybind11::arg("wrap_width"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddText", (void (ImDrawList::*)(const struct ImFont *, float, const struct ImVec2 &, unsigned int, const char *, const char *, float, const struct ImVec4 *)) &ImDrawList::AddText, "C++: ImDrawList::AddText(const struct ImFont *, float, const struct ImVec2 &, unsigned int, const char *, const char *, float, const struct ImVec4 *) --> void", pybind11::arg("font"), pybind11::arg("font_size"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("text_begin"), pybind11::arg("text_end"), pybind11::arg("wrap_width"), pybind11::arg("cpu_fine_clip_rect"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddPolyline", (void (ImDrawList::*)(const struct ImVec2 *, int, unsigned int, bool, float)) &ImDrawList::AddPolyline, "C++: ImDrawList::AddPolyline(const struct ImVec2 *, int, unsigned int, bool, float) --> void", pybind11::arg("points"), pybind11::arg("num_points"), pybind11::arg("col"), pybind11::arg("closed"), pybind11::arg("thickness"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddConvexPolyFilled", (void (ImDrawList::*)(const struct ImVec2 *, int, unsigned int)) &ImDrawList::AddConvexPolyFilled, "C++: ImDrawList::AddConvexPolyFilled(const struct ImVec2 *, int, unsigned int) --> void", pybind11::arg("points"), pybind11::arg("num_points"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddBezierCurve", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, unsigned int const & a4, float const & a5) -> void { return o.AddBezierCurve(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("pos0"), pybind11::arg("cp0"), pybind11::arg("cp1"), pybind11::arg("pos1"), pybind11::arg("col"), pybind11::arg("thickness"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddBezierCurve", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int, float, int)) &ImDrawList::AddBezierCurve, "C++: ImDrawList::AddBezierCurve(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int, float, int) --> void", pybind11::arg("pos0"), pybind11::arg("cp0"), pybind11::arg("cp1"), pybind11::arg("pos1"), pybind11::arg("col"), pybind11::arg("thickness"), pybind11::arg("num_segments"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImage", [](ImDrawList &o, void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2) -> void { return o.AddImage(a0, a1, a2); }, "", pybind11::arg("user_texture_id"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImage", [](ImDrawList &o, void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3) -> void { return o.AddImage(a0, a1, a2, a3); }, "", pybind11::arg("user_texture_id"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("uv_min"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImage", [](ImDrawList &o, void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, const struct ImVec2 & a4) -> void { return o.AddImage(a0, a1, a2, a3, a4); }, "", pybind11::arg("user_texture_id"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("uv_min"), pybind11::arg("uv_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImage", (void (ImDrawList::*)(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int)) &ImDrawList::AddImage, "C++: ImDrawList::AddImage(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int) --> void", pybind11::arg("user_texture_id"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("uv_min"), pybind11::arg("uv_max"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImageQuad", [](ImDrawList &o, void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, const struct ImVec2 & a4) -> void { return o.AddImageQuad(a0, a1, a2, a3, a4); }, "", pybind11::arg("user_texture_id"), pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("p4"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImageQuad", [](ImDrawList &o, void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, const struct ImVec2 & a5) -> void { return o.AddImageQuad(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("user_texture_id"), pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("p4"), pybind11::arg("uv1"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImageQuad", [](ImDrawList &o, void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, const struct ImVec2 & a5, const struct ImVec2 & a6) -> void { return o.AddImageQuad(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("user_texture_id"), pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("p4"), pybind11::arg("uv1"), pybind11::arg("uv2"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImageQuad", [](ImDrawList &o, void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, const struct ImVec2 & a5, const struct ImVec2 & a6, const struct ImVec2 & a7) -> void { return o.AddImageQuad(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("user_texture_id"), pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("p4"), pybind11::arg("uv1"), pybind11::arg("uv2"), pybind11::arg("uv3"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImageQuad", [](ImDrawList &o, void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, const struct ImVec2 & a5, const struct ImVec2 & a6, const struct ImVec2 & a7, const struct ImVec2 & a8) -> void { return o.AddImageQuad(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, "", pybind11::arg("user_texture_id"), pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("p4"), pybind11::arg("uv1"), pybind11::arg("uv2"), pybind11::arg("uv3"), pybind11::arg("uv4"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImageQuad", (void (ImDrawList::*)(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int)) &ImDrawList::AddImageQuad, "C++: ImDrawList::AddImageQuad(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int) --> void", pybind11::arg("user_texture_id"), pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("p4"), pybind11::arg("uv1"), pybind11::arg("uv2"), pybind11::arg("uv3"), pybind11::arg("uv4"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImageRounded", [](ImDrawList &o, void * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, unsigned int const & a5, float const & a6) -> void { return o.AddImageRounded(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("user_texture_id"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("uv_min"), pybind11::arg("uv_max"), pybind11::arg("col"), pybind11::arg("rounding"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddImageRounded", (void (ImDrawList::*)(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int, float, int)) &ImDrawList::AddImageRounded, "C++: ImDrawList::AddImageRounded(void *, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int, float, int) --> void", pybind11::arg("user_texture_id"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("uv_min"), pybind11::arg("uv_max"), pybind11::arg("col"), pybind11::arg("rounding"), pybind11::arg("rounding_corners"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathClear", (void (ImDrawList::*)()) &ImDrawList::PathClear, "C++: ImDrawList::PathClear() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathLineTo", (void (ImDrawList::*)(const struct ImVec2 &)) &ImDrawList::PathLineTo, "C++: ImDrawList::PathLineTo(const struct ImVec2 &) --> void", pybind11::arg("pos"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathLineToMergeDuplicate", (void (ImDrawList::*)(const struct ImVec2 &)) &ImDrawList::PathLineToMergeDuplicate, "C++: ImDrawList::PathLineToMergeDuplicate(const struct ImVec2 &) --> void", pybind11::arg("pos"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathFillConvex", (void (ImDrawList::*)(unsigned int)) &ImDrawList::PathFillConvex, "C++: ImDrawList::PathFillConvex(unsigned int) --> void", pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathStroke", [](ImDrawList &o, unsigned int const & a0, bool const & a1) -> void { return o.PathStroke(a0, a1); }, "", pybind11::arg("col"), pybind11::arg("closed"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathStroke", (void (ImDrawList::*)(unsigned int, bool, float)) &ImDrawList::PathStroke, "C++: ImDrawList::PathStroke(unsigned int, bool, float) --> void", pybind11::arg("col"), pybind11::arg("closed"), pybind11::arg("thickness"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathArcTo", [](ImDrawList &o, const struct ImVec2 & a0, float const & a1, float const & a2, float const & a3) -> void { return o.PathArcTo(a0, a1, a2, a3); }, "", pybind11::arg("center"), pybind11::arg("radius"), pybind11::arg("a_min"), pybind11::arg("a_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathArcTo", (void (ImDrawList::*)(const struct ImVec2 &, float, float, float, int)) &ImDrawList::PathArcTo, "C++: ImDrawList::PathArcTo(const struct ImVec2 &, float, float, float, int) --> void", pybind11::arg("center"), pybind11::arg("radius"), pybind11::arg("a_min"), pybind11::arg("a_max"), pybind11::arg("num_segments"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathArcToFast", (void (ImDrawList::*)(const struct ImVec2 &, float, int, int)) &ImDrawList::PathArcToFast, "C++: ImDrawList::PathArcToFast(const struct ImVec2 &, float, int, int) --> void", pybind11::arg("center"), pybind11::arg("radius"), pybind11::arg("a_min_of_12"), pybind11::arg("a_max_of_12"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathBezierCurveTo", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, const struct ImVec2 & a2) -> void { return o.PathBezierCurveTo(a0, a1, a2); }, "", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathBezierCurveTo", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int)) &ImDrawList::PathBezierCurveTo, "C++: ImDrawList::PathBezierCurveTo(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int) --> void", pybind11::arg("p1"), pybind11::arg("p2"), pybind11::arg("p3"), pybind11::arg("num_segments"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathRect", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1) -> void { return o.PathRect(a0, a1); }, "", pybind11::arg("rect_min"), pybind11::arg("rect_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathRect", [](ImDrawList &o, const struct ImVec2 & a0, const struct ImVec2 & a1, float const & a2) -> void { return o.PathRect(a0, a1, a2); }, "", pybind11::arg("rect_min"), pybind11::arg("rect_max"), pybind11::arg("rounding"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PathRect", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, float, int)) &ImDrawList::PathRect, "C++: ImDrawList::PathRect(const struct ImVec2 &, const struct ImVec2 &, float, int) --> void", pybind11::arg("rect_min"), pybind11::arg("rect_max"), pybind11::arg("rounding"), pybind11::arg("rounding_corners"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddDrawCmd", (void (ImDrawList::*)()) &ImDrawList::AddDrawCmd, "C++: ImDrawList::AddDrawCmd() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("CloneOutput", (struct ImDrawList * (ImDrawList::*)() const) &ImDrawList::CloneOutput, "C++: ImDrawList::CloneOutput() const --> struct ImDrawList *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ChannelsSplit", (void (ImDrawList::*)(int)) &ImDrawList::ChannelsSplit, "C++: ImDrawList::ChannelsSplit(int) --> void", pybind11::arg("count"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ChannelsMerge", (void (ImDrawList::*)()) &ImDrawList::ChannelsMerge, "C++: ImDrawList::ChannelsMerge() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ChannelsSetCurrent", (void (ImDrawList::*)(int)) &ImDrawList::ChannelsSetCurrent, "C++: ImDrawList::ChannelsSetCurrent(int) --> void", pybind11::arg("n"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Clear", (void (ImDrawList::*)()) &ImDrawList::Clear, "C++: ImDrawList::Clear() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ClearFreeMemory", (void (ImDrawList::*)()) &ImDrawList::ClearFreeMemory, "C++: ImDrawList::ClearFreeMemory() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PrimReserve", (void (ImDrawList::*)(int, int)) &ImDrawList::PrimReserve, "C++: ImDrawList::PrimReserve(int, int) --> void", pybind11::arg("idx_count"), pybind11::arg("vtx_count"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PrimRect", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, unsigned int)) &ImDrawList::PrimRect, "C++: ImDrawList::PrimRect(const struct ImVec2 &, const struct ImVec2 &, unsigned int) --> void", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PrimRectUV", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int)) &ImDrawList::PrimRectUV, "C++: ImDrawList::PrimRectUV(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int) --> void", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("uv_a"), pybind11::arg("uv_b"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PrimQuadUV", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int)) &ImDrawList::PrimQuadUV, "C++: ImDrawList::PrimQuadUV(const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, unsigned int) --> void", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"), pybind11::arg("d"), pybind11::arg("uv_a"), pybind11::arg("uv_b"), pybind11::arg("uv_c"), pybind11::arg("uv_d"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PrimWriteVtx", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, unsigned int)) &ImDrawList::PrimWriteVtx, "C++: ImDrawList::PrimWriteVtx(const struct ImVec2 &, const struct ImVec2 &, unsigned int) --> void", pybind11::arg("pos"), pybind11::arg("uv"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PrimWriteIdx", (void (ImDrawList::*)(unsigned short)) &ImDrawList::PrimWriteIdx, "C++: ImDrawList::PrimWriteIdx(unsigned short) --> void", pybind11::arg("idx"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("PrimVtx", (void (ImDrawList::*)(const struct ImVec2 &, const struct ImVec2 &, unsigned int)) &ImDrawList::PrimVtx, "C++: ImDrawList::PrimVtx(const struct ImVec2 &, const struct ImVec2 &, unsigned int) --> void", pybind11::arg("pos"), pybind11::arg("uv"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("UpdateClipRect", (void (ImDrawList::*)()) &ImDrawList::UpdateClipRect, "C++: ImDrawList::UpdateClipRect() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("UpdateTextureID", (void (ImDrawList::*)()) &ImDrawList::UpdateTextureID, "C++: ImDrawList::UpdateTextureID() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct ImDrawList & (ImDrawList::*)(const struct ImDrawList &)) &ImDrawList::operator=, "C++: ImDrawList::operator=(const struct ImDrawList &) --> struct ImDrawList &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
}


// File: imgui_11.cpp
#include <imgui.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_11(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // ImDrawData file:imgui.h line:1979
		pybind11::class_<ImDrawData, std::shared_ptr<ImDrawData>> cl(M(""), "ImDrawData", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImDrawData(); } ) );
		cl.def( pybind11::init( [](ImDrawData const &o){ return new ImDrawData(o); } ) );
		cl.def_readwrite("Valid", &ImDrawData::Valid);
		cl.def_readwrite("CmdListsCount", &ImDrawData::CmdListsCount);
		cl.def_readwrite("TotalIdxCount", &ImDrawData::TotalIdxCount);
		cl.def_readwrite("TotalVtxCount", &ImDrawData::TotalVtxCount);
		cl.def_readwrite("DisplayPos", &ImDrawData::DisplayPos);
		cl.def_readwrite("DisplaySize", &ImDrawData::DisplaySize);
		cl.def_readwrite("FramebufferScale", &ImDrawData::FramebufferScale);
		cl.def("Clear", (void (ImDrawData::*)()) &ImDrawData::Clear, "C++: ImDrawData::Clear() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("DeIndexAllBuffers", (void (ImDrawData::*)()) &ImDrawData::DeIndexAllBuffers, "C++: ImDrawData::DeIndexAllBuffers() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ScaleClipRects", (void (ImDrawData::*)(const struct ImVec2 &)) &ImDrawData::ScaleClipRects, "C++: ImDrawData::ScaleClipRects(const struct ImVec2 &) --> void", pybind11::arg("fb_scale"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct ImDrawData & (ImDrawData::*)(const struct ImDrawData &)) &ImDrawData::operator=, "C++: ImDrawData::operator=(const struct ImDrawData &) --> struct ImDrawData &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImFontConfig file:imgui.h line:2002
		pybind11::class_<ImFontConfig, std::shared_ptr<ImFontConfig>> cl(M(""), "ImFontConfig", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImFontConfig(); } ) );
		cl.def_readwrite("FontDataSize", &ImFontConfig::FontDataSize);
		cl.def_readwrite("FontDataOwnedByAtlas", &ImFontConfig::FontDataOwnedByAtlas);
		cl.def_readwrite("FontNo", &ImFontConfig::FontNo);
		cl.def_readwrite("SizePixels", &ImFontConfig::SizePixels);
		cl.def_readwrite("OversampleH", &ImFontConfig::OversampleH);
		cl.def_readwrite("OversampleV", &ImFontConfig::OversampleV);
		cl.def_readwrite("PixelSnapH", &ImFontConfig::PixelSnapH);
		cl.def_readwrite("GlyphExtraSpacing", &ImFontConfig::GlyphExtraSpacing);
		cl.def_readwrite("GlyphOffset", &ImFontConfig::GlyphOffset);
		cl.def_readwrite("GlyphMinAdvanceX", &ImFontConfig::GlyphMinAdvanceX);
		cl.def_readwrite("GlyphMaxAdvanceX", &ImFontConfig::GlyphMaxAdvanceX);
		cl.def_readwrite("MergeMode", &ImFontConfig::MergeMode);
		cl.def_readwrite("RasterizerFlags", &ImFontConfig::RasterizerFlags);
		cl.def_readwrite("RasterizerMultiply", &ImFontConfig::RasterizerMultiply);
		cl.def_readwrite("EllipsisChar", &ImFontConfig::EllipsisChar);
	}
	{ // ImFontGlyph file:imgui.h line:2029
		pybind11::class_<ImFontGlyph, std::shared_ptr<ImFontGlyph>> cl(M(""), "ImFontGlyph", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImFontGlyph(); } ) );
		cl.def_readwrite("Codepoint", &ImFontGlyph::Codepoint);
		cl.def_readwrite("AdvanceX", &ImFontGlyph::AdvanceX);
		cl.def_readwrite("X0", &ImFontGlyph::X0);
		cl.def_readwrite("Y0", &ImFontGlyph::Y0);
		cl.def_readwrite("X1", &ImFontGlyph::X1);
		cl.def_readwrite("Y1", &ImFontGlyph::Y1);
		cl.def_readwrite("U0", &ImFontGlyph::U0);
		cl.def_readwrite("V0", &ImFontGlyph::V0);
		cl.def_readwrite("U1", &ImFontGlyph::U1);
		cl.def_readwrite("V1", &ImFontGlyph::V1);
	}
	{ // ImFontAtlasCustomRect file:imgui.h line:2054
		pybind11::class_<ImFontAtlasCustomRect, std::shared_ptr<ImFontAtlasCustomRect>> cl(M(""), "ImFontAtlasCustomRect", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImFontAtlasCustomRect(); } ) );
		cl.def_readwrite("ID", &ImFontAtlasCustomRect::ID);
		cl.def_readwrite("Width", &ImFontAtlasCustomRect::Width);
		cl.def_readwrite("Height", &ImFontAtlasCustomRect::Height);
		cl.def_readwrite("X", &ImFontAtlasCustomRect::X);
		cl.def_readwrite("Y", &ImFontAtlasCustomRect::Y);
		cl.def_readwrite("GlyphAdvanceX", &ImFontAtlasCustomRect::GlyphAdvanceX);
		cl.def_readwrite("GlyphOffset", &ImFontAtlasCustomRect::GlyphOffset);
		cl.def("IsPacked", (bool (ImFontAtlasCustomRect::*)() const) &ImFontAtlasCustomRect::IsPacked, "C++: ImFontAtlasCustomRect::IsPacked() const --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImFontAtlas file:imgui.h line:2090
		pybind11::class_<ImFontAtlas, std::shared_ptr<ImFontAtlas>> cl(M(""), "ImFontAtlas", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImFontAtlas(); } ) );
		cl.def( pybind11::init( [](ImFontAtlas const &o){ return new ImFontAtlas(o); } ) );
		cl.def_readwrite("Locked", &ImFontAtlas::Locked);
		cl.def_readwrite("Flags", &ImFontAtlas::Flags);
		cl.def_readwrite("TexDesiredWidth", &ImFontAtlas::TexDesiredWidth);
		cl.def_readwrite("TexGlyphPadding", &ImFontAtlas::TexGlyphPadding);
		cl.def_readwrite("TexWidth", &ImFontAtlas::TexWidth);
		cl.def_readwrite("TexHeight", &ImFontAtlas::TexHeight);
		cl.def_readwrite("TexUvScale", &ImFontAtlas::TexUvScale);
		cl.def_readwrite("TexUvWhitePixel", &ImFontAtlas::TexUvWhitePixel);
		cl.def_readwrite("Fonts", &ImFontAtlas::Fonts);
		cl.def_readwrite("CustomRects", &ImFontAtlas::CustomRects);
		cl.def_readwrite("ConfigData", &ImFontAtlas::ConfigData);
		cl.def("AddFont", (struct ImFont * (ImFontAtlas::*)(const struct ImFontConfig *)) &ImFontAtlas::AddFont, "C++: ImFontAtlas::AddFont(const struct ImFontConfig *) --> struct ImFont *", pybind11::return_value_policy::reference, pybind11::arg("font_cfg"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontDefault", [](ImFontAtlas &o) -> ImFont * { return o.AddFontDefault(); }, "", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontDefault", (struct ImFont * (ImFontAtlas::*)(const struct ImFontConfig *)) &ImFontAtlas::AddFontDefault, "C++: ImFontAtlas::AddFontDefault(const struct ImFontConfig *) --> struct ImFont *", pybind11::return_value_policy::reference, pybind11::arg("font_cfg"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromFileTTF", [](ImFontAtlas &o, const char * a0, float const & a1) -> ImFont * { return o.AddFontFromFileTTF(a0, a1); }, "", pybind11::return_value_policy::reference, pybind11::arg("filename"), pybind11::arg("size_pixels"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromFileTTF", [](ImFontAtlas &o, const char * a0, float const & a1, const struct ImFontConfig * a2) -> ImFont * { return o.AddFontFromFileTTF(a0, a1, a2); }, "", pybind11::return_value_policy::reference, pybind11::arg("filename"), pybind11::arg("size_pixels"), pybind11::arg("font_cfg"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromFileTTF", (struct ImFont * (ImFontAtlas::*)(const char *, float, const struct ImFontConfig *, const unsigned short *)) &ImFontAtlas::AddFontFromFileTTF, "C++: ImFontAtlas::AddFontFromFileTTF(const char *, float, const struct ImFontConfig *, const unsigned short *) --> struct ImFont *", pybind11::return_value_policy::reference, pybind11::arg("filename"), pybind11::arg("size_pixels"), pybind11::arg("font_cfg"), pybind11::arg("glyph_ranges"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromMemoryTTF", [](ImFontAtlas &o, void * a0, int const & a1, float const & a2) -> ImFont * { return o.AddFontFromMemoryTTF(a0, a1, a2); }, "", pybind11::return_value_policy::reference, pybind11::arg("font_data"), pybind11::arg("font_size"), pybind11::arg("size_pixels"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromMemoryTTF", [](ImFontAtlas &o, void * a0, int const & a1, float const & a2, const struct ImFontConfig * a3) -> ImFont * { return o.AddFontFromMemoryTTF(a0, a1, a2, a3); }, "", pybind11::return_value_policy::reference, pybind11::arg("font_data"), pybind11::arg("font_size"), pybind11::arg("size_pixels"), pybind11::arg("font_cfg"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromMemoryTTF", (struct ImFont * (ImFontAtlas::*)(void *, int, float, const struct ImFontConfig *, const unsigned short *)) &ImFontAtlas::AddFontFromMemoryTTF, "C++: ImFontAtlas::AddFontFromMemoryTTF(void *, int, float, const struct ImFontConfig *, const unsigned short *) --> struct ImFont *", pybind11::return_value_policy::reference, pybind11::arg("font_data"), pybind11::arg("font_size"), pybind11::arg("size_pixels"), pybind11::arg("font_cfg"), pybind11::arg("glyph_ranges"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromMemoryCompressedTTF", [](ImFontAtlas &o, const void * a0, int const & a1, float const & a2) -> ImFont * { return o.AddFontFromMemoryCompressedTTF(a0, a1, a2); }, "", pybind11::return_value_policy::reference, pybind11::arg("compressed_font_data"), pybind11::arg("compressed_font_size"), pybind11::arg("size_pixels"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromMemoryCompressedTTF", [](ImFontAtlas &o, const void * a0, int const & a1, float const & a2, const struct ImFontConfig * a3) -> ImFont * { return o.AddFontFromMemoryCompressedTTF(a0, a1, a2, a3); }, "", pybind11::return_value_policy::reference, pybind11::arg("compressed_font_data"), pybind11::arg("compressed_font_size"), pybind11::arg("size_pixels"), pybind11::arg("font_cfg"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromMemoryCompressedTTF", (struct ImFont * (ImFontAtlas::*)(const void *, int, float, const struct ImFontConfig *, const unsigned short *)) &ImFontAtlas::AddFontFromMemoryCompressedTTF, "C++: ImFontAtlas::AddFontFromMemoryCompressedTTF(const void *, int, float, const struct ImFontConfig *, const unsigned short *) --> struct ImFont *", pybind11::return_value_policy::reference, pybind11::arg("compressed_font_data"), pybind11::arg("compressed_font_size"), pybind11::arg("size_pixels"), pybind11::arg("font_cfg"), pybind11::arg("glyph_ranges"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromMemoryCompressedBase85TTF", [](ImFontAtlas &o, const char * a0, float const & a1) -> ImFont * { return o.AddFontFromMemoryCompressedBase85TTF(a0, a1); }, "", pybind11::return_value_policy::reference, pybind11::arg("compressed_font_data_base85"), pybind11::arg("size_pixels"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromMemoryCompressedBase85TTF", [](ImFontAtlas &o, const char * a0, float const & a1, const struct ImFontConfig * a2) -> ImFont * { return o.AddFontFromMemoryCompressedBase85TTF(a0, a1, a2); }, "", pybind11::return_value_policy::reference, pybind11::arg("compressed_font_data_base85"), pybind11::arg("size_pixels"), pybind11::arg("font_cfg"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddFontFromMemoryCompressedBase85TTF", (struct ImFont * (ImFontAtlas::*)(const char *, float, const struct ImFontConfig *, const unsigned short *)) &ImFontAtlas::AddFontFromMemoryCompressedBase85TTF, "C++: ImFontAtlas::AddFontFromMemoryCompressedBase85TTF(const char *, float, const struct ImFontConfig *, const unsigned short *) --> struct ImFont *", pybind11::return_value_policy::reference, pybind11::arg("compressed_font_data_base85"), pybind11::arg("size_pixels"), pybind11::arg("font_cfg"), pybind11::arg("glyph_ranges"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ClearInputData", (void (ImFontAtlas::*)()) &ImFontAtlas::ClearInputData, "C++: ImFontAtlas::ClearInputData() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ClearTexData", (void (ImFontAtlas::*)()) &ImFontAtlas::ClearTexData, "C++: ImFontAtlas::ClearTexData() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ClearFonts", (void (ImFontAtlas::*)()) &ImFontAtlas::ClearFonts, "C++: ImFontAtlas::ClearFonts() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Clear", (void (ImFontAtlas::*)()) &ImFontAtlas::Clear, "C++: ImFontAtlas::Clear() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Build", (bool (ImFontAtlas::*)()) &ImFontAtlas::Build, "C++: ImFontAtlas::Build() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("IsBuilt", (bool (ImFontAtlas::*)()) &ImFontAtlas::IsBuilt, "C++: ImFontAtlas::IsBuilt() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("SetTexID", (void (ImFontAtlas::*)(void *)) &ImFontAtlas::SetTexID, "C++: ImFontAtlas::SetTexID(void *) --> void", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetGlyphRangesDefault", (const unsigned short * (ImFontAtlas::*)()) &ImFontAtlas::GetGlyphRangesDefault, "C++: ImFontAtlas::GetGlyphRangesDefault() --> const unsigned short *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetGlyphRangesKorean", (const unsigned short * (ImFontAtlas::*)()) &ImFontAtlas::GetGlyphRangesKorean, "C++: ImFontAtlas::GetGlyphRangesKorean() --> const unsigned short *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetGlyphRangesJapanese", (const unsigned short * (ImFontAtlas::*)()) &ImFontAtlas::GetGlyphRangesJapanese, "C++: ImFontAtlas::GetGlyphRangesJapanese() --> const unsigned short *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetGlyphRangesChineseFull", (const unsigned short * (ImFontAtlas::*)()) &ImFontAtlas::GetGlyphRangesChineseFull, "C++: ImFontAtlas::GetGlyphRangesChineseFull() --> const unsigned short *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetGlyphRangesChineseSimplifiedCommon", (const unsigned short * (ImFontAtlas::*)()) &ImFontAtlas::GetGlyphRangesChineseSimplifiedCommon, "C++: ImFontAtlas::GetGlyphRangesChineseSimplifiedCommon() --> const unsigned short *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetGlyphRangesCyrillic", (const unsigned short * (ImFontAtlas::*)()) &ImFontAtlas::GetGlyphRangesCyrillic, "C++: ImFontAtlas::GetGlyphRangesCyrillic() --> const unsigned short *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetGlyphRangesThai", (const unsigned short * (ImFontAtlas::*)()) &ImFontAtlas::GetGlyphRangesThai, "C++: ImFontAtlas::GetGlyphRangesThai() --> const unsigned short *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetGlyphRangesVietnamese", (const unsigned short * (ImFontAtlas::*)()) &ImFontAtlas::GetGlyphRangesVietnamese, "C++: ImFontAtlas::GetGlyphRangesVietnamese() --> const unsigned short *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddCustomRectRegular", (int (ImFontAtlas::*)(unsigned int, int, int)) &ImFontAtlas::AddCustomRectRegular, "C++: ImFontAtlas::AddCustomRectRegular(unsigned int, int, int) --> int", pybind11::arg("id"), pybind11::arg("width"), pybind11::arg("height"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddCustomRectFontGlyph", [](ImFontAtlas &o, struct ImFont * a0, unsigned short const & a1, int const & a2, int const & a3, float const & a4) -> int { return o.AddCustomRectFontGlyph(a0, a1, a2, a3, a4); }, "", pybind11::arg("font"), pybind11::arg("id"), pybind11::arg("width"), pybind11::arg("height"), pybind11::arg("advance_x"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddCustomRectFontGlyph", (int (ImFontAtlas::*)(struct ImFont *, unsigned short, int, int, float, const struct ImVec2 &)) &ImFontAtlas::AddCustomRectFontGlyph, "C++: ImFontAtlas::AddCustomRectFontGlyph(struct ImFont *, unsigned short, int, int, float, const struct ImVec2 &) --> int", pybind11::arg("font"), pybind11::arg("id"), pybind11::arg("width"), pybind11::arg("height"), pybind11::arg("advance_x"), pybind11::arg("offset"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetCustomRectByIndex", (const struct ImFontAtlasCustomRect * (ImFontAtlas::*)(int) const) &ImFontAtlas::GetCustomRectByIndex, "C++: ImFontAtlas::GetCustomRectByIndex(int) const --> const struct ImFontAtlasCustomRect *", pybind11::return_value_policy::reference, pybind11::arg("index"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("CalcCustomRectUV", (void (ImFontAtlas::*)(const struct ImFontAtlasCustomRect *, struct ImVec2 *, struct ImVec2 *)) &ImFontAtlas::CalcCustomRectUV, "C++: ImFontAtlas::CalcCustomRectUV(const struct ImFontAtlasCustomRect *, struct ImVec2 *, struct ImVec2 *) --> void", pybind11::arg("rect"), pybind11::arg("out_uv_min"), pybind11::arg("out_uv_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
}


// File: imgui_12.cpp
#include <imgui.h>
#include <imgui_internal.h>
#include <inttypes.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_12(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // ImFont file:imgui.h line:2180
		pybind11::class_<ImFont, std::shared_ptr<ImFont>> cl(M(""), "ImFont", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImFont(); } ) );
		cl.def( pybind11::init( [](ImFont const &o){ return new ImFont(o); } ) );
		cl.def_readwrite("IndexAdvanceX", &ImFont::IndexAdvanceX);
		cl.def_readwrite("FallbackAdvanceX", &ImFont::FallbackAdvanceX);
		cl.def_readwrite("FontSize", &ImFont::FontSize);
		cl.def_readwrite("IndexLookup", &ImFont::IndexLookup);
		cl.def_readwrite("Glyphs", &ImFont::Glyphs);
		cl.def_readwrite("DisplayOffset", &ImFont::DisplayOffset);
		cl.def_readwrite("ConfigDataCount", &ImFont::ConfigDataCount);
		cl.def_readwrite("FallbackChar", &ImFont::FallbackChar);
		cl.def_readwrite("EllipsisChar", &ImFont::EllipsisChar);
		cl.def_readwrite("Scale", &ImFont::Scale);
		cl.def_readwrite("Ascent", &ImFont::Ascent);
		cl.def_readwrite("Descent", &ImFont::Descent);
		cl.def_readwrite("MetricsTotalSurface", &ImFont::MetricsTotalSurface);
		cl.def_readwrite("DirtyLookupTables", &ImFont::DirtyLookupTables);
		cl.def("FindGlyph", (const struct ImFontGlyph * (ImFont::*)(unsigned short) const) &ImFont::FindGlyph, "C++: ImFont::FindGlyph(unsigned short) const --> const struct ImFontGlyph *", pybind11::return_value_policy::reference, pybind11::arg("c"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("FindGlyphNoFallback", (const struct ImFontGlyph * (ImFont::*)(unsigned short) const) &ImFont::FindGlyphNoFallback, "C++: ImFont::FindGlyphNoFallback(unsigned short) const --> const struct ImFontGlyph *", pybind11::return_value_policy::reference, pybind11::arg("c"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetCharAdvance", (float (ImFont::*)(unsigned short) const) &ImFont::GetCharAdvance, "C++: ImFont::GetCharAdvance(unsigned short) const --> float", pybind11::arg("c"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("IsLoaded", (bool (ImFont::*)() const) &ImFont::IsLoaded, "C++: ImFont::IsLoaded() const --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetDebugName", (const char * (ImFont::*)() const) &ImFont::GetDebugName, "C++: ImFont::GetDebugName() const --> const char *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("CalcWordWrapPositionA", (const char * (ImFont::*)(float, const char *, const char *, float) const) &ImFont::CalcWordWrapPositionA, "C++: ImFont::CalcWordWrapPositionA(float, const char *, const char *, float) const --> const char *", pybind11::return_value_policy::reference, pybind11::arg("scale"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("wrap_width"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("RenderChar", (void (ImFont::*)(struct ImDrawList *, float, struct ImVec2, unsigned int, unsigned short) const) &ImFont::RenderChar, "C++: ImFont::RenderChar(struct ImDrawList *, float, struct ImVec2, unsigned int, unsigned short) const --> void", pybind11::arg("draw_list"), pybind11::arg("size"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("c"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("RenderText", [](ImFont const &o, struct ImDrawList * a0, float const & a1, struct ImVec2 const & a2, unsigned int const & a3, const struct ImVec4 & a4, const char * a5, const char * a6) -> void { return o.RenderText(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("draw_list"), pybind11::arg("size"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("clip_rect"), pybind11::arg("text_begin"), pybind11::arg("text_end"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("RenderText", [](ImFont const &o, struct ImDrawList * a0, float const & a1, struct ImVec2 const & a2, unsigned int const & a3, const struct ImVec4 & a4, const char * a5, const char * a6, float const & a7) -> void { return o.RenderText(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("draw_list"), pybind11::arg("size"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("clip_rect"), pybind11::arg("text_begin"), pybind11::arg("text_end"), pybind11::arg("wrap_width"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("RenderText", (void (ImFont::*)(struct ImDrawList *, float, struct ImVec2, unsigned int, const struct ImVec4 &, const char *, const char *, float, bool) const) &ImFont::RenderText, "C++: ImFont::RenderText(struct ImDrawList *, float, struct ImVec2, unsigned int, const struct ImVec4 &, const char *, const char *, float, bool) const --> void", pybind11::arg("draw_list"), pybind11::arg("size"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("clip_rect"), pybind11::arg("text_begin"), pybind11::arg("text_end"), pybind11::arg("wrap_width"), pybind11::arg("cpu_fine_clip"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("BuildLookupTable", (void (ImFont::*)()) &ImFont::BuildLookupTable, "C++: ImFont::BuildLookupTable() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ClearOutputData", (void (ImFont::*)()) &ImFont::ClearOutputData, "C++: ImFont::ClearOutputData() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GrowIndex", (void (ImFont::*)(int)) &ImFont::GrowIndex, "C++: ImFont::GrowIndex(int) --> void", pybind11::arg("new_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddGlyph", (void (ImFont::*)(unsigned short, float, float, float, float, float, float, float, float, float)) &ImFont::AddGlyph, "C++: ImFont::AddGlyph(unsigned short, float, float, float, float, float, float, float, float, float) --> void", pybind11::arg("c"), pybind11::arg("x0"), pybind11::arg("y0"), pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("u0"), pybind11::arg("v0"), pybind11::arg("u1"), pybind11::arg("v1"), pybind11::arg("advance_x"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRemapChar", [](ImFont &o, unsigned short const & a0, unsigned short const & a1) -> void { return o.AddRemapChar(a0, a1); }, "", pybind11::arg("dst"), pybind11::arg("src"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("AddRemapChar", (void (ImFont::*)(unsigned short, unsigned short, bool)) &ImFont::AddRemapChar, "C++: ImFont::AddRemapChar(unsigned short, unsigned short, bool) --> void", pybind11::arg("dst"), pybind11::arg("src"), pybind11::arg("overwrite_dst"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("SetFallbackChar", (void (ImFont::*)(unsigned short)) &ImFont::SetFallbackChar, "C++: ImFont::SetFallbackChar(unsigned short) --> void", pybind11::arg("c"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct ImFont & (ImFont::*)(const struct ImFont &)) &ImFont::operator=, "C++: ImFont::operator=(const struct ImFont &) --> struct ImFont &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
}


// File: unknown/unknown.cpp
#include <imgui.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_13(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // ImGui::Font file: line:6
		pybind11::class_<ImGui::Font, std::shared_ptr<ImGui::Font>> cl(M("ImGui"), "Font", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGui::Font(); } ) );

		pybind11::enum_<ImGui::Font::Enum>(cl, "Enum", pybind11::arithmetic(), "")
			.value("Regular", ImGui::Font::Enum::Regular)
			.value("Mono", ImGui::Font::Enum::Mono)
			.value("Count", ImGui::Font::Enum::Count)
			.export_values();

	}
	// ImGui::PushFont(enum ImGui::Font::Enum) file: line:17
	M("ImGui").def("PushFont", (void (*)(enum ImGui::Font::Enum)) &ImGui::PushFont, "C++: ImGui::PushFont(enum ImGui::Font::Enum) --> void", pybind11::arg("_font"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // ImGui::ImString file: line:20
		pybind11::class_<ImGui::ImString, std::shared_ptr<ImGui::ImString>> cl(M("ImGui"), "ImString", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGui::ImString(); } ) );
		cl.def( pybind11::init( [](ImGui::ImString const &o){ return new ImGui::ImString(o); } ) );
		cl.def( pybind11::init<const char *>(), pybind11::arg("rhs") );

		cl.def("assign", (class ImGui::ImString & (ImGui::ImString::*)(const class ImGui::ImString &)) &ImGui::ImString::operator=, "C++: ImGui::ImString::operator=(const class ImGui::ImString &) --> class ImGui::ImString &", pybind11::return_value_policy::reference_internal, pybind11::arg("rhs"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (class ImGui::ImString & (ImGui::ImString::*)(const char *)) &ImGui::ImString::operator=, "C++: ImGui::ImString::operator=(const char *) --> class ImGui::ImString &", pybind11::return_value_policy::reference_internal, pybind11::arg("rhs"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Clear", (void (ImGui::ImString::*)()) &ImGui::ImString::Clear, "C++: ImGui::ImString::Clear() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("IsEmpty", (bool (ImGui::ImString::*)() const) &ImGui::ImString::IsEmpty, "C++: ImGui::ImString::IsEmpty() const --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("CStr", (const char * (ImGui::ImString::*)() const) &ImGui::ImString::CStr, "C++: ImGui::ImString::CStr() const --> const char *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	// ImGui::ColorPicker4(float *, bool) file: line:3
	M("ImGui").def("ColorPicker4", (bool (*)(float *, bool)) &ImGui::ColorPicker4, "C++: ImGui::ColorPicker4(float *, bool) --> bool", pybind11::arg("col"), pybind11::arg("show_alpha"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorEdit4(const char *, unsigned int *, bool) file: line:6
	M("ImGui").def("ColorEdit4", [](const char * a0, unsigned int * a1) -> bool { return ImGui::ColorEdit4(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("_rgba"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ColorEdit4", (bool (*)(const char *, unsigned int *, bool)) &ImGui::ColorEdit4, "C++: ImGui::ColorEdit4(const char *, unsigned int *, bool) --> bool", pybind11::arg("label"), pybind11::arg("_rgba"), pybind11::arg("show_alpha"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorWheel(const char *, float *, float) file: line:3
	M("ImGui").def("ColorWheel", (void (*)(const char *, float *, float)) &ImGui::ColorWheel, "C++: ImGui::ColorWheel(const char *, float *, float) --> void", pybind11::arg("_text"), pybind11::arg("_rgba"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorWheel(const char *, unsigned int *, float) file: line:5
	M("ImGui").def("ColorWheel", (void (*)(const char *, unsigned int *, float)) &ImGui::ColorWheel, "C++: ImGui::ColorWheel(const char *, unsigned int *, float) --> void", pybind11::arg("_text"), pybind11::arg("_rgba"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::InitDockContext() file: line:4
	M("ImGui").def("InitDockContext", (void (*)()) &ImGui::InitDockContext, "C++: ImGui::InitDockContext() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShutdownDockContext() file: line:7
	M("ImGui").def("ShutdownDockContext", (void (*)()) &ImGui::ShutdownDockContext, "C++: ImGui::ShutdownDockContext() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RootDock(const struct ImVec2 &, const struct ImVec2 &) file: line:10
	M("ImGui").def("RootDock", (void (*)(const struct ImVec2 &, const struct ImVec2 &)) &ImGui::RootDock, "C++: ImGui::RootDock(const struct ImVec2 &, const struct ImVec2 &) --> void", pybind11::arg("pos"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginDock(const char *, bool *, int) file: line:13
	M("ImGui").def("BeginDock", [](const char * a0) -> bool { return ImGui::BeginDock(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginDock", [](const char * a0, bool * a1) -> bool { return ImGui::BeginDock(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("opened"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginDock", (bool (*)(const char *, bool *, int)) &ImGui::BeginDock, "C++: ImGui::BeginDock(const char *, bool *, int) --> bool", pybind11::arg("label"), pybind11::arg("opened"), pybind11::arg("extra_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndDock() file: line:16
	M("ImGui").def("EndDock", (void (*)()) &ImGui::EndDock, "C++: ImGui::EndDock() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetDockActive() file: line:19
	M("ImGui").def("SetDockActive", (void (*)()) &ImGui::SetDockActive, "C++: ImGui::SetDockActive() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // ImGui::ImFileInfo file: line:3
		pybind11::class_<ImGui::ImFileInfo, std::shared_ptr<ImGui::ImFileInfo>> cl(M("ImGui"), "ImFileInfo", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<const char *, long long>(), pybind11::arg("name"), pybind11::arg("size") );

		cl.def_readwrite("Name", &ImGui::ImFileInfo::Name);
		cl.def_readwrite("Size", &ImGui::ImFileInfo::Size);
	}
	{ // ImGui::ImFileList file: line:12
		pybind11::class_<ImGui::ImFileList, std::shared_ptr<ImGui::ImFileList>> cl(M("ImGui"), "ImFileList", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGui::ImFileList(); } ), "doc" );
		cl.def( pybind11::init<const char *>(), pybind11::arg("path") );

		cl.def_readwrite("FileList", &ImGui::ImFileList::FileList);
		cl.def_readwrite("Pos", &ImGui::ImFileList::Pos);
		cl.def("ChDir", (void (ImGui::ImFileList::*)(const char *)) &ImGui::ImFileList::ChDir, "C++: ImGui::ImFileList::ChDir(const char *) --> void", pybind11::arg("path"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Draw", (void (ImGui::ImFileList::*)()) &ImGui::ImFileList::Draw, "C++: ImGui::ImFileList::Draw() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
	}
}


// File: unknown/unknown_1.cpp

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_14(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGuizmo::SetDrawlist() file: line:109
	M("ImGuizmo").def("SetDrawlist", (void (*)()) &ImGuizmo::SetDrawlist, "C++: ImGuizmo::SetDrawlist() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::BeginFrame() file: line:112
	M("ImGuizmo").def("BeginFrame", (void (*)()) &ImGuizmo::BeginFrame, "C++: ImGuizmo::BeginFrame() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::IsOver() file: line:115
	M("ImGuizmo").def("IsOver", (bool (*)()) &ImGuizmo::IsOver, "C++: ImGuizmo::IsOver() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::IsUsing() file: line:118
	M("ImGuizmo").def("IsUsing", (bool (*)()) &ImGuizmo::IsUsing, "C++: ImGuizmo::IsUsing() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::Enable(bool) file: line:122
	M("ImGuizmo").def("Enable", (void (*)(bool)) &ImGuizmo::Enable, "C++: ImGuizmo::Enable(bool) --> void", pybind11::arg("enable"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::DecomposeMatrixToComponents(const float *, float *, float *, float *) file: line:136
	M("ImGuizmo").def("DecomposeMatrixToComponents", (void (*)(const float *, float *, float *, float *)) &ImGuizmo::DecomposeMatrixToComponents, "C++: ImGuizmo::DecomposeMatrixToComponents(const float *, float *, float *, float *) --> void", pybind11::arg("matrix"), pybind11::arg("translation"), pybind11::arg("rotation"), pybind11::arg("scale"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::RecomposeMatrixFromComponents(const float *, const float *, const float *, float *) file: line:137
	M("ImGuizmo").def("RecomposeMatrixFromComponents", (void (*)(const float *, const float *, const float *, float *)) &ImGuizmo::RecomposeMatrixFromComponents, "C++: ImGuizmo::RecomposeMatrixFromComponents(const float *, const float *, const float *, float *) --> void", pybind11::arg("translation"), pybind11::arg("rotation"), pybind11::arg("scale"), pybind11::arg("matrix"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::SetRect(float, float, float, float) file: line:139
	M("ImGuizmo").def("SetRect", (void (*)(float, float, float, float)) &ImGuizmo::SetRect, "C++: ImGuizmo::SetRect(float, float, float, float) --> void", pybind11::arg("x"), pybind11::arg("y"), pybind11::arg("width"), pybind11::arg("height"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::SetOrthographic(bool) file: line:141
	M("ImGuizmo").def("SetOrthographic", (void (*)(bool)) &ImGuizmo::SetOrthographic, "C++: ImGuizmo::SetOrthographic(bool) --> void", pybind11::arg("isOrthographic"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::DrawCube(const float *, const float *, const float *) file: line:144
	M("ImGuizmo").def("DrawCube", (void (*)(const float *, const float *, const float *)) &ImGuizmo::DrawCube, "C++: ImGuizmo::DrawCube(const float *, const float *, const float *) --> void", pybind11::arg("view"), pybind11::arg("projection"), pybind11::arg("matrix"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::DrawGrid(const float *, const float *, const float *, const float) file: line:145
	M("ImGuizmo").def("DrawGrid", (void (*)(const float *, const float *, const float *, const float)) &ImGuizmo::DrawGrid, "C++: ImGuizmo::DrawGrid(const float *, const float *, const float *, const float) --> void", pybind11::arg("view"), pybind11::arg("projection"), pybind11::arg("matrix"), pybind11::arg("gridSize"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGuizmo::OPERATION file: line:151
	pybind11::enum_<ImGuizmo::OPERATION>(M("ImGuizmo"), "OPERATION", pybind11::arithmetic(), "")
		.value("TRANSLATE", ImGuizmo::OPERATION::TRANSLATE)
		.value("ROTATE", ImGuizmo::OPERATION::ROTATE)
		.value("SCALE", ImGuizmo::OPERATION::SCALE)
		.value("BOUNDS", ImGuizmo::OPERATION::BOUNDS)
		.export_values();

;

	// ImGuizmo::MODE file: line:159
	pybind11::enum_<ImGuizmo::MODE>(M("ImGuizmo"), "MODE", pybind11::arithmetic(), "")
		.value("LOCAL", ImGuizmo::MODE::LOCAL)
		.value("WORLD", ImGuizmo::MODE::WORLD)
		.export_values();

;

	// ImGuizmo::Manipulate(const float *, const float *, enum ImGuizmo::OPERATION, enum ImGuizmo::MODE, float *, float *, float *, float *, float *) file: line:165
	M("ImGuizmo").def("Manipulate", [](const float * a0, const float * a1, enum ImGuizmo::OPERATION const & a2, enum ImGuizmo::MODE const & a3, float * a4) -> void { return ImGuizmo::Manipulate(a0, a1, a2, a3, a4); }, "", pybind11::arg("view"), pybind11::arg("projection"), pybind11::arg("operation"), pybind11::arg("mode"), pybind11::arg("matrix"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuizmo").def("Manipulate", [](const float * a0, const float * a1, enum ImGuizmo::OPERATION const & a2, enum ImGuizmo::MODE const & a3, float * a4, float * a5) -> void { return ImGuizmo::Manipulate(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("view"), pybind11::arg("projection"), pybind11::arg("operation"), pybind11::arg("mode"), pybind11::arg("matrix"), pybind11::arg("deltaMatrix"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuizmo").def("Manipulate", [](const float * a0, const float * a1, enum ImGuizmo::OPERATION const & a2, enum ImGuizmo::MODE const & a3, float * a4, float * a5, float * a6) -> void { return ImGuizmo::Manipulate(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("view"), pybind11::arg("projection"), pybind11::arg("operation"), pybind11::arg("mode"), pybind11::arg("matrix"), pybind11::arg("deltaMatrix"), pybind11::arg("snap"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuizmo").def("Manipulate", [](const float * a0, const float * a1, enum ImGuizmo::OPERATION const & a2, enum ImGuizmo::MODE const & a3, float * a4, float * a5, float * a6, float * a7) -> void { return ImGuizmo::Manipulate(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("view"), pybind11::arg("projection"), pybind11::arg("operation"), pybind11::arg("mode"), pybind11::arg("matrix"), pybind11::arg("deltaMatrix"), pybind11::arg("snap"), pybind11::arg("localBounds"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuizmo").def("Manipulate", (void (*)(const float *, const float *, enum ImGuizmo::OPERATION, enum ImGuizmo::MODE, float *, float *, float *, float *, float *)) &ImGuizmo::Manipulate, "C++: ImGuizmo::Manipulate(const float *, const float *, enum ImGuizmo::OPERATION, enum ImGuizmo::MODE, float *, float *, float *, float *, float *) --> void", pybind11::arg("view"), pybind11::arg("projection"), pybind11::arg("operation"), pybind11::arg("mode"), pybind11::arg("matrix"), pybind11::arg("deltaMatrix"), pybind11::arg("snap"), pybind11::arg("localBounds"), pybind11::arg("boundsSnap"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: unknown/unknown_2.cpp
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_15(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // ImGui::MarkdownConfig file: line:132
		pybind11::class_<ImGui::MarkdownConfig, std::shared_ptr<ImGui::MarkdownConfig>> cl(M("ImGui"), "MarkdownConfig", "");
		pybind11::handle cl_type = cl;

		{ // ImGui::MarkdownConfig::HeadingFormat file: line:135
			auto & enclosing_class = cl;
			pybind11::class_<ImGui::MarkdownConfig::HeadingFormat, std::shared_ptr<ImGui::MarkdownConfig::HeadingFormat>> cl(enclosing_class, "HeadingFormat", "");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init( [](){ return new ImGui::MarkdownConfig::HeadingFormat(); } ) );
			cl.def_readwrite("separator", &ImGui::MarkdownConfig::HeadingFormat::separator);
		}

		cl.def( pybind11::init( [](){ return new ImGui::MarkdownConfig(); } ) );
	}
	// ImGui::Markdown(const char *, int, const struct ImGui::MarkdownConfig &) file: line:145
	M("ImGui").def("Markdown", (void (*)(const char *, int, const struct ImGui::MarkdownConfig &)) &ImGui::Markdown, "C++: ImGui::Markdown(const char *, int, const struct ImGui::MarkdownConfig &) --> void", pybind11::arg("markdown_"), pybind11::arg("markdownLength_"), pybind11::arg("mdConfig_"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // ImGui::MemoryEditor file: line:3
		pybind11::class_<ImGui::MemoryEditor, std::shared_ptr<ImGui::MemoryEditor>> cl(M("ImGui"), "MemoryEditor", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGui::MemoryEditor(); } ) );
		cl.def_readwrite("AllowEdits", &ImGui::MemoryEditor::AllowEdits);
		cl.def_readwrite("HexII", &ImGui::MemoryEditor::HexII);
		cl.def_readwrite("Rows", &ImGui::MemoryEditor::Rows);
		cl.def_readwrite("DataEditingAddr", &ImGui::MemoryEditor::DataEditingAddr);
		cl.def_readwrite("DataEditingTakeFocus", &ImGui::MemoryEditor::DataEditingTakeFocus);
		cl.def("Draw", [](ImGui::MemoryEditor &o, void * a0, int const & a1) -> void { return o.Draw(a0, a1); }, "", pybind11::arg("mem_data"), pybind11::arg("mem_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Draw", (void (ImGui::MemoryEditor::*)(void *, int, int)) &ImGui::MemoryEditor::Draw, "C++: ImGui::MemoryEditor::Draw(void *, int, int) --> void", pybind11::arg("mem_data"), pybind11::arg("mem_size"), pybind11::arg("base_display_addr"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Draw", [](ImGui::MemoryEditor &o, const void * a0, int const & a1) -> void { return o.Draw(a0, a1); }, "", pybind11::arg("mem_data"), pybind11::arg("mem_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Draw", (void (ImGui::MemoryEditor::*)(const void *, int, int)) &ImGui::MemoryEditor::Draw, "C++: ImGui::MemoryEditor::Draw(const void *, int, int) --> void", pybind11::arg("mem_data"), pybind11::arg("mem_size"), pybind11::arg("base_display_addr"), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	// ImGui::RangeSliderFloat(const char *, float *, float *, float, float, const char *, float) file: line:3
	M("ImGui").def("RangeSliderFloat", [](const char * a0, float * a1, float * a2, float const & a3, float const & a4) -> bool { return ImGui::RangeSliderFloat(a0, a1, a2, a3, a4); }, "", pybind11::arg("label"), pybind11::arg("v1"), pybind11::arg("v2"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RangeSliderFloat", [](const char * a0, float * a1, float * a2, float const & a3, float const & a4, const char * a5) -> bool { return ImGui::RangeSliderFloat(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("label"), pybind11::arg("v1"), pybind11::arg("v2"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("display_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RangeSliderFloat", (bool (*)(const char *, float *, float *, float, float, const char *, float)) &ImGui::RangeSliderFloat, "C++: ImGui::RangeSliderFloat(const char *, float *, float *, float, float, const char *, float) --> bool", pybind11::arg("label"), pybind11::arg("v1"), pybind11::arg("v2"), pybind11::arg("v_min"), pybind11::arg("v_max"), pybind11::arg("display_format"), pybind11::arg("power"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_internal.cpp
#include <imgui.h>
#include <imgui_internal.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_internal(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGuiLogType file:imgui_internal.h line:431
	pybind11::enum_<ImGuiLogType>(M(""), "ImGuiLogType", pybind11::arithmetic(), "")
		.value("ImGuiLogType_None", ImGuiLogType::ImGuiLogType_None)
		.value("ImGuiLogType_TTY", ImGuiLogType::ImGuiLogType_TTY)
		.value("ImGuiLogType_File", ImGuiLogType::ImGuiLogType_File)
		.value("ImGuiLogType_Buffer", ImGuiLogType::ImGuiLogType_Buffer)
		.value("ImGuiLogType_Clipboard", ImGuiLogType::ImGuiLogType_Clipboard)
		.export_values();

;

	// ImGuiAxis file:imgui_internal.h line:441
	pybind11::enum_<ImGuiAxis>(M(""), "ImGuiAxis", pybind11::arithmetic(), "")
		.value("ImGuiAxis_None", ImGuiAxis::ImGuiAxis_None)
		.value("ImGuiAxis_X", ImGuiAxis::ImGuiAxis_X)
		.value("ImGuiAxis_Y", ImGuiAxis::ImGuiAxis_Y)
		.export_values();

;

	// ImGuiInputReadMode file:imgui_internal.h line:465
	pybind11::enum_<ImGuiInputReadMode>(M(""), "ImGuiInputReadMode", pybind11::arithmetic(), "")
		.value("ImGuiInputReadMode_Down", ImGuiInputReadMode::ImGuiInputReadMode_Down)
		.value("ImGuiInputReadMode_Pressed", ImGuiInputReadMode::ImGuiInputReadMode_Pressed)
		.value("ImGuiInputReadMode_Released", ImGuiInputReadMode::ImGuiInputReadMode_Released)
		.value("ImGuiInputReadMode_Repeat", ImGuiInputReadMode::ImGuiInputReadMode_Repeat)
		.value("ImGuiInputReadMode_RepeatSlow", ImGuiInputReadMode::ImGuiInputReadMode_RepeatSlow)
		.value("ImGuiInputReadMode_RepeatFast", ImGuiInputReadMode::ImGuiInputReadMode_RepeatFast)
		.export_values();

;

	// ImGuiPopupPositionPolicy file:imgui_internal.h line:518
	pybind11::enum_<ImGuiPopupPositionPolicy>(M(""), "ImGuiPopupPositionPolicy", pybind11::arithmetic(), "")
		.value("ImGuiPopupPositionPolicy_Default", ImGuiPopupPositionPolicy::ImGuiPopupPositionPolicy_Default)
		.value("ImGuiPopupPositionPolicy_ComboBox", ImGuiPopupPositionPolicy::ImGuiPopupPositionPolicy_ComboBox)
		.export_values();

;

	{ // ImRect file:imgui_internal.h line:542
		pybind11::class_<ImRect, std::shared_ptr<ImRect>> cl(M(""), "ImRect", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImRect(); } ) );
		cl.def( pybind11::init<const struct ImVec2 &, const struct ImVec2 &>(), pybind11::arg("min"), pybind11::arg("max") );

		cl.def( pybind11::init<const struct ImVec4 &>(), pybind11::arg("v") );

		cl.def( pybind11::init<float, float, float, float>(), pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("x2"), pybind11::arg("y2") );

		cl.def( pybind11::init( [](ImRect const &o){ return new ImRect(o); } ) );
		cl.def_readwrite("Min", &ImRect::Min);
		cl.def_readwrite("Max", &ImRect::Max);
		cl.def("GetCenter", (struct ImVec2 (ImRect::*)() const) &ImRect::GetCenter, "C++: ImRect::GetCenter() const --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetSize", (struct ImVec2 (ImRect::*)() const) &ImRect::GetSize, "C++: ImRect::GetSize() const --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetWidth", (float (ImRect::*)() const) &ImRect::GetWidth, "C++: ImRect::GetWidth() const --> float", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetHeight", (float (ImRect::*)() const) &ImRect::GetHeight, "C++: ImRect::GetHeight() const --> float", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetTL", (struct ImVec2 (ImRect::*)() const) &ImRect::GetTL, "C++: ImRect::GetTL() const --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetTR", (struct ImVec2 (ImRect::*)() const) &ImRect::GetTR, "C++: ImRect::GetTR() const --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetBL", (struct ImVec2 (ImRect::*)() const) &ImRect::GetBL, "C++: ImRect::GetBL() const --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetBR", (struct ImVec2 (ImRect::*)() const) &ImRect::GetBR, "C++: ImRect::GetBR() const --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Contains", (bool (ImRect::*)(const struct ImVec2 &) const) &ImRect::Contains, "C++: ImRect::Contains(const struct ImVec2 &) const --> bool", pybind11::arg("p"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Contains", (bool (ImRect::*)(const struct ImRect &) const) &ImRect::Contains, "C++: ImRect::Contains(const struct ImRect &) const --> bool", pybind11::arg("r"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Overlaps", (bool (ImRect::*)(const struct ImRect &) const) &ImRect::Overlaps, "C++: ImRect::Overlaps(const struct ImRect &) const --> bool", pybind11::arg("r"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Add", (void (ImRect::*)(const struct ImVec2 &)) &ImRect::Add, "C++: ImRect::Add(const struct ImVec2 &) --> void", pybind11::arg("p"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Add", (void (ImRect::*)(const struct ImRect &)) &ImRect::Add, "C++: ImRect::Add(const struct ImRect &) --> void", pybind11::arg("r"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Expand", (void (ImRect::*)(const float)) &ImRect::Expand, "C++: ImRect::Expand(const float) --> void", pybind11::arg("amount"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Expand", (void (ImRect::*)(const struct ImVec2 &)) &ImRect::Expand, "C++: ImRect::Expand(const struct ImVec2 &) --> void", pybind11::arg("amount"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Translate", (void (ImRect::*)(const struct ImVec2 &)) &ImRect::Translate, "C++: ImRect::Translate(const struct ImVec2 &) --> void", pybind11::arg("d"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("TranslateX", (void (ImRect::*)(float)) &ImRect::TranslateX, "C++: ImRect::TranslateX(float) --> void", pybind11::arg("dx"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("TranslateY", (void (ImRect::*)(float)) &ImRect::TranslateY, "C++: ImRect::TranslateY(float) --> void", pybind11::arg("dy"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ClipWith", (void (ImRect::*)(const struct ImRect &)) &ImRect::ClipWith, "C++: ImRect::ClipWith(const struct ImRect &) --> void", pybind11::arg("r"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("ClipWithFull", (void (ImRect::*)(const struct ImRect &)) &ImRect::ClipWithFull, "C++: ImRect::ClipWithFull(const struct ImRect &) --> void", pybind11::arg("r"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Floor", (void (ImRect::*)()) &ImRect::Floor, "C++: ImRect::Floor() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("IsInverted", (bool (ImRect::*)() const) &ImRect::IsInverted, "C++: ImRect::IsInverted() const --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct ImRect & (ImRect::*)(const struct ImRect &)) &ImRect::operator=, "C++: ImRect::operator=(const struct ImRect &) --> struct ImRect &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImGuiDataTypeInfo file:imgui_internal.h line:577
		pybind11::class_<ImGuiDataTypeInfo, std::shared_ptr<ImGuiDataTypeInfo>> cl(M(""), "ImGuiDataTypeInfo", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiDataTypeInfo(); } ) );
		cl.def_readwrite("Size", &ImGuiDataTypeInfo::Size);
	}
	{ // ImGuiWindowSettings file:imgui_internal.h line:663
		pybind11::class_<ImGuiWindowSettings, std::shared_ptr<ImGuiWindowSettings>> cl(M(""), "ImGuiWindowSettings", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiWindowSettings(); } ) );
		cl.def_readwrite("ID", &ImGuiWindowSettings::ID);
		cl.def_readwrite("Pos", &ImGuiWindowSettings::Pos);
		cl.def_readwrite("Size", &ImGuiWindowSettings::Size);
		cl.def_readwrite("Collapsed", &ImGuiWindowSettings::Collapsed);
	}
	{ // ImGuiSettingsHandler file:imgui_internal.h line:674
		pybind11::class_<ImGuiSettingsHandler, std::shared_ptr<ImGuiSettingsHandler>> cl(M(""), "ImGuiSettingsHandler", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiSettingsHandler(); } ) );
		cl.def_readwrite("TypeHash", &ImGuiSettingsHandler::TypeHash);
	}
	{ // ImGuiColumns file:imgui_internal.h line:710
		pybind11::class_<ImGuiColumns, std::shared_ptr<ImGuiColumns>> cl(M(""), "ImGuiColumns", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiColumns(); } ) );
		cl.def_readwrite("ID", &ImGuiColumns::ID);
		cl.def_readwrite("Flags", &ImGuiColumns::Flags);
		cl.def_readwrite("IsFirstFrame", &ImGuiColumns::IsFirstFrame);
		cl.def_readwrite("IsBeingResized", &ImGuiColumns::IsBeingResized);
		cl.def_readwrite("Current", &ImGuiColumns::Current);
		cl.def_readwrite("Count", &ImGuiColumns::Count);
		cl.def_readwrite("OffMinX", &ImGuiColumns::OffMinX);
		cl.def_readwrite("OffMaxX", &ImGuiColumns::OffMaxX);
		cl.def_readwrite("LineMinY", &ImGuiColumns::LineMinY);
		cl.def_readwrite("LineMaxY", &ImGuiColumns::LineMaxY);
		cl.def_readwrite("HostCursorPosY", &ImGuiColumns::HostCursorPosY);
		cl.def_readwrite("HostCursorMaxPosX", &ImGuiColumns::HostCursorMaxPosX);
		cl.def_readwrite("HostClipRect", &ImGuiColumns::HostClipRect);
		cl.def_readwrite("HostWorkRect", &ImGuiColumns::HostWorkRect);
		cl.def_readwrite("Columns", &ImGuiColumns::Columns);
		cl.def("Clear", (void (ImGuiColumns::*)()) &ImGuiColumns::Clear, "C++: ImGuiColumns::Clear() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImDrawListSharedData file:imgui_internal.h line:744
		pybind11::class_<ImDrawListSharedData, std::shared_ptr<ImDrawListSharedData>> cl(M(""), "ImDrawListSharedData", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImDrawListSharedData(); } ) );
		cl.def( pybind11::init( [](ImDrawListSharedData const &o){ return new ImDrawListSharedData(o); } ) );
		cl.def_readwrite("TexUvWhitePixel", &ImDrawListSharedData::TexUvWhitePixel);
		cl.def_readwrite("FontSize", &ImDrawListSharedData::FontSize);
		cl.def_readwrite("CurveTessellationTol", &ImDrawListSharedData::CurveTessellationTol);
		cl.def_readwrite("ClipRectFullscreen", &ImDrawListSharedData::ClipRectFullscreen);
		cl.def_readwrite("InitialFlags", &ImDrawListSharedData::InitialFlags);
		cl.def("assign", (struct ImDrawListSharedData & (ImDrawListSharedData::*)(const struct ImDrawListSharedData &)) &ImDrawListSharedData::operator=, "C++: ImDrawListSharedData::operator=(const struct ImDrawListSharedData &) --> struct ImDrawListSharedData &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImGuiShrinkWidthItem file:imgui_internal.h line:839
		pybind11::class_<ImGuiShrinkWidthItem, std::shared_ptr<ImGuiShrinkWidthItem>> cl(M(""), "ImGuiShrinkWidthItem", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiShrinkWidthItem(); } ) );
		cl.def_readwrite("Index", &ImGuiShrinkWidthItem::Index);
		cl.def_readwrite("Width", &ImGuiShrinkWidthItem::Width);
	}
	{ // ImGuiContext file:imgui_internal.h line:858
		pybind11::class_<ImGuiContext, std::shared_ptr<ImGuiContext>> cl(M(""), "ImGuiContext", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<struct ImFontAtlas *>(), pybind11::arg("shared_font_atlas") );

		cl.def_readwrite("Initialized", &ImGuiContext::Initialized);
		cl.def_readwrite("FrameScopeActive", &ImGuiContext::FrameScopeActive);
		cl.def_readwrite("FrameScopePushedImplicitWindow", &ImGuiContext::FrameScopePushedImplicitWindow);
		cl.def_readwrite("FontAtlasOwnedByContext", &ImGuiContext::FontAtlasOwnedByContext);
		cl.def_readwrite("IO", &ImGuiContext::IO);
		cl.def_readwrite("Style", &ImGuiContext::Style);
		cl.def_readwrite("FontSize", &ImGuiContext::FontSize);
		cl.def_readwrite("FontBaseSize", &ImGuiContext::FontBaseSize);
		cl.def_readwrite("DrawListSharedData", &ImGuiContext::DrawListSharedData);
		cl.def_readwrite("Time", &ImGuiContext::Time);
		cl.def_readwrite("FrameCount", &ImGuiContext::FrameCount);
		cl.def_readwrite("FrameCountEnded", &ImGuiContext::FrameCountEnded);
		cl.def_readwrite("FrameCountRendered", &ImGuiContext::FrameCountRendered);
		cl.def_readwrite("Windows", &ImGuiContext::Windows);
		cl.def_readwrite("WindowsFocusOrder", &ImGuiContext::WindowsFocusOrder);
		cl.def_readwrite("WindowsSortBuffer", &ImGuiContext::WindowsSortBuffer);
		cl.def_readwrite("CurrentWindowStack", &ImGuiContext::CurrentWindowStack);
		cl.def_readwrite("WindowsById", &ImGuiContext::WindowsById);
		cl.def_readwrite("WindowsActiveCount", &ImGuiContext::WindowsActiveCount);
		cl.def_readwrite("WheelingWindowRefMousePos", &ImGuiContext::WheelingWindowRefMousePos);
		cl.def_readwrite("WheelingWindowTimer", &ImGuiContext::WheelingWindowTimer);
		cl.def_readwrite("HoveredId", &ImGuiContext::HoveredId);
		cl.def_readwrite("HoveredIdAllowOverlap", &ImGuiContext::HoveredIdAllowOverlap);
		cl.def_readwrite("HoveredIdPreviousFrame", &ImGuiContext::HoveredIdPreviousFrame);
		cl.def_readwrite("HoveredIdTimer", &ImGuiContext::HoveredIdTimer);
		cl.def_readwrite("HoveredIdNotActiveTimer", &ImGuiContext::HoveredIdNotActiveTimer);
		cl.def_readwrite("ActiveId", &ImGuiContext::ActiveId);
		cl.def_readwrite("ActiveIdIsAlive", &ImGuiContext::ActiveIdIsAlive);
		cl.def_readwrite("ActiveIdTimer", &ImGuiContext::ActiveIdTimer);
		cl.def_readwrite("ActiveIdIsJustActivated", &ImGuiContext::ActiveIdIsJustActivated);
		cl.def_readwrite("ActiveIdAllowOverlap", &ImGuiContext::ActiveIdAllowOverlap);
		cl.def_readwrite("ActiveIdHasBeenPressedBefore", &ImGuiContext::ActiveIdHasBeenPressedBefore);
		cl.def_readwrite("ActiveIdHasBeenEditedBefore", &ImGuiContext::ActiveIdHasBeenEditedBefore);
		cl.def_readwrite("ActiveIdHasBeenEditedThisFrame", &ImGuiContext::ActiveIdHasBeenEditedThisFrame);
		cl.def_readwrite("ActiveIdUsingNavDirMask", &ImGuiContext::ActiveIdUsingNavDirMask);
		cl.def_readwrite("ActiveIdUsingNavInputMask", &ImGuiContext::ActiveIdUsingNavInputMask);
		cl.def_readwrite("ActiveIdUsingKeyInputMask", &ImGuiContext::ActiveIdUsingKeyInputMask);
		cl.def_readwrite("ActiveIdClickOffset", &ImGuiContext::ActiveIdClickOffset);
		cl.def_readwrite("ActiveIdSource", &ImGuiContext::ActiveIdSource);
		cl.def_readwrite("ActiveIdPreviousFrame", &ImGuiContext::ActiveIdPreviousFrame);
		cl.def_readwrite("ActiveIdPreviousFrameIsAlive", &ImGuiContext::ActiveIdPreviousFrameIsAlive);
		cl.def_readwrite("ActiveIdPreviousFrameHasBeenEditedBefore", &ImGuiContext::ActiveIdPreviousFrameHasBeenEditedBefore);
		cl.def_readwrite("LastActiveId", &ImGuiContext::LastActiveId);
		cl.def_readwrite("LastActiveIdTimer", &ImGuiContext::LastActiveIdTimer);
		cl.def_readwrite("NextWindowData", &ImGuiContext::NextWindowData);
		cl.def_readwrite("NextItemData", &ImGuiContext::NextItemData);
		cl.def_readwrite("ColorModifiers", &ImGuiContext::ColorModifiers);
		cl.def_readwrite("StyleModifiers", &ImGuiContext::StyleModifiers);
		cl.def_readwrite("FontStack", &ImGuiContext::FontStack);
		cl.def_readwrite("OpenPopupStack", &ImGuiContext::OpenPopupStack);
		cl.def_readwrite("BeginPopupStack", &ImGuiContext::BeginPopupStack);
		cl.def_readwrite("NavId", &ImGuiContext::NavId);
		cl.def_readwrite("NavActivateId", &ImGuiContext::NavActivateId);
		cl.def_readwrite("NavActivateDownId", &ImGuiContext::NavActivateDownId);
		cl.def_readwrite("NavActivatePressedId", &ImGuiContext::NavActivatePressedId);
		cl.def_readwrite("NavInputId", &ImGuiContext::NavInputId);
		cl.def_readwrite("NavJustTabbedId", &ImGuiContext::NavJustTabbedId);
		cl.def_readwrite("NavJustMovedToId", &ImGuiContext::NavJustMovedToId);
		cl.def_readwrite("NavJustMovedToMultiSelectScopeId", &ImGuiContext::NavJustMovedToMultiSelectScopeId);
		cl.def_readwrite("NavNextActivateId", &ImGuiContext::NavNextActivateId);
		cl.def_readwrite("NavInputSource", &ImGuiContext::NavInputSource);
		cl.def_readwrite("NavScoringRectScreen", &ImGuiContext::NavScoringRectScreen);
		cl.def_readwrite("NavScoringCount", &ImGuiContext::NavScoringCount);
		cl.def_readwrite("NavWindowingTimer", &ImGuiContext::NavWindowingTimer);
		cl.def_readwrite("NavWindowingHighlightAlpha", &ImGuiContext::NavWindowingHighlightAlpha);
		cl.def_readwrite("NavWindowingToggleLayer", &ImGuiContext::NavWindowingToggleLayer);
		cl.def_readwrite("NavLayer", &ImGuiContext::NavLayer);
		cl.def_readwrite("NavIdTabCounter", &ImGuiContext::NavIdTabCounter);
		cl.def_readwrite("NavIdIsAlive", &ImGuiContext::NavIdIsAlive);
		cl.def_readwrite("NavMousePosDirty", &ImGuiContext::NavMousePosDirty);
		cl.def_readwrite("NavDisableHighlight", &ImGuiContext::NavDisableHighlight);
		cl.def_readwrite("NavDisableMouseHover", &ImGuiContext::NavDisableMouseHover);
		cl.def_readwrite("NavAnyRequest", &ImGuiContext::NavAnyRequest);
		cl.def_readwrite("NavInitRequest", &ImGuiContext::NavInitRequest);
		cl.def_readwrite("NavInitRequestFromMove", &ImGuiContext::NavInitRequestFromMove);
		cl.def_readwrite("NavInitResultId", &ImGuiContext::NavInitResultId);
		cl.def_readwrite("NavInitResultRectRel", &ImGuiContext::NavInitResultRectRel);
		cl.def_readwrite("NavMoveFromClampedRefRect", &ImGuiContext::NavMoveFromClampedRefRect);
		cl.def_readwrite("NavMoveRequest", &ImGuiContext::NavMoveRequest);
		cl.def_readwrite("NavMoveRequestFlags", &ImGuiContext::NavMoveRequestFlags);
		cl.def_readwrite("NavMoveRequestForward", &ImGuiContext::NavMoveRequestForward);
		cl.def_readwrite("NavMoveDir", &ImGuiContext::NavMoveDir);
		cl.def_readwrite("NavMoveDirLast", &ImGuiContext::NavMoveDirLast);
		cl.def_readwrite("NavMoveClipDir", &ImGuiContext::NavMoveClipDir);
		cl.def_readwrite("NavMoveResultLocal", &ImGuiContext::NavMoveResultLocal);
		cl.def_readwrite("NavMoveResultLocalVisibleSet", &ImGuiContext::NavMoveResultLocalVisibleSet);
		cl.def_readwrite("NavMoveResultOther", &ImGuiContext::NavMoveResultOther);
		cl.def_readwrite("FocusRequestCurrCounterAll", &ImGuiContext::FocusRequestCurrCounterAll);
		cl.def_readwrite("FocusRequestCurrCounterTab", &ImGuiContext::FocusRequestCurrCounterTab);
		cl.def_readwrite("FocusRequestNextCounterAll", &ImGuiContext::FocusRequestNextCounterAll);
		cl.def_readwrite("FocusRequestNextCounterTab", &ImGuiContext::FocusRequestNextCounterTab);
		cl.def_readwrite("FocusTabPressed", &ImGuiContext::FocusTabPressed);
		cl.def_readwrite("DrawData", &ImGuiContext::DrawData);
		cl.def_readwrite("DrawDataBuilder", &ImGuiContext::DrawDataBuilder);
		cl.def_readwrite("DimBgRatio", &ImGuiContext::DimBgRatio);
		cl.def_readwrite("BackgroundDrawList", &ImGuiContext::BackgroundDrawList);
		cl.def_readwrite("ForegroundDrawList", &ImGuiContext::ForegroundDrawList);
		cl.def_readwrite("MouseCursor", &ImGuiContext::MouseCursor);
		cl.def_readwrite("DragDropActive", &ImGuiContext::DragDropActive);
		cl.def_readwrite("DragDropWithinSourceOrTarget", &ImGuiContext::DragDropWithinSourceOrTarget);
		cl.def_readwrite("DragDropSourceFlags", &ImGuiContext::DragDropSourceFlags);
		cl.def_readwrite("DragDropSourceFrameCount", &ImGuiContext::DragDropSourceFrameCount);
		cl.def_readwrite("DragDropMouseButton", &ImGuiContext::DragDropMouseButton);
		cl.def_readwrite("DragDropPayload", &ImGuiContext::DragDropPayload);
		cl.def_readwrite("DragDropTargetRect", &ImGuiContext::DragDropTargetRect);
		cl.def_readwrite("DragDropTargetId", &ImGuiContext::DragDropTargetId);
		cl.def_readwrite("DragDropAcceptFlags", &ImGuiContext::DragDropAcceptFlags);
		cl.def_readwrite("DragDropAcceptIdCurrRectSurface", &ImGuiContext::DragDropAcceptIdCurrRectSurface);
		cl.def_readwrite("DragDropAcceptIdCurr", &ImGuiContext::DragDropAcceptIdCurr);
		cl.def_readwrite("DragDropAcceptIdPrev", &ImGuiContext::DragDropAcceptIdPrev);
		cl.def_readwrite("DragDropAcceptFrameCount", &ImGuiContext::DragDropAcceptFrameCount);
		cl.def_readwrite("DragDropPayloadBufHeap", &ImGuiContext::DragDropPayloadBufHeap);
		cl.def_readwrite("TabBars", &ImGuiContext::TabBars);
		cl.def_readwrite("CurrentTabBarStack", &ImGuiContext::CurrentTabBarStack);
		cl.def_readwrite("ShrinkWidthBuffer", &ImGuiContext::ShrinkWidthBuffer);
		cl.def_readwrite("LastValidMousePos", &ImGuiContext::LastValidMousePos);
		cl.def_readwrite("InputTextState", &ImGuiContext::InputTextState);
		cl.def_readwrite("InputTextPasswordFont", &ImGuiContext::InputTextPasswordFont);
		cl.def_readwrite("TempInputTextId", &ImGuiContext::TempInputTextId);
		cl.def_readwrite("ColorEditOptions", &ImGuiContext::ColorEditOptions);
		cl.def_readwrite("ColorEditLastHue", &ImGuiContext::ColorEditLastHue);
		cl.def_readwrite("ColorPickerRef", &ImGuiContext::ColorPickerRef);
		cl.def_readwrite("DragCurrentAccumDirty", &ImGuiContext::DragCurrentAccumDirty);
		cl.def_readwrite("DragCurrentAccum", &ImGuiContext::DragCurrentAccum);
		cl.def_readwrite("DragSpeedDefaultRatio", &ImGuiContext::DragSpeedDefaultRatio);
		cl.def_readwrite("ScrollbarClickDeltaToGrabCenter", &ImGuiContext::ScrollbarClickDeltaToGrabCenter);
		cl.def_readwrite("TooltipOverrideCount", &ImGuiContext::TooltipOverrideCount);
		cl.def_readwrite("PrivateClipboard", &ImGuiContext::PrivateClipboard);
		cl.def_readwrite("MultiSelectScopeId", &ImGuiContext::MultiSelectScopeId);
		cl.def_readwrite("PlatformImePos", &ImGuiContext::PlatformImePos);
		cl.def_readwrite("PlatformImeLastPos", &ImGuiContext::PlatformImeLastPos);
		cl.def_readwrite("SettingsLoaded", &ImGuiContext::SettingsLoaded);
		cl.def_readwrite("SettingsDirtyTimer", &ImGuiContext::SettingsDirtyTimer);
		cl.def_readwrite("SettingsIniData", &ImGuiContext::SettingsIniData);
		cl.def_readwrite("SettingsHandlers", &ImGuiContext::SettingsHandlers);
		cl.def_readwrite("SettingsWindows", &ImGuiContext::SettingsWindows);
		cl.def_readwrite("LogEnabled", &ImGuiContext::LogEnabled);
		cl.def_readwrite("LogType", &ImGuiContext::LogType);
		cl.def_readwrite("LogBuffer", &ImGuiContext::LogBuffer);
		cl.def_readwrite("LogLinePosY", &ImGuiContext::LogLinePosY);
		cl.def_readwrite("LogLineFirstItem", &ImGuiContext::LogLineFirstItem);
		cl.def_readwrite("LogDepthRef", &ImGuiContext::LogDepthRef);
		cl.def_readwrite("LogDepthToExpand", &ImGuiContext::LogDepthToExpand);
		cl.def_readwrite("LogDepthToExpandDefault", &ImGuiContext::LogDepthToExpandDefault);
		cl.def_readwrite("DebugItemPickerActive", &ImGuiContext::DebugItemPickerActive);
		cl.def_readwrite("DebugItemPickerBreakID", &ImGuiContext::DebugItemPickerBreakID);
		cl.def_readwrite("FramerateSecPerFrameIdx", &ImGuiContext::FramerateSecPerFrameIdx);
		cl.def_readwrite("FramerateSecPerFrameAccum", &ImGuiContext::FramerateSecPerFrameAccum);
		cl.def_readwrite("WantCaptureMouseNextFrame", &ImGuiContext::WantCaptureMouseNextFrame);
		cl.def_readwrite("WantCaptureKeyboardNextFrame", &ImGuiContext::WantCaptureKeyboardNextFrame);
		cl.def_readwrite("WantTextInputNextFrame", &ImGuiContext::WantTextInputNextFrame);
	}
}


// File: imgui_internal_1.cpp
#include <imgui.h>
#include <imgui_internal.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_internal_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // ImGuiWindow file:imgui_internal.h line:1283
		pybind11::class_<ImGuiWindow, std::shared_ptr<ImGuiWindow>> cl(M(""), "ImGuiWindow", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<struct ImGuiContext *, const char *>(), pybind11::arg("context"), pybind11::arg("name") );

		cl.def_readwrite("ID", &ImGuiWindow::ID);
		cl.def_readwrite("Flags", &ImGuiWindow::Flags);
		cl.def_readwrite("Pos", &ImGuiWindow::Pos);
		cl.def_readwrite("Size", &ImGuiWindow::Size);
		cl.def_readwrite("SizeFull", &ImGuiWindow::SizeFull);
		cl.def_readwrite("ContentSize", &ImGuiWindow::ContentSize);
		cl.def_readwrite("ContentSizeExplicit", &ImGuiWindow::ContentSizeExplicit);
		cl.def_readwrite("WindowPadding", &ImGuiWindow::WindowPadding);
		cl.def_readwrite("WindowRounding", &ImGuiWindow::WindowRounding);
		cl.def_readwrite("WindowBorderSize", &ImGuiWindow::WindowBorderSize);
		cl.def_readwrite("NameBufLen", &ImGuiWindow::NameBufLen);
		cl.def_readwrite("MoveId", &ImGuiWindow::MoveId);
		cl.def_readwrite("ChildId", &ImGuiWindow::ChildId);
		cl.def_readwrite("Scroll", &ImGuiWindow::Scroll);
		cl.def_readwrite("ScrollMax", &ImGuiWindow::ScrollMax);
		cl.def_readwrite("ScrollTarget", &ImGuiWindow::ScrollTarget);
		cl.def_readwrite("ScrollTargetCenterRatio", &ImGuiWindow::ScrollTargetCenterRatio);
		cl.def_readwrite("ScrollbarSizes", &ImGuiWindow::ScrollbarSizes);
		cl.def_readwrite("ScrollbarX", &ImGuiWindow::ScrollbarX);
		cl.def_readwrite("ScrollbarY", &ImGuiWindow::ScrollbarY);
		cl.def_readwrite("Active", &ImGuiWindow::Active);
		cl.def_readwrite("WasActive", &ImGuiWindow::WasActive);
		cl.def_readwrite("WriteAccessed", &ImGuiWindow::WriteAccessed);
		cl.def_readwrite("Collapsed", &ImGuiWindow::Collapsed);
		cl.def_readwrite("WantCollapseToggle", &ImGuiWindow::WantCollapseToggle);
		cl.def_readwrite("SkipItems", &ImGuiWindow::SkipItems);
		cl.def_readwrite("Appearing", &ImGuiWindow::Appearing);
		cl.def_readwrite("Hidden", &ImGuiWindow::Hidden);
		cl.def_readwrite("HasCloseButton", &ImGuiWindow::HasCloseButton);
		cl.def_readwrite("ResizeBorderHeld", &ImGuiWindow::ResizeBorderHeld);
		cl.def_readwrite("BeginCount", &ImGuiWindow::BeginCount);
		cl.def_readwrite("BeginOrderWithinParent", &ImGuiWindow::BeginOrderWithinParent);
		cl.def_readwrite("BeginOrderWithinContext", &ImGuiWindow::BeginOrderWithinContext);
		cl.def_readwrite("PopupId", &ImGuiWindow::PopupId);
		cl.def_readwrite("AutoFitFramesX", &ImGuiWindow::AutoFitFramesX);
		cl.def_readwrite("AutoFitFramesY", &ImGuiWindow::AutoFitFramesY);
		cl.def_readwrite("AutoFitChildAxises", &ImGuiWindow::AutoFitChildAxises);
		cl.def_readwrite("AutoFitOnlyGrows", &ImGuiWindow::AutoFitOnlyGrows);
		cl.def_readwrite("AutoPosLastDirection", &ImGuiWindow::AutoPosLastDirection);
		cl.def_readwrite("HiddenFramesCanSkipItems", &ImGuiWindow::HiddenFramesCanSkipItems);
		cl.def_readwrite("HiddenFramesCannotSkipItems", &ImGuiWindow::HiddenFramesCannotSkipItems);
		cl.def_readwrite("SetWindowPosAllowFlags", &ImGuiWindow::SetWindowPosAllowFlags);
		cl.def_readwrite("SetWindowSizeAllowFlags", &ImGuiWindow::SetWindowSizeAllowFlags);
		cl.def_readwrite("SetWindowCollapsedAllowFlags", &ImGuiWindow::SetWindowCollapsedAllowFlags);
		cl.def_readwrite("SetWindowPosVal", &ImGuiWindow::SetWindowPosVal);
		cl.def_readwrite("SetWindowPosPivot", &ImGuiWindow::SetWindowPosPivot);
		cl.def_readwrite("IDStack", &ImGuiWindow::IDStack);
		cl.def_readwrite("DC", &ImGuiWindow::DC);
		cl.def_readwrite("OuterRectClipped", &ImGuiWindow::OuterRectClipped);
		cl.def_readwrite("InnerRect", &ImGuiWindow::InnerRect);
		cl.def_readwrite("InnerClipRect", &ImGuiWindow::InnerClipRect);
		cl.def_readwrite("WorkRect", &ImGuiWindow::WorkRect);
		cl.def_readwrite("ClipRect", &ImGuiWindow::ClipRect);
		cl.def_readwrite("ContentsRegionRect", &ImGuiWindow::ContentsRegionRect);
		cl.def_readwrite("LastFrameActive", &ImGuiWindow::LastFrameActive);
		cl.def_readwrite("LastTimeActive", &ImGuiWindow::LastTimeActive);
		cl.def_readwrite("ItemWidthDefault", &ImGuiWindow::ItemWidthDefault);
		cl.def_readwrite("MenuColumns", &ImGuiWindow::MenuColumns);
		cl.def_readwrite("StateStorage", &ImGuiWindow::StateStorage);
		cl.def_readwrite("ColumnsStorage", &ImGuiWindow::ColumnsStorage);
		cl.def_readwrite("FontWindowScale", &ImGuiWindow::FontWindowScale);
		cl.def_readwrite("SettingsIdx", &ImGuiWindow::SettingsIdx);
		cl.def_readwrite("DrawListInst", &ImGuiWindow::DrawListInst);
		cl.def_readwrite("MemoryCompacted", &ImGuiWindow::MemoryCompacted);
		cl.def_readwrite("MemoryDrawListIdxCapacity", &ImGuiWindow::MemoryDrawListIdxCapacity);
		cl.def_readwrite("MemoryDrawListVtxCapacity", &ImGuiWindow::MemoryDrawListVtxCapacity);
		cl.def("GetID", [](ImGuiWindow &o, const char * a0) -> unsigned int { return o.GetID(a0); }, "", pybind11::arg("str"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetID", (unsigned int (ImGuiWindow::*)(const char *, const char *)) &ImGuiWindow::GetID, "C++: ImGuiWindow::GetID(const char *, const char *) --> unsigned int", pybind11::arg("str"), pybind11::arg("str_end"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetID", (unsigned int (ImGuiWindow::*)(const void *)) &ImGuiWindow::GetID, "C++: ImGuiWindow::GetID(const void *) --> unsigned int", pybind11::arg("ptr"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetID", (unsigned int (ImGuiWindow::*)(int)) &ImGuiWindow::GetID, "C++: ImGuiWindow::GetID(int) --> unsigned int", pybind11::arg("n"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetIDNoKeepAlive", [](ImGuiWindow &o, const char * a0) -> unsigned int { return o.GetIDNoKeepAlive(a0); }, "", pybind11::arg("str"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetIDNoKeepAlive", (unsigned int (ImGuiWindow::*)(const char *, const char *)) &ImGuiWindow::GetIDNoKeepAlive, "C++: ImGuiWindow::GetIDNoKeepAlive(const char *, const char *) --> unsigned int", pybind11::arg("str"), pybind11::arg("str_end"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetIDNoKeepAlive", (unsigned int (ImGuiWindow::*)(const void *)) &ImGuiWindow::GetIDNoKeepAlive, "C++: ImGuiWindow::GetIDNoKeepAlive(const void *) --> unsigned int", pybind11::arg("ptr"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetIDNoKeepAlive", (unsigned int (ImGuiWindow::*)(int)) &ImGuiWindow::GetIDNoKeepAlive, "C++: ImGuiWindow::GetIDNoKeepAlive(int) --> unsigned int", pybind11::arg("n"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetIDFromRectangle", (unsigned int (ImGuiWindow::*)(const struct ImRect &)) &ImGuiWindow::GetIDFromRectangle, "C++: ImGuiWindow::GetIDFromRectangle(const struct ImRect &) --> unsigned int", pybind11::arg("r_abs"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("Rect", (struct ImRect (ImGuiWindow::*)() const) &ImGuiWindow::Rect, "C++: ImGuiWindow::Rect() const --> struct ImRect", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("CalcFontSize", (float (ImGuiWindow::*)() const) &ImGuiWindow::CalcFontSize, "C++: ImGuiWindow::CalcFontSize() const --> float", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("TitleBarHeight", (float (ImGuiWindow::*)() const) &ImGuiWindow::TitleBarHeight, "C++: ImGuiWindow::TitleBarHeight() const --> float", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("TitleBarRect", (struct ImRect (ImGuiWindow::*)() const) &ImGuiWindow::TitleBarRect, "C++: ImGuiWindow::TitleBarRect() const --> struct ImRect", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("MenuBarHeight", (float (ImGuiWindow::*)() const) &ImGuiWindow::MenuBarHeight, "C++: ImGuiWindow::MenuBarHeight() const --> float", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("MenuBarRect", (struct ImRect (ImGuiWindow::*)() const) &ImGuiWindow::MenuBarRect, "C++: ImGuiWindow::MenuBarRect() const --> struct ImRect", pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // ImGuiTabItem file:imgui_internal.h line:1420
		pybind11::class_<ImGuiTabItem, std::shared_ptr<ImGuiTabItem>> cl(M(""), "ImGuiTabItem", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiTabItem(); } ) );
		cl.def_readwrite("ID", &ImGuiTabItem::ID);
		cl.def_readwrite("Flags", &ImGuiTabItem::Flags);
		cl.def_readwrite("LastFrameVisible", &ImGuiTabItem::LastFrameVisible);
		cl.def_readwrite("LastFrameSelected", &ImGuiTabItem::LastFrameSelected);
		cl.def_readwrite("NameOffset", &ImGuiTabItem::NameOffset);
		cl.def_readwrite("Offset", &ImGuiTabItem::Offset);
		cl.def_readwrite("Width", &ImGuiTabItem::Width);
		cl.def_readwrite("WidthContents", &ImGuiTabItem::WidthContents);
	}
	{ // ImGuiTabBar file:imgui_internal.h line:1435
		pybind11::class_<ImGuiTabBar, std::shared_ptr<ImGuiTabBar>> cl(M(""), "ImGuiTabBar", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new ImGuiTabBar(); } ) );
		cl.def_readwrite("Tabs", &ImGuiTabBar::Tabs);
		cl.def_readwrite("ID", &ImGuiTabBar::ID);
		cl.def_readwrite("SelectedTabId", &ImGuiTabBar::SelectedTabId);
		cl.def_readwrite("NextSelectedTabId", &ImGuiTabBar::NextSelectedTabId);
		cl.def_readwrite("VisibleTabId", &ImGuiTabBar::VisibleTabId);
		cl.def_readwrite("CurrFrameVisible", &ImGuiTabBar::CurrFrameVisible);
		cl.def_readwrite("PrevFrameVisible", &ImGuiTabBar::PrevFrameVisible);
		cl.def_readwrite("BarRect", &ImGuiTabBar::BarRect);
		cl.def_readwrite("LastTabContentHeight", &ImGuiTabBar::LastTabContentHeight);
		cl.def_readwrite("OffsetMax", &ImGuiTabBar::OffsetMax);
		cl.def_readwrite("OffsetMaxIdeal", &ImGuiTabBar::OffsetMaxIdeal);
		cl.def_readwrite("OffsetNextTab", &ImGuiTabBar::OffsetNextTab);
		cl.def_readwrite("ScrollingAnim", &ImGuiTabBar::ScrollingAnim);
		cl.def_readwrite("ScrollingTarget", &ImGuiTabBar::ScrollingTarget);
		cl.def_readwrite("ScrollingTargetDistToVisibility", &ImGuiTabBar::ScrollingTargetDistToVisibility);
		cl.def_readwrite("ScrollingSpeed", &ImGuiTabBar::ScrollingSpeed);
		cl.def_readwrite("Flags", &ImGuiTabBar::Flags);
		cl.def_readwrite("ReorderRequestTabId", &ImGuiTabBar::ReorderRequestTabId);
		cl.def_readwrite("ReorderRequestDir", &ImGuiTabBar::ReorderRequestDir);
		cl.def_readwrite("WantLayout", &ImGuiTabBar::WantLayout);
		cl.def_readwrite("VisibleTabWasSubmitted", &ImGuiTabBar::VisibleTabWasSubmitted);
		cl.def_readwrite("LastTabItemIdx", &ImGuiTabBar::LastTabItemIdx);
		cl.def_readwrite("FramePadding", &ImGuiTabBar::FramePadding);
		cl.def_readwrite("TabsNames", &ImGuiTabBar::TabsNames);
		cl.def("GetTabOrder", (int (ImGuiTabBar::*)(const struct ImGuiTabItem *) const) &ImGuiTabBar::GetTabOrder, "C++: ImGuiTabBar::GetTabOrder(const struct ImGuiTabItem *) const --> int", pybind11::arg("tab"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("GetTabName", (const char * (ImGuiTabBar::*)(const struct ImGuiTabItem *) const) &ImGuiTabBar::GetTabName, "C++: ImGuiTabBar::GetTabName(const struct ImGuiTabItem *) const --> const char *", pybind11::return_value_policy::reference, pybind11::arg("tab"), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
}


// File: imgui_internal_2.cpp
#include <imgui.h>
#include <imgui_internal.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_internal_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::GetCurrentWindowRead() file:imgui_internal.h line:1482
	M("ImGui").def("GetCurrentWindowRead", (struct ImGuiWindow * (*)()) &ImGui::GetCurrentWindowRead, "C++: ImGui::GetCurrentWindowRead() --> struct ImGuiWindow *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetCurrentWindow() file:imgui_internal.h line:1483
	M("ImGui").def("GetCurrentWindow", (struct ImGuiWindow * (*)()) &ImGui::GetCurrentWindow, "C++: ImGui::GetCurrentWindow() --> struct ImGuiWindow *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FindWindowByID(unsigned int) file:imgui_internal.h line:1484
	M("ImGui").def("FindWindowByID", (struct ImGuiWindow * (*)(unsigned int)) &ImGui::FindWindowByID, "C++: ImGui::FindWindowByID(unsigned int) --> struct ImGuiWindow *", pybind11::return_value_policy::reference, pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FindWindowByName(const char *) file:imgui_internal.h line:1485
	M("ImGui").def("FindWindowByName", (struct ImGuiWindow * (*)(const char *)) &ImGui::FindWindowByName, "C++: ImGui::FindWindowByName(const char *) --> struct ImGuiWindow *", pybind11::return_value_policy::reference, pybind11::arg("name"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FocusWindow(struct ImGuiWindow *) file:imgui_internal.h line:1486
	M("ImGui").def("FocusWindow", (void (*)(struct ImGuiWindow *)) &ImGui::FocusWindow, "C++: ImGui::FocusWindow(struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FocusTopMostWindowUnderOne(struct ImGuiWindow *, struct ImGuiWindow *) file:imgui_internal.h line:1487
	M("ImGui").def("FocusTopMostWindowUnderOne", (void (*)(struct ImGuiWindow *, struct ImGuiWindow *)) &ImGui::FocusTopMostWindowUnderOne, "C++: ImGui::FocusTopMostWindowUnderOne(struct ImGuiWindow *, struct ImGuiWindow *) --> void", pybind11::arg("under_this_window"), pybind11::arg("ignore_window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BringWindowToFocusFront(struct ImGuiWindow *) file:imgui_internal.h line:1488
	M("ImGui").def("BringWindowToFocusFront", (void (*)(struct ImGuiWindow *)) &ImGui::BringWindowToFocusFront, "C++: ImGui::BringWindowToFocusFront(struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BringWindowToDisplayFront(struct ImGuiWindow *) file:imgui_internal.h line:1489
	M("ImGui").def("BringWindowToDisplayFront", (void (*)(struct ImGuiWindow *)) &ImGui::BringWindowToDisplayFront, "C++: ImGui::BringWindowToDisplayFront(struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BringWindowToDisplayBack(struct ImGuiWindow *) file:imgui_internal.h line:1490
	M("ImGui").def("BringWindowToDisplayBack", (void (*)(struct ImGuiWindow *)) &ImGui::BringWindowToDisplayBack, "C++: ImGui::BringWindowToDisplayBack(struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::UpdateWindowParentAndRootLinks(struct ImGuiWindow *, int, struct ImGuiWindow *) file:imgui_internal.h line:1491
	M("ImGui").def("UpdateWindowParentAndRootLinks", (void (*)(struct ImGuiWindow *, int, struct ImGuiWindow *)) &ImGui::UpdateWindowParentAndRootLinks, "C++: ImGui::UpdateWindowParentAndRootLinks(struct ImGuiWindow *, int, struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::arg("flags"), pybind11::arg("parent_window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CalcWindowExpectedSize(struct ImGuiWindow *) file:imgui_internal.h line:1492
	M("ImGui").def("CalcWindowExpectedSize", (struct ImVec2 (*)(struct ImGuiWindow *)) &ImGui::CalcWindowExpectedSize, "C++: ImGui::CalcWindowExpectedSize(struct ImGuiWindow *) --> struct ImVec2", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsWindowChildOf(struct ImGuiWindow *, struct ImGuiWindow *) file:imgui_internal.h line:1493
	M("ImGui").def("IsWindowChildOf", (bool (*)(struct ImGuiWindow *, struct ImGuiWindow *)) &ImGui::IsWindowChildOf, "C++: ImGui::IsWindowChildOf(struct ImGuiWindow *, struct ImGuiWindow *) --> bool", pybind11::arg("window"), pybind11::arg("potential_parent"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsWindowNavFocusable(struct ImGuiWindow *) file:imgui_internal.h line:1494
	M("ImGui").def("IsWindowNavFocusable", (bool (*)(struct ImGuiWindow *)) &ImGui::IsWindowNavFocusable, "C++: ImGui::IsWindowNavFocusable(struct ImGuiWindow *) --> bool", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetWindowAllowedExtentRect(struct ImGuiWindow *) file:imgui_internal.h line:1495
	M("ImGui").def("GetWindowAllowedExtentRect", (struct ImRect (*)(struct ImGuiWindow *)) &ImGui::GetWindowAllowedExtentRect, "C++: ImGui::GetWindowAllowedExtentRect(struct ImGuiWindow *) --> struct ImRect", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowPos(struct ImGuiWindow *, const struct ImVec2 &, int) file:imgui_internal.h line:1496
	M("ImGui").def("SetWindowPos", [](struct ImGuiWindow * a0, const struct ImVec2 & a1) -> void { return ImGui::SetWindowPos(a0, a1); }, "", pybind11::arg("window"), pybind11::arg("pos"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetWindowPos", (void (*)(struct ImGuiWindow *, const struct ImVec2 &, int)) &ImGui::SetWindowPos, "C++: ImGui::SetWindowPos(struct ImGuiWindow *, const struct ImVec2 &, int) --> void", pybind11::arg("window"), pybind11::arg("pos"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowSize(struct ImGuiWindow *, const struct ImVec2 &, int) file:imgui_internal.h line:1497
	M("ImGui").def("SetWindowSize", [](struct ImGuiWindow * a0, const struct ImVec2 & a1) -> void { return ImGui::SetWindowSize(a0, a1); }, "", pybind11::arg("window"), pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetWindowSize", (void (*)(struct ImGuiWindow *, const struct ImVec2 &, int)) &ImGui::SetWindowSize, "C++: ImGui::SetWindowSize(struct ImGuiWindow *, const struct ImVec2 &, int) --> void", pybind11::arg("window"), pybind11::arg("size"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetWindowCollapsed(struct ImGuiWindow *, bool, int) file:imgui_internal.h line:1498
	M("ImGui").def("SetWindowCollapsed", [](struct ImGuiWindow * a0, bool const & a1) -> void { return ImGui::SetWindowCollapsed(a0, a1); }, "", pybind11::arg("window"), pybind11::arg("collapsed"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetWindowCollapsed", (void (*)(struct ImGuiWindow *, bool, int)) &ImGui::SetWindowCollapsed, "C++: ImGui::SetWindowCollapsed(struct ImGuiWindow *, bool, int) --> void", pybind11::arg("window"), pybind11::arg("collapsed"), pybind11::arg("cond"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GcCompactTransientWindowBuffers(struct ImGuiWindow *) file:imgui_internal.h line:1499
	M("ImGui").def("GcCompactTransientWindowBuffers", (void (*)(struct ImGuiWindow *)) &ImGui::GcCompactTransientWindowBuffers, "C++: ImGui::GcCompactTransientWindowBuffers(struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GcAwakeTransientWindowBuffers(struct ImGuiWindow *) file:imgui_internal.h line:1500
	M("ImGui").def("GcAwakeTransientWindowBuffers", (void (*)(struct ImGuiWindow *)) &ImGui::GcAwakeTransientWindowBuffers, "C++: ImGui::GcAwakeTransientWindowBuffers(struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetCurrentFont(struct ImFont *) file:imgui_internal.h line:1502
	M("ImGui").def("SetCurrentFont", (void (*)(struct ImFont *)) &ImGui::SetCurrentFont, "C++: ImGui::SetCurrentFont(struct ImFont *) --> void", pybind11::arg("font"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetDefaultFont() file:imgui_internal.h line:1503
	M("ImGui").def("GetDefaultFont", (struct ImFont * (*)()) &ImGui::GetDefaultFont, "C++: ImGui::GetDefaultFont() --> struct ImFont *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetForegroundDrawList(struct ImGuiWindow *) file:imgui_internal.h line:1504
	M("ImGui").def("GetForegroundDrawList", (struct ImDrawList * (*)(struct ImGuiWindow *)) &ImGui::GetForegroundDrawList, "C++: ImGui::GetForegroundDrawList(struct ImGuiWindow *) --> struct ImDrawList *", pybind11::return_value_policy::reference, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Initialize(struct ImGuiContext *) file:imgui_internal.h line:1507
	M("ImGui").def("Initialize", (void (*)(struct ImGuiContext *)) &ImGui::Initialize, "C++: ImGui::Initialize(struct ImGuiContext *) --> void", pybind11::arg("context"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Shutdown(struct ImGuiContext *) file:imgui_internal.h line:1508
	M("ImGui").def("Shutdown", (void (*)(struct ImGuiContext *)) &ImGui::Shutdown, "C++: ImGui::Shutdown(struct ImGuiContext *) --> void", pybind11::arg("context"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::UpdateHoveredWindowAndCaptureFlags() file:imgui_internal.h line:1511
	M("ImGui").def("UpdateHoveredWindowAndCaptureFlags", (void (*)()) &ImGui::UpdateHoveredWindowAndCaptureFlags, "C++: ImGui::UpdateHoveredWindowAndCaptureFlags() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::StartMouseMovingWindow(struct ImGuiWindow *) file:imgui_internal.h line:1512
	M("ImGui").def("StartMouseMovingWindow", (void (*)(struct ImGuiWindow *)) &ImGui::StartMouseMovingWindow, "C++: ImGui::StartMouseMovingWindow(struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::UpdateMouseMovingWindowNewFrame() file:imgui_internal.h line:1513
	M("ImGui").def("UpdateMouseMovingWindowNewFrame", (void (*)()) &ImGui::UpdateMouseMovingWindowNewFrame, "C++: ImGui::UpdateMouseMovingWindowNewFrame() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::UpdateMouseMovingWindowEndFrame() file:imgui_internal.h line:1514
	M("ImGui").def("UpdateMouseMovingWindowEndFrame", (void (*)()) &ImGui::UpdateMouseMovingWindowEndFrame, "C++: ImGui::UpdateMouseMovingWindowEndFrame() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::MarkIniSettingsDirty() file:imgui_internal.h line:1517
	M("ImGui").def("MarkIniSettingsDirty", (void (*)()) &ImGui::MarkIniSettingsDirty, "C++: ImGui::MarkIniSettingsDirty() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::MarkIniSettingsDirty(struct ImGuiWindow *) file:imgui_internal.h line:1518
	M("ImGui").def("MarkIniSettingsDirty", (void (*)(struct ImGuiWindow *)) &ImGui::MarkIniSettingsDirty, "C++: ImGui::MarkIniSettingsDirty(struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CreateNewWindowSettings(const char *) file:imgui_internal.h line:1519
	M("ImGui").def("CreateNewWindowSettings", (struct ImGuiWindowSettings * (*)(const char *)) &ImGui::CreateNewWindowSettings, "C++: ImGui::CreateNewWindowSettings(const char *) --> struct ImGuiWindowSettings *", pybind11::return_value_policy::reference, pybind11::arg("name"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FindWindowSettings(unsigned int) file:imgui_internal.h line:1520
	M("ImGui").def("FindWindowSettings", (struct ImGuiWindowSettings * (*)(unsigned int)) &ImGui::FindWindowSettings, "C++: ImGui::FindWindowSettings(unsigned int) --> struct ImGuiWindowSettings *", pybind11::return_value_policy::reference, pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FindOrCreateWindowSettings(const char *) file:imgui_internal.h line:1521
	M("ImGui").def("FindOrCreateWindowSettings", (struct ImGuiWindowSettings * (*)(const char *)) &ImGui::FindOrCreateWindowSettings, "C++: ImGui::FindOrCreateWindowSettings(const char *) --> struct ImGuiWindowSettings *", pybind11::return_value_policy::reference, pybind11::arg("name"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FindSettingsHandler(const char *) file:imgui_internal.h line:1522
	M("ImGui").def("FindSettingsHandler", (struct ImGuiSettingsHandler * (*)(const char *)) &ImGui::FindSettingsHandler, "C++: ImGui::FindSettingsHandler(const char *) --> struct ImGuiSettingsHandler *", pybind11::return_value_policy::reference, pybind11::arg("type_name"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollX(struct ImGuiWindow *, float) file:imgui_internal.h line:1525
	M("ImGui").def("SetScrollX", (void (*)(struct ImGuiWindow *, float)) &ImGui::SetScrollX, "C++: ImGui::SetScrollX(struct ImGuiWindow *, float) --> void", pybind11::arg("window"), pybind11::arg("new_scroll_x"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollY(struct ImGuiWindow *, float) file:imgui_internal.h line:1526
	M("ImGui").def("SetScrollY", (void (*)(struct ImGuiWindow *, float)) &ImGui::SetScrollY, "C++: ImGui::SetScrollY(struct ImGuiWindow *, float) --> void", pybind11::arg("window"), pybind11::arg("new_scroll_y"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollFromPosX(struct ImGuiWindow *, float, float) file:imgui_internal.h line:1527
	M("ImGui").def("SetScrollFromPosX", [](struct ImGuiWindow * a0, float const & a1) -> void { return ImGui::SetScrollFromPosX(a0, a1); }, "", pybind11::arg("window"), pybind11::arg("local_x"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetScrollFromPosX", (void (*)(struct ImGuiWindow *, float, float)) &ImGui::SetScrollFromPosX, "C++: ImGui::SetScrollFromPosX(struct ImGuiWindow *, float, float) --> void", pybind11::arg("window"), pybind11::arg("local_x"), pybind11::arg("center_x_ratio"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetScrollFromPosY(struct ImGuiWindow *, float, float) file:imgui_internal.h line:1528
	M("ImGui").def("SetScrollFromPosY", [](struct ImGuiWindow * a0, float const & a1) -> void { return ImGui::SetScrollFromPosY(a0, a1); }, "", pybind11::arg("window"), pybind11::arg("local_y"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SetScrollFromPosY", (void (*)(struct ImGuiWindow *, float, float)) &ImGui::SetScrollFromPosY, "C++: ImGui::SetScrollFromPosY(struct ImGuiWindow *, float, float) --> void", pybind11::arg("window"), pybind11::arg("local_y"), pybind11::arg("center_y_ratio"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ScrollToBringRectIntoView(struct ImGuiWindow *, const struct ImRect &) file:imgui_internal.h line:1529
	M("ImGui").def("ScrollToBringRectIntoView", (struct ImVec2 (*)(struct ImGuiWindow *, const struct ImRect &)) &ImGui::ScrollToBringRectIntoView, "C++: ImGui::ScrollToBringRectIntoView(struct ImGuiWindow *, const struct ImRect &) --> struct ImVec2", pybind11::arg("window"), pybind11::arg("item_rect"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetItemID() file:imgui_internal.h line:1532
	M("ImGui").def("GetItemID", (unsigned int (*)()) &ImGui::GetItemID, "C++: ImGui::GetItemID() --> unsigned int", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetActiveID() file:imgui_internal.h line:1533
	M("ImGui").def("GetActiveID", (unsigned int (*)()) &ImGui::GetActiveID, "C++: ImGui::GetActiveID() --> unsigned int", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetFocusID() file:imgui_internal.h line:1534
	M("ImGui").def("GetFocusID", (unsigned int (*)()) &ImGui::GetFocusID, "C++: ImGui::GetFocusID() --> unsigned int", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetActiveID(unsigned int, struct ImGuiWindow *) file:imgui_internal.h line:1535
	M("ImGui").def("SetActiveID", (void (*)(unsigned int, struct ImGuiWindow *)) &ImGui::SetActiveID, "C++: ImGui::SetActiveID(unsigned int, struct ImGuiWindow *) --> void", pybind11::arg("id"), pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_internal_3.cpp
#include <imgui.h>
#include <imgui_internal.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_internal_3(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::SetFocusID(unsigned int, struct ImGuiWindow *) file:imgui_internal.h line:1536
	M("ImGui").def("SetFocusID", (void (*)(unsigned int, struct ImGuiWindow *)) &ImGui::SetFocusID, "C++: ImGui::SetFocusID(unsigned int, struct ImGuiWindow *) --> void", pybind11::arg("id"), pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ClearActiveID() file:imgui_internal.h line:1537
	M("ImGui").def("ClearActiveID", (void (*)()) &ImGui::ClearActiveID, "C++: ImGui::ClearActiveID() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetHoveredID() file:imgui_internal.h line:1538
	M("ImGui").def("GetHoveredID", (unsigned int (*)()) &ImGui::GetHoveredID, "C++: ImGui::GetHoveredID() --> unsigned int", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetHoveredID(unsigned int) file:imgui_internal.h line:1539
	M("ImGui").def("SetHoveredID", (void (*)(unsigned int)) &ImGui::SetHoveredID, "C++: ImGui::SetHoveredID(unsigned int) --> void", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::KeepAliveID(unsigned int) file:imgui_internal.h line:1540
	M("ImGui").def("KeepAliveID", (void (*)(unsigned int)) &ImGui::KeepAliveID, "C++: ImGui::KeepAliveID(unsigned int) --> void", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::MarkItemEdited(unsigned int) file:imgui_internal.h line:1541
	M("ImGui").def("MarkItemEdited", (void (*)(unsigned int)) &ImGui::MarkItemEdited, "C++: ImGui::MarkItemEdited(unsigned int) --> void", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushOverrideID(unsigned int) file:imgui_internal.h line:1542
	M("ImGui").def("PushOverrideID", (void (*)(unsigned int)) &ImGui::PushOverrideID, "C++: ImGui::PushOverrideID(unsigned int) --> void", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ItemSize(const struct ImVec2 &, float) file:imgui_internal.h line:1545
	M("ImGui").def("ItemSize", [](const struct ImVec2 & a0) -> void { return ImGui::ItemSize(a0); }, "", pybind11::arg("size"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ItemSize", (void (*)(const struct ImVec2 &, float)) &ImGui::ItemSize, "C++: ImGui::ItemSize(const struct ImVec2 &, float) --> void", pybind11::arg("size"), pybind11::arg("text_baseline_y"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ItemSize(const struct ImRect &, float) file:imgui_internal.h line:1546
	M("ImGui").def("ItemSize", [](const struct ImRect & a0) -> void { return ImGui::ItemSize(a0); }, "", pybind11::arg("bb"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ItemSize", (void (*)(const struct ImRect &, float)) &ImGui::ItemSize, "C++: ImGui::ItemSize(const struct ImRect &, float) --> void", pybind11::arg("bb"), pybind11::arg("text_baseline_y"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ItemAdd(const struct ImRect &, unsigned int, const struct ImRect *) file:imgui_internal.h line:1547
	M("ImGui").def("ItemAdd", [](const struct ImRect & a0, unsigned int const & a1) -> bool { return ImGui::ItemAdd(a0, a1); }, "", pybind11::arg("bb"), pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ItemAdd", (bool (*)(const struct ImRect &, unsigned int, const struct ImRect *)) &ImGui::ItemAdd, "C++: ImGui::ItemAdd(const struct ImRect &, unsigned int, const struct ImRect *) --> bool", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("nav_bb"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ItemHoverable(const struct ImRect &, unsigned int) file:imgui_internal.h line:1548
	M("ImGui").def("ItemHoverable", (bool (*)(const struct ImRect &, unsigned int)) &ImGui::ItemHoverable, "C++: ImGui::ItemHoverable(const struct ImRect &, unsigned int) --> bool", pybind11::arg("bb"), pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsClippedEx(const struct ImRect &, unsigned int, bool) file:imgui_internal.h line:1549
	M("ImGui").def("IsClippedEx", (bool (*)(const struct ImRect &, unsigned int, bool)) &ImGui::IsClippedEx, "C++: ImGui::IsClippedEx(const struct ImRect &, unsigned int, bool) --> bool", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("clip_even_when_logged"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FocusableItemRegister(struct ImGuiWindow *, unsigned int) file:imgui_internal.h line:1550
	M("ImGui").def("FocusableItemRegister", (bool (*)(struct ImGuiWindow *, unsigned int)) &ImGui::FocusableItemRegister, "C++: ImGui::FocusableItemRegister(struct ImGuiWindow *, unsigned int) --> bool", pybind11::arg("window"), pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FocusableItemUnregister(struct ImGuiWindow *) file:imgui_internal.h line:1551
	M("ImGui").def("FocusableItemUnregister", (void (*)(struct ImGuiWindow *)) &ImGui::FocusableItemUnregister, "C++: ImGui::FocusableItemUnregister(struct ImGuiWindow *) --> void", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CalcItemSize(struct ImVec2, float, float) file:imgui_internal.h line:1552
	M("ImGui").def("CalcItemSize", (struct ImVec2 (*)(struct ImVec2, float, float)) &ImGui::CalcItemSize, "C++: ImGui::CalcItemSize(struct ImVec2, float, float) --> struct ImVec2", pybind11::arg("size"), pybind11::arg("default_w"), pybind11::arg("default_h"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CalcWrapWidthForPos(const struct ImVec2 &, float) file:imgui_internal.h line:1553
	M("ImGui").def("CalcWrapWidthForPos", (float (*)(const struct ImVec2 &, float)) &ImGui::CalcWrapWidthForPos, "C++: ImGui::CalcWrapWidthForPos(const struct ImVec2 &, float) --> float", pybind11::arg("pos"), pybind11::arg("wrap_pos_x"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushMultiItemsWidths(int, float) file:imgui_internal.h line:1554
	M("ImGui").def("PushMultiItemsWidths", (void (*)(int, float)) &ImGui::PushMultiItemsWidths, "C++: ImGui::PushMultiItemsWidths(int, float) --> void", pybind11::arg("components"), pybind11::arg("width_full"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushItemFlag(int, bool) file:imgui_internal.h line:1555
	M("ImGui").def("PushItemFlag", (void (*)(int, bool)) &ImGui::PushItemFlag, "C++: ImGui::PushItemFlag(int, bool) --> void", pybind11::arg("option"), pybind11::arg("enabled"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopItemFlag() file:imgui_internal.h line:1556
	M("ImGui").def("PopItemFlag", (void (*)()) &ImGui::PopItemFlag, "C++: ImGui::PopItemFlag() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsItemToggledSelection() file:imgui_internal.h line:1557
	M("ImGui").def("IsItemToggledSelection", (bool (*)()) &ImGui::IsItemToggledSelection, "C++: ImGui::IsItemToggledSelection() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetContentRegionMaxAbs() file:imgui_internal.h line:1558
	M("ImGui").def("GetContentRegionMaxAbs", (struct ImVec2 (*)()) &ImGui::GetContentRegionMaxAbs, "C++: ImGui::GetContentRegionMaxAbs() --> struct ImVec2", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShrinkWidths(struct ImGuiShrinkWidthItem *, int, float) file:imgui_internal.h line:1559
	M("ImGui").def("ShrinkWidths", (void (*)(struct ImGuiShrinkWidthItem *, int, float)) &ImGui::ShrinkWidths, "C++: ImGui::ShrinkWidths(struct ImGuiShrinkWidthItem *, int, float) --> void", pybind11::arg("items"), pybind11::arg("count"), pybind11::arg("width_excess"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LogBegin(enum ImGuiLogType, int) file:imgui_internal.h line:1562
	M("ImGui").def("LogBegin", (void (*)(enum ImGuiLogType, int)) &ImGui::LogBegin, "C++: ImGui::LogBegin(enum ImGuiLogType, int) --> void", pybind11::arg("type"), pybind11::arg("auto_open_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LogToBuffer(int) file:imgui_internal.h line:1563
	M("ImGui").def("LogToBuffer", []() -> void { return ImGui::LogToBuffer(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("LogToBuffer", (void (*)(int)) &ImGui::LogToBuffer, "C++: ImGui::LogToBuffer(int) --> void", pybind11::arg("auto_open_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::OpenPopupEx(unsigned int) file:imgui_internal.h line:1566
	M("ImGui").def("OpenPopupEx", (void (*)(unsigned int)) &ImGui::OpenPopupEx, "C++: ImGui::OpenPopupEx(unsigned int) --> void", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ClosePopupToLevel(int, bool) file:imgui_internal.h line:1567
	M("ImGui").def("ClosePopupToLevel", (void (*)(int, bool)) &ImGui::ClosePopupToLevel, "C++: ImGui::ClosePopupToLevel(int, bool) --> void", pybind11::arg("remaining"), pybind11::arg("restore_focus_to_window_under_popup"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ClosePopupsOverWindow(struct ImGuiWindow *, bool) file:imgui_internal.h line:1568
	M("ImGui").def("ClosePopupsOverWindow", (void (*)(struct ImGuiWindow *, bool)) &ImGui::ClosePopupsOverWindow, "C++: ImGui::ClosePopupsOverWindow(struct ImGuiWindow *, bool) --> void", pybind11::arg("ref_window"), pybind11::arg("restore_focus_to_window_under_popup"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsPopupOpen(unsigned int) file:imgui_internal.h line:1569
	M("ImGui").def("IsPopupOpen", (bool (*)(unsigned int)) &ImGui::IsPopupOpen, "C++: ImGui::IsPopupOpen(unsigned int) --> bool", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginPopupEx(unsigned int, int) file:imgui_internal.h line:1570
	M("ImGui").def("BeginPopupEx", (bool (*)(unsigned int, int)) &ImGui::BeginPopupEx, "C++: ImGui::BeginPopupEx(unsigned int, int) --> bool", pybind11::arg("id"), pybind11::arg("extra_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginTooltipEx(int, bool) file:imgui_internal.h line:1571
	M("ImGui").def("BeginTooltipEx", [](int const & a0) -> void { return ImGui::BeginTooltipEx(a0); }, "", pybind11::arg("extra_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginTooltipEx", (void (*)(int, bool)) &ImGui::BeginTooltipEx, "C++: ImGui::BeginTooltipEx(int, bool) --> void", pybind11::arg("extra_flags"), pybind11::arg("override_previous_tooltip"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetTopMostPopupModal() file:imgui_internal.h line:1572
	M("ImGui").def("GetTopMostPopupModal", (struct ImGuiWindow * (*)()) &ImGui::GetTopMostPopupModal, "C++: ImGui::GetTopMostPopupModal() --> struct ImGuiWindow *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FindBestWindowPosForPopup(struct ImGuiWindow *) file:imgui_internal.h line:1573
	M("ImGui").def("FindBestWindowPosForPopup", (struct ImVec2 (*)(struct ImGuiWindow *)) &ImGui::FindBestWindowPosForPopup, "C++: ImGui::FindBestWindowPosForPopup(struct ImGuiWindow *) --> struct ImVec2", pybind11::arg("window"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FindBestWindowPosForPopupEx(const struct ImVec2 &, const struct ImVec2 &, int *, const struct ImRect &, const struct ImRect &, enum ImGuiPopupPositionPolicy) file:imgui_internal.h line:1574
	M("ImGui").def("FindBestWindowPosForPopupEx", [](const struct ImVec2 & a0, const struct ImVec2 & a1, int * a2, const struct ImRect & a3, const struct ImRect & a4) -> ImVec2 { return ImGui::FindBestWindowPosForPopupEx(a0, a1, a2, a3, a4); }, "", pybind11::arg("ref_pos"), pybind11::arg("size"), pybind11::arg("last_dir"), pybind11::arg("r_outer"), pybind11::arg("r_avoid"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("FindBestWindowPosForPopupEx", (struct ImVec2 (*)(const struct ImVec2 &, const struct ImVec2 &, int *, const struct ImRect &, const struct ImRect &, enum ImGuiPopupPositionPolicy)) &ImGui::FindBestWindowPosForPopupEx, "C++: ImGui::FindBestWindowPosForPopupEx(const struct ImVec2 &, const struct ImVec2 &, int *, const struct ImRect &, const struct ImRect &, enum ImGuiPopupPositionPolicy) --> struct ImVec2", pybind11::arg("ref_pos"), pybind11::arg("size"), pybind11::arg("last_dir"), pybind11::arg("r_outer"), pybind11::arg("r_avoid"), pybind11::arg("policy"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::NavInitWindow(struct ImGuiWindow *, bool) file:imgui_internal.h line:1577
	M("ImGui").def("NavInitWindow", (void (*)(struct ImGuiWindow *, bool)) &ImGui::NavInitWindow, "C++: ImGui::NavInitWindow(struct ImGuiWindow *, bool) --> void", pybind11::arg("window"), pybind11::arg("force_reinit"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::NavMoveRequestButNoResultYet() file:imgui_internal.h line:1578
	M("ImGui").def("NavMoveRequestButNoResultYet", (bool (*)()) &ImGui::NavMoveRequestButNoResultYet, "C++: ImGui::NavMoveRequestButNoResultYet() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::NavMoveRequestCancel() file:imgui_internal.h line:1579
	M("ImGui").def("NavMoveRequestCancel", (void (*)()) &ImGui::NavMoveRequestCancel, "C++: ImGui::NavMoveRequestCancel() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::NavMoveRequestForward(int, int, const struct ImRect &, int) file:imgui_internal.h line:1580
	M("ImGui").def("NavMoveRequestForward", (void (*)(int, int, const struct ImRect &, int)) &ImGui::NavMoveRequestForward, "C++: ImGui::NavMoveRequestForward(int, int, const struct ImRect &, int) --> void", pybind11::arg("move_dir"), pybind11::arg("clip_dir"), pybind11::arg("bb_rel"), pybind11::arg("move_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::NavMoveRequestTryWrapping(struct ImGuiWindow *, int) file:imgui_internal.h line:1581
	M("ImGui").def("NavMoveRequestTryWrapping", (void (*)(struct ImGuiWindow *, int)) &ImGui::NavMoveRequestTryWrapping, "C++: ImGui::NavMoveRequestTryWrapping(struct ImGuiWindow *, int) --> void", pybind11::arg("window"), pybind11::arg("move_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetNavInputAmount(int, enum ImGuiInputReadMode) file:imgui_internal.h line:1582
	M("ImGui").def("GetNavInputAmount", (float (*)(int, enum ImGuiInputReadMode)) &ImGui::GetNavInputAmount, "C++: ImGui::GetNavInputAmount(int, enum ImGuiInputReadMode) --> float", pybind11::arg("n"), pybind11::arg("mode"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetNavInputAmount2d(int, enum ImGuiInputReadMode, float, float) file:imgui_internal.h line:1583
	M("ImGui").def("GetNavInputAmount2d", [](int const & a0, enum ImGuiInputReadMode const & a1) -> ImVec2 { return ImGui::GetNavInputAmount2d(a0, a1); }, "", pybind11::arg("dir_sources"), pybind11::arg("mode"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("GetNavInputAmount2d", [](int const & a0, enum ImGuiInputReadMode const & a1, float const & a2) -> ImVec2 { return ImGui::GetNavInputAmount2d(a0, a1, a2); }, "", pybind11::arg("dir_sources"), pybind11::arg("mode"), pybind11::arg("slow_factor"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("GetNavInputAmount2d", (struct ImVec2 (*)(int, enum ImGuiInputReadMode, float, float)) &ImGui::GetNavInputAmount2d, "C++: ImGui::GetNavInputAmount2d(int, enum ImGuiInputReadMode, float, float) --> struct ImVec2", pybind11::arg("dir_sources"), pybind11::arg("mode"), pybind11::arg("slow_factor"), pybind11::arg("fast_factor"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CalcTypematicRepeatAmount(float, float, float, float) file:imgui_internal.h line:1584
	M("ImGui").def("CalcTypematicRepeatAmount", (int (*)(float, float, float, float)) &ImGui::CalcTypematicRepeatAmount, "C++: ImGui::CalcTypematicRepeatAmount(float, float, float, float) --> int", pybind11::arg("t0"), pybind11::arg("t1"), pybind11::arg("repeat_delay"), pybind11::arg("repeat_rate"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ActivateItem(unsigned int) file:imgui_internal.h line:1585
	M("ImGui").def("ActivateItem", (void (*)(unsigned int)) &ImGui::ActivateItem, "C++: ImGui::ActivateItem(unsigned int) --> void", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_internal_4.cpp
#include <imgui.h>
#include <imgui_internal.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_internal_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::SetNavID(unsigned int, int) file:imgui_internal.h line:1586
	M("ImGui").def("SetNavID", (void (*)(unsigned int, int)) &ImGui::SetNavID, "C++: ImGui::SetNavID(unsigned int, int) --> void", pybind11::arg("id"), pybind11::arg("nav_layer"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SetNavIDWithRectRel(unsigned int, int, const struct ImRect &) file:imgui_internal.h line:1587
	M("ImGui").def("SetNavIDWithRectRel", (void (*)(unsigned int, int, const struct ImRect &)) &ImGui::SetNavIDWithRectRel, "C++: ImGui::SetNavIDWithRectRel(unsigned int, int, const struct ImRect &) --> void", pybind11::arg("id"), pybind11::arg("nav_layer"), pybind11::arg("rect_rel"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsActiveIdUsingNavDir(int) file:imgui_internal.h line:1591
	M("ImGui").def("IsActiveIdUsingNavDir", (bool (*)(int)) &ImGui::IsActiveIdUsingNavDir, "C++: ImGui::IsActiveIdUsingNavDir(int) --> bool", pybind11::arg("dir"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsActiveIdUsingNavInput(int) file:imgui_internal.h line:1592
	M("ImGui").def("IsActiveIdUsingNavInput", (bool (*)(int)) &ImGui::IsActiveIdUsingNavInput, "C++: ImGui::IsActiveIdUsingNavInput(int) --> bool", pybind11::arg("input"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsActiveIdUsingKey(int) file:imgui_internal.h line:1593
	M("ImGui").def("IsActiveIdUsingKey", (bool (*)(int)) &ImGui::IsActiveIdUsingKey, "C++: ImGui::IsActiveIdUsingKey(int) --> bool", pybind11::arg("key"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsMouseDragPastThreshold(int, float) file:imgui_internal.h line:1594
	M("ImGui").def("IsMouseDragPastThreshold", [](int const & a0) -> bool { return ImGui::IsMouseDragPastThreshold(a0); }, "", pybind11::arg("button"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsMouseDragPastThreshold", (bool (*)(int, float)) &ImGui::IsMouseDragPastThreshold, "C++: ImGui::IsMouseDragPastThreshold(int, float) --> bool", pybind11::arg("button"), pybind11::arg("lock_threshold"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsKeyPressedMap(int, bool) file:imgui_internal.h line:1595
	M("ImGui").def("IsKeyPressedMap", [](int const & a0) -> bool { return ImGui::IsKeyPressedMap(a0); }, "", pybind11::arg("key"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("IsKeyPressedMap", (bool (*)(int, bool)) &ImGui::IsKeyPressedMap, "C++: ImGui::IsKeyPressedMap(int, bool) --> bool", pybind11::arg("key"), pybind11::arg("repeat"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsNavInputDown(int) file:imgui_internal.h line:1596
	M("ImGui").def("IsNavInputDown", (bool (*)(int)) &ImGui::IsNavInputDown, "C++: ImGui::IsNavInputDown(int) --> bool", pybind11::arg("n"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsNavInputPressed(int, enum ImGuiInputReadMode) file:imgui_internal.h line:1597
	M("ImGui").def("IsNavInputPressed", (bool (*)(int, enum ImGuiInputReadMode)) &ImGui::IsNavInputPressed, "C++: ImGui::IsNavInputPressed(int, enum ImGuiInputReadMode) --> bool", pybind11::arg("n"), pybind11::arg("mode"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsNavInputPressedAnyOfTwo(int, int, enum ImGuiInputReadMode) file:imgui_internal.h line:1598
	M("ImGui").def("IsNavInputPressedAnyOfTwo", (bool (*)(int, int, enum ImGuiInputReadMode)) &ImGui::IsNavInputPressedAnyOfTwo, "C++: ImGui::IsNavInputPressedAnyOfTwo(int, int, enum ImGuiInputReadMode) --> bool", pybind11::arg("n1"), pybind11::arg("n2"), pybind11::arg("mode"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginDragDropTargetCustom(const struct ImRect &, unsigned int) file:imgui_internal.h line:1601
	M("ImGui").def("BeginDragDropTargetCustom", (bool (*)(const struct ImRect &, unsigned int)) &ImGui::BeginDragDropTargetCustom, "C++: ImGui::BeginDragDropTargetCustom(const struct ImRect &, unsigned int) --> bool", pybind11::arg("bb"), pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ClearDragDrop() file:imgui_internal.h line:1602
	M("ImGui").def("ClearDragDrop", (void (*)()) &ImGui::ClearDragDrop, "C++: ImGui::ClearDragDrop() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::IsDragDropPayloadBeingAccepted() file:imgui_internal.h line:1603
	M("ImGui").def("IsDragDropPayloadBeingAccepted", (bool (*)()) &ImGui::IsDragDropPayloadBeingAccepted, "C++: ImGui::IsDragDropPayloadBeingAccepted() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginColumns(const char *, int, int) file:imgui_internal.h line:1606
	M("ImGui").def("BeginColumns", [](const char * a0, int const & a1) -> void { return ImGui::BeginColumns(a0, a1); }, "", pybind11::arg("str_id"), pybind11::arg("count"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("BeginColumns", (void (*)(const char *, int, int)) &ImGui::BeginColumns, "C++: ImGui::BeginColumns(const char *, int, int) --> void", pybind11::arg("str_id"), pybind11::arg("count"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::EndColumns() file:imgui_internal.h line:1607
	M("ImGui").def("EndColumns", (void (*)()) &ImGui::EndColumns, "C++: ImGui::EndColumns() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushColumnClipRect(int) file:imgui_internal.h line:1608
	M("ImGui").def("PushColumnClipRect", (void (*)(int)) &ImGui::PushColumnClipRect, "C++: ImGui::PushColumnClipRect(int) --> void", pybind11::arg("column_index"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PushColumnsBackground() file:imgui_internal.h line:1609
	M("ImGui").def("PushColumnsBackground", (void (*)()) &ImGui::PushColumnsBackground, "C++: ImGui::PushColumnsBackground() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::PopColumnsBackground() file:imgui_internal.h line:1610
	M("ImGui").def("PopColumnsBackground", (void (*)()) &ImGui::PopColumnsBackground, "C++: ImGui::PopColumnsBackground() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColumnsID(const char *, int) file:imgui_internal.h line:1611
	M("ImGui").def("GetColumnsID", (unsigned int (*)(const char *, int)) &ImGui::GetColumnsID, "C++: ImGui::GetColumnsID(const char *, int) --> unsigned int", pybind11::arg("str_id"), pybind11::arg("count"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FindOrCreateColumns(struct ImGuiWindow *, unsigned int) file:imgui_internal.h line:1612
	M("ImGui").def("FindOrCreateColumns", (struct ImGuiColumns * (*)(struct ImGuiWindow *, unsigned int)) &ImGui::FindOrCreateColumns, "C++: ImGui::FindOrCreateColumns(struct ImGuiWindow *, unsigned int) --> struct ImGuiColumns *", pybind11::return_value_policy::reference, pybind11::arg("window"), pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColumnOffsetFromNorm(const struct ImGuiColumns *, float) file:imgui_internal.h line:1613
	M("ImGui").def("GetColumnOffsetFromNorm", (float (*)(const struct ImGuiColumns *, float)) &ImGui::GetColumnOffsetFromNorm, "C++: ImGui::GetColumnOffsetFromNorm(const struct ImGuiColumns *, float) --> float", pybind11::arg("columns"), pybind11::arg("offset_norm"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetColumnNormFromOffset(const struct ImGuiColumns *, float) file:imgui_internal.h line:1614
	M("ImGui").def("GetColumnNormFromOffset", (float (*)(const struct ImGuiColumns *, float)) &ImGui::GetColumnNormFromOffset, "C++: ImGui::GetColumnNormFromOffset(const struct ImGuiColumns *, float) --> float", pybind11::arg("columns"), pybind11::arg("offset"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::BeginTabBarEx(struct ImGuiTabBar *, const struct ImRect &, int) file:imgui_internal.h line:1617
	M("ImGui").def("BeginTabBarEx", (bool (*)(struct ImGuiTabBar *, const struct ImRect &, int)) &ImGui::BeginTabBarEx, "C++: ImGui::BeginTabBarEx(struct ImGuiTabBar *, const struct ImRect &, int) --> bool", pybind11::arg("tab_bar"), pybind11::arg("bb"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TabBarFindTabByID(struct ImGuiTabBar *, unsigned int) file:imgui_internal.h line:1618
	M("ImGui").def("TabBarFindTabByID", (struct ImGuiTabItem * (*)(struct ImGuiTabBar *, unsigned int)) &ImGui::TabBarFindTabByID, "C++: ImGui::TabBarFindTabByID(struct ImGuiTabBar *, unsigned int) --> struct ImGuiTabItem *", pybind11::return_value_policy::reference, pybind11::arg("tab_bar"), pybind11::arg("tab_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TabBarRemoveTab(struct ImGuiTabBar *, unsigned int) file:imgui_internal.h line:1619
	M("ImGui").def("TabBarRemoveTab", (void (*)(struct ImGuiTabBar *, unsigned int)) &ImGui::TabBarRemoveTab, "C++: ImGui::TabBarRemoveTab(struct ImGuiTabBar *, unsigned int) --> void", pybind11::arg("tab_bar"), pybind11::arg("tab_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TabBarCloseTab(struct ImGuiTabBar *, struct ImGuiTabItem *) file:imgui_internal.h line:1620
	M("ImGui").def("TabBarCloseTab", (void (*)(struct ImGuiTabBar *, struct ImGuiTabItem *)) &ImGui::TabBarCloseTab, "C++: ImGui::TabBarCloseTab(struct ImGuiTabBar *, struct ImGuiTabItem *) --> void", pybind11::arg("tab_bar"), pybind11::arg("tab"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TabBarQueueChangeTabOrder(struct ImGuiTabBar *, const struct ImGuiTabItem *, int) file:imgui_internal.h line:1621
	M("ImGui").def("TabBarQueueChangeTabOrder", (void (*)(struct ImGuiTabBar *, const struct ImGuiTabItem *, int)) &ImGui::TabBarQueueChangeTabOrder, "C++: ImGui::TabBarQueueChangeTabOrder(struct ImGuiTabBar *, const struct ImGuiTabItem *, int) --> void", pybind11::arg("tab_bar"), pybind11::arg("tab"), pybind11::arg("dir"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TabItemEx(struct ImGuiTabBar *, const char *, bool *, int) file:imgui_internal.h line:1622
	M("ImGui").def("TabItemEx", (bool (*)(struct ImGuiTabBar *, const char *, bool *, int)) &ImGui::TabItemEx, "C++: ImGui::TabItemEx(struct ImGuiTabBar *, const char *, bool *, int) --> bool", pybind11::arg("tab_bar"), pybind11::arg("label"), pybind11::arg("p_open"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TabItemCalcSize(const char *, bool) file:imgui_internal.h line:1623
	M("ImGui").def("TabItemCalcSize", (struct ImVec2 (*)(const char *, bool)) &ImGui::TabItemCalcSize, "C++: ImGui::TabItemCalcSize(const char *, bool) --> struct ImVec2", pybind11::arg("label"), pybind11::arg("has_close_button"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TabItemBackground(struct ImDrawList *, const struct ImRect &, int, unsigned int) file:imgui_internal.h line:1624
	M("ImGui").def("TabItemBackground", (void (*)(struct ImDrawList *, const struct ImRect &, int, unsigned int)) &ImGui::TabItemBackground, "C++: ImGui::TabItemBackground(struct ImDrawList *, const struct ImRect &, int, unsigned int) --> void", pybind11::arg("draw_list"), pybind11::arg("bb"), pybind11::arg("flags"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TabItemLabelAndCloseButton(struct ImDrawList *, const struct ImRect &, int, struct ImVec2, const char *, unsigned int, unsigned int) file:imgui_internal.h line:1625
	M("ImGui").def("TabItemLabelAndCloseButton", (bool (*)(struct ImDrawList *, const struct ImRect &, int, struct ImVec2, const char *, unsigned int, unsigned int)) &ImGui::TabItemLabelAndCloseButton, "C++: ImGui::TabItemLabelAndCloseButton(struct ImDrawList *, const struct ImRect &, int, struct ImVec2, const char *, unsigned int, unsigned int) --> bool", pybind11::arg("draw_list"), pybind11::arg("bb"), pybind11::arg("flags"), pybind11::arg("frame_padding"), pybind11::arg("label"), pybind11::arg("tab_id"), pybind11::arg("close_button_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderText(struct ImVec2, const char *, const char *, bool) file:imgui_internal.h line:1630
	M("ImGui").def("RenderText", [](struct ImVec2 const & a0, const char * a1) -> void { return ImGui::RenderText(a0, a1); }, "", pybind11::arg("pos"), pybind11::arg("text"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderText", [](struct ImVec2 const & a0, const char * a1, const char * a2) -> void { return ImGui::RenderText(a0, a1, a2); }, "", pybind11::arg("pos"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderText", (void (*)(struct ImVec2, const char *, const char *, bool)) &ImGui::RenderText, "C++: ImGui::RenderText(struct ImVec2, const char *, const char *, bool) --> void", pybind11::arg("pos"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("hide_text_after_hash"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderTextWrapped(struct ImVec2, const char *, const char *, float) file:imgui_internal.h line:1631
	M("ImGui").def("RenderTextWrapped", (void (*)(struct ImVec2, const char *, const char *, float)) &ImGui::RenderTextWrapped, "C++: ImGui::RenderTextWrapped(struct ImVec2, const char *, const char *, float) --> void", pybind11::arg("pos"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("wrap_width"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderTextClipped(const struct ImVec2 &, const struct ImVec2 &, const char *, const char *, const struct ImVec2 *, const struct ImVec2 &, const struct ImRect *) file:imgui_internal.h line:1632
	M("ImGui").def("RenderTextClipped", [](const struct ImVec2 & a0, const struct ImVec2 & a1, const char * a2, const char * a3, const struct ImVec2 * a4) -> void { return ImGui::RenderTextClipped(a0, a1, a2, a3, a4); }, "", pybind11::arg("pos_min"), pybind11::arg("pos_max"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("text_size_if_known"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderTextClipped", [](const struct ImVec2 & a0, const struct ImVec2 & a1, const char * a2, const char * a3, const struct ImVec2 * a4, const struct ImVec2 & a5) -> void { return ImGui::RenderTextClipped(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("pos_min"), pybind11::arg("pos_max"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("text_size_if_known"), pybind11::arg("align"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderTextClipped", (void (*)(const struct ImVec2 &, const struct ImVec2 &, const char *, const char *, const struct ImVec2 *, const struct ImVec2 &, const struct ImRect *)) &ImGui::RenderTextClipped, "C++: ImGui::RenderTextClipped(const struct ImVec2 &, const struct ImVec2 &, const char *, const char *, const struct ImVec2 *, const struct ImVec2 &, const struct ImRect *) --> void", pybind11::arg("pos_min"), pybind11::arg("pos_max"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("text_size_if_known"), pybind11::arg("align"), pybind11::arg("clip_rect"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderTextClippedEx(struct ImDrawList *, const struct ImVec2 &, const struct ImVec2 &, const char *, const char *, const struct ImVec2 *, const struct ImVec2 &, const struct ImRect *) file:imgui_internal.h line:1633
	M("ImGui").def("RenderTextClippedEx", [](struct ImDrawList * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const char * a3, const char * a4, const struct ImVec2 * a5) -> void { return ImGui::RenderTextClippedEx(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("draw_list"), pybind11::arg("pos_min"), pybind11::arg("pos_max"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("text_size_if_known"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderTextClippedEx", [](struct ImDrawList * a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const char * a3, const char * a4, const struct ImVec2 * a5, const struct ImVec2 & a6) -> void { return ImGui::RenderTextClippedEx(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("draw_list"), pybind11::arg("pos_min"), pybind11::arg("pos_max"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("text_size_if_known"), pybind11::arg("align"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderTextClippedEx", (void (*)(struct ImDrawList *, const struct ImVec2 &, const struct ImVec2 &, const char *, const char *, const struct ImVec2 *, const struct ImVec2 &, const struct ImRect *)) &ImGui::RenderTextClippedEx, "C++: ImGui::RenderTextClippedEx(struct ImDrawList *, const struct ImVec2 &, const struct ImVec2 &, const char *, const char *, const struct ImVec2 *, const struct ImVec2 &, const struct ImRect *) --> void", pybind11::arg("draw_list"), pybind11::arg("pos_min"), pybind11::arg("pos_max"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("text_size_if_known"), pybind11::arg("align"), pybind11::arg("clip_rect"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_internal_5.cpp
#include <imgui.h>
#include <imgui_internal.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_internal_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::RenderTextEllipsis(struct ImDrawList *, const struct ImVec2 &, const struct ImVec2 &, float, float, const char *, const char *, const struct ImVec2 *) file:imgui_internal.h line:1634
	M("ImGui").def("RenderTextEllipsis", (void (*)(struct ImDrawList *, const struct ImVec2 &, const struct ImVec2 &, float, float, const char *, const char *, const struct ImVec2 *)) &ImGui::RenderTextEllipsis, "C++: ImGui::RenderTextEllipsis(struct ImDrawList *, const struct ImVec2 &, const struct ImVec2 &, float, float, const char *, const char *, const struct ImVec2 *) --> void", pybind11::arg("draw_list"), pybind11::arg("pos_min"), pybind11::arg("pos_max"), pybind11::arg("clip_max_x"), pybind11::arg("ellipsis_max_x"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("text_size_if_known"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderFrame(struct ImVec2, struct ImVec2, unsigned int, bool, float) file:imgui_internal.h line:1635
	M("ImGui").def("RenderFrame", [](struct ImVec2 const & a0, struct ImVec2 const & a1, unsigned int const & a2) -> void { return ImGui::RenderFrame(a0, a1, a2); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("fill_col"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderFrame", [](struct ImVec2 const & a0, struct ImVec2 const & a1, unsigned int const & a2, bool const & a3) -> void { return ImGui::RenderFrame(a0, a1, a2, a3); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("fill_col"), pybind11::arg("border"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderFrame", (void (*)(struct ImVec2, struct ImVec2, unsigned int, bool, float)) &ImGui::RenderFrame, "C++: ImGui::RenderFrame(struct ImVec2, struct ImVec2, unsigned int, bool, float) --> void", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("fill_col"), pybind11::arg("border"), pybind11::arg("rounding"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderFrameBorder(struct ImVec2, struct ImVec2, float) file:imgui_internal.h line:1636
	M("ImGui").def("RenderFrameBorder", [](struct ImVec2 const & a0, struct ImVec2 const & a1) -> void { return ImGui::RenderFrameBorder(a0, a1); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderFrameBorder", (void (*)(struct ImVec2, struct ImVec2, float)) &ImGui::RenderFrameBorder, "C++: ImGui::RenderFrameBorder(struct ImVec2, struct ImVec2, float) --> void", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("rounding"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderColorRectWithAlphaCheckerboard(struct ImVec2, struct ImVec2, unsigned int, float, struct ImVec2, float, int) file:imgui_internal.h line:1637
	M("ImGui").def("RenderColorRectWithAlphaCheckerboard", [](struct ImVec2 const & a0, struct ImVec2 const & a1, unsigned int const & a2, float const & a3, struct ImVec2 const & a4) -> void { return ImGui::RenderColorRectWithAlphaCheckerboard(a0, a1, a2, a3, a4); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("fill_col"), pybind11::arg("grid_step"), pybind11::arg("grid_off"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderColorRectWithAlphaCheckerboard", [](struct ImVec2 const & a0, struct ImVec2 const & a1, unsigned int const & a2, float const & a3, struct ImVec2 const & a4, float const & a5) -> void { return ImGui::RenderColorRectWithAlphaCheckerboard(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("fill_col"), pybind11::arg("grid_step"), pybind11::arg("grid_off"), pybind11::arg("rounding"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderColorRectWithAlphaCheckerboard", (void (*)(struct ImVec2, struct ImVec2, unsigned int, float, struct ImVec2, float, int)) &ImGui::RenderColorRectWithAlphaCheckerboard, "C++: ImGui::RenderColorRectWithAlphaCheckerboard(struct ImVec2, struct ImVec2, unsigned int, float, struct ImVec2, float, int) --> void", pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("fill_col"), pybind11::arg("grid_step"), pybind11::arg("grid_off"), pybind11::arg("rounding"), pybind11::arg("rounding_corners_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderCheckMark(struct ImVec2, unsigned int, float) file:imgui_internal.h line:1638
	M("ImGui").def("RenderCheckMark", (void (*)(struct ImVec2, unsigned int, float)) &ImGui::RenderCheckMark, "C++: ImGui::RenderCheckMark(struct ImVec2, unsigned int, float) --> void", pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("sz"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderNavHighlight(const struct ImRect &, unsigned int, int) file:imgui_internal.h line:1639
	M("ImGui").def("RenderNavHighlight", [](const struct ImRect & a0, unsigned int const & a1) -> void { return ImGui::RenderNavHighlight(a0, a1); }, "", pybind11::arg("bb"), pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderNavHighlight", (void (*)(const struct ImRect &, unsigned int, int)) &ImGui::RenderNavHighlight, "C++: ImGui::RenderNavHighlight(const struct ImRect &, unsigned int, int) --> void", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::FindRenderedTextEnd(const char *, const char *) file:imgui_internal.h line:1640
	M("ImGui").def("FindRenderedTextEnd", [](const char * a0) -> const char * { return ImGui::FindRenderedTextEnd(a0); }, "", pybind11::return_value_policy::reference, pybind11::arg("text"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("FindRenderedTextEnd", (const char * (*)(const char *, const char *)) &ImGui::FindRenderedTextEnd, "C++: ImGui::FindRenderedTextEnd(const char *, const char *) --> const char *", pybind11::return_value_policy::reference, pybind11::arg("text"), pybind11::arg("text_end"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::LogRenderedText(const struct ImVec2 *, const char *, const char *) file:imgui_internal.h line:1641
	M("ImGui").def("LogRenderedText", [](const struct ImVec2 * a0, const char * a1) -> void { return ImGui::LogRenderedText(a0, a1); }, "", pybind11::arg("ref_pos"), pybind11::arg("text"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("LogRenderedText", (void (*)(const struct ImVec2 *, const char *, const char *)) &ImGui::LogRenderedText, "C++: ImGui::LogRenderedText(const struct ImVec2 *, const char *, const char *) --> void", pybind11::arg("ref_pos"), pybind11::arg("text"), pybind11::arg("text_end"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderArrow(struct ImDrawList *, struct ImVec2, unsigned int, int, float) file:imgui_internal.h line:1644
	M("ImGui").def("RenderArrow", [](struct ImDrawList * a0, struct ImVec2 const & a1, unsigned int const & a2, int const & a3) -> void { return ImGui::RenderArrow(a0, a1, a2, a3); }, "", pybind11::arg("draw_list"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("dir"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("RenderArrow", (void (*)(struct ImDrawList *, struct ImVec2, unsigned int, int, float)) &ImGui::RenderArrow, "C++: ImGui::RenderArrow(struct ImDrawList *, struct ImVec2, unsigned int, int, float) --> void", pybind11::arg("draw_list"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::arg("dir"), pybind11::arg("scale"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderBullet(struct ImDrawList *, struct ImVec2, unsigned int) file:imgui_internal.h line:1645
	M("ImGui").def("RenderBullet", (void (*)(struct ImDrawList *, struct ImVec2, unsigned int)) &ImGui::RenderBullet, "C++: ImGui::RenderBullet(struct ImDrawList *, struct ImVec2, unsigned int) --> void", pybind11::arg("draw_list"), pybind11::arg("pos"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderMouseCursor(struct ImDrawList *, struct ImVec2, float, int, unsigned int, unsigned int, unsigned int) file:imgui_internal.h line:1646
	M("ImGui").def("RenderMouseCursor", (void (*)(struct ImDrawList *, struct ImVec2, float, int, unsigned int, unsigned int, unsigned int)) &ImGui::RenderMouseCursor, "C++: ImGui::RenderMouseCursor(struct ImDrawList *, struct ImVec2, float, int, unsigned int, unsigned int, unsigned int) --> void", pybind11::arg("draw_list"), pybind11::arg("pos"), pybind11::arg("scale"), pybind11::arg("mouse_cursor"), pybind11::arg("col_fill"), pybind11::arg("col_border"), pybind11::arg("col_shadow"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderArrowPointingAt(struct ImDrawList *, struct ImVec2, struct ImVec2, int, unsigned int) file:imgui_internal.h line:1647
	M("ImGui").def("RenderArrowPointingAt", (void (*)(struct ImDrawList *, struct ImVec2, struct ImVec2, int, unsigned int)) &ImGui::RenderArrowPointingAt, "C++: ImGui::RenderArrowPointingAt(struct ImDrawList *, struct ImVec2, struct ImVec2, int, unsigned int) --> void", pybind11::arg("draw_list"), pybind11::arg("pos"), pybind11::arg("half_sz"), pybind11::arg("direction"), pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::RenderRectFilledRangeH(struct ImDrawList *, const struct ImRect &, unsigned int, float, float, float) file:imgui_internal.h line:1648
	M("ImGui").def("RenderRectFilledRangeH", (void (*)(struct ImDrawList *, const struct ImRect &, unsigned int, float, float, float)) &ImGui::RenderRectFilledRangeH, "C++: ImGui::RenderRectFilledRangeH(struct ImDrawList *, const struct ImRect &, unsigned int, float, float, float) --> void", pybind11::arg("draw_list"), pybind11::arg("rect"), pybind11::arg("col"), pybind11::arg("x_start_norm"), pybind11::arg("x_end_norm"), pybind11::arg("rounding"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TextEx(const char *, const char *, int) file:imgui_internal.h line:1657
	M("ImGui").def("TextEx", [](const char * a0) -> void { return ImGui::TextEx(a0); }, "", pybind11::arg("text"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("TextEx", [](const char * a0, const char * a1) -> void { return ImGui::TextEx(a0, a1); }, "", pybind11::arg("text"), pybind11::arg("text_end"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("TextEx", (void (*)(const char *, const char *, int)) &ImGui::TextEx, "C++: ImGui::TextEx(const char *, const char *, int) --> void", pybind11::arg("text"), pybind11::arg("text_end"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ButtonEx(const char *, const struct ImVec2 &, int) file:imgui_internal.h line:1658
	M("ImGui").def("ButtonEx", [](const char * a0) -> bool { return ImGui::ButtonEx(a0); }, "", pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ButtonEx", [](const char * a0, const struct ImVec2 & a1) -> bool { return ImGui::ButtonEx(a0, a1); }, "", pybind11::arg("label"), pybind11::arg("size_arg"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ButtonEx", (bool (*)(const char *, const struct ImVec2 &, int)) &ImGui::ButtonEx, "C++: ImGui::ButtonEx(const char *, const struct ImVec2 &, int) --> bool", pybind11::arg("label"), pybind11::arg("size_arg"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CloseButton(unsigned int, const struct ImVec2 &) file:imgui_internal.h line:1659
	M("ImGui").def("CloseButton", (bool (*)(unsigned int, const struct ImVec2 &)) &ImGui::CloseButton, "C++: ImGui::CloseButton(unsigned int, const struct ImVec2 &) --> bool", pybind11::arg("id"), pybind11::arg("pos"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::CollapseButton(unsigned int, const struct ImVec2 &) file:imgui_internal.h line:1660
	M("ImGui").def("CollapseButton", (bool (*)(unsigned int, const struct ImVec2 &)) &ImGui::CollapseButton, "C++: ImGui::CollapseButton(unsigned int, const struct ImVec2 &) --> bool", pybind11::arg("id"), pybind11::arg("pos"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ArrowButtonEx(const char *, int, struct ImVec2, int) file:imgui_internal.h line:1661
	M("ImGui").def("ArrowButtonEx", (bool (*)(const char *, int, struct ImVec2, int)) &ImGui::ArrowButtonEx, "C++: ImGui::ArrowButtonEx(const char *, int, struct ImVec2, int) --> bool", pybind11::arg("str_id"), pybind11::arg("dir"), pybind11::arg("size_arg"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::Scrollbar(enum ImGuiAxis) file:imgui_internal.h line:1662
	M("ImGui").def("Scrollbar", (void (*)(enum ImGuiAxis)) &ImGui::Scrollbar, "C++: ImGui::Scrollbar(enum ImGuiAxis) --> void", pybind11::arg("axis"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ScrollbarEx(const struct ImRect &, unsigned int, enum ImGuiAxis, float *, float, float, int) file:imgui_internal.h line:1663
	M("ImGui").def("ScrollbarEx", (bool (*)(const struct ImRect &, unsigned int, enum ImGuiAxis, float *, float, float, int)) &ImGui::ScrollbarEx, "C++: ImGui::ScrollbarEx(const struct ImRect &, unsigned int, enum ImGuiAxis, float *, float, float, int) --> bool", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("axis"), pybind11::arg("p_scroll_v"), pybind11::arg("avail_v"), pybind11::arg("contents_v"), pybind11::arg("rounding_corners"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::GetScrollbarID(struct ImGuiWindow *, enum ImGuiAxis) file:imgui_internal.h line:1664
	M("ImGui").def("GetScrollbarID", (unsigned int (*)(struct ImGuiWindow *, enum ImGuiAxis)) &ImGui::GetScrollbarID, "C++: ImGui::GetScrollbarID(struct ImGuiWindow *, enum ImGuiAxis) --> unsigned int", pybind11::arg("window"), pybind11::arg("axis"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SeparatorEx(int) file:imgui_internal.h line:1665
	M("ImGui").def("SeparatorEx", (void (*)(int)) &ImGui::SeparatorEx, "C++: ImGui::SeparatorEx(int) --> void", pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ButtonBehavior(const struct ImRect &, unsigned int, bool *, bool *, int) file:imgui_internal.h line:1668
	M("ImGui").def("ButtonBehavior", [](const struct ImRect & a0, unsigned int const & a1, bool * a2, bool * a3) -> bool { return ImGui::ButtonBehavior(a0, a1, a2, a3); }, "", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("out_hovered"), pybind11::arg("out_held"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("ButtonBehavior", (bool (*)(const struct ImRect &, unsigned int, bool *, bool *, int)) &ImGui::ButtonBehavior, "C++: ImGui::ButtonBehavior(const struct ImRect &, unsigned int, bool *, bool *, int) --> bool", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("out_hovered"), pybind11::arg("out_held"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DragBehavior(unsigned int, int, void *, float, const void *, const void *, const char *, float, int) file:imgui_internal.h line:1669
	M("ImGui").def("DragBehavior", (bool (*)(unsigned int, int, void *, float, const void *, const void *, const char *, float, int)) &ImGui::DragBehavior, "C++: ImGui::DragBehavior(unsigned int, int, void *, float, const void *, const void *, const char *, float, int) --> bool", pybind11::arg("id"), pybind11::arg("data_type"), pybind11::arg("p_v"), pybind11::arg("v_speed"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::SliderBehavior(const struct ImRect &, unsigned int, int, void *, const void *, const void *, const char *, float, int, struct ImRect *) file:imgui_internal.h line:1670
	M("ImGui").def("SliderBehavior", (bool (*)(const struct ImRect &, unsigned int, int, void *, const void *, const void *, const char *, float, int, struct ImRect *)) &ImGui::SliderBehavior, "C++: ImGui::SliderBehavior(const struct ImRect &, unsigned int, int, void *, const void *, const void *, const char *, float, int, struct ImRect *) --> bool", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("data_type"), pybind11::arg("p_v"), pybind11::arg("p_min"), pybind11::arg("p_max"), pybind11::arg("format"), pybind11::arg("power"), pybind11::arg("flags"), pybind11::arg("out_grab_bb"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: imgui_internal_6.cpp
#include <imgui.h>
#include <imgui_internal.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_imgui_internal_6(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::SplitterBehavior(const struct ImRect &, unsigned int, enum ImGuiAxis, float *, float *, float, float, float, float) file:imgui_internal.h line:1671
	M("ImGui").def("SplitterBehavior", [](const struct ImRect & a0, unsigned int const & a1, enum ImGuiAxis const & a2, float * a3, float * a4, float const & a5, float const & a6) -> bool { return ImGui::SplitterBehavior(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("axis"), pybind11::arg("size1"), pybind11::arg("size2"), pybind11::arg("min_size1"), pybind11::arg("min_size2"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SplitterBehavior", [](const struct ImRect & a0, unsigned int const & a1, enum ImGuiAxis const & a2, float * a3, float * a4, float const & a5, float const & a6, float const & a7) -> bool { return ImGui::SplitterBehavior(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("axis"), pybind11::arg("size1"), pybind11::arg("size2"), pybind11::arg("min_size1"), pybind11::arg("min_size2"), pybind11::arg("hover_extend"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("SplitterBehavior", (bool (*)(const struct ImRect &, unsigned int, enum ImGuiAxis, float *, float *, float, float, float, float)) &ImGui::SplitterBehavior, "C++: ImGui::SplitterBehavior(const struct ImRect &, unsigned int, enum ImGuiAxis, float *, float *, float, float, float, float) --> bool", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("axis"), pybind11::arg("size1"), pybind11::arg("size2"), pybind11::arg("min_size1"), pybind11::arg("min_size2"), pybind11::arg("hover_extend"), pybind11::arg("hover_visibility_delay"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreeNodeBehavior(unsigned int, int, const char *, const char *) file:imgui_internal.h line:1672
	M("ImGui").def("TreeNodeBehavior", [](unsigned int const & a0, int const & a1, const char * a2) -> bool { return ImGui::TreeNodeBehavior(a0, a1, a2); }, "", pybind11::arg("id"), pybind11::arg("flags"), pybind11::arg("label"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("TreeNodeBehavior", (bool (*)(unsigned int, int, const char *, const char *)) &ImGui::TreeNodeBehavior, "C++: ImGui::TreeNodeBehavior(unsigned int, int, const char *, const char *) --> bool", pybind11::arg("id"), pybind11::arg("flags"), pybind11::arg("label"), pybind11::arg("label_end"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreeNodeBehaviorIsOpen(unsigned int, int) file:imgui_internal.h line:1673
	M("ImGui").def("TreeNodeBehaviorIsOpen", [](unsigned int const & a0) -> bool { return ImGui::TreeNodeBehaviorIsOpen(a0); }, "", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("TreeNodeBehaviorIsOpen", (bool (*)(unsigned int, int)) &ImGui::TreeNodeBehaviorIsOpen, "C++: ImGui::TreeNodeBehaviorIsOpen(unsigned int, int) --> bool", pybind11::arg("id"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TreePushOverrideID(unsigned int) file:imgui_internal.h line:1674
	M("ImGui").def("TreePushOverrideID", (void (*)(unsigned int)) &ImGui::TreePushOverrideID, "C++: ImGui::TreePushOverrideID(unsigned int) --> void", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DataTypeGetInfo(int) file:imgui_internal.h line:1685
	M("ImGui").def("DataTypeGetInfo", (const struct ImGuiDataTypeInfo * (*)(int)) &ImGui::DataTypeGetInfo, "C++: ImGui::DataTypeGetInfo(int) --> const struct ImGuiDataTypeInfo *", pybind11::return_value_policy::reference, pybind11::arg("data_type"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DataTypeFormatString(char *, int, int, const void *, const char *) file:imgui_internal.h line:1686
	M("ImGui").def("DataTypeFormatString", (int (*)(char *, int, int, const void *, const char *)) &ImGui::DataTypeFormatString, "C++: ImGui::DataTypeFormatString(char *, int, int, const void *, const char *) --> int", pybind11::arg("buf"), pybind11::arg("buf_size"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DataTypeApplyOp(int, int, void *, void *, const void *) file:imgui_internal.h line:1687
	M("ImGui").def("DataTypeApplyOp", (void (*)(int, int, void *, void *, const void *)) &ImGui::DataTypeApplyOp, "C++: ImGui::DataTypeApplyOp(int, int, void *, void *, const void *) --> void", pybind11::arg("data_type"), pybind11::arg("op"), pybind11::arg("output"), pybind11::arg("arg_1"), pybind11::arg("arg_2"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DataTypeApplyOpFromText(const char *, const char *, int, void *, const char *) file:imgui_internal.h line:1688
	M("ImGui").def("DataTypeApplyOpFromText", (bool (*)(const char *, const char *, int, void *, const char *)) &ImGui::DataTypeApplyOpFromText, "C++: ImGui::DataTypeApplyOpFromText(const char *, const char *, int, void *, const char *) --> bool", pybind11::arg("buf"), pybind11::arg("initial_value_buf"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TempInputTextScalar(const struct ImRect &, unsigned int, const char *, int, void *, const char *) file:imgui_internal.h line:1692
	M("ImGui").def("TempInputTextScalar", (bool (*)(const struct ImRect &, unsigned int, const char *, int, void *, const char *)) &ImGui::TempInputTextScalar, "C++: ImGui::TempInputTextScalar(const struct ImRect &, unsigned int, const char *, int, void *, const char *) --> bool", pybind11::arg("bb"), pybind11::arg("id"), pybind11::arg("label"), pybind11::arg("data_type"), pybind11::arg("p_data"), pybind11::arg("format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::TempInputTextIsActive(unsigned int) file:imgui_internal.h line:1693
	M("ImGui").def("TempInputTextIsActive", (bool (*)(unsigned int)) &ImGui::TempInputTextIsActive, "C++: ImGui::TempInputTextIsActive(unsigned int) --> bool", pybind11::arg("id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorTooltip(const char *, const float *, int) file:imgui_internal.h line:1696
	M("ImGui").def("ColorTooltip", (void (*)(const char *, const float *, int)) &ImGui::ColorTooltip, "C++: ImGui::ColorTooltip(const char *, const float *, int) --> void", pybind11::arg("text"), pybind11::arg("col"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorEditOptionsPopup(const float *, int) file:imgui_internal.h line:1697
	M("ImGui").def("ColorEditOptionsPopup", (void (*)(const float *, int)) &ImGui::ColorEditOptionsPopup, "C++: ImGui::ColorEditOptionsPopup(const float *, int) --> void", pybind11::arg("col"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ColorPickerOptionsPopup(const float *, int) file:imgui_internal.h line:1698
	M("ImGui").def("ColorPickerOptionsPopup", (void (*)(const float *, int)) &ImGui::ColorPickerOptionsPopup, "C++: ImGui::ColorPickerOptionsPopup(const float *, int) --> void", pybind11::arg("ref_col"), pybind11::arg("flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShadeVertsLinearColorGradientKeepAlpha(struct ImDrawList *, int, int, struct ImVec2, struct ImVec2, unsigned int, unsigned int) file:imgui_internal.h line:1704
	M("ImGui").def("ShadeVertsLinearColorGradientKeepAlpha", (void (*)(struct ImDrawList *, int, int, struct ImVec2, struct ImVec2, unsigned int, unsigned int)) &ImGui::ShadeVertsLinearColorGradientKeepAlpha, "C++: ImGui::ShadeVertsLinearColorGradientKeepAlpha(struct ImDrawList *, int, int, struct ImVec2, struct ImVec2, unsigned int, unsigned int) --> void", pybind11::arg("draw_list"), pybind11::arg("vert_start_idx"), pybind11::arg("vert_end_idx"), pybind11::arg("gradient_p0"), pybind11::arg("gradient_p1"), pybind11::arg("col0"), pybind11::arg("col1"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::ShadeVertsLinearUV(struct ImDrawList *, int, int, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, bool) file:imgui_internal.h line:1705
	M("ImGui").def("ShadeVertsLinearUV", (void (*)(struct ImDrawList *, int, int, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, bool)) &ImGui::ShadeVertsLinearUV, "C++: ImGui::ShadeVertsLinearUV(struct ImDrawList *, int, int, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, bool) --> void", pybind11::arg("draw_list"), pybind11::arg("vert_start_idx"), pybind11::arg("vert_end_idx"), pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("uv_a"), pybind11::arg("uv_b"), pybind11::arg("clamp"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DebugDrawItemRect(unsigned int) file:imgui_internal.h line:1708
	M("ImGui").def("DebugDrawItemRect", []() -> void { return ImGui::DebugDrawItemRect(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGui").def("DebugDrawItemRect", (void (*)(unsigned int)) &ImGui::DebugDrawItemRect, "C++: ImGui::DebugDrawItemRect(unsigned int) --> void", pybind11::arg("col"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::DebugStartItemPicker() file:imgui_internal.h line:1709
	M("ImGui").def("DebugStartItemPicker", (void (*)()) &ImGui::DebugStartItemPicker, "C++: ImGui::DebugStartItemPicker() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

}
