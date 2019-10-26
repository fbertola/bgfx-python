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
	M("ImGuiExtra").def("imguiCreate", []() -> void { return ::imguiCreate(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuiExtra").def("imguiCreate", [](float const & a0) -> void { return ::imguiCreate(a0); }, "", pybind11::arg("_fontSize"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuiExtra").def("imguiCreate", (void (*)(float, struct bx::AllocatorI *)) &::imguiCreate, "C++: ImGui::imguiCreate(float, struct bx::AllocatorI *) --> void", pybind11::arg("_fontSize"), pybind11::arg("_allocator"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::imguiDestroy() file:imgui.h line:40
	M("ImGuiExtra").def("imguiDestroy", (void (*)()) &::imguiDestroy, "C++: ImGui::imguiDestroy() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::imguiBeginFrame(int, int, unsigned char, int, unsigned short, unsigned short, int, unsigned short) file:imgui.h line:42
	M("ImGuiExtra").def("imguiBeginFrame", [](int const & a0, int const & a1, unsigned char const & a2, int const & a3, unsigned short const & a4, unsigned short const & a5) -> void { return ::imguiBeginFrame(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_mx"), pybind11::arg("_my"), pybind11::arg("_button"), pybind11::arg("_scroll"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuiExtra").def("imguiBeginFrame", [](int const & a0, int const & a1, unsigned char const & a2, int const & a3, unsigned short const & a4, unsigned short const & a5, int const & a6) -> void { return ::imguiBeginFrame(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("_mx"), pybind11::arg("_my"), pybind11::arg("_button"), pybind11::arg("_scroll"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_inputChar"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("ImGuiExtra").def("imguiBeginFrame", (void (*)(int, int, unsigned char, int, unsigned short, unsigned short, int, unsigned short)) &::imguiBeginFrame, "C++: ImGui::imguiBeginFrame(int, int, unsigned char, int, unsigned short, unsigned short, int, unsigned short) --> void", pybind11::arg("_mx"), pybind11::arg("_my"), pybind11::arg("_button"), pybind11::arg("_scroll"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_inputChar"), pybind11::arg("_view"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// ImGui::imguiEndFrame() file:imgui.h line:43
	M("ImGuiExtra").def("imguiEndFrame", (void (*)()) &::imguiEndFrame, "C++: ImGui::imguiEndFrame() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

//	// ImGui::Image(struct bgfx::TextureHandle, unsigned char, unsigned char, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec4 &, const struct ImVec4 &) file:imgui.h line:46
//	M("ImGuiExtra").def("Image", [](struct bgfx::TextureHandle const & a0, unsigned char const & a1, unsigned char const & a2, const struct ImVec2 & a3) -> void { return ImGui::Image(a0, a1, a2, a3); }, "", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("Image", [](struct bgfx::TextureHandle const & a0, unsigned char const & a1, unsigned char const & a2, const struct ImVec2 & a3, const struct ImVec2 & a4) -> void { return ImGui::Image(a0, a1, a2, a3, a4); }, "", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("Image", [](struct bgfx::TextureHandle const & a0, unsigned char const & a1, unsigned char const & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, const struct ImVec2 & a5) -> void { return ImGui::Image(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("Image", [](struct bgfx::TextureHandle const & a0, unsigned char const & a1, unsigned char const & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, const struct ImVec2 & a5, const struct ImVec4 & a6) -> void { return ImGui::Image(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_tintCol"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("Image", (void (*)(struct bgfx::TextureHandle, unsigned char, unsigned char, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec4 &, const struct ImVec4 &)) &ImGui::Image, "C++: ImGui::Image(struct bgfx::TextureHandle, unsigned char, unsigned char, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec4 &, const struct ImVec4 &) --> void", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_tintCol"), pybind11::arg("_borderCol"), pybind11::call_guard<pybind11::gil_scoped_release>());
//
//	// ImGui::Image(struct bgfx::TextureHandle, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec4 &, const struct ImVec4 &) file:imgui.h line:64
//	M("ImGuiExtra").def("Image", [](struct bgfx::TextureHandle const & a0, const struct ImVec2 & a1) -> void { return ImGui::Image(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("Image", [](struct bgfx::TextureHandle const & a0, const struct ImVec2 & a1, const struct ImVec2 & a2) -> void { return ImGui::Image(a0, a1, a2); }, "", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("Image", [](struct bgfx::TextureHandle const & a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3) -> void { return ImGui::Image(a0, a1, a2, a3); }, "", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("Image", [](struct bgfx::TextureHandle const & a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, const struct ImVec4 & a4) -> void { return ImGui::Image(a0, a1, a2, a3, a4); }, "", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_tintCol"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("Image", (void (*)(struct bgfx::TextureHandle, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec4 &, const struct ImVec4 &)) &ImGui::Image, "C++: ImGui::Image(struct bgfx::TextureHandle, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec4 &, const struct ImVec4 &) --> void", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_tintCol"), pybind11::arg("_borderCol"), pybind11::call_guard<pybind11::gil_scoped_release>());
//
//	// ImGui::ImageButton(struct bgfx::TextureHandle, unsigned char, unsigned char, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int, const struct ImVec4 &, const struct ImVec4 &) file:imgui.h line:76
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, unsigned char const & a1, unsigned char const & a2, const struct ImVec2 & a3) -> bool { return ImGui::ImageButton(a0, a1, a2, a3); }, "", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, unsigned char const & a1, unsigned char const & a2, const struct ImVec2 & a3, const struct ImVec2 & a4) -> bool { return ImGui::ImageButton(a0, a1, a2, a3, a4); }, "", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, unsigned char const & a1, unsigned char const & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, const struct ImVec2 & a5) -> bool { return ImGui::ImageButton(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, unsigned char const & a1, unsigned char const & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, const struct ImVec2 & a5, int const & a6) -> bool { return ImGui::ImageButton(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_framePadding"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, unsigned char const & a1, unsigned char const & a2, const struct ImVec2 & a3, const struct ImVec2 & a4, const struct ImVec2 & a5, int const & a6, const struct ImVec4 & a7) -> bool { return ImGui::ImageButton(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_framePadding"), pybind11::arg("_bgCol"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", (bool (*)(struct bgfx::TextureHandle, unsigned char, unsigned char, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int, const struct ImVec4 &, const struct ImVec4 &)) &ImGui::ImageButton, "C++: ImGui::ImageButton(struct bgfx::TextureHandle, unsigned char, unsigned char, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int, const struct ImVec4 &, const struct ImVec4 &) --> bool", pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::arg("_mip"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_framePadding"), pybind11::arg("_bgCol"), pybind11::arg("_tintCol"), pybind11::call_guard<pybind11::gil_scoped_release>());
//
//	// ImGui::ImageButton(struct bgfx::TextureHandle, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int, const struct ImVec4 &, const struct ImVec4 &) file:imgui.h line:95
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, const struct ImVec2 & a1) -> bool { return ImGui::ImageButton(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, const struct ImVec2 & a1, const struct ImVec2 & a2) -> bool { return ImGui::ImageButton(a0, a1, a2); }, "", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3) -> bool { return ImGui::ImageButton(a0, a1, a2, a3); }, "", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, int const & a4) -> bool { return ImGui::ImageButton(a0, a1, a2, a3, a4); }, "", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_framePadding"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", [](struct bgfx::TextureHandle const & a0, const struct ImVec2 & a1, const struct ImVec2 & a2, const struct ImVec2 & a3, int const & a4, const struct ImVec4 & a5) -> bool { return ImGui::ImageButton(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_framePadding"), pybind11::arg("_bgCol"), pybind11::call_guard<pybind11::gil_scoped_release>());
//	M("ImGuiExtra").def("ImageButton", (bool (*)(struct bgfx::TextureHandle, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int, const struct ImVec4 &, const struct ImVec4 &)) &ImGui::ImageButton, "C++: ImGui::ImageButton(struct bgfx::TextureHandle, const struct ImVec2 &, const struct ImVec2 &, const struct ImVec2 &, int, const struct ImVec4 &, const struct ImVec4 &) --> bool", pybind11::arg("_handle"), pybind11::arg("_size"), pybind11::arg("_uv0"), pybind11::arg("_uv1"), pybind11::arg("_framePadding"), pybind11::arg("_bgCol"), pybind11::arg("_tintCol"), pybind11::call_guard<pybind11::gil_scoped_release>());
//
//	// ImGui::NextLine() file:imgui.h line:107
//	M("ImGuiExtra").def("NextLine", (void (*)()) &ImGui::NextLine, "C++: ImGui::NextLine() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
//
//	// ImGui::MouseOverArea() file:imgui.h line:112
//	M("ImGuiExtra").def("MouseOverArea", (bool (*)()) &ImGui::MouseOverArea, "C++: ImGui::MouseOverArea() --> bool", pybind11::call_guard<pybind11::gil_scoped_release>());

}