#include <stdbool.h>
#include <memory>

class Resource {
public:
    enum Type {
        MainResource,
        Image,
        CSSStyleSheet,
        Script,
        Font,
        Raw,
        LinkPrefetch,
        LinkSubresource,
        TextTrack,
        ImportResource,
        Media,
        XSLStyleSheet,
        SVGDocument
    };
};

class KURL {
public:
    bool protocolIsData() const;
};

class SecurityOrigin {
public:
    bool canDisplay(const KURL&) const;
    bool canRequest(const KURL&) const;
};

class Document;
class Frame;
class Settings;
class ChromeClient;

enum ContentSecurityPolicyOption {
    DoNotCheckContentSecurityPolicy,
    CheckContentSecurityPolicy
};

class ResourceLoaderOptions {
public:
    std::shared_ptr<SecurityOrigin> securityOrigin;
    ContentSecurityPolicyOption contentSecurityPolicyOption;
    enum MixedContentBlockingTreatment {
        StrictMixedContentBlocking,
        LaxMixedContentBlocking
    } mixedContentBlockingTreatment;
};

class FetchRequest {
public:
    enum OriginRestriction {
        RestrictToSameOrigin,
        NoOriginRestriction
    };
};

class ContentSecurityPolicy {
public:
    enum ReportingStatus {
        SuppressReport,
        SendReport
    };
    bool allowScriptFromSource(const KURL&, ReportingStatus);
    bool allowStyleFromSource(const KURL&, ReportingStatus);
    bool allowImageFromSource(const KURL&, ReportingStatus);
    bool allowFontFromSource(const KURL&, ReportingStatus);
    bool allowMediaFromSource(const KURL&, ReportingStatus);
};

class Document {
public:
    SecurityOrigin* securityOrigin();
    ContentSecurityPolicy* contentSecurityPolicy();
};

class Frame {
public:
    class Script {
    public:
        bool shouldBypassMainWorldContentSecurityPolicy();
    };
    Script& script();
    Settings* settings();
    class Loader {
    public:
        class Client {
        public:
            bool allowScriptFromSource(bool, const KURL&);
            void didNotAllowScript();
        };
        Client* client();
    };
    Loader& loader();
    ChromeClient& chromeClient();
};

class Settings {
public:
    bool scriptEnabled();
};

class ChromeClient {
public:
    bool isSVGImageChromeClient();
};

class ResourceFetcher {
public:
    bool canRequest(Resource::Type type, const KURL& url, const ResourceLoaderOptions& options, bool forPreload, FetchRequest::OriginRestriction originRestriction) const;
    Document* document() const;
    Frame* frame() const;
    void printAccessDeniedMessage(const KURL&) const;
    bool checkInsecureContent(Resource::Type, const KURL&, ResourceLoaderOptions::MixedContentBlockingTreatment) const;
    class Context {
    public:
        void reportLocalLoadFailed(const KURL&);
    };
    Context& context() const;
    Document* m_document;
};

#define ASSERT(expr) ((void)0)
#define WTF_LOG(category, message) ((void)0)