#include <stddef.h>
#include <string.h>

typedef int SIXELSTATUS;
typedef struct image_buffer image_buffer_t;
typedef struct sixel_allocator sixel_allocator_t;

#define SIXEL_FALSE 0
#define SIXEL_BAD_INPUT 1
#define SIXEL_BAD_ALLOCATION 2
#define SIXEL_OK 3
#define SIXEL_HEIGHT_LIMIT 32767
#define SIXEL_WIDTH_LIMIT 32767
#define SIXEL_PALETTE_MAX 256

struct image_buffer {
    int width;
    int height;
    unsigned char *data;
    int ncolors;
    unsigned int palette[256];
};

#define SIXEL_RGB(r, g, b) ((r) << 16 | (g) << 8 | (b))

static const unsigned int sixel_default_color_table[16] = {
    0x000000, 0x0000AA, 0x00AA00, 0x00AAAA,
    0xAA0000, 0xAA00AA, 0xAA5500, 0xAAAAAA,
    0x555555, 0x5555FF, 0x55FF55, 0x55FFFF,
    0xFF5555, 0xFF55FF, 0xFFFF55, 0xFFFFFF
};

void *sixel_allocator_malloc(sixel_allocator_t *allocator, size_t size);
void sixel_helper_set_additional_message(const char *message);