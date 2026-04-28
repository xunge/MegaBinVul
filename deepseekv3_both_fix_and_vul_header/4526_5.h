#include <string>
#include <cassert>

class String {
public:
    String() {}
    String(const char* s) : m_str(s) {}
    String(const std::string& s) : m_str(s) {}
    String operator+(const String& other) const { return String(m_str + other.m_str); }
    String operator+(const char* s) const { return String(m_str + s); }
    friend String operator+(const char* s, const String& str) { return String(s + str.m_str); }
    std::string m_str;
};

class KURL {
public:
    KURL() {}
    KURL(const KURL&, const std::string&) {}
    bool isNull() const { return false; }
    std::string protocol() const { return ""; }
};

class SecurityOrigin {
public:
    std::string toString() const { return ""; }
    std::string protocol() const { return ""; }
    std::string domain() const { return ""; }
    bool domainWasSetInDOM() const { return false; }
    bool canAccessCheckSuborigins(const SecurityOrigin*) const { return false; }
    static SecurityOrigin* create(const KURL&) { return nullptr; }
};

class SecurityContext {
public:
    SecurityOrigin* getSecurityOrigin() const { return nullptr; }
    bool isSandboxed(int) const { return false; }
};

class Frame {
public:
    bool isRemoteFrame() const { return false; }
    SecurityContext* securityContext() const { return nullptr; }
};

class Document {
public:
    const KURL& url() const { static KURL url; return url; }
    SecurityOrigin* getSecurityOrigin() const { return nullptr; }
    bool isSandboxed(int) const { return false; }
};

class LocalDOMWindow;

class DOMWindow {
public:
    Frame* frame() const { return nullptr; }
    Document* document() const { return nullptr; }
    bool isLocalDOMWindow() const { return false; }
    String crossDomainAccessErrorMessage(const LocalDOMWindow* callingWindow) const;
};

class LocalDOMWindow : public DOMWindow {
public:
    Document* document() const { return nullptr; }
};

#define ASSERT(x) assert(x)
const int SandboxOrigin = 0;