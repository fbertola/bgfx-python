import cppyy

cppyy.cppdef(
    """
    void imguiCreate(float _fontSize = 18.0f, bx::AllocatorI* _allocator = NULL);
    void imguiDestroy();
    
    void imguiBeginFrame(int32_t _mx, int32_t _my, uint8_t _button, int32_t _scroll, uint16_t _width, uint16_t _height, int _inputChar = -1, bgfx::ViewId _view = 255);
    void imguiEndFrame();
    
    namespace ImGuiBgfx {
        class ImGuiExtra {
        public:
            //ImguiExtra() : {}
            void create(float _fontSize = 18.0f) { imguiCreate(_fontSize, NULL); }
            void destroy() { imguiDestroy(); }

            void beginFrame(int32_t _mx, int32_t _my, uint8_t _button, int32_t _scroll, uint16_t _width, uint16_t _height, int _inputChar = -1, bgfx::ViewId _view = 255) {
                imguiBeginFrame(_mx, _my, _button, _scroll, _width, _height, _inputChar, _view);
            }
            void endFrame() { imguiEndFrame(); }
        };
    }
"""
)

ImGuiExtra = cppyy.gbl.ImGuiBgfx.ImGuiExtra()
