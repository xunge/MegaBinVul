#include <cstddef>

class ExecutionContext;

class ActiveScriptWrappable {
public:
    explicit ActiveScriptWrappable(void*) {}
};

class ActiveDOMObject {
public:
    explicit ActiveDOMObject(ExecutionContext*) {}
};

enum AnimationPlayState { Idle };

struct nullValue {
    operator double() const { return 0; }
};

static int nextSequenceNumber() { return 0; }

class Animation;

class AnimationEffect {
public:
    Animation* animation() { return nullptr; }
    void attach(Animation*);
};

class AnimationTimeline {
public:
    class Document* document();
};

class InspectorInstrumentation {
public:
    static void didCreateAnimation(class Document*, int);
};

class Animation : public ActiveScriptWrappable, public ActiveDOMObject {
public:
    Animation(ExecutionContext*, AnimationTimeline&, AnimationEffect*);
    void cancel();
    void setEffect(int);
    
private:
    AnimationPlayState m_playState;
    double m_playbackRate;
    double m_startTime;
    double m_holdTime;
    int m_sequenceNumber;
    AnimationEffect* m_content;
    AnimationTimeline* m_timeline;
    bool m_paused;
    bool m_held;
    bool m_isPausedForTesting;
    bool m_isCompositedAnimationDisabledForTesting;
    bool m_outdated;
    bool m_finished;
    void* m_compositorState;
    bool m_compositorPending;
    int m_compositorGroup;
    bool m_preFinalizerRegistered;
    bool m_currentTimePending;
    bool m_stateIsBeingUpdated;
    bool m_effectSuppressed;
};