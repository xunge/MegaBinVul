#include <string>
#include <functional>
#include <memory>

namespace base {
template <typename T>
class Unretained {
public:
    explicit Unretained(T* obj) : obj_(obj) {}
    T* get() const { return obj_; }
private:
    T* obj_;
};

template <typename Method, typename Receiver>
std::function<void()> Bind(Method method, Unretained<Receiver> receiver) {
    return [method, receiver]() { (receiver.get()->*method)(); };
}
}  // namespace base

class ScriptContext;
class ObjectBackedNativeHandler {
public:
    explicit ObjectBackedNativeHandler(ScriptContext* context);
};

class LazyBackgroundPageNativeHandler : public ObjectBackedNativeHandler {
public:
    explicit LazyBackgroundPageNativeHandler(ScriptContext* context);
    void IncrementKeepaliveCount();
    void DecrementKeepaliveCount();
    void RouteFunction(const std::string& name, const std::function<void()>& func);
    void RouteFunction(const std::string& name, const std::string& feature, const std::function<void()>& func);
};