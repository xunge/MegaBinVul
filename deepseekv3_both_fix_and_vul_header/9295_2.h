#include <stdint.h>
#include <string>

typedef int32_t status_t;
#define OK 0

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex& mutex) {}
    };
};

template<typename T>
class sp {
public:
    sp() {}
    sp(T* ptr) {}
    void clear() {}
    T* get() const { return nullptr; }
};

class DataSource {};
class NuCachedSource2 {};
class DrmManagerClient {};

namespace NuPlayer {
    class GenericSource {
    protected:
        int64_t mMetaDataSize;
        std::string mContentType;
        std::string mSniffedMIME;
        sp<DataSource> mDataSource;
        sp<NuCachedSource2> mCachedSource;
        sp<DataSource> mHttpSource;
        Mutex mDisconnectLock;
        DrmManagerClient* mDrmManagerClient;

        void cancelPollBuffering();
        void notifyPrepared(status_t err);
        void notifyPreparedAndCleanup(status_t err);
    };
}