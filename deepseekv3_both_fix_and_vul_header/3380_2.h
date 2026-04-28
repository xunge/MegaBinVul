#include <stdbool.h>
#include <assert.h>

#define ASSERT(x) assert(x)

typedef struct {
    bool isActive();
    void startOneShot(int);
} Timer;

typedef struct {
    bool isStopping();
} PartialLayout;

typedef struct {
    bool shouldDisplaySeamlesslyWithParent();
} Document;

typedef struct {
    Document* document();
} Frame;

typedef struct {
    void updateWidgetPositions();
} RenderView;

class FrameView {
public:
    void scheduleOrPerformPostLayoutTasks();
private:
    Timer m_postLayoutTasksTimer;
    bool m_inSynchronousPostLayout;
    Frame frame();
    RenderView* renderView();
    PartialLayout partialLayout();
    bool needsLayout();
    void resumeOverflowEvents();
    void performPostLayoutTasks();
    void suspendOverflowEvents();
    void layout();
};