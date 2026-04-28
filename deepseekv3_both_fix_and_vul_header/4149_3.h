#include <stdbool.h>

enum ResourceRequestBlockedReason {
    ResourceRequestBlockedReasonNone
};

namespace ContentSecurityPolicy {
    enum RedirectStatus {
        DidRedirect,
        DidNotRedirect
    };
}

struct ResourceRequest {
    bool followedRedirect() const;
};

struct InitiatorInfo {
    void* info;
};

struct ResourceLoaderOptions {
    InitiatorInfo initiatorInfo;
};

struct KURL {};

namespace Resource {
    enum Type {
        Type1,
        Type2
    };
}

namespace FetchRequest {
    enum OriginRestriction {
        Restriction1,
        Restriction2
    };
}

class FrameFetchContext {
public:
    bool canRequest(Resource::Type type, const ResourceRequest& resourceRequest, const KURL& url, const ResourceLoaderOptions& options, bool forPreload, FetchRequest::OriginRestriction originRestriction) const;
    bool canRequest(Resource::Type type, const ResourceRequest& resourceRequest, const KURL& url, const ResourceLoaderOptions& options, bool forPreload, FetchRequest::OriginRestriction originRestriction, ContentSecurityPolicy::RedirectStatus redirectStatus) const;
    ResourceRequestBlockedReason canRequestInternal(Resource::Type type, const ResourceRequest& resourceRequest, const KURL& url, const ResourceLoaderOptions& options, bool forPreload, FetchRequest::OriginRestriction originRestriction) const;
    ResourceRequestBlockedReason canRequestInternal(Resource::Type type, const ResourceRequest& resourceRequest, const KURL& url, const ResourceLoaderOptions& options, bool forPreload, FetchRequest::OriginRestriction originRestriction, ContentSecurityPolicy::RedirectStatus redirectStatus) const;
    void* frame() const;
    void* ensureLoaderForNotifications() const;
};

class InspectorInstrumentation {
public:
    static void didBlockRequest(void* frame, const ResourceRequest& resourceRequest, void* loader, const InitiatorInfo& initiatorInfo, ResourceRequestBlockedReason reason);
};