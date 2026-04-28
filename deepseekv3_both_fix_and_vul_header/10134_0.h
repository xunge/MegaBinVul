#include <assert.h>
#include <stdio.h>

typedef struct jas_stream_t jas_stream_t;
typedef struct jas_image_t jas_image_t;
typedef struct jas_matrix_t jas_matrix_t;

typedef struct {
    int width;
    int height;
    int depth;
    int length;
} ras_hdr_t;

#define RAS_ROWSIZE(hdr) (((hdr)->width * (hdr)->depth + 7) / 8)
#define RAS_ISRGB(hdr) ((hdr)->depth == 24)
#define RAS_RED(v) ((v) & 0xff)
#define RAS_GREEN(v) (((v) & 0xff) << 8)
#define RAS_BLUE(v) (((v) & 0xff) << 16)
#define RAS_ONES(n) ((1 << (n)) - 1)