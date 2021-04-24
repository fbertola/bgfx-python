#include "imgui_extra.h"


void _ImGuiExtra::create(float _fontSize) {
    imguiCreate(_fontSize, NULL);
}

void _ImGuiExtra::destroy() {
    imguiDestroy();
}

void _ImGuiExtra::begin_frame(int32_t _mx, int32_t _my, uint8_t _button, int32_t _scroll, uint16_t _width, uint16_t _height, int _inputChar, bgfx::ViewId _view) {
    imguiBeginFrame(_mx, _my, _button, _scroll, _width, _height, _inputChar, _view);
}

void _ImGuiExtra::end_frame() {
    imguiEndFrame();
}
