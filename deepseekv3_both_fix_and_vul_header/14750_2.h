#include <stdint.h>
#include <sys/types.h>
#include <limits.h>
#include <assert.h>

typedef int32_t status_t;
typedef int64_t off64_t;

#define ERROR_MALFORMED 1
#define ERROR_IO 2
#define ERROR_OUT_OF_RANGE 3
#define OK 0

#define CHECK(expr) assert(expr)

struct SampleToChunkEntry {
    uint32_t startChunk;
    uint32_t samplesPerChunk;
    uint32_t chunkDesc;
};

class DataSource {
public:
    virtual ssize_t readAt(off64_t offset, void* data, size_t size) = 0;
};

class SampleTable {
public:
    status_t setSampleToChunkParams(off64_t data_offset, size_t data_size);
private:
    off64_t mSampleToChunkOffset;
    uint32_t mNumSampleToChunkOffsets;
    SampleToChunkEntry* mSampleToChunkEntries;
    DataSource* mDataSource;

    static uint32_t U32_AT(const uint8_t* ptr) {
        return ptr[0] << 24 | ptr[1] << 16 | ptr[2] << 8 | ptr[3];
    }
};