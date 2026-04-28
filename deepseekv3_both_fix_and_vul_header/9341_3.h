#include <memory>
#include <vector>

enum FrameDetachType {};

class PluginScriptForbiddenScope {
public:
    PluginScriptForbiddenScope() {}
};

template<typename T>
class RefPtrWillBeRawPtr {
public:
    explicit RefPtrWillBeRawPtr(T* ptr) {}
};

class FrameLoader {
public:
    void stopAllLoaders();
    void dispatchUnloadEvent();
    void detach();
    void clear();
};

class Document {
public:
    void detach();
    Document* operator->();
};

class FrameScheduler {
public:
    void clear();
};

class FrameClient {
public:
    void willBeDetached();
};

class ScriptController {
public:
    void clearForClose();
};

class Frame {
public:
    static void detach(FrameDetachType type);
};

class LocalFrame {
public:
    void detach(FrameDetachType type);
    FrameLoader& m_loader;
    Document* document();
    void detachChildren();
    FrameScheduler m_frameScheduler;
    FrameClient* client();
    ScriptController& script();
    void setView(void*);
    void willDetachFrameHost();
    std::vector<void*> m_supplements;
};

class SubframeLoadingDisabler {
public:
    explicit SubframeLoadingDisabler(Document&) {}
};

class ScriptForbiddenScope {
public:
    ScriptForbiddenScope() {}
};

class InspectorInstrumentation {
public:
    static void frameDetachedFromParent(LocalFrame*);
};

class LocalFrameLifecycleNotifier {
public:
    static void notifyContextDestroyed();
};

template<typename T>
class WeakIdentifierMap {
public:
    static void notifyObjectDestroyed(T*);
};