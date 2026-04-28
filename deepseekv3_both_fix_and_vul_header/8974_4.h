#include <string>
#include <cstring>
#include <cwchar>

class v8_Isolate {
public:
    class Scope {
    public:
        Scope(v8_Isolate* isolate) {}
    };
};

class v8_HandleScope {
public:
    v8_HandleScope(v8_Isolate* isolate) {}
};

class v8_Value {};
class v8_ObjectTemplate {
public:
    void Set(v8_Isolate* isolate, const char* name, v8_Value* value) {}
};

template <class T>
class v8_Persistent {
public:
    void Reset(v8_Isolate* isolate, T* handle) {}
    T* Get(v8_Isolate* isolate) { return nullptr; }
};

template <class T>
class v8_Local {
public:
    v8_Local() {}
    v8_Local(T* ptr) {}
    static v8_Local New(v8_Isolate* isolate, v8_Persistent<T>& handle) { return v8_Local(handle.Get(isolate)); }
    T* operator->() { return nullptr; }
    operator T*() { return nullptr; }
};

namespace v8 {
    typedef ::v8_Isolate Isolate;
    typedef ::v8_Value Value;
    typedef ::v8_ObjectTemplate ObjectTemplate;
    typedef ::v8_HandleScope HandleScope;
    template <class T> using Local = v8_Local<T>;
    template <class T> using Persistent = v8_Persistent<T>;
}

class CFX_ByteString {
public:
    CFX_ByteString() {}
    CFX_ByteString(const char* str) {}
    const char* c_str() const { return nullptr; }
};

class CFX_WideString {
public:
    CFX_WideString(const wchar_t* str) {}
    CFX_ByteString UTF8Encode() const { return CFX_ByteString(); }
};

class CFXJS_ObjDefinition {
public:
    static CFXJS_ObjDefinition* ForID(v8::Isolate* pIsolate, int nObjDefnID) { return nullptr; }
    v8::Local<v8::ObjectTemplate> GetInstanceTemplate() { return v8::Local<v8::ObjectTemplate>(); }
    v8::Persistent<v8::ObjectTemplate> m_objTemplate;
};