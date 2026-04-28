#include <stdint.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>

typedef int32_t status_t;
#define OK 0
#define ERROR_OUT_OF_RANGE (-1)
#define ERROR_END_OF_STREAM (-2)
#define ERROR_IO (-3)
#define ERROR_MALFORMED (-4)
#define ERROR_BUFFER_TOO_SMALL (-5)

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class MediaBuffer {
public:
    void release() {}
    void set_range(size_t, size_t) {}
    size_t range_length() const { return 0; }
    size_t range_offset() const { return 0; }
    size_t size() const { return 0; }
    void* data() { return nullptr; }
    MediaBuffer* clone() { return nullptr; }
    class MetaData {
    public:
        void clear() {}
        void setInt64(int, int64_t) {}
        void setInt32(int, int32_t) {}
        bool findInt32(int, int32_t*) { return false; }
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
    status_t findSampleAtTime(int64_t, uint32_t, uint32_t, uint32_t*, uint32_t) { return OK; }
    status_t findSyncSampleNear(uint32_t, uint32_t*, uint32_t) { return OK; }
    status_t getMetaDataForSample(uint32_t, off64_t*, size_t*, uint32_t*, bool*, uint32_t*) { return OK; }
    status_t getMetaDataForSample(uint32_t, off64_t*, size_t*, uint32_t*) { return OK; }
};

class DataSource {
public:
    ssize_t readAt(off64_t, void*, size_t) { return 0; }
};

class MediaBufferGroup {
public:
    status_t acquire_buffer(MediaBuffer**) { return OK; }
};

class MetaData {
public:
    bool findInt32(int, int32_t*) { return false; }
};

class MPEG4Source {
private:
    Mutex mLock;
    bool mStarted;
    off64_t mFirstMoofOffset;
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
    MediaBufferGroup* mGroup;
    MetaData* mFormat;

public:
    status_t read(MediaBuffer**, const ReadOptions*);
    status_t fragmentedRead(MediaBuffer**, const ReadOptions*);
};

#define CHECK(expr) ((void)0)
#define CHECK_EQ(a, b) ((void)0)
#define ALOGV(...) ((void)0)
#define ALOGE(...) ((void)0)
#define ALOGI(...) ((void)0)

static size_t parseNALSize(const uint8_t* data) { return 0; }
static bool isInRange(size_t, size_t, size_t, size_t) { return true; }
static void android_errorWriteLog(uint32_t, const char*) {}

static const int kKeyTime = 0;
static const int kKeyDuration = 0;
static const int kKeyTargetTime = 0;
static const int kKeyIsSyncFrame = 0;
static const int kKeyIsDRM = 0;