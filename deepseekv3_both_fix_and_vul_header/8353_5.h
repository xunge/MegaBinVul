class v8_Isolate;
class ExceptionState;
class SecurityOrigin;

namespace v8 {
    typedef v8_Isolate Isolate;
}

class LocalDOMWindow;

class Document {
public:
    SecurityOrigin* getSecurityOrigin() const;
    LocalDOMWindow* domWindow() const;
};

class Node {
public:
    const Document& document() const;
};

class BindingSecurity {
public:
    static bool shouldAllowAccessTo(v8::Isolate* isolate, const LocalDOMWindow* accessingWindow, const Node* target, ExceptionState& exceptionState);
    static bool canAccessFrame(const LocalDOMWindow* accessingWindow, const SecurityOrigin* targetOrigin, const LocalDOMWindow* targetWindow, ExceptionState& exceptionState);
    static bool canAccessFrame(v8::Isolate* isolate, const LocalDOMWindow* accessingWindow, const SecurityOrigin* targetOrigin, const LocalDOMWindow* targetWindow, ExceptionState& exceptionState);
};