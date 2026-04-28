#include <stdlib.h>

typedef struct jp2_box_s jp2_box_t;
typedef struct jas_stream_s jas_stream_t;

typedef struct {
    unsigned short cmptno;
    unsigned char map;
    unsigned char pcol;
} jp2_cmapent_t;

typedef struct {
    unsigned int numchans;
    jp2_cmapent_t *ents;
} jp2_cmap_t;

struct jp2_box_s {
    union {
        jp2_cmap_t cmap;
    } data;
    size_t datalen;
};

void *jas_alloc2(size_t num, size_t size);
int jp2_getuint16(jas_stream_t *in, unsigned short *val);
int jp2_getuint8(jas_stream_t *in, unsigned char *val);