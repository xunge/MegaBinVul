#include <stdbool.h>

struct ScriptForbiddenScope {
    ScriptForbiddenScope() {}
    ~ScriptForbiddenScope() {}
};

class FrameLoaderClient {
public:
    void didAccessInitialDocument();
};

class FrameLoader {
public:
    bool isLoadingMainFrame();
    FrameLoaderClient* client();
    bool m_didAccessInitialDocument;
    struct {
        void startOneShot(int, const char*);
    } m_didAccessInitialDocumentTimer;
    void didAccessInitialDocument();
};

#define BLINK_FROM_HERE __FILE__