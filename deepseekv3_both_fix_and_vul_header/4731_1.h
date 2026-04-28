#include <functional>
#include <string>
#include <memory>

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
class Callback;

template <typename R, typename... Args>
class Callback<R(Args...)> {
 public:
  Callback() = default;
  template <typename F>
  explicit Callback(F&& f) {}
  Callback(const Callback&) = default;
  Callback(Callback&&) = default;
};

template <typename R, typename... Args>
Callback<R(Args...)> Bind(R (*function)(Args...)) {
  return Callback<R(Args...)>(function);
}

template <typename R, typename T, typename... Args>
Callback<R(Args...)> Bind(R (T::*method)(Args...), UnretainedWrapper<T> wrapper) {
  return Callback<R(Args...)>([=]() { (wrapper.get()->*method)(); });
}

}  // namespace base

class ScriptContext;
class ObjectBackedNativeHandler {
 public:
  explicit ObjectBackedNativeHandler(ScriptContext* context);
  void RouteFunction(const std::string& name, base::Callback<void()> callback);
  void RouteFunction(const std::string& name, const std::string& api_name,
                     base::Callback<void()> callback);
};

class RuntimeCustomBindings : public ObjectBackedNativeHandler {
 public:
  explicit RuntimeCustomBindings(ScriptContext* context);
  void GetManifest();
  void OpenChannelToExtension();
  void OpenChannelToNativeApp();
  void GetExtensionViews();
};