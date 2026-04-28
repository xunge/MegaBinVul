#include <cstdio>
#include <vector>
#include <memory>

class Document;

class ActiveDOMObject {
public:
    ActiveDOMObject(Document*);
};

class AudioContext;

class AudioNode;

class DefaultAudioDestinationNode {
public:
    static DefaultAudioDestinationNode* create(AudioContext*);
};

template<typename T>
class Member {
public:
    Member();
    Member(T*);
};

template<typename T>
class HeapVector {
public:
    HeapVector();
    ~HeapVector();
};

enum AudioContextState { Suspended };

class AudioContext : public ActiveDOMObject {
public:
    AudioContext(Document*);
    void initialize();

    bool m_isStopScheduled;
    bool m_isCleared;
    bool m_isInitialized;
    DefaultAudioDestinationNode* m_destinationNode;
    bool m_isResolvingResumePromises;
    bool m_automaticPullNodesNeedUpdating;
    unsigned m_connectionCount;
    bool m_didInitializeContextGraphMutex;
    unsigned m_audioThread;
    bool m_isOfflineContext;
    AudioContextState m_contextState;
    HeapVector<Member<AudioNode>>* m_referencedNodes;

    static unsigned s_hardwareContextCount;
};

unsigned AudioContext::s_hardwareContextCount = 0;
#define DEBUG_AUDIONODE_REFERENCES 0