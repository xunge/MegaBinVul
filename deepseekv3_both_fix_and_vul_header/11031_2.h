#include <stdlib.h>

typedef int SIXELSTATUS;

struct sixel_allocator_t {
    int dummy;
};

struct parser_context_t {
    int bgindex;
};

struct image_buffer_t {
    unsigned char *data;
    unsigned int *palette;
    int width;
    int height;
    int ncolors;
};

typedef struct sixel_allocator_t sixel_allocator_t;
typedef struct parser_context_t parser_context_t;
typedef struct image_buffer_t image_buffer_t;

#define SIXELAPI
#define SIXEL_FALSE 0
#define SIXEL_OK 1
#define SIXEL_FAILED(x) ((x) != SIXEL_OK)
#define SIXEL_BAD_ALLOCATION (-1)
#define SIXEL_PALETTE_MAX 256

SIXELSTATUS sixel_allocator_new(sixel_allocator_t **allocator, void *, void *, void *, void *);
void sixel_allocator_ref(sixel_allocator_t *allocator);
void sixel_allocator_unref(sixel_allocator_t *allocator);
void *sixel_allocator_malloc(sixel_allocator_t *allocator, size_t size);
void sixel_allocator_free(sixel_allocator_t *allocator, void *ptr);
SIXELSTATUS parser_context_init(parser_context_t *context);
SIXELSTATUS image_buffer_init(image_buffer_t *image, int, int, int, sixel_allocator_t *);
SIXELSTATUS sixel_decode_raw_impl(unsigned char *, int, image_buffer_t *, parser_context_t *, sixel_allocator_t *);
void sixel_helper_set_additional_message(const char *);