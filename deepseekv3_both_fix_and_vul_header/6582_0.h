#include <stdint.h>

typedef struct ParseContext {
    uint64_t state64;
    int frame_start_found;
} ParseContext;

typedef struct DNXHDParserContext {
    ParseContext pc;
    int cur_byte;
    int remaining;
    int h;
    int w;
} DNXHDParserContext;

#define END_NOT_FOUND (-1)

extern int ff_dnxhd_check_header_prefix(uint64_t prefix);
extern int avpriv_dnxhd_get_frame_size(int cid);
extern int dnxhd_get_hr_frame_size(int cid, int w, int h);