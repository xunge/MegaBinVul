#include <string.h>

typedef int SIXELSTATUS;
#define SIXEL_FALSE 0
#define SIXEL_OK 1
#define SIXEL_RUNTIME_ERROR -1

typedef struct gif_context_t {
    unsigned char *img_buffer;
    unsigned char *img_buffer_end;
} gif_context_t;

typedef struct gif_t {
    int w;
    int h;
    int line_size;
    int start_x;
    int start_y;
    int max_x;
    int max_y;
    int cur_x;
    int cur_y;
    int actual_width;
    int actual_height;
    unsigned char lflags;
    unsigned char lpal[256][3];
    unsigned char *color_table;
    unsigned char flags;
    int transparent;
    unsigned char eflags;
    int delay;
    int loop_count;
    int is_terminated;
    unsigned char pal[256][3];
    int step;
    int parse;
} gif_t;

extern unsigned char gif_get8(gif_context_t *s);
extern int gif_get16le(gif_context_t *s);
extern void gif_parse_colortable(gif_context_t *s, unsigned char (*pal)[3], int num_colors);
extern SIXELSTATUS gif_process_raster(gif_context_t *s, gif_t *g);
extern void sixel_helper_set_additional_message(const char *msg);