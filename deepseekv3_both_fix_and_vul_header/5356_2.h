#include <mutex>

class Visitor {
public:
    void trace(void*);
};

class AutoLocker {
public:
    AutoLocker(void*);
};

class EventTargetWithInlineData {
public:
    static void trace(Visitor*);
};

class AudioContext {
public:
    void trace(Visitor* visitor);
    
private:
    bool m_didInitializeContextGraphMutex;
    void* m_renderTarget;
    void* m_destinationNode;
    void* m_listener;
    void* m_referencedNodes;
    void* m_liveNodes;
    void* m_liveAudioSummingJunctions;
};