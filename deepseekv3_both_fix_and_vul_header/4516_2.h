#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <assert.h>

#define ALOGE(...) 
#define android_errorWriteLog(...)

class IBinder;
template <typename T> class wp;

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex& mutex) {}
    };
};

class OMXNodeInstance {
public:
    uint32_t nodeID();
    void onObserverDied(void* master);
};

class OMX {
public:
    void binderDied(const wp<IBinder>& the_late_who);
private:
    Mutex mLock;
    void* mMaster;
    template <typename T> class KeyedVector {
    public:
        ssize_t indexOfKey(const T& key) const;
        OMXNodeInstance* editValueAt(size_t index);
        void removeItemsAt(size_t index);
    };
    KeyedVector<wp<IBinder>> mLiveNodes;
    KeyedVector<uint32_t> mDispatchers;

    void invalidateNodeID_l(uint32_t nodeID);
};

#define CHECK(expr) assert(expr)