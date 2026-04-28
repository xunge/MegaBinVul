#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define VGA_CRT_IM 0x3B4
#define VGA_CRT_DM 0x3B5
#define VGA_CRT_IC 0x3D4
#define VGA_CRT_DC 0x3D5
#define VGA_IS1_RC 0x3DA
#define VGA_ATT_W 0x3C0
#define VGA_PEL_IW 0x3C8
#define VGA_PEL_D 0x3C9
#define VGA_FONTWIDTH 8

#define VIDEO_TYPE_VLFB 2
#define VIDEO_TYPE_EFI 3
#define VIDEO_TYPE_EGAM 4
#define VIDEO_TYPE_MDA 5
#define VIDEO_TYPE_EGAC 6
#define VIDEO_TYPE_VGAC 7
#define VIDEO_TYPE_CGA 8
#define IORESOURCE_IO 0x00000100

typedef uint16_t u16;

struct screen_info {
    uint8_t orig_video_mode;
    uint8_t orig_video_isVGA;
    uint16_t orig_video_cols;
    uint16_t orig_video_lines;
    uint16_t orig_video_ega_bx;
    uint8_t orig_video_points;
};

struct resource {
    const char *name;
    unsigned long flags;
    unsigned long start;
    unsigned long end;
};

struct vgastate {
    void *vgabase;
};

struct console {
    const char *(*con_startup)(void);
};

extern struct screen_info screen_info;
extern struct vgastate vgastate;
extern struct resource ioport_resource;
extern struct console *conswitchp;
extern struct console dummy_con;

static int vga_video_num_lines;
static int vga_video_num_columns;
static unsigned long vga_vram_base;
static unsigned long vga_vram_size;
static unsigned long vga_vram_end;
static int vga_video_type;
static bool vga_can_do_color;
static int vga_video_port_reg;
static int vga_video_port_val;
static int vga_video_font_height;
static int vga_default_font_height;
static int vga_scan_lines;
static bool vga_hardscroll_enabled;
static bool vga_hardscroll_user_enable;
static bool vga_init_done;
static int vgacon_xres;
static int vgacon_yres;

static const uint8_t color_table[16];
static const uint8_t default_red[16];
static const uint8_t default_grn[16];
static const uint8_t default_blu[16];

static uint16_t scr_readw(volatile uint16_t *p);
static void scr_writew(uint16_t val, volatile uint16_t *p);
static void *VGA_MAP_MEM(unsigned long base, unsigned long size);
static void vgacon_scrollback_startup(void);
static void request_resource(struct resource *root, struct resource *new);
static uint8_t inb_p(uint16_t port);
static void outb_p(uint8_t value, uint16_t port);