#include <linux/fb.h>
#include <linux/errno.h>

struct fb_info {
    struct {
        unsigned int hfmax;
        unsigned int vfmax;
        unsigned int dclkmax;
    } monspecs;
};

extern int fb_validate_mode(struct fb_var_screeninfo *var, struct fb_info *info);