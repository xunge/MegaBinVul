#include <memory>
#include <cassert>

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
private:
    T* m_ptr;
};

class Frame;
class Page;
class ScrollingCoordinator;
class Compositor;

class RenderView {
public:
    Compositor* compositor();
};

class FrameView {
public:
    void updateLayoutAndStyleForPainting();
    void updateLayoutAndStyleIfNeededRecursive();
    void updateWidgetPositionsIfNeeded();
    RenderView* renderView();
    void scrollContentsIfNeededRecursive();
    void updateCompositedSelectionBoundsIfNeeded();
    void invalidateTreeIfNeededRecursive();
    
    struct DocumentLifecycle {
        enum State { PaintInvalidationClean };
        State state() const { return PaintInvalidationClean; }
    };
    
    DocumentLifecycle& lifecycle();
    RefPtr<Frame> m_frame;
};

class Frame {
public:
    bool isLocalRoot();
    Page* page();
};

class Page {
public:
    ScrollingCoordinator* scrollingCoordinator();
};

class ScrollingCoordinator {
public:
    void updateAfterCompositingChangeIfNeeded();
};

class Compositor {
public:
    void updateIfNeededRecursive();
    bool inCompositingMode();
};

namespace InspectorInstrumentation {
    void willUpdateLayerTree(Frame*);
    void didUpdateLayerTree(Frame*);
}

#define TRACE_EVENT_INSTANT1(category, name, arg1, value)
#define TRACE_DISABLED_BY_DEFAULT(category) category
#define ASSERT(expr) assert(expr)