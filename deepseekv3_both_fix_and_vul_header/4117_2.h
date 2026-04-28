#include <memory>

namespace v8 {
    template<typename T>
    class Local {
    public:
        T* operator->() { return nullptr; }
    };

    class Object {
    public:
        struct MaybeBool {
            bool IsNothing() { return false; }
            bool FromJust() { return false; }
        };
        MaybeBool DefineOwnProperty(void* context, Local<class Name> key, Local<class Value> value) { return MaybeBool(); }
        MaybeBool Set(void* context, Local<class Name> key, Local<class Value> value) { return MaybeBool(); }
    };

    class Value {};
    class Name {};
    class Context {};

    class Isolate {
    public:
        void* GetCurrentContext() { return nullptr; }
    };
}

using KeyType = v8::Local<v8::Name>;