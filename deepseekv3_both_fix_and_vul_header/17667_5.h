#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

#define V4L2_FIELD_INTERLACED 1
#define V4L2_EVENT_MOTION_DET 0
#define V4L2_EVENT_MD_FL_HAVE_FRAME_SEQ 0
#define VB2_BUF_STATE_DONE 0

struct pci_dev {
    void *dev;
};

struct tw5864_h264_frame {
    struct tw5864_input *input;
    int vlc_len;
    struct {
        void *addr;
    } vlc;
    u32 checksum;
    u64 timestamp;
    u32 seqno;
    u32 gop_seqno;
};

struct tw5864_input {
    struct tw5864_dev *root;
    struct tw5864_buf *vb;
    u8 *buf_cur_ptr;
    int buf_cur_space_left;
    u8 tail;
    int tail_nb_bits;
    void *vdev;
    void *slock;
};

struct tw5864_dev {
    struct pci_dev *pci;
};

struct vb2_buffer {
    u64 timestamp;
};

struct vb2_v4l2_buffer {
    u32 sequence;
    u32 field;
    struct vb2_buffer vb2_buf;
};

struct tw5864_buf {
    struct vb2_v4l2_buffer vb;
};

struct v4l2_event {
    int type;
    struct {
        struct {
            int flags;
            u32 frame_sequence;
        } motion_det;
    } u;
};

static inline u32 tw5864_vlc_checksum(u32 *data, int len) { return 0; }
static inline bool tw5864_is_motion_triggered(struct tw5864_h264_frame *frame) { return false; }
static inline void spin_lock_irqsave(void *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(void *lock, unsigned long flags) {}
static inline void vb2_set_plane_payload(struct vb2_buffer *vb2_buf, int plane, size_t size) {}
static inline void *vb2_plane_vaddr(struct vb2_buffer *vb2_buf, int plane) { return NULL; }
static inline void vb2_buffer_done(struct vb2_buffer *vb2_buf, int state) {}
static inline struct vb2_v4l2_buffer *to_vb2_v4l2_buffer(struct vb2_buffer *vb2_buf) { 
    return (struct vb2_v4l2_buffer *)vb2_buf;
}
static inline void v4l2_event_queue(void *vdev, struct v4l2_event *ev) {}
static inline void dev_dbg(void *dev, const char *fmt, ...) {}
static inline void dev_err_once(void *dev, const char *fmt, ...) {}