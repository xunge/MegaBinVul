#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef signed int s32;

typedef struct {
    char *line_buffer;
    s32 line_pos;
    s32 line_size;
    void *gz_in;  // Replaced gzFile with void* since we can't include zlib.h
    u8 unicode_type;
} GF_BTParser;

void *gf_malloc(size_t size);
void *gf_realloc(void *ptr, size_t size);
void gf_bt_check_line(GF_BTParser *parser);
int gzeof(void *file);  // Declaration for gzeof since we can't include zlib.h