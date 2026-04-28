#include <cassert>
#include <cstddef>

class Page;
class RenderView;

enum ScrollbarInclusion { IncludeScrollbars, ExcludeScrollbars };

struct IntSize {
    int width;
    int height;
    bool operator!=(const IntSize& other) const { return width != other.width || height != other.height; }
};

class Document {
public:
    void enqueueResizeEvent();
    bool printing();
};

class EventHandler {
public:
    void sendResizeEvent();
};

class Frame {
public:
    Document* document();
    EventHandler& eventHandler();
    Page* page();
};

class InspectorInstrumentation {
public:
    static void didResizeMainFrame(Page*);
};

class FrameView {
public:
    Frame* m_frame;
    IntSize m_lastViewportSize;
    float m_lastZoomFactor;
    RenderView* renderView();
    IntSize layoutSize(ScrollbarInclusion);
    bool isMainFrame();
    void sendResizeEventIfNeeded();
};

class RenderView {
public:
    struct Style {
        float zoom();
    };
    Document& document();
    Style* style();
};

#define ASSERT(expr) assert(expr)