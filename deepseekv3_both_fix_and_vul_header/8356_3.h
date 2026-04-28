class v8_Isolate;
class ExceptionState;
class SecurityOrigin;

class LocalDOMWindow {};
class DOMWindow {
public:
    const class Frame* frame() const { return nullptr; }
};
class Frame {
public:
    class SecurityContext* securityContext() const { return nullptr; }
};
class SecurityContext {
public:
    SecurityOrigin* getSecurityOrigin() const { return nullptr; }
};

#define ASSERT(expr) ((void)0)

namespace v8 {
    typedef v8_Isolate Isolate;
}

namespace BindingSecurity {
    bool canAccessFrame(const LocalDOMWindow*, SecurityOrigin*, const DOMWindow*, ExceptionState&);
    bool canAccessFrame(v8::Isolate*, const LocalDOMWindow*, SecurityOrigin*, const DOMWindow*, ExceptionState&);
    bool shouldAllowAccessTo(v8::Isolate*, const LocalDOMWindow*, const DOMWindow*, ExceptionState&);
}