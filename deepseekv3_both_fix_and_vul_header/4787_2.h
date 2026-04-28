#include <cstddef>
#include <stdint.h>

template<typename T>
class sp {
public:
    T* m_ptr;
    sp(T* source) : m_ptr(source) {}
};

class DataSource {};
class SampleTable;

class SampleIterator {
public:
    SampleIterator(SampleTable* table) {}
};

class CompositionDeltaLookup {};

class SampleTable {
private:
    sp<DataSource> mDataSource;
    int64_t mChunkOffsetOffset;
    int32_t mChunkOffsetType;
    uint32_t mNumChunkOffsets;
    int64_t mSampleToChunkOffset;
    uint32_t mNumSampleToChunkOffsets;
    int64_t mSampleSizeOffset;
    uint32_t mSampleSizeFieldSize;
    uint32_t mDefaultSampleSize;
    uint32_t mNumSampleSizes;
    bool mHasTimeToSample;
    uint32_t mTimeToSampleCount;
    uint32_t* mTimeToSample;
    uint32_t* mSampleTimeEntries;
    int32_t* mCompositionTimeDeltaEntries;
    uint32_t mNumCompositionTimeDeltaEntries;
    CompositionDeltaLookup* mCompositionDeltaLookup;
    int64_t mSyncSampleOffset;
    uint32_t mNumSyncSamples;
    uint32_t* mSyncSamples;
    uint32_t mLastSyncSampleIndex;
    uint32_t* mSampleToChunkEntries;
    SampleIterator* mSampleIterator;

public:
    SampleTable(const sp<DataSource> &source);
};