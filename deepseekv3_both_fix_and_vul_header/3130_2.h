#include <memory>

template<typename T> struct OwnPtr {
    T* ptr;
    ~OwnPtr() { delete ptr; }
    T* operator->() { return ptr; }
};

template<typename T> OwnPtr<T> adoptPtr(T* p) { return OwnPtr<T>{p}; }

struct NotifyEndedTask {
    void notifyEnded();
};

class AudioScheduledSourceNode {
public:
    void notifyEnded();
    static void notifyEndedDispatch(void* userData);
};