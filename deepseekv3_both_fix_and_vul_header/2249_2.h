#include <cstdint>
#include <cstddef>
#include <arpa/inet.h>
#include <climits>
#include <new>

#define ERROR_MALFORMED 1
#define ERROR_IO 2
#define ERROR_OUT_OF_RANGE 3
#define OK 0

#define U32_AT(p) (*reinterpret_cast<const uint32_t*>(p))
#define ALOGV(...)
#define ALOGE(...)

const size_t kMaxTotalSize = SIZE_MAX;

typedef int status_t;
typedef int64_t off64_t;

class DataSource {
public:
    virtual ssize_t readAt(off64_t offset, void* data, size_t size) = 0;
};

class SampleTable {
public:
    status_t setSyncSampleParams(off64_t data_offset, size_t data_size);

private:
    DataSource* mDataSource;
    off64_t mSyncSampleOffset;
    uint32_t* mSyncSamples;
    uint32_t mNumSyncSamples;
    uint64_t mTotalSize;
};