#include <assert.h>
#include <stddef.h>
#include <stdint.h>

class Document;
class Page;
class HistoryItem;
class FrameLoadRequest;
class SerializedScriptValue;
class KURL;
class AtomicString;
class UserGestureIndicator;
class WebURLRequest;
class String;
class ResourceRequest;
class DocumentLoader;

#define ASSERT assert

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr = nullptr) : m_ptr(ptr) {}
    T* operator->() const { return m_ptr; }
    T* get() const { return m_ptr; }
    operator T*() const { return m_ptr; }
private:
    T* m_ptr;
};

class Frame {
public:
    Document* document() { return nullptr; }
    bool isNavigationAllowed() { return false; }
    Page* page() { return nullptr; }
    Frame* findFrameForNavigation(const AtomicString&, Frame&) { return nullptr; }
    void navigate(const FrameLoadRequest&) {}
};

class Page {
public:
    bool defersLoading() { return false; }
    class ChromeClient {
    public:
        void focus() {}
    };
    ChromeClient chromeClient() { return ChromeClient(); }
};

class FrameLoadRequest {
public:
    FrameLoadRequest(const FrameLoadRequest&);
    const char* frameName() const { return ""; }
    void setFrameName(const char*) {}
    ResourceRequest& resourceRequest();
    const ResourceRequest& resourceRequest() const;
    void* form() const { return nullptr; }
    bool getShouldSendReferrer() const { return false; }
    void* originDocument() const { return nullptr; }
    bool getShouldSetOpener() const { return false; }
    bool clientRedirect() const { return false; }
    void* triggeringEvent() const { return nullptr; }
};

class ResourceRequest {
public:
    void setHasUserGesture(bool) {}
    const KURL& url() const;
    const char* httpMethod() const { return ""; }
    void setFrameType(int) {}
};

class UserGestureIndicator {
public:
    static bool processingUserGesture() { return false; }
};

class AtomicString {
public:
    AtomicString(const char*) {}
};

class WebURLRequest {
public:
    enum FrameType { FrameTypeAuxiliary };
};

class KURL {
public:
    const char* url() const { return ""; }
};

class HistoryItem {
public:
    SerializedScriptValue* stateObject() { return nullptr; }
};

class SerializedScriptValue {};

class String {
public:
    String() {}
};

class DocumentLoader {
public:
    void setNavigationType(int) {}
    void loadURLExternally(const ResourceRequest&, int, const String&, bool) {}
};

enum FrameLoadType {
    FrameLoadTypeStandard,
    FrameLoadTypeReplaceCurrentItem
};

enum HistoryLoadType {
    HistorySameDocumentLoad
};

enum NavigationPolicy {
    NavigationPolicyDownload,
    NavigationPolicyCurrentTab
};

class DeferredHistoryLoad {
public:
    static DeferredHistoryLoad* create(const ResourceRequest&, HistoryItem*, FrameLoadType, HistoryLoadType) { return nullptr; }
};

class FrameLoader {
public:
    Frame* m_frame;
    bool m_inStopAllLoaders;
    HistoryItem* m_provisionalItem;
    DeferredHistoryLoad* m_deferredHistoryLoad;
    DocumentLoader* m_documentLoader;

    void load(const FrameLoadRequest&, FrameLoadType, HistoryItem*, HistoryLoadType);
    bool isBackForwardLoadType(FrameLoadType) const { return false; }
    bool prepareRequestForThisFrame(FrameLoadRequest&) { return false; }
    void setReferrerForFrameRequest(ResourceRequest&, bool, void*) {}
    FrameLoadType determineFrameLoadType(const FrameLoadRequest&) { return FrameLoadTypeStandard; }
    NavigationPolicy navigationPolicyForRequest(const FrameLoadRequest&) { return NavigationPolicyCurrentTab; }
    bool shouldOpenInNewWindow(Frame*, const FrameLoadRequest&, NavigationPolicy) { return false; }
    void createWindowForRequest(const FrameLoadRequest&, Frame&, NavigationPolicy, bool, bool) {}
    bool shouldPerformFragmentNavigation(void*, const char*, FrameLoadType, const KURL&) { return false; }
    int determineNavigationType(FrameLoadType, bool, void*) { return 0; }
    bool shouldTreatURLAsSameAsCurrent(const KURL&) { return false; }
    void loadInSameDocument(const KURL&, SerializedScriptValue*, FrameLoadType, HistoryLoadType, bool) {}
    void startLoad(const FrameLoadRequest&, FrameLoadType, NavigationPolicy) {}
    DocumentLoader* client() { return m_documentLoader; }
};