#include <string>

class ResourceFetcher {
public:
    void didReceiveResponse(const class Resource* resource, const class ResourceResponse& response);
    
    class Context {
    public:
        bool allowResponse(int type, const class ResourceRequest& request, const class KURL& url, const class ResourceLoaderOptions& options);
        bool canRequest(int type, const class ResourceRequest& request, const class KURL& url, const class ResourceLoaderOptions& options, bool flag, int restriction);
        void dispatchDidFail(unsigned long identifier, const class ResourceError& error, bool isInternal);
        void dispatchDidReceiveResponse(unsigned long identifier, const class ResourceResponse& response, class ResourceLoader* loader);
    };
    Context& context();
};

class KURL {
public:
    bool isEmpty() const;
    std::string string() const;
    std::string elidedString() const;
};

class ResourceResponse {
public:
    bool wasFetchedViaServiceWorker() const;
    const KURL& originalURLViaServiceWorker() const;
};

class ResourceRequest {
};

class ResourceLoaderOptions {
public:
    struct InitiatorInfo {
        const char* name;
    };
    InitiatorInfo initiatorInfo;
};

class Resource {
public:
    int type() const;
    const ResourceRequest& resourceRequest() const;
    const ResourceLoaderOptions& options() const;
    class ResourceLoader* loader() const;
    unsigned long identifier() const;
};

class ResourceLoader {
public:
    void cancel();
};

class ResourceError {
public:
    ResourceError(int domain, int code, const std::string& url, const std::string& message);
};

class FetchInitiatorTypeNames {
public:
    static const char* internal;
};

class FetchRequest {
public:
    static const int UseDefaultOriginRestrictionForType;
};

const int errorDomainBlinkInternal = 0;