#include <memory>
#include <functional>
#include <utility>

class ScriptContext;

class ObjectBackedNativeHandler {
public:
    explicit ObjectBackedNativeHandler(ScriptContext* context) {}
};

template<typename T>
class WeakPtrFactory {
public:
    explicit WeakPtrFactory(T* ptr) {}
};

template<typename T>
T* Unretained(T* ptr) {
    return ptr;
}

template<typename R, typename... Args>
class Callback {
public:
    template<typename F, typename... BoundArgs>
    static Callback Bind(F&& f, BoundArgs&&... args) {
        return Callback();
    }
};

namespace base {
    template<typename F, typename... Args>
    auto Bind(F&& f, Args&&... args) {
        return Callback<void()>::Bind(std::forward<F>(f), std::forward<Args>(args)...);
    }

    template<typename T>
    T* Unretained(T* ptr) {
        return ::Unretained(ptr);
    }
}

class RenderFrameObserverNatives : public ObjectBackedNativeHandler {
public:
    explicit RenderFrameObserverNatives(ScriptContext* context);
    void OnDocumentElementCreated();
    void RouteFunction(const char* name, const Callback<void()>& callback);
    void RouteFunction(const char* name1, const char* name2, const Callback<void()>& callback);
private:
    WeakPtrFactory<RenderFrameObserverNatives> weak_ptr_factory_;
};