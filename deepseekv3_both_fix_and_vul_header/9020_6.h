#include <cstddef>
#include <cassert>

namespace v8 {
class Isolate;
template<typename T> class Local {
public:
    T* operator->();
    bool IsEmpty() const;
    template<typename T2> Local<T2> As();
};
class Value;
class String;
class External {
public:
    void* Value();
};
class Context {
public:
    class Scope {
    public:
        Scope(Context* context);
    };
};
class HandleScope {
public:
    HandleScope(Isolate* isolate);
};
class Object {
public:
    Local<Value> Get(Local<String> key);
    void Delete(Local<String> key);
    Local<Value> GetHiddenValue(Local<String> key);
    void DeleteHiddenValue(Local<String> key);
};
class String {
public:
    static Local<String> NewFromUtf8(Isolate* isolate, const char* data);
};
}

class NativeHandler {
public:
    void Invalidate();
};

class HandlerFunction {};

class ObjectBackedNativeHandler : public NativeHandler {
public:
    v8::Isolate* GetIsolate();
    void Invalidate();
    
    struct RouterData {
        size_t Size();
        v8::Local<v8::Object> Get(size_t);
        void Clear();
    };
    RouterData router_data_;
    
    struct ObjectTemplate {
        void Reset();
    };
    ObjectTemplate object_template_;
    
    struct Context {
        v8::Context* v8_context();
    };
    Context* context_;
};

#define CHECK(x) assert(x)

extern const char* kHandlerFunction;