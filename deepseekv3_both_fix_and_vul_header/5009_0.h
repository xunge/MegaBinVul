#include <stdlib.h>
#include <string.h>

#define SIXELAPI
#define SIXELSTATUS int
#define SIXEL_OK 0
#define SIXEL_FALSE 0
#define SIXEL_FAILED(x) ((x) != SIXEL_OK)
#define SIXEL_BAD_INPUT -1
#define DECSIXEL_PARAMS_MAX 16
#define SIXEL_PALETTE_MAX 256
#define SIXEL_XRGB(r, g, b) (((r) << 16) | ((g) << 8) | (b))

typedef enum {
    PS_GROUND,
    PS_ESC,
    PS_DCS,
    PS_DECSIXEL,
    PS_DECGRA,
    PS_DECGRI,
    PS_DECGCI
} parser_state_t;

typedef struct {
    unsigned char *data;
    int width;
    int height;
    int ncolors;
    int palette[SIXEL_PALETTE_MAX];
} image_buffer_t;

typedef struct {
    parser_state_t state;
    int param;
    int nparams;
    int params[DECSIXEL_PARAMS_MAX];
    int attributed_pad;
    int attributed_pan;
    int attributed_ph;
    int attributed_pv;
    int pos_x;
    int pos_y;
    int repeat_count;
    int color_index;
    int bgindex;
    int max_x;
    int max_y;
} parser_context_t;

typedef struct {
    void *(*malloc)(size_t);
    void (*free)(void *);
    void *(*realloc)(void *, size_t);
} sixel_allocator_t;

static int hls_to_rgb(int h, int l, int s) {
    return 0;
}

static SIXELSTATUS image_buffer_resize(image_buffer_t *image, int width, int height, int bgindex, sixel_allocator_t *allocator) {
    return SIXEL_OK;
}