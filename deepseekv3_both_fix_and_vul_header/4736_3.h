#include <functional>
#include <memory>
#include <string>

namespace base {
template <typename T>
class WeakPtr;
template <typename T>
class WeakPtrFactory {
public:
    explicit WeakPtrFactory(T* ptr) {}
    WeakPtr<T> GetWeakPtr() { return WeakPtr<T>(); }
};
template <typename T>
class WeakPtr {};

template <typename R, typename... Args>
class Callback {};

template <typename R, typename... Args>
Callback<R(Args...)> Bind(R (*)(Args...)) { return Callback<R(Args...)>(); }

template <typename R, typename T, typename... Args>
Callback<R(Args...)> Bind(R (T::*)(Args...), const WeakPtr<T>&) { return Callback<R(Args...)>(); }
}  // namespace base

class ScriptContext {};
class ObjectBackedNativeHandler {
public:
    explicit ObjectBackedNativeHandler(ScriptContext* context) {}
    void RouteFunction(const std::string& name, const std::string& source, const base::Callback<void()>& callback) {}
    void RouteFunction(const std::string& name, const base::Callback<void()>& callback) {}
};

class DisplaySourceCustomBindings : public ObjectBackedNativeHandler {
public:
    explicit DisplaySourceCustomBindings(ScriptContext* context);
    void StartSession();
    void TerminateSession();
private:
    base::WeakPtrFactory<DisplaySourceCustomBindings> weak_factory_;
};