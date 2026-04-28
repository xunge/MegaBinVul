#include <iostream>
#include <cassert>

#define CHECK(cond) assert(cond)
#define CHECK_EQ(a, b) CHECK((a) == (b))
#define DCHECK(cond) assert(cond)
#define DCHECK_EQ(a, b) DCHECK((a) == (b))
#define LOG(severity) std::cerr

namespace v8 {
    template<typename T> class Local;
    
    class String {};
    class Value {
    public:
        bool IsString() const { return false; }
        Local<String> ToString() const;
    };
    
    class Object;
    class Isolate;
    class Context;
    
    template<typename T> class Local {
    public:
        T* operator->() { return nullptr; }
        Local(T*) {}
    };
    
    template<typename T> class Maybe {
    public:
        bool FromMaybe(bool) const { return false; }
    };
    
    enum PropertyAttribute { ReadOnly };
    
    template<typename T>
    class FunctionCallbackInfo {
    public:
        Local<Object> This() const { return Local<Object>(nullptr); }
        int Length() const { return 0; }
        Local<T> operator[](int) const { return Local<T>(nullptr); }
        Isolate* GetIsolate() const { return nullptr; }
    };
    
    class Object {
    public:
        Maybe<bool> DefineOwnProperty(Context*, Local<String>, Local<Value>, PropertyAttribute) { 
            return Maybe<bool>(); 
        }
    };
    
    class Isolate {
    public:
        Context* GetCurrentContext() { return nullptr; }
    };
    
    class Context {};
    
    inline Local<String> Value::ToString() const { return Local<String>(nullptr); }
}