#define USE_RUBBER_BANDING 1

enum ScrollbarInclusion {
    ExcludeScrollbars,
    IncludeScrollbars
};

struct IntSize {
    int width;
    int height;
};

struct IntPoint {
    int x;
    int y;
};

struct IntRect {
    IntSize size() const { return IntSize(); }
    IntPoint location() const { return IntPoint(); }
};

class FrameView {
public:
    IntSize unscaledVisibleContentSize() const { return IntSize(); }
    IntSize unscaledVisibleContentSize(ScrollbarInclusion) const { return IntSize(); }
};

class OverscrollTheme {
public:
    static OverscrollTheme* theme();
    void updateOverhangShadowLayer(void*, void*);
};

class RenderView {
public:
    IntRect documentRect() const { return IntRect(); }
    FrameView* frameView() const { return nullptr; }
};

class GraphicsLayer {
public:
    void setSize(const IntSize&);
    void setPosition(const IntPoint&);
    void* get() { return nullptr; }
};

class RenderLayerCompositor {
public:
    void updateRootLayerPosition();
private:
    GraphicsLayer* m_rootContentLayer;
    GraphicsLayer* m_containerLayer;
    GraphicsLayer* m_layerForOverhangShadow;
    GraphicsLayer* m_overflowControlsHostLayer;
    RenderView m_renderView;
};

#define USE(x) defined(x)