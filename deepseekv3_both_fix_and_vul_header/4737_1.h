#include <functional>
#include <string>

class Dispatcher;
class ScriptContext;

class ObjectBackedNativeHandler {
public:
    explicit ObjectBackedNativeHandler(ScriptContext* context);
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

template <typename R, typename... Args>
class Callback {
public:
    Callback() = default;
    template <typename T>
    Callback(const T&) {}
};

template <typename R, typename... Args>
Callback<R(Args...)> Bind(R (*function)(Args...)) {
    return Callback<R(Args...)>();
}

template <typename R, typename T, typename... Args>
Callback<R(Args...)> Bind(R (T::*method)(Args...), const UnretainedWrapper<T>& wrapper) {
    return Callback<R(Args...)>();
}
}  // namespace base

class ApiDefinitionsNatives : public ObjectBackedNativeHandler {
public:
    ApiDefinitionsNatives(Dispatcher* dispatcher, ScriptContext* context);
    void GetExtensionAPIDefinitionsForTest();
    void RouteFunction(const std::string& name, const base::Callback<void()>& callback);
    void RouteFunction(const std::string& name, const std::string& feature, const base::Callback<void()>& callback);
private:
    Dispatcher* dispatcher_;
};