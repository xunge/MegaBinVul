#include <stdlib.h>
#include <string.h>

typedef unsigned char stbi_uc;
typedef int stbi__int32;

#define STBI_NOTUSED(v)  (void)(v)

typedef struct
{
    int w, h;
    stbi_uc *out;
    stbi_uc *background;
    stbi_uc *history;
    int eflags;
    int delay;
    int transparent;
    stbi_uc pal[256][4];
    stbi_uc lpal[256][4];
    stbi_uc *color_table;
    int bgindex;
    int flags;
    int line_size;
    int start_x, start_y;
    int max_x, max_y;
    int cur_x, cur_y;
    int lflags;
    int step;
    int parse;
} stbi__gif;

typedef struct
{
    stbi_uc *buffer;
    stbi_uc *buffer_end;
    stbi_uc *buffer_start;
    int read_from_callbacks;
    int img_buffer;
    int img_buffer_end;
    int img_buffer_original;
} stbi__context;

static stbi_uc *stbi__errpuc(const char *str1, const char *str2);
static stbi_uc *stbi__malloc(size_t size);
static int stbi__get8(stbi__context *s);
static void stbi__skip(stbi__context *s, int n);
static stbi__int32 stbi__get16le(stbi__context *s);
static int stbi__gif_header(stbi__context *s, stbi__gif *g, int *comp, int is_info);
static void stbi__gif_parse_colortable(stbi__context *s, stbi_uc pal[256][4], int num_entries, int transp);
static stbi_uc *stbi__process_gif_raster(stbi__context *s, stbi__gif *g);