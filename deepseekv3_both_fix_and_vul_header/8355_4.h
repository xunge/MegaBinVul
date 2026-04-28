#include <cassert>

namespace v8 {
class Isolate;
}

class Location;
class LocalDOMWindow;
class SecurityOrigin;
class ExceptionState;
class Frame;
class SecurityContext;

class BindingSecurity {
public:
    static bool shouldAllowAccessTo(v8::Isolate*, const LocalDOMWindow*, const Location*, ExceptionState&);
    static bool canAccessFrame(const LocalDOMWindow*, const SecurityOrigin*, const LocalDOMWindow*, ExceptionState&);
    static bool canAccessFrame(v8::Isolate*, const LocalDOMWindow*, const SecurityOrigin*, const LocalDOMWindow*, ExceptionState&);
};

class Location {
public:
    Frame* frame() const;
};

class Frame {
public:
    SecurityContext* securityContext() const;
    LocalDOMWindow* domWindow() const;
};

class SecurityContext {
public:
    SecurityOrigin* getSecurityOrigin() const;
};

#define ASSERT assert