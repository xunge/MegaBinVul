#include <stdint.h>

struct iw_exif_state {
    uint8_t *d;
    int endian;
};

static unsigned int iw_get_ui16_e(uint8_t *p, int endian);
static unsigned int iw_get_ui32_e(uint8_t *p, int endian);