#include <memory>
#include <cassert>

class Platform {
public:
    static Platform* current();
    bool isThreadedAnimationEnabled();
    bool compositorSupport();
};

class ThreadState {
public:
    static ThreadState* current();
    void registerPreFinalizer(void*);
};

class CompositorAnimationPlayer {
public:
    static std::unique_ptr<CompositorAnimationPlayer> create();
    void setAnimationDelegate(void*);
};

class Animation {
public:
    void createCompositorPlayer();
protected:
    bool m_preFinalizerRegistered = false;
    std::unique_ptr<CompositorAnimationPlayer> m_compositorPlayer;

    void attachCompositorTimeline();
    void attachCompositedLayers();
};

#define ASSERT(x) assert(x)