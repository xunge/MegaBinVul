#include <stdint.h>

typedef uintptr_t Address;

class Isolate;
class Object;

template <typename T>
class Handle {
public:
    Handle();
    Handle(T* object, Isolate* isolate);
    bool is_null() const;
    T* operator->() const;
    template <typename U> static Handle<T> cast(Handle<U> obj);
};

class Object {
public:
    bool IsExecutableAccessorInfo() const;
    bool IsAccessorPair() const;
    bool IsJSFunction() const;
    bool IsJSObject() const;
};

class Name : public Object {};
class Code : public Object {
public:
    enum Kind { LOAD_IC };
};
class Map : public Object {};
class JSObject : public Object {
public:
    bool HasFastProperties() const;
};

class SharedFunctionInfo {
public:
    bool IsBuiltin() const;
    int language_mode() const;
};

class JSFunction : public JSObject {
public:
    SharedFunctionInfo* shared() const;
};

class AccessorPair : public Object {
public:
    Object* getter() const;
};

class ExecutableAccessorInfo : public Object {
public:
    Address getter() const;
    static bool IsCompatibleReceiverMap(Isolate* isolate, Handle<ExecutableAccessorInfo> info, Handle<Map> map);
};

class CallOptimization {
public:
    CallOptimization(Handle<JSFunction> function);
    bool is_simple_api_call() const;
    bool IsCompatibleReceiver(Handle<Object> receiver, Handle<JSObject> holder);
};

class Isolate {
public:
    void TRACE_GENERIC_IC(const char* type, const char* reason);
    void TRACE_IC(const char* type, Handle<Name> name);
    int language_mode() const;
};

class LookupIterator {
public:
    enum State {
        JSPROXY,
        ACCESS_CHECK,
        ACCESSOR,
        INTERCEPTOR
    };

    State state() const;
    bool IsFound() const;
    Handle<Object> GetAccessors();
    template <typename T> Handle<T> GetHolder();
    Handle<Object> GetReceiver();
    Handle<Name> name();
    void Next();
    void LookupForRead(LookupIterator* it);
};

class LoadIC {
public:
    enum State { UNINITIALIZED, PREMONOMORPHIC };
    State state() const;
    void ConfigureVectorState(State state);
    Handle<Code> slow_stub();
    Code::Kind kind() const;
    bool is_strong(int language_mode);
    bool is_sloppy(int language_mode);
    int language_mode() const;
    Handle<Map> receiver_map();
    Handle<Code> ComputeHandler(LookupIterator* lookup);
    void PatchCache(Handle<Name> name, Handle<Code> code);
    Isolate* isolate();
    void UpdateCaches(LookupIterator* lookup);
    bool IsCompatibleReceiver(LookupIterator* lookup, Handle<Map> map);
    void LookupForRead(LookupIterator* it);
};

class NamedLoadHandlerCompiler {
public:
    static Handle<Code> ComputeLoadNonexistent(Handle<Name> name, Handle<Map> map);
};

namespace v8 {
template <typename T>
T ToCData(Address address);
}

#define TRACE_IC(type, name) isolate()->TRACE_IC(type, name)
#define TRACE_GENERIC_IC(isolate, type, reason) isolate->TRACE_GENERIC_IC(type, reason)