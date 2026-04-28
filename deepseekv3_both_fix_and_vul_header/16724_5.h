#include <memory>
#include <string>

using std::unique_ptr;

template<typename T>
class Local;

template<typename T>
class MaybeLocal;

class StringTable {
public:
    static StringTable& Get();
    std::string unsafeInherit;
    std::string inheritUnsafe;
};

class Object;
class Value;

template<typename T>
T ReadOption(MaybeLocal<Object> options, const std::string& key, T defaultValue);

class ReferenceHandle {
public:
    ReferenceHandle(Local<Value> value, bool inherit);
    static unique_ptr<ReferenceHandle> New(Local<Value> value, MaybeLocal<Object> options);
};

template<typename T>
class Local {};

template<typename T>
class MaybeLocal {
public:
    MaybeLocal(Local<T> local);
};