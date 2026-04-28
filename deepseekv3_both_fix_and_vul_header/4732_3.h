#include <functional>
#include <memory>

class ScriptContext;

class ObjectBackedNativeHandler {
public:
    explicit ObjectBackedNativeHandler(ScriptContext* context);
    void RouteFunction(const char* name, std::function<void()> callback);
    void RouteFunction(const char* name, const char* namespace_name, std::function<void()> callback);
};

namespace base {
template <typename T>
class UnretainedWrapper {
public:
    explicit UnretainedWrapper(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
private:
    T* ptr_;
};

template <typename T>
UnretainedWrapper<T> Unretained(T* ptr) {
    return UnretainedWrapper<T>(ptr);
}

template <typename Functor, typename... BoundArgs>
auto Bind(Functor&& functor, BoundArgs&&... args) -> std::function<void()> {
    return [=]() { 
        std::invoke(functor, args.get()...); 
    };
}
}  // namespace base

class WebstoreBindings : public ObjectBackedNativeHandler {
public:
    explicit WebstoreBindings(ScriptContext* context);
    void Install();
};