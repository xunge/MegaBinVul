#include <stdint.h>

typedef uint32_t XMP_Uns32;

static void PutLE24(uint8_t* data, uint32_t val) {
    data[0] = (val >> 0) & 0xFF;
    data[1] = (val >> 8) & 0xFF;
    data[2] = (val >> 16) & 0xFF;
}

struct VP8XChunk {
    uint8_t data[10];
    void width(XMP_Uns32 val);
};