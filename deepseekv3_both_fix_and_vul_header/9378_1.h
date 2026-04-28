#include <stddef.h>

struct FrameView {
    struct Size unscaledVisibleContentSize(int);
    Size unscaledVisibleContentSize();
};

struct Size {
    void setSize(Size);
};

struct RenderView {
    FrameView* frameView();
};

struct RenderLayerCompositor {
    void frameViewDidChangeSize();
    void frameViewDidScroll();
    void updateOverflowControlsLayers();
    
    Size* m_containerLayer;
    RenderView m_renderView;
    Size* m_overflowControlsHostLayer;
};

enum {
    IncludeScrollbars
};