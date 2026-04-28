#include <stddef.h>
#include <stdint.h>

#define VGA_FONTWIDTH 8
#define u16 uint16_t

struct vc_data {
    int vc_cols;
    int vc_rows;
    struct {
        int height;
    } vc_font;
    int vc_num;
    uintptr_t vc_origin;
    uintptr_t vc_screenbuf;
    size_t vc_screenbuf_size;
};

struct screen_info {
    unsigned short orig_video_cols;
    unsigned short orig_video_lines;
};

extern struct screen_info screen_info;
extern int vga_default_font_height;
extern int vga_video_num_columns;
extern int vga_video_num_lines;
extern int vga_is_gfx;
extern size_t vga_vram_size;
extern int vgacon_xres;
extern int vgacon_yres;

void scr_memcpyw(uint16_t *dest, uint16_t *src, size_t count);
void vgacon_doresize(struct vc_data *c, int cols, int rows);
void vgacon_scrollback_switch(int vc_num);