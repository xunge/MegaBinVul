#include <stdio.h>
#include <stdlib.h>

typedef struct jas_stream_s jas_stream_t;

typedef struct jp2_pclr_s {
    int dummy;
} jp2_pclr_t;

typedef struct jp2_box_s {
    union {
        jp2_pclr_t pclr;
    } data;
} jp2_box_t;