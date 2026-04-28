#include <functional>
#include <memory>

class ScriptContext;
class ObjectBackedNativeHandler {
public:
    explicit ObjectBackedNativeHandler(ScriptContext* context) {}
};

namespace base {

template<typename T>
class Unretained {
public:
    explicit Unretained(T* obj) : obj_(obj) {}
    T* get() const { return obj_; }
private:
    T* obj_;
};

template<typename Signature>
class Callback;

template<typename R, typename... Args>
class Callback<R(Args...)> {
public:
    Callback() = default;
    template<typename F>
    explicit Callback(F&& f) {}
};

template<typename R, typename... Args>
Callback<R(Args...)> Bind(R (*function)(Args...)) {
    return Callback<R(Args...)>(function);
}

template<typename R, typename T, typename... Args>
Callback<R(Args...)> Bind(R (T::*method)(Args...), Unretained<T> obj) {
    return Callback<R(Args...)>([obj, method](Args... args) {
        return (obj.get()->*method)(std::forward<Args>(args)...);
    });
}

}  // namespace base

class V8ContextNativeHandler : public ObjectBackedNativeHandler {
public:
    explicit V8ContextNativeHandler(ScriptContext* context);
    void RouteFunction(const char* name, base::Callback<void()> callback);
    void RouteFunction(const char* name, const char* test, base::Callback<void()> callback);
    void GetAvailability();
    void GetModuleSystem();
    void RunWithNativesEnabled();
private:
    ScriptContext* context_;
};