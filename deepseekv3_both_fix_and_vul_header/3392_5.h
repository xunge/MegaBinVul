#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <memory>

#define ASSERT(x) assert(x)
#define RELEASE_ASSERT(x) assert(x)

struct IntPoint {
    int x;
    int y;
};

struct IntSize {
    int width;
    int height;
    bool operator==(const IntSize& other) const {
        return width == other.width && height == other.height;
    }
};

struct IntRect {
    IntPoint location;
    IntSize size;
};

class FloatQuad {
public:
    FloatQuad(const IntRect&);
};

class Frame {
public:
    class Selection {
    public:
        void setCaretRectNeedsUpdate();
    };
    class EventHandler {
    public:
        void dispatchFakeMouseMoveEventSoonInQuad(const FloatQuad&);
    };
    Selection& selection();
    EventHandler& eventHandler();
};

class FrameView {
public:
    bool isInLayout() const;
    void updateAnnotatedRegions();
    void updateWidgetPositions();
    class RenderView* renderView() const;
};

class RenderLayerCompositor {
public:
    bool inCompositingMode() const;
};

class Document {
public:
    void enqueueScrollEventForNode(class Node*);
};

class RenderView {
public:
    FrameView* frameView() const;
    void updateWidgetPositions();
    RenderLayerCompositor* compositor() const;
};

class RenderLayerModelObject {
public:
    FloatQuad localToAbsoluteQuad(const FloatQuad&) const;
};

class RenderLayer {
public:
    void updateLayerPositionsAfterOverflowScroll();
    bool hasVisibleNonLayerContent() const;
    bool hasNonCompositedChild() const;
    bool hasBlockSelectionGapBounds() const;
    class Repainter {
    public:
        IntRect repaintRect() const;
    };
    Repainter& repainter();
};

class Node {
public:
    Document& document();
};

class RenderBox {
public:
    bool isMarquee() const;
    Frame* frame() const;
    FrameView* frameView() const;
    RenderView* view() const;
    RenderLayerModelObject* containerForRepaint() const;
    void repaintUsingContainer(RenderLayerModelObject*, const IntRect&);
    Node* node() const;
};

class InspectorInstrumentation {
public:
    static void willScrollLayer(RenderBox*);
    static void didScrollLayer(RenderBox*);
};

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr) : m_ptr(ptr) {}
    T* operator->() const { return m_ptr; }
    operator T*() const { return m_ptr; }
private:
    T* m_ptr;
};

class RenderLayerScrollableArea {
public:
    RenderBox* m_box;
    bool m_scrollDimensionsDirty;

    void computeScrollDimensions();
    IntSize scrollOffset() const;
    void setScrollOffset(const IntSize&);
    void setScrollOffset(const IntPoint&);
    bool scrollsOverflow() const;
    bool usesCompositedScrolling() const;
    RenderLayer* layer() const;
    FrameView* frameView() const;
    void updateCompositingLayersAfterScroll();
};

IntSize toIntSize(const IntPoint&);
IntRect pixelSnappedIntRect(const IntRect&);