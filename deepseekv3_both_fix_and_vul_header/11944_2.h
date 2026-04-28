#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <strings.h>

#define BT_LINE_SIZE 4096

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef bool Bool;

#define GF_NOT_SUPPORTED 1
#define GF_LOG_ERROR 1
#define GF_LOG_PARSER 1

typedef struct BTDefSymbol {
    char *name;
    char *value;
} BTDefSymbol;

typedef struct {
    char *line_buffer;
    u32 line_pos;
    u32 line_size;
    u32 line_start_pos;
    u32 line;
    void *gz_in;
    u32 unicode_type;
    u32 file_pos;
    u32 file_size;
    u32 is_wrl;
    u32 block_comment;
    u32 def_w;
    u32 def_h;
    u32 done;
    void *def_symbols;
} GF_BTParser;

#define GF_SAFEALLOC(ptr, type) ptr = (type*)malloc(sizeof(type))

void gf_bt_report(GF_BTParser *parser, int code, const char *format, ...);
void GF_LOG(int level, int category, const char *format, ...);
s32 gf_gztell(void *gz_in);
void gf_gzseek(void *gz_in, u32 pos, int whence);
int gf_gzeof(void *gz_in);
int gf_gzgetc(void *gz_in);
char *gf_gzgets(void *gz_in, char *buf, int size);
void gf_set_progress(const char *msg, u32 pos, u32 size);
void gf_utf8_wcstombs(char *dst, u32 dst_size, const unsigned short **src);
char *gf_strdup(const char *str);
void *gf_list_get(void *list, u32 index);
u32 gf_list_count(void *list);
void gf_list_add(void *list, void *item);