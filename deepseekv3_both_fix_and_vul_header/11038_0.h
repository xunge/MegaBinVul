#include <stdlib.h>
#include <string.h>

typedef int SIXELSTATUS;
#define SIXEL_OK 0
#define SIXEL_BAD_ALLOCATION (-1)

#define SIXEL_PIXELFORMAT_PAL8 0
#define SIXEL_PIXELFORMAT_RGB888 1

typedef struct sixel_frame_t {
    int delay;
    unsigned char *palette;
    int ncolors;
    int pixelformat;
    unsigned char *pixels;
    int width;
    int height;
    int transparent;
    int multiframe;
    void *allocator;
} sixel_frame_t;

typedef struct gif_t {
    int delay;
    unsigned char flags;
    unsigned char *color_table;
    unsigned char *out;
    int w;
    int h;
    unsigned char lflags;
    unsigned char eflags;
    int transparent;
    int loop_count;
} gif_t;

extern void *sixel_allocator_malloc(void *allocator, size_t size);
extern void sixel_allocator_free(void *allocator, void *ptr);
extern void sixel_helper_set_additional_message(const char *message);