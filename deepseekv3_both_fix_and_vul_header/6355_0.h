#include <stddef.h>

typedef int SIXELSTATUS;
typedef struct sixel_dither_t sixel_dither_t;
typedef struct sixel_allocator_t sixel_allocator_t;

#define SIXELAPI
#define SIXEL_FALSE 0
#define SIXEL_OK 1
#define SIXEL_BAD_ARGUMENT (-1)
#define SIXEL_BAD_ALLOCATION (-2)
#define SIXEL_BAD_INPUT (-3)
#define SIXEL_FAILED(x) ((x) < 0)
#define SIXEL_PALETTE_MAX 256
#define SIXEL_QUALITY_HIGHCOLOR 1
#define SIXEL_QUALITY_LOW 0
#define SIXEL_LARGE_NORM 0
#define SIXEL_REP_CENTER_BOX 0
#define SIXEL_DIFFUSE_FS 0
#define SIXEL_PIXELFORMAT_RGB888 0

struct sixel_dither_t {
    int ref;
    unsigned char *palette;
    void *cachetable;
    int reqcolors;
    int ncolors;
    int origcolors;
    int keycolor;
    int optimized;
    int optimize_palette;
    int complexion;
    int bodyonly;
    int method_for_largest;
    int method_for_rep;
    int method_for_diffuse;
    int quality_mode;
    int pixelformat;
    sixel_allocator_t *allocator;
};

void sixel_helper_set_additional_message(const char *message);
SIXELSTATUS sixel_allocator_new(sixel_allocator_t **allocator, void *data, void *(*malloc)(void *, size_t), void *(*realloc)(void *, void *, size_t), void (*free)(void *, void *));
void sixel_allocator_ref(sixel_allocator_t *allocator);
void sixel_allocator_unref(sixel_allocator_t *allocator);
void *sixel_allocator_malloc(sixel_allocator_t *allocator, size_t size);