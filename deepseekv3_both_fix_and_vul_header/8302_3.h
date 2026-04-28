#include <functional>
#include <memory>
#include <string>

class LocalFrame;

class ProgressTracker {
public:
    static ProgressTracker* create(LocalFrame*);
};

class FrameLoader;

class Timer {
public:
    Timer() = default;
    Timer(FrameLoader* loader, void (FrameLoader::*callback)(Timer*)) {}
};

enum FrameLoadType { FrameLoadTypeStandard };
enum SandboxFlags { SandboxNone };

#define TRACE_EVENT_OBJECT_CREATED_WITH_ID(category, name, obj)

class FrameLoader {
public:
    FrameLoader(LocalFrame* frame);
    void checkTimerFired(Timer*);
    void didAccessInitialDocumentTimerFired(Timer*);
    void takeObjectSnapshot();

private:
    LocalFrame* m_frame;
    ProgressTracker* m_progressTracker;
    FrameLoadType m_loadType;
    bool m_inStopAllLoaders;
    Timer m_checkTimer;
    bool m_didAccessInitialDocument;
    Timer m_didAccessInitialDocumentTimer;
    SandboxFlags m_forcedSandboxFlags;
    bool m_dispatchingDidClearWindowObjectInMainWorld;
    bool m_protectProvisionalLoader;
};