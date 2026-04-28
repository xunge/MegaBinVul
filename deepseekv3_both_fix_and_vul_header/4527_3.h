#include <stdbool.h>

class v8__Isolate;
namespace v8 { typedef v8__Isolate Isolate; }

class LocalDOMWindow {
public:
    void printErrorMessage(const char* message) const;
};

class SecurityOrigin;

class DOMWindow {
public:
    bool isLocalDOMWindow() const;
    const char* crossDomainAccessErrorMessage(const LocalDOMWindow* accessingWindow) const;
    class Frame* frame() const;
    const DOMWindow* domWindow() const;
};

class Frame {
public:
    const DOMWindow* domWindow() const;
};

enum SecurityReportingOption {
    ReportSecurityError,
    DoNotReportSecurityError
};

#define ASSERT_WITH_SECURITY_IMPLICATION(expr) ((void)0)

bool isOriginAccessibleFromDOMWindow(SecurityOrigin* origin, const LocalDOMWindow* window);