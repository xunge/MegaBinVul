#include <stdint.h>
#include <limits.h>

#define MIN_INT16 SHRT_MIN
#define MAX_INT16 SHRT_MAX

struct adpcmState {
    int16_t previousValue;
    int index;
};

struct IMA {
    struct {
        int channelCount;
    } f;
    int m_framesPerPacket;
    IMA* m_track;
    int decodeBlockQT(const uint8_t *encoded, int16_t *decoded);
};

static inline int16_t clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

static int16_t decodeSample(struct adpcmState& state, uint8_t code) {
    static const int16_t stepTable[89] = { /* IMA ADPCM step table */ };
    static const int8_t indexTable[16] = { /* IMA ADPCM index table */ };

    int step = stepTable[state.index];
    int diff = step >> 3;
    
    if (code & 1) diff += step >> 2;
    if (code & 2) diff += step >> 1;
    if (code & 4) diff += step;
    if (code & 8) diff = -diff;
    
    state.previousValue = clamp(state.previousValue + diff, MIN_INT16, MAX_INT16);
    state.index = clamp(state.index + indexTable[code], 0, 88);
    
    return state.previousValue;
}