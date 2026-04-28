#include <stddef.h>

struct fb_info;
struct vc_data {
    int dummy;
};
struct fb_con {
    int dummy;
};

extern struct fb_info *fbcon_registered_fb[];
extern int con2fb_map[];
extern int con2fb_map_boot[];
extern struct {
    struct vc_data *d;
} vc_cons[];
extern int fg_console;
extern int logo_shown;
extern int info_idx;
extern struct fb_con fb_con;

#define FBCON_LOGO_DONTSHOW 0
#define WARN_CONSOLE_UNLOCKED()
#define EINVAL 22

static int search_for_mapped_con(void);
static int con_is_bound(struct fb_con *con);
static int do_fbcon_takeover(int show_logo);
static int search_fb_in_map(int idx);
static int con2fb_acquire_newinfo(struct vc_data *vc, struct fb_info *info, int unit);
static void fbcon_add_cursor_work(struct fb_info *info);
static void con2fb_release_oldinfo(struct vc_data *vc, struct fb_info *oldinfo, struct fb_info *newinfo);
static void con2fb_init_display(struct vc_data *vc, struct fb_info *info, int unit, int show_logo);