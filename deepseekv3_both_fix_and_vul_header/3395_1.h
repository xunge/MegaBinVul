#include <memory>

template<typename T>
class RefPtr {
public:
    RefPtr(T* ptr) {}
};

class RenderView {
public:
    void updateWidgetPositions();
    class Layer {
    public:
        void updateLayerPositionsAfterDocumentScroll();
    };
    Layer* layer();
};

class FrameView {
public:
    void repaintFixedElementsAfterScrolling();
    bool hasViewportConstrainedObjects();
    void updateWidgetPositions();
    RenderView* renderView();
    int m_nestedLayoutCount;
};