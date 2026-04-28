#include <stdlib.h>
#include <string.h>

typedef unsigned char stbi_uc;
typedef int stbi__int32;

#define STBI_NOTUSED(v)  (void)(v)

typedef struct
{
   stbi_uc *out;
   stbi_uc *background;
   stbi_uc *history;
   int w, h;
   int eflags;
   int delay;
   int transparent;
   int bgindex;
   int line_size;
   int start_x, start_y;
   int max_x, max_y;
   int cur_x, cur_y;
   int lflags;
   int step;
   int parse;
   stbi_uc *color_table;
   stbi_uc pal[256][4];
   stbi_uc lpal[256][4];
   int flags;
} stbi__gif;

typedef struct
{
   // context fields would be defined here
} stbi__context;

static void *stbi__malloc(size_t size);
static void stbi__skip(stbi__context *s, int n);
static int stbi__get8(stbi__context *s);
static int stbi__get16le(stbi__context *s);
static stbi_uc *stbi__errpuc(const char *str, const char *msg);
static int stbi__gif_header(stbi__context *s, stbi__gif *g, int *comp, int is_info);
static void stbi__gif_parse_colortable(stbi__context *s, stbi_uc pal[256][4], int num_entries, int transp);
static stbi_uc *stbi__process_gif_raster(stbi__context *s, stbi__gif *g);