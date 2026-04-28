#include <cstddef>
#include <cwchar>

namespace v8 {
    class Isolate {
    public:
        class Scope {
        public:
            Scope(Isolate* isolate) {}
        };
    };
    
    class HandleScope {
    public:
        HandleScope(Isolate* isolate) {}
    };
    
    template<typename T> class Local;
    template<typename T> class Persistent;
    
    class String;
    class FunctionTemplate;
    class ObjectTemplate;
    class Signature;
    class Value;
    
    typedef void (*FunctionCallback)(void*);
    enum NewStringType { kNormal };
    enum PropertyAttribute { ReadOnly };
    
    class String {
    public:
        static Local<String> NewFromUtf8(Isolate* isolate, const char* data, NewStringType type);
    };
    
    class FunctionTemplate {
    public:
        static Local<FunctionTemplate> New(Isolate* isolate, FunctionCallback callback);
        static Local<FunctionTemplate> New(Isolate* isolate, FunctionCallback callback, 
                                         Local<Value> data, Local<Signature> signature);
    };
    
    class ObjectTemplate {
    public:
        void Set(Local<String> name, Local<FunctionTemplate> value, PropertyAttribute attributes);
    };
    
    template<typename T>
    class Local {
    public:
        Local() {}
        template<typename S>
        Local(const Local<S>& that) {}
        static Local<T> New(Isolate* isolate, const Persistent<T>& handle);
        T* operator->() { return nullptr; }
        Local<T> ToLocalChecked() { return *this; }
    };
    
    template<typename T>
    class Persistent {
    public:
        void Reset(Isolate* isolate, const Local<T>& handle) {}
    };
}

class CFX_WideString {
public:
    CFX_WideString(const wchar_t* str);
    class CFX_ByteString UTF8Encode() const;
};

class CFX_ByteString {
public:
    const char* c_str() const;
};

class CFXJS_ObjDefinition {
public:
    static CFXJS_ObjDefinition* ForID(v8::Isolate* pIsolate, int nObjDefnID);
    v8::Local<v8::ObjectTemplate> GetInstanceTemplate();
    v8::Local<v8::Signature> GetSignature();
    v8::Persistent<v8::ObjectTemplate> m_objTemplate;
};