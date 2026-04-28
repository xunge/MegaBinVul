#include <stdint.h>
#include <string.h>
#include <stdarg.h>

typedef uint32_t u32;
typedef uint16_t u16;

struct fb_bitfield {
    u32 offset;
    u32 length;
    u32 msb_right;
};

struct fb_var_screeninfo {
    u32 activate;
    u32 grayscale;
    u32 xres;
    u32 yres;
    u32 xres_virtual;
    u32 yres_virtual;
    struct fb_bitfield red;
    struct fb_bitfield green;
    struct fb_bitfield blue;
    struct fb_bitfield transp;
};

struct fb_videomode {
    int dummy;
};

struct fb_event {
    struct fb_info *info;
    struct fb_videomode *data;
};

struct fb_cmap {
    u32 start;
    u32 len;
    u16 *red;
    u16 *green;
    u16 *blue;
    u16 *transp;
};

struct fb_info {
    struct fb_var_screeninfo var;
    struct {
        u32 capabilities;
        char id[16];
    } fix;
    struct {
        int (*fb_check_var)(struct fb_var_screeninfo *var, struct fb_info *info);
        int (*fb_set_par)(struct fb_info *info);
        int (*fb_get_caps)(struct fb_info *info, struct fb_var_screeninfo *var, u32 activate);
    } *fbops;
    struct fb_cmap cmap;
    struct {
        struct fb_videomode *prev;
        struct fb_videomode *next;
    } modelist;
};

#define FB_ACTIVATE_INV_MODE 0x01
#define FB_ACTIVATE_FORCE 0x02
#define FB_ACTIVATE_MASK 0x0F
#define FB_ACTIVATE_NOW 0x10
#define FB_CAP_FOURCC 0x20
#define FB_EVENT_MODE_CHANGE 1
#define EINVAL 22
#define KERN_WARNING "<4>"

static inline int check_mul_overflow(u32 a, u32 b, u32 *res) {
    *res = a * b;
    return a && (*res / a != b);
}

static inline int list_empty(const void *list) {
    const struct fb_videomode **l = (const struct fb_videomode **)list;
    return *l == (const struct fb_videomode *)(l + 1);
}

int fb_var_to_videomode(struct fb_videomode *mode, struct fb_var_screeninfo *var);
int fb_mode_is_equal(struct fb_videomode *mode1, struct fb_videomode *mode2);
int fbcon_mode_deleted(struct fb_info *info, struct fb_videomode *mode);
void fb_delete_videomode(struct fb_videomode *mode, void *modelist);
int fb_check_caps(struct fb_info *info, struct fb_var_screeninfo *var, u32 activate);
void fb_pan_display(struct fb_info *info, struct fb_var_screeninfo *var);
void fb_set_cmap(struct fb_cmap *cmap, struct fb_info *info);
int fb_add_videomode(struct fb_videomode *mode, void *modelist);
void fb_notifier_call_chain(int event, struct fb_event *ev);
int printk(const char *fmt, ...);
int pr_warn(const char *fmt, ...);