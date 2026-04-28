#include <memory>

class FrameView;
class Frame;
class Selection;
class Document;
class Page;
class ScrollingCoordinator;
class RenderView;
class FontFaceSet;
class Timer;
class StateMachine;

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr) {}
};

struct TRACE_EVENT0 {
    TRACE_EVENT0(const char*, const char*) {}
};

class Timer {
public:
    void stop() {}
    bool isActive() { return false; }
    void startOneShot(int) {}
};

class Frame {
public:
    Selection& selection();
    Document* document();
    class Loader {
    public:
        void didFirstLayout();
        StateMachine* stateMachine();
        class Client {
        public:
            void dispatchDidFirstVisuallyNonEmptyLayout();
        };
        Client* client();
    };
    Loader& loader();
    Page* page();
};

class Selection {
public:
    void setCaretRectNeedsUpdate();
    void updateAppearance();
};

class Document {
public:
    bool parsing();
    bool didLayoutWithPendingStylesheets();
};

class Page {
public:
    ScrollingCoordinator* scrollingCoordinator();
};

class ScrollingCoordinator {
public:
    void notifyLayoutUpdated();
};

class RenderView {
public:
    void updateWidgetPositions();
};

class FontFaceSet {
public:
    static void didLayout(Document*);
};

class StateMachine {
public:
    bool committedFirstRealDocumentLoad();
};

class FrameView {
public:
    void performPostLayoutTasks();
    RenderView* renderView();
    void updateWidgetPositions();
    void scrollToAnchor();
    void sendResizeEventIfNeeded();

    Timer m_postLayoutTasksTimer;
    Timer m_updateWidgetsTimer;
    Frame* m_frame;
    int m_nestedLayoutCount;
    bool m_firstLayoutCallbackPending;
    bool m_isVisuallyNonEmpty;
    bool m_firstVisuallyNonEmptyLayoutCallbackPending;
};