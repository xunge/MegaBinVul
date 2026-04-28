enum PropertyType {};

namespace v8 {
class Value;
class Object;
class Isolate;

template<typename T>
class Local {
public:
    bool IsEmpty() const { return false; }
    T* operator->() { return nullptr; }
};

template<typename T>
class PropertyCallbackInfo {
public:
    Local<Object> Holder() const { return Local<Object>(); }
    Isolate* GetIsolate() const { return nullptr; }
};

template<typename T>
class Maybe {
public:
    bool FromMaybe(bool defaultValue) { return defaultValue; }
};

class Object {
public:
    Maybe<bool> CreateDataProperty(void* context, PropertyType property, Local<Value> value);
    Maybe<bool> Set(void* context, PropertyType property, Local<Value> value);
};

class Isolate {
public:
    static Isolate* GetCurrent();
    void* GetCurrentContext() { return nullptr; }
};
}  // namespace v8

template<typename T>
class SharedPersistent {
public:
    v8::Local<v8::Object> newLocal(v8::Isolate* isolate) { return v8::Local<v8::Object>(); }
};

class HTMLPlugInElement {
public:
    SharedPersistent<v8::Object>* pluginWrapper() { return nullptr; }
};

class ElementType {
public:
    static HTMLPlugInElement* toImpl(v8::Local<v8::Object> holder) { return nullptr; }
};

template<typename T>
class RefPtr {
public:
    RefPtr(T* ptr) : ptr_(ptr) {}
    T* operator->() { return ptr_; }
    operator bool() const { return ptr_ != nullptr; }
private:
    T* ptr_;
};

#define ASSERT(condition) ((void)0)
#define ALLOW_UNUSED_LOCAL(variable) ((void)variable)
#define v8CallBoolean(maybe) (maybe.FromMaybe(false))