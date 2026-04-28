class v8 {
public:
    class Isolate {
    public:
        static Isolate* GetCurrent();
    };
    class HandleScope {
    public:
        explicit HandleScope(Isolate* isolate);
    };
    template <class T> class Persistent;
    template <class T> class Local {
    public:
        Local();
        static Local<T> New(Isolate* isolate, const Persistent<T>& obj);
    };
    template <class T> class Persistent {
    public:
        void Reset();
        T* operator->() const;
        operator T*() const;
    };
    class Function {};
    class Object {};
};

class Context {
public:
    v8::Isolate* isolate();
    void CallFunction(v8::Local<v8::Function> func);
};

class GCCallback {
public:
    void RunCallback();
    v8::Persistent<v8::Function> callback_;
    v8::Persistent<v8::Function> fallback_;
    Context* context_;
};