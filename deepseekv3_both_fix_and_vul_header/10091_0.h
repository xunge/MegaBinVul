#include <stdint.h>

struct ADPCMState {
    int16_t previousValue;
    uint8_t index;
};

struct Track {
    struct {
        int channelCount;
    } f;
};

class IMA {
public:
    Track* m_track;
    ADPCMState* m_adpcmState;
    int m_framesPerPacket;

    int16_t decodeSample(ADPCMState& state, uint8_t nibble);
    int decodeBlockWAVE(const uint8_t* encoded, int16_t* decoded);
};

inline int clamp(int value, int min, int max) {
    return (value < min) ? min : (value > max) ? max : value;
}