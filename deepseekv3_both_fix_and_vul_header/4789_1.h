#include <stdbool.h>
#include <vector>

class SampleTable {
private:
    int mChunkOffsetOffset;
    int mSampleToChunkOffset;
    int mSampleSizeOffset;
    bool mHasTimeToSample;
    std::vector<int> mTimeToSample;

public:
    bool isValid() const;
};