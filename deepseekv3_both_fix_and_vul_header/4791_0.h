#include <cstddef>

struct SampleTable {
    ~SampleTable();
    int* mSampleToChunkEntries;
    int* mSyncSamples;
    int* mCompositionDeltaLookup;
    int* mCompositionTimeDeltaEntries;
    int* mSampleTimeEntries;
    int* mTimeToSample;
    int* mSampleIterator;
};