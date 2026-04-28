#include <functional>
#include <memory>

class ScriptContext;

class ObjectBackedNativeHandler {
public:
    explicit ObjectBackedNativeHandler(ScriptContext* context);
    void RouteFunction(const char* name, std::function<void()> func);
};

class UtilsNativeHandler : public ObjectBackedNativeHandler {
public:
    explicit UtilsNativeHandler(ScriptContext* context);
    void CreateClassWrapper();
    void DeepCopy();
};

namespace base {
template <typename T>
class Unretained {
public:
    explicit Unretained(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
private:
    T* ptr_;
};

template <typename F, typename T>
std::function<void()> Bind(F f, Unretained<T> u) {
    return std::bind(f, u.get());
}
}