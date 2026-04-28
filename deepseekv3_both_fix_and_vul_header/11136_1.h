#include <stdlib.h>

struct fb_cmap {
    int start;
    int len;
    unsigned short *red;
    unsigned short *green;
    unsigned short *blue;
    unsigned short *transp;
};

struct fb_info {
    struct {
        int bits_per_pixel;
    } var;
    struct fb_cmap cmap;
};

struct uvesafb_pal_entry {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char pad;
};

extern int dac_width;
extern int uvesafb_setpalette(struct uvesafb_pal_entry *entries, int count, int start, struct fb_info *info);
extern int uvesafb_setcolreg(unsigned regno, unsigned red, unsigned green, unsigned blue, unsigned transp, struct fb_info *info);

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12

#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)