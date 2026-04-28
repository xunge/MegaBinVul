#include <memory>

namespace v8 {
template<typename T> class Local;
class Object;
class Value;

class Context {
public:
    Local<Object> Global();
};

class Isolate {
public:
    Context* GetCurrentContext();
};

template<typename T>
class MaybeLocal {
public:
    bool IsEmpty() const;
    Local<T> ToLocalChecked();
};

template<typename T>
class Local {
public:
    Local();
    template <class S> Local(Local<S> that);
    T* operator->() const;
    T* operator*() const;
};
}

struct WebDOMError {
    struct Private;
    std::unique_ptr<Private> m_private;
    
    v8::Local<v8::Value> toV8Value(v8::Local<v8::Object> creationContext, v8::Isolate* isolate);
    
    static v8::Local<v8::Value> toV8(Private*, v8::Local<v8::Object>, v8::Isolate*);
};