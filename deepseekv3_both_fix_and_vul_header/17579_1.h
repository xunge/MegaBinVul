#include <stdint.h>
#include <stdlib.h>

#define DEFAULT_CNTL 0
#define DST_X_LEFT_TO_RIGHT (1 << 0)
#define DST_Y_TOP_TO_BOTTOM (1 << 1)
#define GMC_ROP3_MASK 0x00FF0000
#define ROP3_SRCCOPY 0x00CC0000
#define ROP3_PATCOPY 0x00F00000
#define ROP3_BLACKNESS 0x00000000
#define ROP3_WHITENESS 0x00FF0000
#define PCI_DEVICE_ID_ATI_RAGE128_PF 0x5046
#define VBE_DISPI_INDEX_YRES 1
#define LOG_UNIMP 0

typedef struct ATIVGAState {
    struct {
        uint8_t *vram_ptr;
        uint32_t vbe_start_addr;
        uint32_t vram_size;
        uint32_t vbe_line_offset;
        uint32_t vbe_regs[16];
        uint8_t palette[6];
        void *con;
    } vga;
    struct {
        uint32_t dp_mix;
        uint32_t dp_cntl;
        uint32_t dst_x;
        uint32_t dst_y;
        uint32_t dst_width;
        uint32_t dst_height;
        uint32_t dst_pitch;
        uint32_t default_pitch;
        uint32_t dst_offset;
        uint32_t default_offset;
        uint32_t crtc_offset;
        uint32_t src_x;
        uint32_t src_y;
        uint32_t src_pitch;
        uint32_t src_offset;
        uint32_t dp_brush_frgd_clr;
    } regs;
    uint32_t dev_id;
} ATIVGAState;

typedef struct DisplaySurface {
    uint8_t *data;
    int stride;
    int bits_per_pixel;
} DisplaySurface;

#define DPRINTF(...)
#define qemu_console_surface(con) NULL
#define surface_data(s) ((s)->data)
#define surface_stride(s) ((s)->stride)
#define surface_bits_per_pixel(s) ((s)->bits_per_pixel)
#define qemu_log_mask(mask, ...)
#define pixman_blt(...)
#define pixman_fill(...)
#define g_malloc(size) malloc(size)
#define g_free(ptr) free(ptr)
#define memory_region_set_dirty(...)
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

static inline uint32_t rgb_to_pixel32(uint8_t r, uint8_t g, uint8_t b) {
    return (r << 16) | (g << 8) | b;
}

static inline int ati_bpp_from_datatype(ATIVGAState *s) {
    return 32;
}