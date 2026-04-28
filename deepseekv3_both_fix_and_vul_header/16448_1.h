#include <stdint.h>
#include <stdbool.h>

#define BIT(n) (1 << (n))

typedef struct ATIVGAState ATIVGAState;
typedef struct cursor_surface cursor_surface;

struct ATIVGAState {
    struct {
        uint8_t *vram_ptr;
        void *con;
    } vga;
    struct {
        uint32_t cur_offset;
        uint32_t cur_hv_offs;
        uint32_t cur_color0;
        uint32_t cur_color1;
    } regs;
    cursor_surface *cursor;
    bool cursor_guest_mode;
};

cursor_surface *cursor_alloc(int width, int height);
void cursor_set_mono(cursor_surface *surface, uint32_t fgcolor, uint32_t bgcolor,
                    const uint8_t *image, int transparent, const uint8_t *mask);
void dpy_cursor_define(void *con, cursor_surface *cursor);