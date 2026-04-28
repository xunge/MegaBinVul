#include <stddef.h>
#include <stdlib.h>
#include <linux/types.h>

#define CM_ERASE 0
#define CM_MOVE 1

struct vc_data {
    unsigned long vc_origin;
    unsigned long vc_screenbuf;
    unsigned long vc_visible_origin;
    int vc_size_row;
    int vc_rows;
};

struct vgacon_scrollback {
    int cur;
    int cnt;
    int tail;
    int size;
    int save;
    int restore;
    void *data;
};

extern struct vgacon_scrollback *vgacon_scrollback_cur;
extern int vga_rolled_over;
extern void *vga_vram_base;
extern size_t vga_vram_size;

#define min(a, b) ((a) < (b) ? (a) : (b))

void vc_scrolldelta_helper(struct vc_data *c, int lines, int rolled_over, void *vram_base, size_t vram_size);
void vga_set_mem_top(struct vc_data *c);
void vgacon_restore_screen(struct vc_data *c);
void vgacon_cursor(struct vc_data *c, int mode);
void vgacon_save_screen(struct vc_data *c);
void scr_memcpyw(void *dest, void *src, size_t count);