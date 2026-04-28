#include <stddef.h>

typedef int SIXELSTATUS;

struct sixel_frame_t {
    int width;
    int height;
    int pixelformat;
    unsigned char *pixels;
    struct sixel_allocator_t *allocator;
};

struct sixel_allocator_t;

#define SIXELAPI
#define SIXEL_FALSE 0
#define SIXEL_BAD_INPUT (-1)
#define SIXEL_OK 0
#define SIXEL_FAILED(x) ((x) != SIXEL_OK)
#define SIXEL_WIDTH_LIMIT 16383
#define SIXEL_HEIGHT_LIMIT 16383

enum {
    SIXEL_PIXELFORMAT_PAL1,
    SIXEL_PIXELFORMAT_PAL2,
    SIXEL_PIXELFORMAT_PAL4,
    SIXEL_PIXELFORMAT_G1,
    SIXEL_PIXELFORMAT_G2,
    SIXEL_PIXELFORMAT_G4
};

void sixel_frame_ref(struct sixel_frame_t *frame);
void sixel_frame_unref(struct sixel_frame_t *frame);
void sixel_helper_set_additional_message(const char *message);
void *sixel_allocator_malloc(struct sixel_allocator_t *allocator, size_t size);
void sixel_allocator_free(struct sixel_allocator_t *allocator, void *ptr);
SIXELSTATUS sixel_helper_normalize_pixelformat(unsigned char *dst, int *dst_format,
                                             const unsigned char *src, int src_format,
                                             int width, int height);
SIXELSTATUS clip(unsigned char *pixels, int width, int height, int pixelformat,
                int x, int y, int clip_width, int clip_height);

typedef struct sixel_frame_t sixel_frame_t;