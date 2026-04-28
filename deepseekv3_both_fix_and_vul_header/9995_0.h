#include <stdint.h>
#include <errno.h>

struct vrend_decode_ctx {
   void *grctx;
};

#define VIRGL_SET_FRAMEBUFFER_STATE_NR_CBUFS 0
#define VIRGL_SET_FRAMEBUFFER_STATE_NR_ZSURF_HANDLE 1
#define VIRGL_SET_FRAMEBUFFER_STATE_CBUF_HANDLE(i) (2 + (i))

static uint32_t get_buf_entry(struct vrend_decode_ctx *ctx, int index);
static void vrend_set_framebuffer_state(void *grctx, uint32_t nr_cbufs, uint32_t *surf_handle, uint32_t zsurf_handle);