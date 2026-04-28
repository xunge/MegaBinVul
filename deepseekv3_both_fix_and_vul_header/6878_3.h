#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

typedef int64_t loff_t;
typedef uint64_t u64;
typedef int64_t ssize_t;

#define SMB 0
#define KSMBD_TREE_CONN_FLAG_WRITABLE 0

struct conn_vals {
    unsigned int max_write_size;
};

struct tcon {
    void *share_conf;
};

struct conn {
    struct conn_vals *vals;
};

struct ksmbd_work {
    struct conn *conn;
    struct tcon *tcon;
    void *request_buf;
    void *response_buf;
};

struct smb2_write_req {
    uint64_t Offset;
    uint32_t Length;
    uint32_t RemainingBytes;
    uint16_t WriteChannelInfoOffset;
    uint16_t DataOffset;
    uint32_t Flags;
    uint32_t Channel;
    uint32_t WriteChannelInfoLength;
    uint32_t VolatileFileId;
    uint32_t PersistentFileId;
    struct {
        char ProtocolId;
    } hdr;
    char Buffer;
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

struct path {
    void *dentry;
};

struct file {
    struct path f_path;
};

struct ksmbd_file {
    uint32_t daccess;
    struct file *filp;
};

struct smb2_buffer_desc_v1;

#define WORK_BUFFERS(work, req, rsp) \
    req = (void*)0; \
    rsp = (void*)0

#define le64_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define le16_to_cpu(x) (x)
#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)

#define KSMBD_SHARE_FLAG_PIPE 0
#define SMB2_CHANNEL_RDMA_V1 0
#define SMB2_CHANNEL_RDMA_V1_INVALIDATE 0
#define EINVAL 22
#define EACCES 13
#define ENOENT 2
#define ENOSPC 28
#define EFBIG 27
#define EAGAIN 11
#define ESHARE 0
#define FILE_WRITE_DATA_LE 0
#define FILE_READ_ATTRIBUTES_LE 0
#define SMB2_WRITEFLAG_WRITE_THROUGH 0
#define STATUS_FILE_LOCK_CONFLICT 0
#define STATUS_DISK_FULL 0
#define STATUS_FILE_CLOSED 0
#define STATUS_ACCESS_DENIED 0
#define STATUS_SHARING_VIOLATION 0
#define STATUS_INVALID_PARAMETER 0
#define STATUS_INVALID_HANDLE 0

int smb2_write_pipe(struct ksmbd_work *work);
int smb2_set_remote_key_for_rdma(struct ksmbd_work *work, struct smb2_buffer_desc_v1 *desc, int channel, int length);
int test_share_config_flag(void *conf, int flag);
int test_tree_conn_flag(void *tcon, int flag);
struct ksmbd_file *ksmbd_lookup_fd_slow(struct ksmbd_work *work, int volatile_id, int persistent_id);
int ksmbd_vfs_write(struct ksmbd_work *work, struct ksmbd_file *fp, char *buf, size_t len, loff_t *offset, bool writethrough, ssize_t *nbytes);
ssize_t smb2_write_rdma_channel(struct ksmbd_work *work, struct smb2_write_req *req, struct ksmbd_file *fp, loff_t offset, size_t length, bool writethrough);
void ksmbd_fd_put(struct ksmbd_work *work, struct ksmbd_file *fp);
void smb2_set_err_rsp(struct ksmbd_work *work);
unsigned int get_smbd_max_read_write_size(void);
unsigned int get_rfc1002_len(void *buf);
void inc_rfc1001_len(void *buf, int len);
void ksmbd_debug(int type, const char *fmt, ...);
void pr_err(const char *fmt, ...);