#include <stdbool.h>
#include <assert.h>

#define ASSERT assert

struct Document {
    bool shouldDisplaySeamlesslyWithParent();
};

struct Frame {
    Document* document();
};

struct RenderView {
    void updateWidgetPositions();
};

struct Timer {
    bool isActive();
    void startOneShot(int);
};

struct FrameView {
    Timer m_postLayoutTasksTimer;
    bool m_inSynchronousPostLayout;
    
    bool needsLayout();
    void layout();
    void performPostLayoutTasks();
    void updateWidgetPositions();
    Frame& frame();
    RenderView* renderView();
    
    struct PartialLayout {
        bool isStopping();
    };
    
    PartialLayout partialLayout();
    
    void scheduleOrPerformPostLayoutTasks();
};