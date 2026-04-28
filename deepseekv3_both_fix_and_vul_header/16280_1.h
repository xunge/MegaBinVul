#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint32_t u32;

struct vc_data {
    struct {
        u8 *data;
        int width;
        int height;
    } vc_font;
    int vc_hi_font_mask;
};

struct console_font {
    u8 *data;
    int width;
    int height;
    int charcount;
};

#define FNTSIZE(fontdata) (32768)
#define EINVAL 22