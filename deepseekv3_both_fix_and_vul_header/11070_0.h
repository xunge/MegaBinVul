#include <stddef.h>

typedef int SIXELSTATUS;
typedef struct sixel_frame_t sixel_frame_t;
typedef struct sixel_allocator_t sixel_allocator_t;

#define SIXELAPI
#define SIXEL_FALSE 0
#define SIXEL_BAD_INPUT 1
#define SIXEL_BAD_ALLOCATION 2
#define SIXEL_OK 3
#define SIXEL_FAILED(x) ((x) != SIXEL_OK)
#define SIXEL_WIDTH_LIMIT 10000
#define SIXEL_HEIGHT_LIMIT 10000

void sixel_frame_ref(sixel_frame_t *frame);
void sixel_frame_unref(sixel_frame_t *frame);
void sixel_helper_set_additional_message(const char *message);
SIXELSTATUS sixel_frame_convert_to_rgb888(sixel_frame_t *frame);
void *sixel_allocator_malloc(sixel_allocator_t *allocator, size_t size);
void sixel_allocator_free(sixel_allocator_t *allocator, void *ptr);
SIXELSTATUS sixel_helper_scale_image(
    unsigned char *dst,
    unsigned char *src,
    int src_width,
    int src_height,
    int pixelformat,
    int dst_width,
    int dst_height,
    int method_for_resampling,
    sixel_allocator_t *allocator);

struct sixel_frame_t {
    unsigned char *pixels;
    int width;
    int height;
    sixel_allocator_t *allocator;
};