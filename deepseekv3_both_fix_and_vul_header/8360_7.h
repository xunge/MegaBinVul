#include <cassert>

class v8_Isolate;
class LocalDOMWindow;
class SecurityOrigin;

enum SecurityReportingOption {
    Option1,
    Option2
};

namespace v8 {
    typedef v8_Isolate Isolate;
}

class Location {
public:
    class Frame* frame() const;
};

class SecurityContext {
public:
    SecurityOrigin* getSecurityOrigin() const;
};

class Frame {
public:
    SecurityContext* securityContext() const;
    LocalDOMWindow* domWindow() const;
};

namespace BindingSecurity {
    bool shouldAllowAccessTo(v8::Isolate* isolate, const LocalDOMWindow* accessingWindow, const Location* target, SecurityReportingOption reportingOption);
    bool canAccessFrame(const LocalDOMWindow*, const SecurityOrigin*, const LocalDOMWindow*, SecurityReportingOption);
    bool canAccessFrame(v8::Isolate*, const LocalDOMWindow*, const SecurityOrigin*, const LocalDOMWindow*, SecurityReportingOption);
}

#define ASSERT assert