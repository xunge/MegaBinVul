#include <memory>
#include <string>

class String {
public:
    String();
    String(const char*);
    String(const std::string&);
    String operator+(const String&) const;
    String& operator+=(const String&);
    friend String operator+(const char*, const String&);
};

class SecurityOrigin;
class ContentSecurityPolicy;
class KURL;
class WebString;

template<typename T> class RefPtr {
public:
    RefPtr(T*);
    T* operator->() const;
};

template<typename T> class PassOwnPtr {
public:
    T* leakPtr();
    T* operator->();
};

class ExecutionContext {
public:
    virtual RefPtr<SecurityOrigin> getSecurityOrigin() = 0;
    virtual bool isSecureContext(String&) = 0;
    virtual ContentSecurityPolicy* contentSecurityPolicy() = 0;
};

class SecurityOrigin {
public:
    static RefPtr<SecurityOrigin> create(const KURL&);
    bool canRequest(const KURL&) const;
    String toString() const;
};

class KURL {
public:
    KURL();
    KURL(const KURL&, const String&);
    String protocol() const;
    String getString() const;
    void removeFragmentIdentifier();
};

class SchemeRegistry {
public:
    static bool shouldTreatURLSchemeAsAllowingServiceWorkers(const String&);
};

class ContentSecurityPolicy {
public:
    enum RedirectStatus { DidNotRedirect };
    enum ReportingStatus { SendReport };
    bool allowWorkerContextFromSource(const KURL&, RedirectStatus, ReportingStatus);
};

class WebServiceWorkerError {
public:
    enum ErrorType { ErrorTypeState, ErrorTypeSecurity, ErrorTypeType };
    WebServiceWorkerError(ErrorType, const char*);
    WebServiceWorkerError(ErrorType, const String&);
    WebServiceWorkerError(ErrorType, const WebString&);
};

class WebString {
public:
    static WebString fromUTF8(const std::string&);
    std::string utf8() const;
};

class RegistrationCallbacks {
public:
    virtual void onError(const WebServiceWorkerError&) = 0;
};

class ServiceWorkerProvider {
public:
    virtual bool validateScopeAndScriptURL(const KURL&, const KURL&, WebString*) = 0;
    virtual void registerServiceWorker(const KURL&, const KURL&, RegistrationCallbacks*) = 0;
};

class ServiceWorkerContainer {
public:
    ServiceWorkerProvider* m_provider;
    void registerServiceWorkerImpl(ExecutionContext*, const KURL&, const KURL&, PassOwnPtr<RegistrationCallbacks>);
};