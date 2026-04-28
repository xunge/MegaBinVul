#include <string.h>
#include <errno.h>

#define FBIOGET_VSCREENINFO 0x4600
#define FBIOPUT_VSCREENINFO 0x4601
#define FBIOGET_FSCREENINFO 0x4602
#define FBIOPUTCMAP 0x4604
#define FBIOGETCMAP 0x4605
#define FBIOPAN_DISPLAY 0x4606
#define FBIO_CURSOR 0x4608
#define FBIOGET_CON2FBMAP 0x460F
#define FBIOPUT_CON2FBMAP 0x4610
#define FBIOBLANK 0x4611

#define FB_ACTIVATE_ALL 0x80
#define FBINFO_HIDE_SMEM_START 0x0002
#define FB_BLANK_POWERDOWN 4

#define EFAULT 14
#define EINVAL 22
#define ENOTTY 25

typedef void* user_ptr;

struct fb_var_screeninfo {
    unsigned int xres;
    unsigned int yres;
    unsigned int activate;
    // 其他必要字段...
};

struct fb_fix_screeninfo {
    unsigned long smem_start;
    // 其他必要字段...
};

struct fb_cmap {
    // 必要字段...
};

struct fb_cmap_user {
    // 必要字段...
};

struct fb_info;

struct fb_ops {
    int (*fb_ioctl)(struct fb_info *, unsigned int, unsigned long);
    // 其他操作...
};

struct fb_info {
    struct fb_var_screeninfo var;
    struct fb_fix_screeninfo fix;
    struct fb_cmap cmap;
    unsigned int flags;
    const struct fb_ops *fbops;
    // 其他必要字段...
};

void lock_fb_info(struct fb_info *info);
void unlock_fb_info(struct fb_info *info);
int fb_set_var(struct fb_info *info, struct fb_var_screeninfo *var);
void fbcon_update_vcs(struct fb_info *info, int arg);
int fb_set_user_cmap(struct fb_cmap_user *cmap, struct fb_info *info);
int fb_cmap_to_user(struct fb_cmap *from, struct fb_cmap_user *to);
int fb_pan_display(struct fb_info *info, struct fb_var_screeninfo *var);
int fbcon_get_con2fb_map_ioctl(user_ptr argp);
int fbcon_set_con2fb_map_ioctl(user_ptr argp);
int fb_blank(struct fb_info *info, int blank);
void fbcon_fb_blanked(struct fb_info *info, int blank);

static inline long copy_to_user(user_ptr to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline long copy_from_user(void *to, user_ptr from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

void console_lock(void);
void console_unlock(void);

#define __user