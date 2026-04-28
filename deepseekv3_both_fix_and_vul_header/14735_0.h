#include <stdlib.h>
#include <stdint.h>

typedef struct SANMVideoContext {
    uint8_t *frm0;
    uint8_t *frm1;
    uint8_t *frm2;
    uint8_t *stored_frame;
    uint8_t *rle_buf;
    int frm0_size;
    int frm1_size;
    int frm2_size;
} SANMVideoContext;

#define av_freep(p) do { free(*p); *p = NULL; } while (0)