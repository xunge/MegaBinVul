#include <cstddef>
#include <cstring>
#include <stdint.h>
#include <sys/types.h>

typedef int32_t status_t;
#define OK 0
#define ERROR_OUT_OF_RANGE (-1)
#define ERROR_END_OF_STREAM (-2)
#define ERROR_IO (-3)
#define ERROR_MALFORMED (-4)

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex& mutex) {}
    };
};

class MediaBuffer {
public:
    void release() {}
    void set_range(size_t, size_t) {}
    void* data() { return nullptr; }
    size_t range_length() { return 0; }
    size_t range_offset() { return 0; }
    size_t size() { return 0; }
    MediaBuffer* clone() { return nullptr; }
    class MetaData {
    public:
        void clear() {}
        void setInt64(int, int64_t) {}
        void setInt32(int, int32_t) {}
    };
    MetaData* meta_data() { return nullptr; }
};

class ReadOptions {
public:
    enum SeekMode {
        SEEK_PREVIOUS_SYNC,
        SEEK_NEXT_SYNC,
        SEEK_CLOSEST_SYNC,
        SEEK_CLOSEST
    };
    bool getSeekTo(int64_t*, SeekMode*) const { return false; }
};

class SampleTable {
public:
    enum {
        kFlagBefore,
        kFlagAfter,
        kFlagClosest
    };
    status_t findSampleAtTime(int64_t, int64_t, uint32_t, uint32_t*, uint32_t) { return OK; }
    status_t findSyncSampleNear(uint32_t, uint32_t*, uint32_t) { return OK; }
    status_t getMetaDataForSample(uint32_t, off64_t*, size_t*, uint32_t*, bool*, uint32_t*) { return OK; }
    status_t getMetaDataForSample(uint32_t, off64_t*, size_t*, uint32_t*) { return OK; }
};

class DataSource {
public:
    ssize_t readAt(off64_t, void*, size_t) { return 0; }
};

#define CHECK(expr) 
#define CHECK_EQ(a, b) 
#define ALOGE(...) 
#define ALOGV(...) 
#define ALOGI(...) 

static const int kKeyTime = 0;
static const int kKeyDuration = 1;
static const int kKeyTargetTime = 2;
static const int kKeyIsSyncFrame = 3;
static const int kKeyIsDRM = 4;

class MPEG4Source {
public:
    status_t read(MediaBuffer **out, const ReadOptions *options);
private:
    Mutex mLock;
    bool mStarted;
    int64_t mFirstMoofOffset;
    SampleTable* mSampleTable;
    uint32_t mTimescale;
    uint32_t mCurrentSampleIndex;
    MediaBuffer* mBuffer;
    bool mIsAVC;
    bool mIsHEVC;
    bool mWantsNALFragments;
    size_t mNALLengthSize;
    uint8_t* mSrcBuffer;
    DataSource* mDataSource;
    class MediaBufferGroup {
    public:
        status_t acquire_buffer(MediaBuffer**) { return OK; }
    };
    MediaBufferGroup* mGroup;
    class MetaData {
    public:
        bool findInt32(int, int32_t*) { return false; }
    };
    MetaData* mFormat;

    status_t fragmentedRead(MediaBuffer**, const ReadOptions*) { return OK; }
    size_t parseNALSize(const uint8_t*) { return 0; }
    bool isInRange(size_t, size_t, size_t, size_t) { return true; }
};