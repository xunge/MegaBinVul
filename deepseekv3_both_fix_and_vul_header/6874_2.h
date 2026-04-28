#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

typedef int64_t loff_t;
typedef int64_t ssize_t;
typedef uint64_t u64;

#define SMB 0
#define EINVAL 22
#define EACCES 13
#define ENOENT 2
#define EAGAIN 11
#define ENOSPC 28
#define EFBIG 27
#define ESHARE 1000

#define SMB2_CHANNEL_RDMA_V1 0x0001
#define SMB2_CHANNEL_RDMA_V1_INVALIDATE 0x0002
#define SMB2_WRITEFLAG_WRITE_THROUGH 0x00000001

#define FILE_WRITE_DATA_LE 0x00000002
#define FILE_READ_ATTRIBUTES_LE 0x00000080

#define KSMBD_SHARE_FLAG_PIPE 0x00000001
#define KSMBD_TREE_CONN_FLAG_WRITABLE 0x00000001

#define STATUS_FILE_LOCK_CONFLICT 0xC0000055
#define STATUS_DISK_FULL 0xC000007F
#define STATUS_FILE_CLOSED 0xC0000128
#define STATUS_ACCESS_DENIED 0xC0000022
#define STATUS_SHARING_VIOLATION 0xC0000043
#define STATUS_INVALID_PARAMETER 0xC000000D
#define STATUS_INVALID_HANDLE 0xC0000008

struct ksmbd_work {
    void *request_buf;
    void *response_buf;
    struct {
        struct {
            struct {
                uint32_t max_write_size;
            } *vals;
        } *conn;
        struct {
            struct {
                unsigned long share_conf;
            } *tcon;
        };
    };
};

struct smb2_write_req {
    uint16_t Channel;
    uint16_t WriteChannelInfoOffset;
    uint32_t Length;
    uint16_t DataOffset;
    uint32_t Flags;
    uint64_t Offset;
    uint32_t RemainingBytes;
    uint16_t VolatileFileId;
    uint16_t PersistentFileId;
    uint16_t WriteChannelInfoLength;
    struct {
        uint8_t ProtocolId[4];
    } hdr;
    uint8_t Buffer[1];
};

struct smb2_write_rsp {
    uint16_t StructureSize;
    uint16_t DataOffset;
    uint32_t DataLength;
    uint32_t DataRemaining;
    uint32_t Reserved;
    uint32_t Reserved2;
    struct {
        uint32_t Status;
    } hdr;
};

struct ksmbd_file {
    uint32_t daccess;
    struct {
        struct {
            struct {
                void *dentry;
            } f_path;
        } *filp;
    };
};

#define WORK_BUFFERS(work, req, rsp) \
    req = (struct smb2_write_req *)work->request_buf; \
    rsp = (struct smb2_write_rsp *)work->response_buf

static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint64_t le64_to_cpu(uint64_t x) { return x; }
static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
static inline uint32_t cpu_to_le32(uint32_t x) { return x; }

int test_share_config_flag(unsigned long share_conf, int flag);
int ksmbd_debug(int level, const char *fmt, ...);
int smb2_write_pipe(struct ksmbd_work *work);
int test_tree_conn_flag(void *tcon, int flag);
struct ksmbd_file *ksmbd_lookup_fd_slow(struct ksmbd_work *work, uint16_t vfid, uint16_t pfid);
int ksmbd_vfs_write(struct ksmbd_work *work, struct ksmbd_file *fp, char *buf, size_t len, loff_t *off, bool wt, ssize_t *nbytes);
ssize_t smb2_write_rdma_channel(struct ksmbd_work *work, struct smb2_write_req *req, struct ksmbd_file *fp, loff_t offset, uint32_t rem_bytes, bool wt);
void inc_rfc1001_len(void *buf, int len);
void ksmbd_fd_put(struct ksmbd_work *work, struct ksmbd_file *fp);
void smb2_set_err_rsp(struct ksmbd_work *work);
int get_rfc1002_len(void *buf);
int pr_err(const char *fmt, ...);
int smb2_set_remote_key_for_rdma(struct ksmbd_work *work, void *desc, uint16_t channel, uint16_t offset, uint16_t length);