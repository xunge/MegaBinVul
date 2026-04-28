#include <string>
#include <cwchar>

class IFXJS_Context;
struct FXJSErr;

class CFX_ByteString {
public:
    CFX_ByteString() {}
    CFX_ByteString(const char* str) {}
    const char* c_str() const { return ""; }
    size_t GetLength() const { return 0; }
};

class CFX_WideString {
public:
    CFX_WideString(const wchar_t* str) {}
    CFX_ByteString UTF8Encode() const { return CFX_ByteString(); }
};

namespace v8 {
    class Value;
    class String;
    class Context;
    class Script;
    
    enum NewStringType { kNormal };
    
    template<typename T> class Local {
    public:
        T* operator->() { return nullptr; }
        bool ToLocal(Local<T>* out) { *out = Local<T>(); return false; }
        static Local<T> ToLocalChecked() { return Local<T>(); }
    };
    
    class Isolate {
    public:
        class Scope {
        public:
            Scope(Isolate* isolate) {}
        };
        Local<Context> GetCurrentContext() { return Local<Context>(); }
    };
    
    class TryCatch {
    public:
        TryCatch(Isolate* isolate) {}
        Local<Value> Exception() { return Local<Value>(); }
    };
    
    class Script {
    public:
        static Local<Script> Compile(Local<Context> context, Local<String> source);
        Local<Value> Run(Local<Context> context);
    };
    
    class String {
    public:
        class Utf8Value {
        public:
            Utf8Value(Local<Value> value) {}
        };
        static Local<String> NewFromUtf8(Isolate* isolate, const char* data, NewStringType type, int length);
    };
}