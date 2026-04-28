#include <sys/types.h>
#include <memory>
#include <unordered_map>
#include <cassert>

#define ASSERT(x) assert(x)

class Resource {
public:
    class Response {
    public:
        bool isHTTP() const;
        int httpStatusCode() const;
    };
    Response response() const;
    bool errorOccurred() const;
    bool wasCanceled() const;
    enum Type { MainResource };
    Type type() const;
    void* resourceRequest() const;
    double loadFinishTime() const;
};

class DocumentLoader;
class DOMWindow;
class Performance;

class Document {
public:
    Document* parentDocument() const;
    DOMWindow* domWindow() const;
    bool document() const;
};

class DOMWindow {
public:
    Performance* performance() const;
};

class Performance {
public:
    void addResourceTiming(const class ResourceTimingInfo&, Document*);
};

class ResourceTimingInfo {
public:
    void setInitialRequest(void*);
    void setFinalResponse(const Resource::Response&);
    void setLoadFinishTime(double);
};

class Frame {
public:
    class Loader {
    public:
        void loadDone();
    };
    Loader* loader() const;
};

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr) : m_ptr(ptr) {}
    T* operator->() const { return m_ptr; }
    T& operator*() const { return *m_ptr; }
    T* get() const { return m_ptr; }
private:
    T* m_ptr;
};

typedef std::unordered_map<Resource*, RefPtr<ResourceTimingInfo>> ResourceTimingInfoMap;

class Timer {
public:
    bool isActive() const;
    void startOneShot(int);
};

class ResourceFetcher {
private:
    DocumentLoader* m_documentLoader;
    Document* m_document;
    ResourceTimingInfoMap m_resourceTimingInfoMap;
    Timer m_garbageCollectDocumentResourcesTimer;
public:
    Frame* frame() const;
    void performPostLoadActions();
    void didLoadResource(Resource* resource);
    Document* document() const { return m_document; }
};

// Fix for unordered_map iterator access
#define value second
// Fix for unordered_map erase
#define remove erase