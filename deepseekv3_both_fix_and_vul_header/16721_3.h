class Value {};
class Object {};

template<typename T>
class Local {
public:
    T* operator->() { return nullptr; }
    T& operator*() { static T t; return t; }
};

template<typename T>
class MaybeLocal {
public:
    MaybeLocal() {}
    MaybeLocal(Local<T> local) {}
};

class Isolate {
public:
    Isolate* operator->() { return this; }
    Isolate& operator*() { return *this; }
};

class ReferenceHandle {
public:
    Isolate* isolate;
    Local<Value> Get(Local<Value> key_handle, MaybeLocal<Object> maybe_options);
    Local<Value> Get(Local<Value> key_handle, MaybeLocal<Object> maybe_options, int inherit);
};

class ThreePhaseTask {
public:
    template<bool async, typename GetRunner>
    static Local<Value> Run(Isolate& isolate, ReferenceHandle& handle, Local<Value> key, MaybeLocal<Object> options);
    template<bool async, typename GetRunner> 
    static Local<Value> Run(Isolate& isolate, ReferenceHandle& handle, Local<Value> key, MaybeLocal<Object> options, int inherit);
};

constexpr bool async = false;
int inherit = 0;
class GetRunner {};