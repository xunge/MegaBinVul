#include <stdbool.h>

struct Timer {
    bool isActive();
    void stop();
};

struct StateMachine {
    bool isDisplayingInitialEmptyDocument();
};

class FrameLoader {
public:
    void notifyIfInitialDocumentAccessed();
private:
    Timer m_didAccessInitialDocumentTimer;
    StateMachine m_stateMachine;
    void didAccessInitialDocumentTimerFired(int);
};