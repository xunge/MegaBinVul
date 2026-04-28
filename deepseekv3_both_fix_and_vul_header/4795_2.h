#include <memory>

struct EventEntry;
struct Connection;
struct InputTarget;

template<typename T>
class sp {
public:
    T* operator->() const { return nullptr; }
};

enum {
    AMOTION_EVENT_ACTION_OUTSIDE,
    AMOTION_EVENT_ACTION_HOVER_EXIT,
    AMOTION_EVENT_ACTION_HOVER_ENTER,
    AMOTION_EVENT_ACTION_CANCEL,
    AMOTION_EVENT_ACTION_DOWN,
    AMOTION_EVENT_ACTION_HOVER_MOVE
};

enum {
    AMOTION_EVENT_FLAG_WINDOW_IS_OBSCURED,
    AMOTION_EVENT_FLAG_WINDOW_IS_PARTIALLY_OBSCURED
};

struct EventEntry {
    enum Type {
        TYPE_KEY,
        TYPE_MOTION
    };
    Type type;
};

struct KeyEntry : public EventEntry {
    int32_t action;
    int32_t flags;
};

struct MotionEntry : public EventEntry {
    int32_t action;
    int32_t flags;
    int32_t deviceId;
    int32_t source;
    int32_t displayId;
};

struct InputTarget {
    enum {
        FLAG_DISPATCH_MASK,
        FLAG_DISPATCH_AS_OUTSIDE,
        FLAG_DISPATCH_AS_HOVER_EXIT,
        FLAG_DISPATCH_AS_HOVER_ENTER,
        FLAG_DISPATCH_AS_SLIPPERY_EXIT,
        FLAG_DISPATCH_AS_SLIPPERY_ENTER,
        FLAG_WINDOW_IS_OBSCURED,
        FLAG_WINDOW_IS_PARTIALLY_OBSCURED
    };
    int32_t flags;
    float xOffset;
    float yOffset;
    float scaleFactor;
};

struct DispatchEntry {
    EventEntry* eventEntry;
    int32_t targetFlags;
    float xOffset;
    float yOffset;
    float scaleFactor;
    int32_t resolvedAction;
    int32_t resolvedFlags;

    DispatchEntry(EventEntry* event, int32_t flags, float x, float y, float scale)
        : eventEntry(event), targetFlags(flags), xOffset(x), yOffset(y), scaleFactor(scale) {}
    
    bool hasForegroundTarget() { return false; }
};

struct InputState {
    bool trackKey(KeyEntry* entry, int32_t action, int32_t flags) { return true; }
    bool trackMotion(MotionEntry* entry, int32_t action, int32_t flags) { return true; }
    bool isHovering(int32_t deviceId, int32_t source, int32_t displayId) { return true; }
};

template<typename T>
class Queue {
public:
    void enqueueAtTail(T* entry) {}
};

struct Connection {
    InputState inputState;
    Queue<DispatchEntry> outboundQueue;
    const char* getInputChannelName() { return ""; }
};

class InputDispatcher {
public:
    void enqueueDispatchEntryLocked(
        const sp<Connection>& connection, EventEntry* eventEntry, const InputTarget* inputTarget,
        int32_t dispatchMode);
    void incrementPendingForegroundDispatchesLocked(EventEntry* eventEntry);
    void traceOutboundQueueLengthLocked(const sp<Connection>& connection);
};