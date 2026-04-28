#include <stdint.h>
#include <stdio.h>

#define SVGA_CMD_UPDATE 1
#define SVGA_CMD_UPDATE_VERBOSE 2
#define SVGA_CMD_RECT_FILL 3
#define SVGA_CMD_RECT_COPY 4
#define SVGA_CMD_DEFINE_CURSOR 5
#define SVGA_CMD_DEFINE_ALPHA_CURSOR 6
#define SVGA_CMD_RECT_ROP_FILL 7
#define SVGA_CMD_RECT_ROP_COPY 8
#define SVGA_CMD_DRAW_GLYPH_CLIPPED 9
#define SVGA_CMD_SURFACE_ALPHA_BLEND 10
#define SVGA_CMD_SURFACE_FILL 11
#define SVGA_CMD_SURFACE_COPY 12
#define SVGA_CMD_FRONT_ROP_FILL 13
#define SVGA_CMD_FENCE 14
#define SVGA_CMD_INVALID_CMD 15

#define SVGA_FIFO_STOP 0
#define SVGA_BITMAP_SIZE(x, y) (((x) + 31) / 32 * 4 * (y))
#define SVGA_PIXMAP_SIZE(x, y, bpp) ((x) * (y) * (((bpp) + 7) / 8))

struct vmsvga_state_s {
    uint32_t fifo_stop;
    uint32_t *fifo;
    int syncing;
};

struct vmsvga_cursor_definition_s {
    uint32_t id;
    uint32_t hot_x;
    uint32_t hot_y;
    uint32_t width;
    uint32_t height;
    uint32_t bpp;
    uint8_t mask[8192];
    uint8_t image[8192];
};

static int vmsvga_fifo_length(struct vmsvga_state_s *s);
static uint32_t vmsvga_fifo_read(struct vmsvga_state_s *s);
static uint8_t vmsvga_fifo_read_raw(struct vmsvga_state_s *s);
static void vmsvga_update_rect_delayed(struct vmsvga_state_s *s, int x, int y, int width, int height);
static uint32_t cpu_to_le32(uint32_t v);