#include <assert.h>
#include <stdio.h>

typedef struct jas_stream_t jas_stream_t;
typedef struct jas_image_t jas_image_t;
typedef struct jas_matrix_t jas_matrix_t;

typedef struct {
    int width;
    int height;
    int depth;
} ras_hdr_t;

typedef struct {
    int dummy;
} ras_cmap_t;

#define RAS_ROWSIZE(hdr) (((hdr)->width * (hdr)->depth + 7) / 8)
#define RAS_ONES(n) ((1 << (n)) - 1)
#define RAS_GETRED(v) (((v) >> 16) & 0xff)
#define RAS_GETGREEN(v) (((v) >> 8) & 0xff)
#define RAS_GETBLUE(v) ((v) & 0xff)