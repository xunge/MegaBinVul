#include <algorithm>
#include <cassert>

#define RELEASE_ASSERT(x) assert(x)
#define ASSERT(x) assert(x)
#define ENABLE(x) 0

enum FrameSchedulingState {
    Idle,
    SynchronizeAnimations
};

class SMILTime {
public:
    SMILTime(double t = 0) : m_time(t) {}
    bool isFinite() const { return true; }
    double value() const { return m_time; }
    SMILTime operator-(double t) const { return SMILTime(m_time - t); }
private:
    double m_time;
};

class DiscardScope {
public:
    DiscardScope(void*) {}
};

class SMILTimeContainer {
public:
    void begin();
    double currentTime() { return 0; }
    SMILTime updateAnimations(SMILTime, bool) { return SMILTime(); }
    double elapsed() { return 0; }
    bool hasPendingSynchronization() { return false; }
    bool isTimelineRunning() { return true; }
    void scheduleWakeUp(double, FrameSchedulingState) {}

private:
    double m_beginTime = 0;
    double m_presetStartTime = 0;
    double m_pauseTime = 0;
    FrameSchedulingState m_frameSchedulingState = Idle;
    void* m_ownerSVGElement = nullptr;
    static constexpr double initialFrameDelay = 0;
};