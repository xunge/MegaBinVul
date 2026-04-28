#include <stddef.h>

struct String {
    const char* data;
};

struct DocumentLoader;

struct Document {
    enum DismissalType { NoDismissal };
    DocumentLoader* loader();
    DismissalType pageDismissalEventBeingDispatched();
    void detach();
    String url();
};

struct Frame {
    Document* document();
    void detachChildren();
    void* page();
};

struct DocumentLoader {
    void replaceDocumentWhileExecutingJavaScriptURL(struct DocumentInit& init, const String& source, Document* ownerDocument);
};

struct UseCounter {
    enum CountType { ReplaceDocumentViaJavaScriptURL };
    static void count(Document&, CountType);
};

struct DocumentInit {
    DocumentInit(String url, Frame* frame);
    void withNewRegistrationContext();
};

struct SubframeLoadingDisabler {
    SubframeLoadingDisabler(Document*);
};

struct Client {
    void transitionToCommittedForNewPage();
};

template<typename T>
struct RefPtrWillBeRawPtr {
    RefPtrWillBeRawPtr(T*);
    T* operator->();
};

struct FrameLoader {
    Frame* m_frame;
    Client* client();
    void stopAllLoaders();
    void clear();
    void replaceDocumentWhileExecutingJavaScriptURL(const String&, Document*);
};