#ifndef IMGUI_EXTRA_H_HEADER_GUARD
#define IMGUI_EXTRA_H_HEADER_GUARD

#include <bgfx/bgfx.h>
#include <bx/bx.h>
#include <imgui/imgui.h>

class _ImGuiExtra {
public:
    //ImguiExtra() : {}
    void create(float _fontSize = 18.0f);
    void destroy();

    void begin_frame(int32_t _mx, int32_t _my, uint8_t _button, int32_t _scroll, uint16_t _width, uint16_t _height, int _inputChar = -1, bgfx::ViewId _view = 255);
    void end_frame();
};

#endif // IMGUI_EXTRA_H_HEADER_GUARD