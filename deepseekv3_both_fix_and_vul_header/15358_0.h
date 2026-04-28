#include <stdint.h>
#include <stddef.h>
#include <algorithm>

struct BtifAvrcpAudioTrack {
    size_t bufferLength;
    float* buffer;
};

static const float kScaleQ31ToFloat = 1.0f / (1UL << 31);

static size_t sampleSizeFor(BtifAvrcpAudioTrack* trackHolder) {
    return sizeof(float);
}