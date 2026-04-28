#include <memory>

class Document;
class Frame;
class FrameLoader;
class FrameView;
class Page;
class RenderView;
class ScrollingCoordinator;
class Selection;

class Timer {
public:
    void stop();
    void startOneShot(int);
};

class FrameView {
public:
    void performPostLayoutTasks();
    RenderView* renderView();
    Frame* frame() { return m_frame; }
    void scrollToAnchor();
    void sendResizeEventIfNeeded();
    void resumeOverflowEvents();
    
    Timer m_postLayoutTasksTimer;
    Timer m_updateWidgetsTimer;
    Frame* m_frame;
    int m_nestedLayoutCount;
    bool m_firstLayoutCallbackPending;
    bool m_isVisuallyNonEmpty;
    bool m_firstVisuallyNonEmptyLayoutCallbackPending;
};

class Frame {
public:
    Selection& selection();
    Document* document();
    FrameLoader& loader();
    Page* page();
};

class RenderView {
public:
    void updateWidgetPositions();
};

class Page {
public:
    ScrollingCoordinator* scrollingCoordinator();
};

class ScrollingCoordinator {
public:
    void notifyLayoutUpdated();
};

class FontFaceSet {
public:
    static void didLayout(Document*);
};

class Selection {
public:
    void setCaretRectNeedsUpdate();
    void updateAppearance();
};

class FrameLoader {
public:
    void didFirstLayout();
    class StateMachine {
    public:
        bool committedFirstRealDocumentLoad();
    };
    class Client {
    public:
        void dispatchDidFirstVisuallyNonEmptyLayout();
    };
    Client* client();
    StateMachine* stateMachine();
};

class Document {
public:
    bool parsing();
    bool didLayoutWithPendingStylesheets();
};

template<typename T> class RefPtr {
public:
    RefPtr(T*);
    T* operator->();
};

struct TRACE_EVENT0 {
    TRACE_EVENT0(const char*, const char*);
};