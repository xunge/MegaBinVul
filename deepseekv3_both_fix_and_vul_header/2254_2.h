#include <stdint.h>
#include <cstddef>

typedef int32_t status_t;
#define OK 0
#define ERROR_END_OF_STREAM (-1)

class MediaBuffer {
public:
    void release();
    class MetaData {
    public:
        bool findInt32(int32_t key, int32_t* value);
        void setInt32(int32_t key, int32_t value);
        void setInt64(int32_t key, int64_t value);
    };
    MetaData* meta_data();
};

struct PageInfo {
    uint32_t mPageNo;
    uint64_t mGranulePosition;
};

class MyOpusExtractor {
public:
    status_t readNextPacket(MediaBuffer **out);
private:
    uint64_t mOffset;
    uint64_t mFirstDataOffset;
    int64_t mStartGranulePosition;
    PageInfo mCurrentPage;
    int64_t mCurGranulePosition;

    status_t _readNextPacket(MediaBuffer** out, bool calcVorbisTimestamp);
    uint32_t getNumSamplesInPacket(MediaBuffer* buffer);
    int64_t getTimeUsOfGranule(int64_t granulePosition);
    void seekToOffset(uint64_t offset);
};

static const int32_t kKeyValidSamples = 0;
static const int32_t kKeyTime = 1;