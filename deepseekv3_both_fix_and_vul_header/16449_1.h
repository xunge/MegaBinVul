#include <stdint.h>
#include <stddef.h>

#define BIT(n) (1 << (n))

typedef struct VGACommonState {
    uint8_t *vram_ptr;
    int hw_cursor_x;
    int hw_cursor_y;
} VGACommonState;

typedef struct ATIVGAState {
    VGACommonState vga;
    uint8_t *vram_ptr;
    uint32_t cursor_offset;
    struct {
        uint32_t crtc_gen_cntl;
        uint32_t crtc_v_total_disp;
        uint32_t crtc_h_total_disp;
        uint32_t cur_color0;
        uint32_t cur_color1;
    } regs;
} ATIVGAState;

#define CRTC2_CUR_EN (1 << 0)

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))