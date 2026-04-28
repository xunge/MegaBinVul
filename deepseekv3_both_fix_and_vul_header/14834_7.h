#include <stdint.h>
#include <assert.h>

class IntPoint {
public:
    IntPoint();
    IntPoint(int x, int y);
};

class IntSize {
public:
    IntSize();
    IntSize(int width, int height);
    IntSize(const IntPoint&);
    bool operator==(const IntSize&) const;
};

class IntRect {
public:
    IntRect();
    IntRect(int x, int y, int width, int height);
};

class FloatQuad {
public:
    FloatQuad();
    FloatQuad(const IntRect&);
};

class LocalFrame {
public:
    struct Selection {
        void setCaretRectNeedsUpdate();
    };
    struct EventHandler {
        void dispatchFakeMouseMoveEventSoonInQuad(const FloatQuad&);
    };
    Selection& selection();
    EventHandler& eventHandler();
};

class FrameView {
public:
    bool isInPerformLayout();
    void updateAnnotatedRegions();
    void setNeedsUpdateWidgetPositions();
    void updateWidgetPositions();
    void* renderView();
};

class RenderLayerModelObject {
public:
    FloatQuad localToAbsoluteQuad(const FloatQuad&) const;
};

class AXObjectCache {
public:
    void handleScrollPositionChanged(void*);
};

class DisableCompositingQueryAsserts {
public:
    DisableCompositingQueryAsserts();
};

template<typename T> class RefPtr {
public:
    RefPtr(T*);
    T* operator->() const;
};

enum InvalidationScrollType {
    InvalidationScroll
};

enum LocalBackgroundAttachment {
    LocalBackgroundAttachment
};

#define ASSERT(expr) assert(expr)
#define TRACE_EVENT1(category, name, arg1_name, arg1_val)

namespace TRACE_DISABLED_BY_DEFAULT {
    const char* devtools_timeline();
}

namespace InspectorInstrumentation {
    void willScrollLayer(void*);
    void didScrollLayer(void*);
}

namespace InspectorScrollLayerEvent {
    void* data(void*);
}

struct Document {
    void enqueueScrollEventForNode(void*);
    AXObjectCache* existingAXObjectCache();
};

IntSize toIntSize(const IntPoint&);

struct RenderLayerScrollableArea {
    bool m_scrollDimensionsDirty;
    
    void computeScrollDimensions();
    IntSize scrollOffset();
    void setScrollOffset(const IntSize&);
    void setScrollOffset(const IntPoint&);
    bool scrollsOverflow();
    bool usesCompositedScrolling();
    void updateCompositingLayersAfterScroll();
    
    struct Box {
        bool isMarquee();
        LocalFrame* frame();
        FrameView* frameView();
        const RenderLayerModelObject* containerForPaintInvalidation();
        void setPreviousPaintInvalidationRect(const IntRect&);
        IntRect boundsRectForPaintInvalidation(const RenderLayerModelObject*);
        void invalidatePaintUsingContainer(const RenderLayerModelObject*, const IntRect&, InvalidationScrollType);
        void setShouldDoFullPaintInvalidation(bool);
        struct View {
            struct Compositor {
                bool inCompositingMode();
            };
            Compositor* compositor();
        };
        View* view();
        struct Node {
            Document& document();
        };
        Node* node();
        Document& document();
        struct Style {
            struct BackgroundLayers {
                int attachment() const;
            };
            BackgroundLayers backgroundLayers() const;
        };
        const Style* style() const;
    };
    Box& box();
    
    struct Layer {
        struct Clipper {
            void clearClipRectsIncludingDescendants();
        };
        Clipper& clipper();
        bool hasVisibleNonLayerContent() const;
        bool hasNonCompositedChild() const;
        bool hasBlockSelectionGapBounds() const;
        struct Renderer {
            IntRect previousPaintInvalidationRect() const;
        };
        Renderer* renderer() const;
    };
    Layer* layer();
};

struct RELEASE_ASSERT {
    RELEASE_ASSERT(bool);
};