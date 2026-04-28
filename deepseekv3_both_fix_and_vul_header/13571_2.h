#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define PITCH(w) (((w) + 7) >> 3)
#define FBCON_SWAP(rotate, x, y) ((rotate) ? (y) : (x))
#define CALC_FONTSZ(h, pitch, charcount) ((h) * (pitch) * (charcount))
#define FONT_EXTRA_WORDS 4
#define FNTSIZE(p) (*(int*)(p - FONT_EXTRA_WORDS * sizeof(int)))
#define REFCOUNT(p) (*(int*)(p - (FONT_EXTRA_WORDS - 1) * sizeof(int)))
#define FNTSUM(p) (*(int*)(p - (FONT_EXTRA_WORDS - 2) * sizeof(int)))

#define EINVAL 22
#define ENOMEM 12
#define GFP_USER 0x10

typedef uint8_t u8;

struct vc_font {
    int width;
};

struct vc_data {
    int vc_num;
    struct vc_font vc_font;
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

struct console_font {
    unsigned int charcount;
    int width;
    int height;
    u8 *data;
};

struct fbcon_display {
    int userfont;
    u8 *fontdata;
};

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline uint32_t crc32(uint32_t crc, const void *buf, size_t size) {
    // Simple placeholder implementation
    return 0;
}

extern struct fb_info *fbcon_info_from_console(int console);
extern int fbcon_invalid_charcount(struct fb_info *info, unsigned int charcount);
extern int fbcon_do_set_font(struct vc_data *vc, int width, int height, int charcount, u8 *data, int userfont);
extern struct {
    struct vc_data *d;
} vc_cons[63];
extern struct fbcon_display fb_display[63];
extern int first_fb_vc;
extern int last_fb_vc;