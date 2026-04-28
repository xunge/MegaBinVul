#include <stdbool.h>
#include <assert.h>

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr) {}
};

struct XMLHttpRequestProgressEvent {
    static XMLHttpRequestProgressEvent* create(const char*) { return nullptr; }
};

struct EventNames {
    const char* abortEvent;
};

EventNames eventNames() {
    static EventNames instance;
    return instance;
}

#define ASSERT assert

class XMLHttpRequest {
public:
    enum State { UNSENT, OPENED, DONE };
    
    void abort();
    bool internalAbort();
    void clearResponseBuffers();
    void changeState(State);
    
    struct {
        void clear() {}
    } m_requestHeaders;
    
    struct {
        void dispatchEventAndLoadEnd(XMLHttpRequestProgressEvent*) {}
    } m_progressEventThrottle;
    
    struct {
        void dispatchEventAndLoadEnd(XMLHttpRequestProgressEvent*) {}
    } *m_upload;
    
    State m_state;
    bool m_uploadComplete;
    bool m_uploadEventsAllowed;
    void* m_loader;
};