// File: imgui.cpp
#include <dear-imgui/imgui.h>
#include <common/imgui/imgui.h>
#include <bgfx.h>
#include <bx/allocator.h>

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

void bind_imgui_extra(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ImGui::imguiCreate(float, struct bx::AllocatorI *) file:imgui.h line:39
	M("ImGuiExtra").def("imgui_create", []() -> void { return ::imguiCreate(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuiExtra").def("imgui_create", [](float const & a0) -> void { return ::imguiCreate(a0); }, "", pybind11::arg("_fontSize"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuiExtra").def("imgui_create", (void (*)(float, struct bx::AllocatorI *)) &::imguiCreate, "C++: ImGui::imguiCreate(float, struct bx::AllocatorI *) --> void", pybind11::arg("_fontSize"), pybind11::arg("_allocator"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::imguiDestroy() file:imgui.h line:40
	M("ImGuiExtra").def("imgui_destroy", (void (*)()) &::imguiDestroy, "C++: ImGui::imguiDestroy() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::imguiBeginFrame(int, int, unsigned char, int, unsigned short, unsigned short, int, unsigned short) file:imgui.h line:42
	M("ImGuiExtra").def("imgui_begin_frame", [](int const & a0, int const & a1, unsigned char const & a2, int const & a3, unsigned short const & a4, unsigned short const & a5) -> void { return ::imguiBeginFrame(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_mx"), pybind11::arg("_my"), pybind11::arg("_button"), pybind11::arg("_scroll"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuiExtra").def("imgui_begin_frame", [](int const & a0, int const & a1, unsigned char const & a2, int const & a3, unsigned short const & a4, unsigned short const & a5, int const & a6) -> void { return ::imguiBeginFrame(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("_mx"), pybind11::arg("_my"), pybind11::arg("_button"), pybind11::arg("_scroll"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_inputChar"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuiExtra").def("imgui_begin_frame", (void (*)(int, int, unsigned char, int, unsigned short, unsigned short, int, unsigned short)) &::imguiBeginFrame, "C++: ImGui::imguiBeginFrame(int, int, unsigned char, int, unsigned short, unsigned short, int, unsigned short) --> void", pybind11::arg("_mx"), pybind11::arg("_my"), pybind11::arg("_button"), pybind11::arg("_scroll"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_inputChar"), pybind11::arg("_view"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::imguiEndFrame() file:imgui.h line:43
	M("ImGuiExtra").def("imgui_end_frame", (void (*)()) &::imguiEndFrame, "C++: ImGui::imguiEndFrame() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

}