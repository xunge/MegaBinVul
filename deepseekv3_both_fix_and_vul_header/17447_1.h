#include <stdlib.h>

typedef unsigned int u32;

struct fb_info {
    int state;
    struct {
        int xres;
        int yres;
    } var;
    u32 *pseudo_palette;
    struct {
        void *owner;
    } *fbops;
};

struct linux_logo {
    int width;
    int height;
    unsigned char *data;
};

struct fb_image {
    int width;
    int height;
    int depth;
    unsigned char *data;
    int dx;
    int dy;
};

struct fb_logo {
    int needs_cmapreset;
    int needs_truepalette;
    int needs_directpalette;
    int depth;
} fb_logo;

int fb_center_logo;

#define FBINFO_STATE_RUNNING 0
#define FB_ROTATE_CW 1
#define FB_ROTATE_CCW 2
#define GFP_KERNEL 0

static void *kmalloc(size_t size, int flags) { return malloc(size); }
static void *kmalloc_array(size_t n, size_t size, int flags) { return malloc(n * size); }
static void kfree(void *ptr) { free(ptr); }

static void fb_set_logocmap(struct fb_info *info, const struct linux_logo *logo) {}
static void fb_set_logo_truepalette(struct fb_info *info, const struct linux_logo *logo, u32 *palette) {}
static void fb_set_logo_directpalette(struct fb_info *info, const struct linux_logo *logo, u32 *palette) {}
static void fb_set_logo(struct fb_info *info, const struct linux_logo *logo, unsigned char *new_logo, int depth) {}
static void fb_rotate_logo(struct fb_info *info, unsigned char *logo_rotate, struct fb_image *image, int rotate) {}
static void fb_do_show_logo(struct fb_info *info, struct fb_image *image, int rotate, unsigned int n) {}