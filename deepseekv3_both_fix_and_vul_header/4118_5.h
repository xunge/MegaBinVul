#include <cstdint>
#include <string>

namespace v8 {

template<typename T>
class Local {
public:
    T* operator->();
};

class Context {};
class Value {};

class Object {
public:
    bool Set(Local<Context> context, uint32_t index, Local<Value> value);
    bool Set(Local<Context> context, const char* key, Local<Value> value);
};

}  // namespace v8

namespace base {
std::string UintToString(uint32_t index);
}  // namespace base

inline bool IsTrue(bool value) {
    return value;
}

inline bool SetProperty(v8::Local<v8::Context> context,
                       v8::Local<v8::Object> object,
                       const char* key,
                       v8::Local<v8::Value> value) {
    return IsTrue(object->Set(context, key, value));
}