#include <stdio.h>
#include <stdlib.h>

namespace v8 {

class Value;
class Object;
class Function;
class String;
class Context;
class Isolate;

template <typename T> class Local {
public:
    T* operator->();
    template <class S> static Local<T> Cast(Local<S> value);
    bool ToLocal(Local<T>* out);
};

class Value {
public:
    bool IsFunction();
};

class Object : public Value {
public:
    Local<Value> Get(Local<Context> context, Local<String> key);
};

class Function : public Value {};
class String : public Value {};
class Context {};
class Isolate {};

class TryCatch {
public:
    TryCatch(Isolate* isolate);
    void ReThrow();
};

} // namespace v8

class ScriptState {
public:
    v8::Isolate* isolate();
    v8::Local<v8::Context> context();
    void* getExecutionContext();
};

class ExceptionState {
public:
    enum ExecutionContextType { ExecutionContext };
};

class V8ScriptRunner {
public:
    static v8::Local<v8::Value> callInternalFunction(v8::Local<v8::Function>, v8::Local<v8::Value>, int, v8::Local<v8::Value>[], v8::Isolate*);
    static v8::Local<v8::Value> callFunction(v8::Local<v8::Function>, void*, v8::Local<v8::Value>, int, v8::Local<v8::Value>[], v8::Isolate*);
};

class PrivateScriptRunner {
public:
    v8::Local<v8::Value> runDOMMethod(ScriptState*, ScriptState*, const char*, const char*, v8::Local<v8::Value>, int, v8::Local<v8::Value>[]);
    v8::Local<v8::Object> classObjectOfPrivateScript(ScriptState*, const char*);
    void initializeHolderIfNeeded(ScriptState*, v8::Local<v8::Object>, v8::Local<v8::Value>);
    void rethrowExceptionInPrivateScript(v8::Isolate*, v8::TryCatch&, ScriptState*, ExceptionState::ExecutionContextType, const char*, const char*);
    v8::Local<v8::String> v8String(v8::Isolate*, const char*);
};

#define RELEASE_NOTREACHED() abort()