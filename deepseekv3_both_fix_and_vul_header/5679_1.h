#include <stdint.h>

struct oz_usb_hdr;

struct oz_data {
    int format;
};

struct oz_multiple_fixed {
    int unit_size;
    uint8_t endpoint;
    uint8_t data[];
};

struct oz_isoc_fixed {
    int unit_size;
    uint8_t endpoint;
    uint8_t data[];
};

struct oz_usb_ctx {
    void *hport;
};

#define OZ_DATA_F_MULTIPLE_FIXED 0
#define OZ_DATA_F_ISOC_FIXED 1

typedef uint8_t u8;

void oz_hcd_data_ind(void *hport, u8 endpoint, u8 *data, int unit_size);