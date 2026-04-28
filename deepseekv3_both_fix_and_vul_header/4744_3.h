#include <string>
#include <vector>
#include <memory>

class Event {
public:
    void setDefaultHandled();
    double platformTimeStamp();
};

class ResourceRequest;
class FrameLoadRequest;
class AtomicString;
class Document;
class KURL;
class SecurityOrigin;

enum NavigationPolicy {
    NavigationPolicyDownload
};

enum InputToLoadPerfMetricReportPolicy {
    ReportLink
};

enum RelationType {
    RelationNoReferrer,
    RelationNoOpener
};

enum ReferrerPolicyEnum {
    NeverSendReferrer,
    NeverSetOpener
};

class ReferrerPolicy {
public:
    static bool referrerPolicyFromString(const std::string&, ReferrerPolicy*);
};

class SecurityPolicy {
public:
    static bool referrerPolicyFromString(const std::string&, ReferrerPolicy*);
    static std::string generateReferrer(ReferrerPolicy, const KURL&, const std::string&);
};

class WebURLRequest {
public:
    enum RequestContext {
        RequestContextDownload,
        RequestContextHyperlink
    };
};

class StringBuilder {
public:
    void append(const std::string&);
    std::string toString();
};

class KURL {
public:
    KURL(const std::string&);
    bool protocolIsData() const;
    std::string toString() const;
};

class ResourceRequest {
public:
    ResourceRequest(const KURL&);
    void setUIStartTime(double);
    void setInputPerfMetricReportPolicy(InputToLoadPerfMetricReportPolicy);
    void setHTTPReferrer(const std::string&);
    void setRequestContext(WebURLRequest::RequestContext);
};

class AtomicString {
public:
    AtomicString();
    AtomicString(const std::string&);
    bool operator==(const AtomicString&) const;
};

class SecurityOrigin {
public:
    bool canRequest(const KURL&);
};

class LocalFrame {
public:
    class Loader {
    public:
        class Client {
        public:
            void loadURLExternally(const ResourceRequest&, NavigationPolicy, const AtomicString&, bool);
        };
        Client* client();
        void load(const FrameLoadRequest&);
    };
    Loader& loader();
    LocalFrame* frame();
};

class FrameLoadRequest {
public:
    FrameLoadRequest(Document*, const ResourceRequest&, const std::string&);
    void setTriggeringEvent(Event*);
    void setShouldSendReferrer(ReferrerPolicyEnum);
    void setShouldSetOpener(ReferrerPolicyEnum);
};

class Document {
public:
    LocalFrame* frame();
    KURL completeURL(const std::string&);
    std::string outgoingReferrer();
    SecurityOrigin* getSecurityOrigin();
};

class HTMLAnchorElement {
public:
    Document& document();
    std::string fastGetAttribute(const std::string&);
    std::string getAttribute(const std::string&);
    bool hasAttribute(const std::string&);
    bool hasRel(RelationType);
    void sendPings(const KURL&);
    void appendServerMapMousePosition(StringBuilder&, Event*);
    static std::string stripLeadingAndTrailingHTMLSpaces(const std::string&);
    void handleClick(Event*);
};

const std::string hrefAttr = "href";
const std::string referrerpolicyAttr = "referrerpolicy";
const std::string downloadAttr = "download";
const std::string targetAttr = "target";
const AtomicString nullAtom;