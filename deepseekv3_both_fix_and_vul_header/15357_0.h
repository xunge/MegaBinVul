#include <stdint.h>
#include <stddef.h>
#include <algorithm>

struct BtifAvrcpAudioTrack {
    size_t bufferLength;
    float* buffer;
};

static const float kScaleQ23ToFloat = 1.0f / (1 << 23);

static size_t sampleSizeFor(BtifAvrcpAudioTrack* trackHolder);