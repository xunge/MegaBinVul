#include <stdbool.h>

enum UserGestureStatus { None };
enum CheckContentSecurityPolicy { CheckContentSecurityPolicy };

struct KURL {
    const char* string() const;
};

struct AtomicString {};

struct Document;
struct LocalFrame;
struct SecurityOrigin;
struct FrameLoader;
struct Client;
struct SubframeLoadingDisabler;
struct FrameHost;

struct HTMLFrameOwnerElement {
    Document& document();
    LocalFrame* contentFrame();
    bool loadOrRedirectSubframe(const KURL&, const AtomicString&, bool);
};

struct LocalFrame {
    void navigate(Document&, const KURL&, bool, UserGestureStatus);
    FrameLoader& loader();
    FrameHost* host();
};

struct Document {
    LocalFrame* frame();
    SecurityOrigin* securityOrigin();
};

struct SecurityOrigin {
    bool canDisplay(const KURL&);
};

struct FrameLoader {
    Client* client();
    static void reportLocalLoadFailed(LocalFrame*, const char*);
};

struct Client {
    bool createFrame(struct FrameLoadRequest, const AtomicString&, HTMLFrameOwnerElement*);
};

struct SubframeLoadingDisabler {
    static bool canLoadFrame(HTMLFrameOwnerElement&);
};

struct FrameHost {
    static const int maxNumberOfFrames;
    int subframeCount();
};

struct FrameLoadRequest {
    FrameLoadRequest(Document*, const KURL&, const char*, int);
};

template<typename T>
struct RefPtrWillBeRawPtr {
    T* ptr;
    RefPtrWillBeRawPtr(T* p = nullptr) : ptr(p) {}
    T* get() const { return ptr; }
    T* operator->() const { return ptr; }
    operator T*() const { return ptr; }
};

const int FrameHost::maxNumberOfFrames = 0;