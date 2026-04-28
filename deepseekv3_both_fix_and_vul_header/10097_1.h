#include <stdint.h>
#include <assert.h>

struct ms_adpcm_state {
    int predictorIndex;
    int16_t delta;
    int16_t sample1;
    int16_t sample2;
};

struct MSADPCM {
    struct {
        struct {
            int channelCount;
        } f;
    } *m_track;
    int m_framesPerPacket;
    int m_numCoefficients;
    int16_t (*m_coefficients)[2];
    int16_t decodeSample(struct ms_adpcm_state &state, uint8_t code, const int16_t *coefficient, bool *ok = nullptr);
    int decodeBlock(const uint8_t *encoded, int16_t *decoded);
};