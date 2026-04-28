#include <functional>
#include <memory>

namespace base {
class CancelableTaskTracker {
public:
    typedef int TaskId;
};

template<typename T>
class Unretained {
public:
    explicit Unretained(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
private:
    T* ptr_;
};

template <typename T>
class WeakPtr {
public:
    WeakPtr() : ptr_(nullptr) {}
    explicit WeakPtr(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
    T* GetWeakPtr() { return ptr_; }
private:
    T* ptr_;
};

template<typename T, typename Arg1, typename Arg2>
std::function<void()> Bind(T f, Arg1 arg1, Arg2 arg2) {
    return [=]() { 
        return std::mem_fn(f)(arg1, arg2); 
    };
}

template<typename T, typename Arg1, typename Arg2>
std::function<void()> Bind(T f, Unretained<Arg1> arg1, Arg2 arg2) {
    return [=]() { 
        return std::mem_fn(f)(arg1.get(), arg2); 
    };
}

template<typename T, typename Arg1, typename Arg2>
std::function<void()> Bind(T f, WeakPtr<Arg1> arg1, Arg2 arg2) {
    return [=]() { 
        return std::mem_fn(f)(arg1.get(), arg2); 
    };
}
}

class SessionService {
public:
    using SessionCallback = std::function<void()>;

    base::CancelableTaskTracker::TaskId GetLastSession(
        const SessionCallback& callback,
        base::CancelableTaskTracker* tracker);

    base::CancelableTaskTracker::TaskId ScheduleGetLastSessionCommands(
        std::function<void()> callback,
        base::CancelableTaskTracker* tracker);

    void OnGotSessionCommands(SessionCallback callback);

    base::WeakPtr<SessionService> weak_factory_;
};