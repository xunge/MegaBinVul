#include <string>

namespace v8 {
    template<typename T> class Handle {
    public:
        Handle() {}
    };
    class String {};
    class Isolate {};
    
    inline Handle<String> v8AtomicString(Isolate* isolate, const char* str) {
        return Handle<String>();
    }
}