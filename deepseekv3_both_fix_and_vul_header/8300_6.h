#include <vector>

class Page;
class Platform;
class Scheduler;

class ScopedPageLoadDeferrer {
public:
    explicit ScopedPageLoadDeferrer(Page* exclusion);
    ~ScopedPageLoadDeferrer();

    void setDefersLoading(bool);
    std::vector<Page*> m_deferredPages;
};

class Page {
public:
    static std::vector<Page*> ordinaryPages();
    bool defersLoading() const;
    class Frame {
    public:
        bool isLocalFrame() const;
        class Loader {
        public:
            void notifyIfInitialDocumentAccessed();
        };
        Loader& loader();
    };
    Frame* mainFrame();
    Frame* deprecatedLocalMainFrame();
};

class Platform {
public:
    static Platform* current();
    class Thread {
    public:
        class Scheduler* scheduler();
    };
    Thread* currentThread();
};

class Scheduler {
public:
    void suspendTimerQueue();
};

// Replace append with push_back
#define append push_back