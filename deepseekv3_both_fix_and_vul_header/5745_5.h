#include <memory>

namespace v8 {
    template<typename T>
    class Local {
    public:
        Local() {}
        Local(T*) {}
        T* operator->() { return nullptr; }
    };

    class Value {};
    class Object : public Value {};
    
    class Isolate {
    public:
        class Context {
        public:
            Local<Object> Global();
        };
        Context* GetCurrentContext();
    };
}

class WebBlob {
private:
    std::unique_ptr<void> m_private;
public:
    v8::Local<v8::Value> toV8Value(v8::Local<v8::Object> creationContext, v8::Isolate* isolate);
    static v8::Local<v8::Value> toV8(void* privateData, v8::Local<v8::Object> creationContext, v8::Isolate* isolate);
};