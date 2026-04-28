#include <stddef.h>

class LocalFrame {
public:
    bool isMainFrame();
};

class Color {
public:
    static const Color white;
};

class FrameView;

class Timer {
public:
    Timer(FrameView* view, void (FrameView::*callback)()) {}
};

struct ScrollableArea {
    enum ScrollElasticity { ScrollElasticityAllowed };
    static void setVerticalScrollElasticity(ScrollElasticity) {}
    static void setHorizontalScrollElasticity(ScrollElasticity) {}
};

const ScrollableArea::ScrollElasticity ScrollElasticityAllowed = ScrollableArea::ScrollElasticityAllowed;

class FrameView {
public:
    FrameView(LocalFrame* frame);
    void init();
    void postLayoutTimerFired();
    void updateWidgetsTimerFired();
    void didScrollTimerFired();

private:
    LocalFrame* m_frame;
    bool m_canHaveScrollbars;
    int m_slowRepaintObjectCount;
    bool m_hasPendingLayout;
    int m_layoutSubtreeRoot;
    bool m_inSynchronousPostLayout;
    Timer m_postLayoutTasksTimer;
    Timer m_updateWidgetsTimer;
    bool m_isTransparent;
    Color m_baseBackgroundColor;
    const char* m_mediaType;
    bool m_overflowStatusDirty;
    int m_viewportRenderer;
    bool m_wasScrolledByUser;
    bool m_inProgrammaticScroll;
    bool m_safeToPropagateScrollToParent;
    bool m_isTrackingPaintInvalidations;
    void* m_scrollCorner;
    bool m_hasSoftwareFilters;
    float m_visibleContentScaleFactor;
    float m_inputEventsScaleFactorForEmulation;
    bool m_layoutSizeFixedToFrameSize;
    Timer m_didScrollTimer;
    bool m_needsUpdateWidgetPositions;
};

#define ASSERT(expr) ((void)0)