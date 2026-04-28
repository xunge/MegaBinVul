#include <cstdint>
#include <cstdlib>
#include <memory>
#include <cassert>
#include <set>

#define ASSERT(x) assert(x)

class Document {
public:
    static std::set<Document*>& liveDocumentSet();
    unsigned nodeCount() const;
    void detach();
};

class DocumentLoader {
public:
    void detachFromFrame();
};

class Frame {
public:
    Document* document() const;
    void detachChildren();
    void* client() const;
};

class InstanceCounters {
public:
    enum CounterType { NodeCounter };
    static unsigned counterValue(CounterType);
};

class PluginScriptForbiddenScope {
public:
    PluginScriptForbiddenScope();
    ~PluginScriptForbiddenScope();
};

class SubframeLoadingDisabler {
public:
    explicit SubframeLoadingDisabler(Document*);
};

class ThreadState {
public:
    static ThreadState* current();
    void schedulePageNavigationGCIfNeeded(float ratio);
};

template<typename T>
class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr();
    explicit RefPtrWillBeRawPtr(T*);
    T* get() const;
    T* release();
    bool operator!=(const RefPtrWillBeRawPtr&) const;
};

struct FrameNavigationDisabler {
    explicit FrameNavigationDisabler(Frame&);
};

class FrameLoaderClient {
public:
    void dispatchWillClose();
};

class FrameLoader {
public:
    bool prepareForCommit();
    void detachDocumentLoader(DocumentLoader*);
    void dispatchUnloadEvent();
    FrameLoaderClient* client() const;

private:
    Frame* m_frame;
    DocumentLoader* m_documentLoader;
    RefPtrWillBeRawPtr<DocumentLoader> m_provisionalDocumentLoader;
};