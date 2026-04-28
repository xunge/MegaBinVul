#include <stdint.h>

typedef uintptr_t Address;

enum ICState {
    PREMONOMORPHIC,
    UNINITIALIZED
};

class Object;
class Name;
class Code;
class Map;
class JSObject;
class JSFunction;
class AccessorPair;
class ExecutableAccessorInfo;
class SharedFunctionInfo;
class LookupIterator;
class Isolate;
class CallOptimization;
class LoadIC;
class NamedLoadHandlerCompiler;

template<typename T>
class Handle {
public:
    Handle() : object_(nullptr), isolate_(nullptr) {}
    T* operator->() const;
    bool is_null() const;
    T* operator*() const;
    static Handle<T> cast(Handle<Object> object);
    Handle(T* object, Isolate* isolate);
private:
    T* object_;
    Isolate* isolate_;
};

class Object {
public:
    bool IsExecutableAccessorInfo() const;
    bool IsAccessorPair() const;
    bool IsJSFunction() const;
    bool IsJSObject() const;
};

class Name : public Object {};
class Code {
public:
    enum Kind {
        LOAD_IC
    };
};
class Map : public Object {};
class JSObject : public Object {
public:
    bool HasFastProperties() const;
};
class JSFunction : public JSObject {
public:
    bool IsBuiltin() const;
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

class SharedFunctionInfo {
public:
    enum LanguageMode {
        SLOPPY
    };
    LanguageMode language_mode() const;
};

class LookupIterator {
public:
    enum State {
        JSPROXY,
        ACCESS_CHECK,
        ACCESSOR
    };
    State state() const;
    bool IsFound() const;
    Handle<Object> GetAccessors();
    template<typename T> Handle<T> GetHolder();
    Handle<Object> GetReceiver();
    Handle<Name> name();
};

class Isolate {
public:
    void* GetData(uint32_t index);
};

class CallOptimization {
public:
    CallOptimization(Handle<JSFunction> function);
    bool is_simple_api_call() const;
    bool IsCompatibleReceiver(Handle<Object> receiver, Handle<JSObject> holder);
};

class LoadIC {
public:
    ICState state() const;
    bool UseVector() const;
    void ConfigureVectorState(ICState state);
    void set_target(Code* code);
    Handle<Code> pre_monomorphic_stub();
    Handle<Code> slow_stub();
    Code::Kind kind() const;
    Handle<Map> receiver_map();
    Isolate* isolate();
    Handle<Code> ComputeHandler(LookupIterator* lookup);
    void PatchCache(Handle<Name> name, Handle<Code> code);
    void UpdateCaches(LookupIterator* lookup);
};

class NamedLoadHandlerCompiler {
public:
    static Handle<Code> ComputeLoadNonexistent(Handle<Name> name, Handle<Map> receiver_map);
};

namespace v8 {
template <typename T>
T ToCData(Address address);
}

bool is_sloppy(SharedFunctionInfo::LanguageMode mode);

#define TRACE_IC(tag, name)
#define TRACE_GENERIC_IC(isolate, tag, message)