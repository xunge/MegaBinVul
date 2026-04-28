#include <stdbool.h>

class JSObject;

struct PrototypeIterator {
    bool IsAtEnd();
    void Advance();
    JSObject* GetCurrent();
    template<typename T> T* GetCurrent() { return static_cast<T*>(GetCurrent()); }
};

class DisallowHeapAllocation {
public:
    DisallowHeapAllocation() {}
};

class JSObject {
public:
    bool IsJSProxy();
    bool IsAccessCheckNeeded();
    bool HasIndexedInterceptor();
    bool HasStringWrapperElements();
    struct Elements {
        int length();
    };
    Elements* elements();
};