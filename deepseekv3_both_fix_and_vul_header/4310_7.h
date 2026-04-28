#include <functional>
#include <memory>

class ExtensionFrameHelper {
public:
    static ExtensionFrameHelper* Get(void* render_frame);
    void ScheduleAtDocumentStart(std::function<void()> callback);
};

class UserScript {
public:
    enum RunLocation {
        DOCUMENT_START
    };
};

namespace base {
template <typename T>
class WeakPtr {
public:
    T* get() const;
    T* operator->() const;
    explicit operator bool() const;
};

template <typename T>
class WeakPtrFactory {
public:
    explicit WeakPtrFactory(T* ptr);
    WeakPtr<T> GetWeakPtr();
    ~WeakPtrFactory();
};

template <typename Signature>
class Callback;

template <typename R, typename... Args>
class Callback<R(Args...)> {
public:
    template <typename Functor>
    Callback(Functor&& f);
    void Run(Args... args);
    operator std::function<void()>() const;
};

template <typename R, typename... Args>
Callback<R(Args...)> Bind(R (*function)(Args...), Args... args);

template <typename R, typename T, typename... Args>
Callback<R(Args...)> Bind(R (T::*method)(Args...), base::WeakPtr<T> obj, Args... args);
}  // namespace base

class ScriptInjectionManager {
public:
    void StartInjectScripts(void* render_frame, UserScript::RunLocation location);

    class RFOHelper {
    public:
        RFOHelper();
        void DidCreateDocumentElement();
        void StartInjectScripts(UserScript::RunLocation location);
        void* render_frame();
        ScriptInjectionManager* manager_;
        base::WeakPtrFactory<RFOHelper> weak_factory_{this};
    };
};