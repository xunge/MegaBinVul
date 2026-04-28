#include <stdbool.h>
#include <assert.h>

#define ASSERT_WITH_SECURITY_IMPLICATION(expr) assert(expr)

namespace v8 {
class Isolate;
}

class DOMWindow;

class Frame {
public:
    DOMWindow* domWindow() const;
};

class LocalDOMWindow;
class SecurityOrigin;

class DOMWindow {
public:
    Frame* frame() const;
    bool isLocalDOMWindow() const;
    const char* sanitizedCrossDomainAccessErrorMessage(const LocalDOMWindow*) const;
    const char* crossDomainAccessErrorMessage(const LocalDOMWindow*) const;
};

class ExceptionState {
public:
    void throwSecurityError(const char*, const char*);
};

bool isOriginAccessibleFromDOMWindow(const SecurityOrigin*, const LocalDOMWindow*);