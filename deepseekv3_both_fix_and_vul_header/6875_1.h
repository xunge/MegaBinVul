#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef uint64_t u64;

struct ksmbd_work {
    void *request_buf;
    void *response_buf;
    void *sess;
};

struct smb2_write_req {
    uint32_t Length;
    uint64_t VolatileFileId;
    uint16_t DataOffset;
    uint8_t Buffer[1];
    struct {
        uint8_t ProtocolId[4];
    } hdr;
};

struct smb2_write_rsp {
    uint16_t StructureSize;
    uint16_t DataOffset;
    uint16_t Reserved;
    uint32_t DataLength;
    uint32_t DataRemaining;
    uint16_t Reserved2;
    struct {
        uint32_t Status;
    } hdr;
};

struct ksmbd_rpc_command {
    int flags;
};

#define noinline __attribute__((noinline))
#define le32_to_cpu(x) (x)
#define le16_to_cpu(x) (x)
#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)
#define pr_err(fmt, ...)
#define EINVAL 1
#define EOPNOTSUPP 2
#define STATUS_NOT_SUPPORTED 0
#define STATUS_INVALID_HANDLE 0
#define KSMBD_RPC_ENOTIMPLEMENTED 0
#define KSMBD_RPC_OK 0

static inline void *smb2_get_msg(void *buf) { return buf; }
static inline size_t get_rfc1002_len(void *buf) { return 0; }
static inline void kvfree(void *obj) {}
static inline void smb2_set_err_rsp(struct ksmbd_work *work) {}
static inline void inc_rfc1001_len(void *buf, int len) {}
static inline struct ksmbd_rpc_command *ksmbd_rpc_write(void *sess, u64 id, char *buf, size_t len) { return NULL; }