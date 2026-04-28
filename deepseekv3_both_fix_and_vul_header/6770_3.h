#include <stdint.h>
#include <stddef.h>

#define FBIOGTYPE 0x4600
#define FBIOPUTCMAP_SPARC 0x4601
#define FBIOGETCMAP_SPARC 0x4602
#define EFAULT 14
#define EINVAL 22

#define __user
#define put_user(x, y) (*(y) = (x), 0)
#define __put_user(x, y) (*(y) = (x), 0)
#define get_user(x, y) (x = *(y), 0)
#define __get_user(x, y) (x = *(y), 0)

typedef uint8_t u8;
typedef uint16_t u16;

struct fb_cmap {
    unsigned int start;
    unsigned int len;
    u16 *red;
    u16 *green;
    u16 *blue;
    u16 *transp;
};

struct fb_info {
    struct {
        unsigned int xres;
        unsigned int yres;
    } var;
    struct fb_cmap cmap;
};

struct fbtype {
    unsigned int fb_type;
    unsigned int fb_height;
    unsigned int fb_width;
    unsigned int fb_depth;
    unsigned int fb_cmsize;
};

struct fbcmap {
    unsigned int index;
    unsigned int count;
    unsigned char *red;
    unsigned char *green;
    unsigned char *blue;
};

int fb_set_cmap(struct fb_cmap *cmap, struct fb_info *info);