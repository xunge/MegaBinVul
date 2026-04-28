#include <stdint.h>
#include <stddef.h>
#include <algorithm>

#define kScaleQ15ToFloat (1.0f / 32768.0f)

typedef struct {
    size_t bufferLength;
    float* buffer;
} BtifAvrcpAudioTrack;

static size_t sampleSizeFor(BtifAvrcpAudioTrack* trackHolder);