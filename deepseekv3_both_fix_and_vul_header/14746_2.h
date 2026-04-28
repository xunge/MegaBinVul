#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <limits.h>

typedef int32_t status_t;
typedef int64_t off64_t;
typedef int64_t ssize_t;

enum {
    ERROR_MALFORMED = -1,
    ERROR_IO = -2,
    ERROR_OUT_OF_RANGE = -3,
    OK = 0
};

#define U32_AT(p) (ntohl(*(const uint32_t *)(p)))
#define ALOGV(...) ((void)0)

class DataSource {
public:
    virtual ssize_t readAt(off64_t offset, void *data, size_t size) = 0;
};

class SampleTable {
public:
    status_t setSyncSampleParams(off64_t data_offset, size_t data_size);
private:
    off64_t mSyncSampleOffset;
    uint32_t mNumSyncSamples;
    uint32_t* mSyncSamples;
    DataSource* mDataSource;
};