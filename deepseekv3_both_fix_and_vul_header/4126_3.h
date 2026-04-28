#include <memory>
#include <functional>

class ScriptContext;

class ObjectBackedNativeHandler {
public:
    explicit ObjectBackedNativeHandler(ScriptContext* context) {}
};

namespace base {
template <typename T>
class UnretainedT {
public:
    explicit UnretainedT(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
private:
    T* ptr_;
};

template <typename T>
class WeakPtr {};

template <typename T>
class WeakPtrFactory {
public:
    explicit WeakPtrFactory(T* ptr) : ptr_(ptr) {}
    WeakPtr<T> GetWeakPtr() { return WeakPtr<T>(); }
private:
    T* ptr_;
};

template <typename Functor, typename... Args>
std::function<void()> Bind(Functor&& functor, Args&&... args) {
    return std::function<void()>();
}

template <typename T>
UnretainedT<T> Unretained(T* ptr) {
    return UnretainedT<T>(ptr);
}
}

class RenderFrameObserverNatives : public ObjectBackedNativeHandler {
public:
    explicit RenderFrameObserverNatives(ScriptContext* context);
    void OnDocumentElementCreated();
    void RouteFunction(const char* name, std::function<void()> callback);
private:
    base::WeakPtrFactory<RenderFrameObserverNatives> weak_ptr_factory_{this};
};