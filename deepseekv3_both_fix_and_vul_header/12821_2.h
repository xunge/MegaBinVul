#include <stdbool.h>
#include <stdint.h>

#define KD_TEXT 0x00
#define u16 uint16_t

enum con_scroll { SM_UP };

struct vc_data {
    unsigned int vc_rows;
    unsigned int vc_mode;
    unsigned long vc_origin;
    unsigned int vc_size_row;
    unsigned int vc_screenbuf_size;
    uint16_t vc_video_erase_char;
    unsigned long vc_scr_end;
    unsigned long vc_visible_origin;
    unsigned long vc_pos;
};

extern bool vga_is_gfx;
extern bool vga_hardscroll_enabled;
extern unsigned long vga_vram_base;
extern unsigned long vga_vram_end;
extern unsigned long vga_rolled_over;

void vgacon_restore_screen(struct vc_data *c);
void vgacon_scrollback_update(struct vc_data *c, unsigned int t, unsigned int lines);
void scr_memcpyw(uint16_t *dest, uint16_t *src, unsigned int count);
void scr_memsetw(uint16_t *dest, uint16_t fill, unsigned int count);
void scr_memmovew(uint16_t *dest, uint16_t *src, unsigned int count);
void vga_set_mem_top(struct vc_data *c);