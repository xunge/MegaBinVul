#include <stdint.h>
#include <sys/types.h>
#include <math.h>

typedef int32_t status_t;
#define NO_INIT (-ENODEV)
#define NO_ERROR 0
#define EINVAL 22
#define ENODEV 19
#define DESTROYED 0

#define EFFECT_CMD_GET_PARAM 0
#define EFFECT_CMD_SET_PARAM 1
#define EFFECT_CMD_SET_PARAM_DEFERRED 2

#define ALOGVV(...)

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex& mutex) {}
    };
};

class EffectHandle {
public:
    bool destroyed_l() { return false; }
    void commandExecuted(uint32_t, uint32_t, void*, uint32_t, void*) {}
};

template<typename T>
class Vector {
public:
    size_t size() { return 0; }
    T& operator[](size_t) { static T t; return t; }
};

struct effect_param_t {
    uint32_t psize;
    uint32_t vsize;
};

struct EffectInterface {
    status_t (*command)(void*, uint32_t, uint32_t, void*, uint32_t*, void*);
    bool operator==(const void* ptr) { return false; }
    EffectInterface* operator->() { return this; }
    EffectInterface& operator*() { return *this; }
};

namespace AudioFlinger {
class EffectModule {
public:
    Mutex mLock;
    int mState;
    EffectInterface* mEffectInterface;
    status_t mStatus;
    Vector<EffectHandle*> mHandles;
    
    status_t command(uint32_t cmdCode,
                    uint32_t cmdSize,
                    void* pCmdData,
                    uint32_t* replySize,
                    void* pReplyData);
};
}

static inline uint32_t roundUpDelta(uint32_t delta, uint32_t size) {
    return delta;
}

void android_errorWriteLog(uint32_t, const char*);