#include <cstddef>
#include <mutex>
#include <vector>
#include <memory>

class Document;

class ActiveDOMObject {
public:
    explicit ActiveDOMObject(Document*);
};

class AudioBuffer {
public:
    static std::unique_ptr<AudioBuffer> create(unsigned, size_t, float);
};

class AudioNode;

class AudioContext;

class OfflineAudioDestinationNode {
public:
    static OfflineAudioDestinationNode* create(AudioContext*, AudioBuffer*);
};

template<typename T>
class Member {
};

template<typename T>
class HeapVector {
public:
    HeapVector();
};

enum AudioContextState { Suspended };

class AudioContext : public ActiveDOMObject {
public:
    AudioContext(Document*, unsigned, size_t, float);
    void initialize();

private:
    bool m_isStopScheduled;
    bool m_isCleared;
    bool m_isInitialized;
    std::unique_ptr<AudioBuffer> m_renderTarget;
    OfflineAudioDestinationNode* m_destinationNode;
    bool m_isResolvingResumePromises;
    bool m_automaticPullNodesNeedUpdating;
    unsigned m_connectionCount;
    bool m_didInitializeContextGraphMutex;
    size_t m_audioThread;
    bool m_isOfflineContext;
    AudioContextState m_contextState;
    HeapVector<Member<AudioNode>>* m_referencedNodes;
};