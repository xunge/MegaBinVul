#include <memory>
#include <functional>

enum PlaybackState {
    FINISHED_STATE
};

class AudioContext {
public:
    void notifyNodeFinishedProcessing(void*);
    void decrementActiveSourceCount();
};

class NotifyEndedTask {
public:
    NotifyEndedTask(void*);
};

template<typename T>
class OwnPtr {
public:
    explicit OwnPtr(T* ptr) : m_ptr(ptr) {}
    ~OwnPtr() { delete m_ptr; }
    T* leakPtr() { T* ptr = m_ptr; m_ptr = nullptr; return ptr; }
    T* get() { return m_ptr; }
private:
    T* m_ptr;
};

template<typename T>
OwnPtr<T> adoptPtr(T* ptr) { return OwnPtr<T>(ptr); }

class AudioScheduledSourceNode {
public:
    void finish();
    static void notifyEndedDispatch(void*);
    AudioContext* context();
    PlaybackState m_playbackState;
    bool m_hasEndedListener;
};

void callOnMainThread(void (*)(void*), void*);