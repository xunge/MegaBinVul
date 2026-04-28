#include <stdint.h>
#include <string.h>

#define CEPH_PREAMBLE_LEN 64
#define CEPH_CRC_LEN 4
#define CEPH_FRAME_MAX_SEGMENT_COUNT 4
#define CEPH_MSG_MAX_CONTROL_LEN 4096
#define CEPH_MSG_MAX_FRONT_LEN 65536
#define CEPH_MSG_MAX_MIDDLE_LEN 524288
#define CEPH_MSG_MAX_DATA_LEN (512 * 1024 * 1024)

#define EBADMSG 74
#define EINVAL 22

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct ceph_frame_desc {
    u8 fd_tag;
    u8 fd_seg_cnt;
    u32 fd_lens[CEPH_FRAME_MAX_SEGMENT_COUNT];
    u16 fd_aligns[CEPH_FRAME_MAX_SEGMENT_COUNT];
};

static u32 crc32c(u32 crc, const void *buf, size_t len);
static u32 get_unaligned_le32(const void *p);
static u8 ceph_decode_8(void **p);
static u16 ceph_decode_16(void **p);
static u32 ceph_decode_32(void **p);
static void pr_err(const char *fmt, ...);