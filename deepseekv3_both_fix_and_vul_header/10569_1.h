#include <stdint.h>
#include <stddef.h>

struct iw_exif_state {
    uint8_t *d;
    size_t d_len;
    int endian;
};

static unsigned int iw_get_ui16_e(const uint8_t *d, int endian) {
    return endian ? (d[0] << 8) | d[1] : (d[1] << 8) | d[0];
}

static unsigned int iw_get_ui32_e(const uint8_t *d, int endian) {
    return endian ? (d[0] << 24) | (d[1] << 16) | (d[2] << 8) | d[3] 
                 : (d[3] << 24) | (d[2] << 16) | (d[1] << 8) | d[0];
}