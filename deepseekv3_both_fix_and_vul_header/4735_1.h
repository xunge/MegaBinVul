#include <functional>
#include <string>
#include <memory>

class ScriptContext;

class ObjectBackedNativeHandler {
public:
    explicit ObjectBackedNativeHandler(ScriptContext* context) {}
    virtual ~ObjectBackedNativeHandler() {}
};

namespace base {

template <typename T>
class UnretainedWrapper {
public:
    explicit UnretainedWrapper(T* o) : obj_(o) {}
    T* get() const { return obj_; }

private:
    T* obj_;
};

template <typename T>
UnretainedWrapper<T> Unretained(T* o) {
    return UnretainedWrapper<T>(o);
}

template <typename Signature>
class Callback;

template <typename R, typename... Args>
class Callback<R(Args...)> {
public:
    Callback() = default;
    template <typename Functor>
    explicit Callback(Functor&& functor) {}
    R Run(Args... args) const { return R(); }
};

template <typename R, typename... Args>
Callback<R(Args...)> Bind(R (*function)(Args...)) {
    return Callback<R(Args...)>();
}

template <typename T, typename R, typename... Args>
Callback<R(Args...)> Bind(R (T::*method)(Args...), UnretainedWrapper<T> this_) {
    return Callback<R(Args...)>();
}

}  // namespace base

class I18NCustomBindings : public ObjectBackedNativeHandler {
public:
    explicit I18NCustomBindings(ScriptContext* context);
    void GetL10nMessage();
    void GetL10nUILanguage();
    void DetectTextLanguage();
    void RouteFunction(const std::string& name, const base::Callback<void()>& callback);
    void RouteFunction(const std::string& name, const std::string& api,
                      const base::Callback<void()>& callback);
};