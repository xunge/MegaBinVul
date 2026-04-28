#include <memory>
#include <string>

enum FetchInitiatorTypeNames { css };
enum CredentialRequest { DoNotAllowStoredCredentials };

struct Referrer {
    std::string referrerPolicy;
    std::string referrer;
};

class SecurityOrigin {};
class Fetcher {};

class Document {
public:
    std::string completeURL(const std::string& url);
    SecurityOrigin* securityOrigin();
    Fetcher* fetcher();
};

class ResourceRequest {
public:
    ResourceRequest(const std::string& url);
    void setHTTPReferrer(const std::string&);
    std::string url() const;
};

class FetchRequest {
public:
    FetchRequest(const ResourceRequest&, FetchInitiatorTypeNames);
    void setContentSecurityCheck(bool);
    void setCrossOriginAccessControl(SecurityOrigin*, CredentialRequest);
    ResourceRequest& mutableResourceRequest();
    std::string url() const;
};

class SecurityPolicy {
public:
    static std::string generateReferrer(const std::string&, const std::string&, const std::string&);
};

class FontResource {
public:
    static std::unique_ptr<FontResource> fetch(const FetchRequest&, Fetcher*);
};

class CSSFontFaceSrcValue {
public:
    FontResource* fetch(Document* document);
    void restoreCachedResourceIfNeeded(Document* document);
    bool shouldSetCrossOriginAccessControl(const std::string& url, SecurityOrigin* securityOrigin);

private:
    std::unique_ptr<FontResource> m_fetched;
    std::string m_resource;
    bool m_shouldCheckContentSecurityPolicy;
    Referrer m_referrer;
};