namespace v8 {

template<typename T>
class Local {
public:
    Local() {}
    T* operator->() { return nullptr; }
};

class Value {};

class Object : public Value {
public:
    Local<Object> Global() { return Local<Object>(); }
};

class Context : public Object {};

class Isolate {
public:
    Local<Context> GetCurrentContext() { return Local<Context>(); }
};

}  // namespace v8

class WebArrayBuffer {};
class DOMArrayBuffer : public WebArrayBuffer {};

template<typename T>
class PassRefPtr {
public:
    PassRefPtr(T*) {}
    template<typename U>
    PassRefPtr(U& ref) : ptr_(static_cast<T*>(&ref)) {}
    T* operator->() { return ptr_; }
    T& operator*() { return *ptr_; }
private:
    T* ptr_;
};

class WebArrayBufferConverter {
public:
    static v8::Local<v8::Value> toV8Value(WebArrayBuffer*, v8::Local<v8::Object>, v8::Isolate*);
    static v8::Local<v8::Value> toV8(PassRefPtr<DOMArrayBuffer>, v8::Local<v8::Object>, v8::Isolate*);
};