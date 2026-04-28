#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef uint8_t u8;

struct vc_data {
    int vc_num;
    struct {
        int width;
    } vc_font;
};
struct console_font {
    unsigned int charcount;
    int width;
    int height;
    u8 *data;
};
struct fb_info {
    struct {
        int rotate;
        int xres;
        int yres;
    } var;
    struct {
        int blit_x;
        int blit_y;
    } pixmap;
};
struct fbcon_display {
    u8 *fontdata;
    int userfont;
};
struct vc_cons {
    struct vc_data *d;
};

#define PITCH(w) (((w) + 7) >> 3)
#define FBCON_SWAP(rotate, x, y) ((rotate) ? (y) : (x))
#define CALC_FONTSZ(h, p, c) ((h) * (p) * (c))
#define FONT_EXTRA_WORDS 4
#define FNTSIZE(p) (*(int*)(p - FONT_EXTRA_WORDS * sizeof(int)))
#define REFCOUNT(p) (*(int*)(p - (FONT_EXTRA_WORDS - 1) * sizeof(int)))
#define FNTSUM(p) (*(int*)(p - (FONT_EXTRA_WORDS - 2) * sizeof(int)))
#define GFP_USER 0

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline uint32_t crc32(uint32_t crc, const void *buf, size_t len) {
    uint32_t sum = 0;
    const uint8_t *p = buf;
    for (size_t i = 0; i < len; i++) {
        sum += p[i];
    }
    return sum;
}

extern struct fb_info *fbcon_info_from_console(int console);
extern int fbcon_invalid_charcount(struct fb_info *info, unsigned int charcount);
extern int fbcon_do_set_font(struct vc_data *vc, int width, int height, int charcount, u8 *data, int userfont);
extern int first_fb_vc;
extern int last_fb_vc;
extern struct vc_cons vc_cons[];
extern struct fbcon_display fb_display[];