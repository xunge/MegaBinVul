#include <stdint.h>
#include <stdlib.h>

template<typename T>
class sp {
public:
    sp(T* ptr) {}
};

class DataSource {};

class SampleTable;

class SampleIterator {
public:
    SampleIterator(SampleTable* table) {}
};

class CompositionDeltaLookup {
public:
    CompositionDeltaLookup() {}
};

struct SampleTableEntry {
    uint32_t count;
    uint32_t size;
};

struct TimeToSampleEntry {
    uint32_t count;
    uint32_t duration;
};

struct SampleToChunkEntry {
    uint32_t firstChunk;
    uint32_t samplesPerChunk;
    uint32_t chunkDescriptionIndex;
};

class SampleTable {
public:
    SampleTable(const sp<DataSource> &source);
    
private:
    sp<DataSource> mDataSource;
    int64_t mChunkOffsetOffset;
    uint32_t mChunkOffsetType;
    uint32_t mNumChunkOffsets;
    int64_t mSampleToChunkOffset;
    uint32_t mNumSampleToChunkOffsets;
    int64_t mSampleSizeOffset;
    uint32_t mSampleSizeFieldSize;
    uint32_t mDefaultSampleSize;
    uint32_t mNumSampleSizes;
    uint32_t mTimeToSampleCount;
    TimeToSampleEntry *mTimeToSample;
    SampleTableEntry *mSampleTimeEntries;
    int32_t *mCompositionTimeDeltaEntries;
    uint32_t mNumCompositionTimeDeltaEntries;
    CompositionDeltaLookup *mCompositionDeltaLookup;
    int64_t mSyncSampleOffset;
    uint32_t mNumSyncSamples;
    uint32_t *mSyncSamples;
    uint32_t mLastSyncSampleIndex;
    SampleToChunkEntry *mSampleToChunkEntries;
    SampleIterator *mSampleIterator;
};