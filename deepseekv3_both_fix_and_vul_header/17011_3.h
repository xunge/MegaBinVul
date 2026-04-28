#include <stdint.h>
#include <stdatomic.h>

typedef uint32_t u32;
typedef uint64_t dma_addr_t;

struct vb2_buffer {
    uint64_t timestamp;
};

struct vb2_v4l2_buffer {
    struct vb2_buffer vb2_buf;
    uint32_t flags;
    uint32_t field;
    uint32_t sequence;
    uint32_t timecode;
};

struct amvdec_codec_ops {
    u32 (*num_pending_bufs)(struct amvdec_session *sess);
};

struct amvdec_core {
    void *dev;
};

struct amvdec_session {
    struct amvdec_core *core;
    struct {
        struct amvdec_codec_ops *codec_ops;
        u32 pixfmt;
    } *fmt_out;
    void *m2m_ctx;
    atomic_int esparser_queued_bufs;
    u32 sequence_out;
};

#define V4L2_PIX_FMT_VP9 0
#define V4L2_FIELD_NONE 0
#define VB2_BUF_STATE_ERROR 0
#define VB2_BUF_STATE_DONE 0
#define EAGAIN 11
#define PARSER_FETCH_CMD 0