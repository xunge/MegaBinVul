#include <string>
#include <cassert>

namespace v8 {
class Value {
public:
    bool IsString();
    bool IsInt32();
    int Int32Value();
};

class String {
public:
    class Utf8Value {
    public:
        explicit Utf8Value(v8::Value*);
        std::string operator*();
    };
};

class Isolate;

template<typename T>
class FunctionCallbackInfo {
public:
    int Length() const;
    T* operator[](int) const;
    class ReturnValue {
    public:
        void Set(void*);
    };
    ReturnValue GetReturnValue() const;
    Isolate* GetIsolate() const;
};
}

class BlobNativeHandler {
public:
    struct Context {
        struct V8Context {
            void* Global();
        };
        V8Context* v8_context();
    };
    Context* context();
    void TakeBrowserProcessBlob(const v8::FunctionCallbackInfo<v8::Value>& args);
};

namespace blink {
class WebString {
public:
    static WebString fromUTF8(const std::string&);
};

class WebBlob {
public:
    static WebBlob createFromUUID(const WebString&, const WebString&, int);
    void* toV8Value(void*, v8::Isolate*);
};
}

#define CHECK(cond) assert(cond)
#define CHECK_EQ(a, b) assert((a) == (b))
#define DCHECK(cond) assert(cond)
#define DCHECK_EQ(a, b) assert((a) == (b))