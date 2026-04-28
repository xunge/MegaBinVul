#include <stddef.h>

typedef int SIXELSTATUS;
#define SIXEL_FALSE 0
#define SIXEL_OK 1
#define SIXEL_RUNTIME_ERROR (-1)

typedef struct gif_lzw {
    signed short prefix;
    unsigned char first;
    unsigned char suffix;
} gif_lzw;

typedef struct gif_context {
    unsigned char *img_buffer;
} gif_context_t;

typedef struct gif {
    gif_lzw codes[4096];
} gif_t;

#define gif_lzw_max_code_size 12

static unsigned char gif_get8(gif_context_t *s);
static void gif_out_code(gif_t *g, unsigned short code);
static void sixel_helper_set_additional_message(const char *msg);