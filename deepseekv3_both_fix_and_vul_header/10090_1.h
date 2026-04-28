#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

#define EINVAL 22
#define ENOMEM 12
#define FREE(x) free(x)

struct pipe_vertex_element {
    unsigned src_offset;
    unsigned instance_divisor;
    unsigned vertex_buffer_index;
    unsigned src_format;
};

struct vrend_decode_ctx {
    void *grctx;
};

#define PIPE_MAX_ATTRIBS 32
#define VIRGL_OBJ_VERTEX_ELEMENTS_V0_SRC_OFFSET(i) (0)
#define VIRGL_OBJ_VERTEX_ELEMENTS_V0_INSTANCE_DIVISOR(i) (0)
#define VIRGL_OBJ_VERTEX_ELEMENTS_V0_VERTEX_BUFFER_INDEX(i) (0)
#define VIRGL_OBJ_VERTEX_ELEMENTS_V0_SRC_FORMAT(i) (0)

unsigned get_buf_entry(struct vrend_decode_ctx *ctx, int entry);
int vrend_create_vertex_elements_state(void *grctx, uint32_t handle, int num_elements, struct pipe_vertex_element *ve);