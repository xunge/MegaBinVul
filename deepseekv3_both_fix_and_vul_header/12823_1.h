#include <stdint.h>
#include <stddef.h>

typedef uint16_t u16;

struct vc_data {
    unsigned long vc_origin;
    unsigned long vc_visible_origin;
    unsigned long vc_screenbuf;
    size_t vc_screenbuf_size;
};

struct vgacon_scrollback {
    int save;
    int restore;
    int cur;
    int cnt;
};

extern struct vgacon_scrollback *vgacon_scrollback_cur;
extern int vga_is_gfx;
extern size_t vga_vram_size;

static inline void scr_memcpyw(u16 *dest, u16 *src, size_t count);