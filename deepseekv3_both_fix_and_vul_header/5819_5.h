#include <cassert>

namespace v8 {

template<typename T> class Local;

class Value {
public:
    bool IsObject() const;
};

class Context {};

class Object : public Value {
public:
    Local<Context> CreationContext() const;
};

template<typename T>
class Local {
public:
    T* operator->() const;
    static Local<Object> Cast(const Local<Value>& value);
};

template<typename T>
class FunctionCallbackInfo {
public:
    int Length() const;
    Local<T> operator[](int index) const;
    struct ReturnValue {
        void Set(void* value);
    };
    ReturnValue GetReturnValue() const;
};

}  // namespace v8

class blink {
public:
    class WebFrame {
    public:
        static bool scriptCanAccess(WebFrame* frame);
    };
};

class ScriptContext {
public:
    class ModuleSystem {
    public:
        void* NewInstance();
    };
    
    blink::WebFrame* web_frame();
    ModuleSystem* module_system();
};

class ScriptContextSet {
public:
    ScriptContext* GetByV8Context(v8::Local<v8::Context> context);
};

class V8ContextNativeHandler {
public:
    class Dispatcher {
    public:
        ScriptContextSet script_context_set();
    };
    
    Dispatcher* dispatcher_;
    
    void GetModuleSystem(const v8::FunctionCallbackInfo<v8::Value>& args);
};

#define CHECK(expr) assert(expr)
#define CHECK_EQ(a, b) assert((a) == (b))