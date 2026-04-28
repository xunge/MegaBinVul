#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define SMB311_PROT_ID 0x0311
#define SMB302_PROT_ID 0x0302
#define SMB30_PROT_ID 0x0300
#define SMB21_PROT_ID 0x0210
#define SMB2X_PROT_ID 0x02FF
#define BAD_PROT_ID 0xFFFF

#define STATUS_INVALID_PARAMETER 0xC000000D
#define STATUS_NOT_SUPPORTED 0xC00000BB
#define STATUS_SUCCESS 0x00000000

#define SMB2_NEGOTIATE_SIGNING_ENABLED_LE 0x0001
#define SMB2_NEGOTIATE_SIGNING_REQUIRED_LE 0x0002

#define KSMBD_CONFIG_OPT_AUTO 0
#define KSMBD_CONFIG_OPT_DISABLED 1
#define KSMBD_CONFIG_OPT_MANDATORY 2

#define SMB 1
#define OFFSET_OF_NEG_CONTEXT 128
#define AUTH_GSS_LENGTH 64
#define SMB2_CLIENT_GUID_SIZE 16
#define GFP_KERNEL 0

#define EINVAL 22
#define ENOMEM 12

typedef uint16_t __le16;
typedef uint32_t __le32;

struct ksmbd_work {
    struct ksmbd_conn *conn;
    void *request_buf;
    void *response_buf;
    int send_no_response;
};

struct ksmbd_conn_vals {
    uint32_t capabilities;
    uint32_t max_trans_size;
    uint32_t max_read_size;
    uint32_t max_write_size;
};

struct ksmbd_conn {
    bool need_neg;
    uint16_t dialect;
    uint32_t cli_cap;
    struct preauth_integrity_info *preauth_info;
    struct ksmbd_conn_vals *vals;
    uint16_t connection_type;
    unsigned char ClientGUID[SMB2_CLIENT_GUID_SIZE];
    uint16_t cli_sec_mode;
    bool use_spnego;
    bool sign;
    uint16_t srv_sec_mode;
};

struct smb2_negotiate_req {
    uint16_t StructureSize;
    uint16_t DialectCount;
    uint16_t SecurityMode;
    uint16_t Reserved;
    uint32_t Capabilities;
    unsigned char ClientGUID[SMB2_CLIENT_GUID_SIZE];
    uint32_t NegotiateContextOffset;
    uint16_t NegotiateContextCount;
    uint16_t Reserved2;
    __le16 Dialects[1];
};

struct smb2_negotiate_rsp {
    struct {
        uint32_t Status;
    } hdr;
    uint16_t StructureSize;
    uint16_t SecurityMode;
    uint16_t DialectRevision;
    uint16_t NegotiateContextCount;
    uint32_t ServerGuid[4];
    uint32_t Capabilities;
    uint32_t MaxTransactSize;
    uint32_t MaxReadSize;
    uint32_t MaxWriteSize;
    uint64_t SystemTime;
    uint64_t ServerStartTime;
    uint16_t SecurityBufferOffset;
    uint16_t SecurityBufferLength;
    uint32_t NegotiateContextOffset;
    unsigned char Buffer[1];
    unsigned char ServerGUID[SMB2_CLIENT_GUID_SIZE];
};

struct smb2_hdr {
    uint32_t Status;
};

struct preauth_integrity_info {
    unsigned char Preauth_HashValue[32];
};

struct server_conf {
    int signing;
    bool enforced_signing;
};

extern struct server_conf server_conf;

static inline uint32_t le32_to_cpu(uint32_t val) { return val; }
static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline uint32_t cpu_to_le32(uint32_t val) { return val; }
static inline uint16_t cpu_to_le16(uint16_t val) { return val; }
static inline uint64_t cpu_to_le64(uint64_t val) { return val; }

extern int ksmbd_conn_good(struct ksmbd_work *work);
extern void ksmbd_debug(int type, const char *fmt, ...);
extern void pr_err(const char *fmt, ...);
extern uint64_t ksmbd_systime(void);
extern void ksmbd_copy_gss_neg_header(char *buf);
extern void ksmbd_conn_set_need_negotiate(struct ksmbd_work *work);
extern void smb2_set_err_rsp(struct ksmbd_work *work);
extern void *smb2_get_msg(void *buf);
extern unsigned int get_rfc1002_len(void *buf);
extern void inc_rfc1001_len(void *buf, unsigned int len);
extern __le32 deassemble_neg_contexts(struct ksmbd_conn *conn, struct smb2_negotiate_req *req, unsigned int len);
extern void assemble_neg_contexts(struct ksmbd_conn *conn, struct smb2_negotiate_rsp *rsp, void *buf);
extern int init_smb3_11_server(struct ksmbd_conn *conn);
extern int init_smb3_02_server(struct ksmbd_conn *conn);
extern int init_smb3_0_server(struct ksmbd_conn *conn);
extern int init_smb2_1_server(struct ksmbd_conn *conn);
extern void ksmbd_gen_preauth_integrity_hash(struct ksmbd_conn *conn, void *buf, void *hash);
extern void *kzalloc(size_t size, int flags);