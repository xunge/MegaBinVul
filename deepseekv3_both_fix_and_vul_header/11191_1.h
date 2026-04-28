#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

typedef int SIXELSTATUS;

struct sixel_decoder_t {
    char *input;
    char *output;
    struct sixel_allocator_t *allocator;
};

typedef struct sixel_decoder_t sixel_decoder_t;
typedef struct sixel_allocator_t sixel_allocator_t;

#define SIXELAPI
#define SIXEL_FALSE 0
#define SIXEL_LIBC_ERROR 0
#define SIXEL_BAD_ALLOCATION 0
#define SIXEL_FAILED(x) (x != 0)
#define SIXEL_PIXELFORMAT_PAL8 0
#define SIXEL_FORMAT_PNG 0

#define HAVE__SETMODE 0
#define HAVE_SETMODE 0

void sixel_decoder_ref(sixel_decoder_t *decoder);
void sixel_decoder_unref(sixel_decoder_t *decoder);
void sixel_helper_set_additional_message(const char *msg);
void *sixel_allocator_malloc(sixel_allocator_t *allocator, size_t size);
void *sixel_allocator_realloc(sixel_allocator_t *allocator, void *ptr, size_t size);
void sixel_allocator_free(sixel_allocator_t *allocator, void *ptr);
SIXELSTATUS sixel_decode_raw(unsigned char *raw_data, int raw_len, unsigned char **indexed_pixels, int *sx, int *sy, unsigned char **palette, int *ncolors, sixel_allocator_t *allocator);
SIXELSTATUS sixel_helper_write_image_file(unsigned char *indexed_pixels, int sx, int sy, unsigned char *palette, int pixelformat, const char *output, int format, sixel_allocator_t *allocator);