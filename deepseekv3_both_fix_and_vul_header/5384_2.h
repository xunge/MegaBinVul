#include <memory>

class UtteranceEventDelegate;

namespace base {
template <typename T>
class WeakPtr {
public:
    WeakPtr() = default;
    WeakPtr(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
    operator T*() const { return ptr_; }
private:
    T* ptr_ = nullptr;
};
}

extern UtteranceEventDelegate* event_delegate_;