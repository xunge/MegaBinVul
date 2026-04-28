#include <memory>

enum NavigationType {
    NavigationToDifferentDocument
};

class Document;
class DocumentLoader;
class ProgressTracker;
class StateMachine;
class FrameClient;

class FrameView {
public:
    void restoreScrollbar();
};

class LocalFrame {
public:
    FrameView* view();
    Document* document();
};

class Document {
public:
    void* url();
};

class DocumentLoader {
public:
    bool isCommittedButEmpty();
};

class ProgressTracker {
public:
    void finishedParsing();
};

class StateMachine {
public:
    bool creatingInitialEmptyDocument();
};

class ScriptForbiddenScope {
public:
    ScriptForbiddenScope() {}
    ~ScriptForbiddenScope() {}
};

template<typename T>
class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T* ptr) : m_ptr(ptr) {}
    T* get() { return m_ptr; }
    T* operator->() { return m_ptr; }
    operator T*() { return m_ptr; }
private:
    T* m_ptr;
};

class FrameClient {
public:
    void dispatchDidFinishDocumentLoad(bool);
    void runScriptsAtDocumentReady();
};

class FrameLoader {
public:
    void finishedParsing();
    void checkCompleted();
    void processFragment(const void* url, NavigationType type);
    FrameClient* client();
    StateMachine m_stateMachine;
    RefPtrWillBeRawPtr<LocalFrame> m_frame;
    ProgressTracker* m_progressTracker;
    DocumentLoader* m_documentLoader;
};