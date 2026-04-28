#include <memory>

enum ExceptionCode { TimeoutError };
enum State { DONE };

class XMLHttpRequest;
class EventNames {
public:
    const char* timeoutEvent;
};

class XMLHttpRequest {
public:
    void handleDidTimeout();
    bool internalAbort();
    void handleDidFailGeneric();
    void changeState(State state);
    void dispatchEventAndLoadEnd(const char* event);
    State m_state;
    bool m_async;
    ExceptionCode m_exceptionCode;
    static EventNames eventNames();
};

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr);
};