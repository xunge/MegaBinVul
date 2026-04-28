#include <stdbool.h>
#include <stdint.h>

typedef struct {
    char *line_buffer;
    uint32_t line_pos;
    uint32_t line_size;
    char *cur_buffer;
} GF_BTParser;

void gf_bt_check_line(GF_BTParser *parser);

typedef uint32_t u32;
typedef int32_t s32;
typedef bool Bool;