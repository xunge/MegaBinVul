#include <stdint.h>

typedef uint32_t XMP_Uns32;

static void PutLE24(uint8_t* data, XMP_Uns32 val) {
    data[0] = (uint8_t)(val & 0xFF);
    data[1] = (uint8_t)((val >> 8) & 0xFF);
    data[2] = (uint8_t)((val >> 16) & 0xFF);
}

struct VP8XChunk {
    uint8_t data[10];
    void height(XMP_Uns32 val);
};