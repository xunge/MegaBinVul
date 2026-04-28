#include <stddef.h>
#include <assert.h>

class Frame;

class Color {
public:
    static const Color white;
};

class FrameView;

class Timer {
public:
    Timer(FrameView* view, void (FrameView::*callback)()) {}
};

class ScrollableArea {
public:
    enum ScrollElasticity { ScrollElasticityAllowed };
    static void setVerticalScrollElasticity(ScrollElasticity) {}
    static void setHorizontalScrollElasticity(ScrollElasticity) {}
};

const ScrollableArea::ScrollElasticity ScrollElasticityAllowed = ScrollableArea::ScrollElasticityAllowed;

class FrameView {
public:
    FrameView(Frame* frame);
    bool isMainFrame() const { return false; }
    void init() {}

private:
    void layoutTimerFired() {}
    void postLayoutTimerFired() {}
    void updateWidgetsTimerFired() {}
    void deferredRepaintTimerFired() {}

    Frame* m_frame;
    bool m_canHaveScrollbars;
    int m_slowRepaintObjectCount;
    Timer m_layoutTimer;
    void* m_layoutRoot;
    bool m_inSynchronousPostLayout;
    Timer m_postLayoutTasksTimer;
    Timer m_updateWidgetsTimer;
    bool m_isTransparent;
    Color m_baseBackgroundColor;
    const char* m_mediaType;
    int m_overflowEventSuspendCount;
    bool m_overflowStatusDirty;
    void* m_viewportRenderer;
    bool m_wasScrolledByUser;
    bool m_inProgrammaticScroll;
    bool m_safeToPropagateScrollToParent;
    Timer m_deferredRepaintTimer;
    bool m_isTrackingRepaints;
    bool m_shouldUpdateWhileOffscreen;
    int m_deferSetNeedsLayouts;
    bool m_setNeedsLayoutWasDeferred;
    void* m_scrollCorner;
    bool m_shouldAutoSize;
    bool m_inAutoSize;
    bool m_didRunAutosize;
    bool m_hasSoftwareFilters;
    float m_visibleContentScaleFactor;
    float m_inputEventsScaleFactorForEmulation;
    void* m_partialLayout;
    bool m_layoutSizeFixedToFrameSize;
};

#define ASSERT(x) assert(x)