#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define SMB2_PREAUTH_HASH_SIZE 64
#define SMB2_CLIENT_GUID_SIZE 16
#define SMB2_MAX_BUFFER_SIZE 65536
#define CIFS_NEG_OP 0
#define CIFSSEC_MAY_SIGN 0
#define SMB2_NEGOTIATE_SIGNING_REQUIRED 1
#define SMB2_NEGOTIATE_SIGNING_ENABLED 2
#define SMB20_PROT_ID 0x0202
#define SMB21_PROT_ID 0x0210
#define SMB30_PROT_ID 0x0300
#define SMB302_PROT_ID 0x0302
#define SMB311_PROT_ID 0x0311
#define SMB2_NEGOTIATE 0
#define SMB2_SEC_MODE_FLAGS_ALL 0x0007
#define SMB2_NT_FIND 0x00000001
#define SMB2_LARGE_FILES 0x00000002
#define CIFS_NEGFLAVOR_EXTENDED 2
#define EIO 5
#define EOPNOTSUPP 95

struct smb2_sync_hdr {
    uint64_t SessionId;
};

struct cifs_ses {
    struct TCP_Server_Info *server;
    char *preauth_sha_hash;
    bool sign;
    int sectype;
};

struct smb_rqst {
    struct kvec *rq_iov;
    int rq_nvec;
};

struct smb2_negotiate_req {
    struct smb2_sync_hdr sync_hdr;
    uint16_t Dialects[4];
    uint16_t DialectCount;
    uint16_t SecurityMode;
    uint32_t Capabilities;
    uint8_t ClientGUID[SMB2_CLIENT_GUID_SIZE];
};

struct smb2_negotiate_rsp {
    uint16_t DialectRevision;
    uint16_t SecurityMode;
    uint32_t Capabilities;
    uint32_t MaxTransactSize;
    uint32_t MaxReadSize;
    uint32_t MaxWriteSize;
    uint16_t NegotiateContextCount;
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct TCP_Server_Info {
    uint16_t dialect;
    uint16_t sec_mode;
    uint32_t capabilities;
    uint32_t maxBuf;
    uint32_t max_read;
    uint32_t max_write;
    uint8_t preauth_sha_hash[SMB2_PREAUTH_HASH_SIZE];
    uint8_t client_guid[SMB2_CLIENT_GUID_SIZE];
    bool sec_ntlmssp;
    int negflavor;
    struct smb_version_operations *ops;
    struct smb_version_values *vals;
};

struct smb_version_operations {
    // placeholder for operations
};

struct smb_version_values {
    const char *version_string;
    uint16_t protocol_id;
    uint32_t req_capabilities;
};

extern int cifs_send_recv(unsigned int xid, struct cifs_ses *ses, struct smb_rqst *rqst, int *resp_buftype, int flags, struct kvec *rsp_iov);
extern void cifs_small_buf_release(void *buf);
extern void free_rsp_buf(int resp_buftype, void *buf);
extern int smb2_plain_req_init(int command, void *data, void **req, unsigned int *total_len);
extern char *smb2_get_data_area_len(int *blob_offset, int *blob_length, struct smb2_sync_hdr *hdr);
extern int decode_negTokenInit(char *security_blob, int blob_length, struct TCP_Server_Info *server);
extern int smb311_decode_neg_context(struct smb2_negotiate_rsp *rsp, struct TCP_Server_Info *server, size_t len);
extern int cifs_enable_signing(struct TCP_Server_Info *server, bool sign);
extern void assemble_neg_contexts(struct smb2_negotiate_req *req, unsigned int *total_len);

#define FYI 0
#define VFS 0
#define WARN(cond, fmt, ...) 
#define cifs_dbg(level, fmt, ...) 

extern unsigned int global_secflags;
extern const char SMB3ANY_VERSION_STRING[];
extern const char SMBDEFAULT_VERSION_STRING[];
extern struct smb_version_operations smb21_operations;
extern struct smb_version_operations smb311_operations;
extern struct smb_version_values smb21_values;
extern struct smb_version_values smb311_values;

static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
static inline uint32_t cpu_to_le32(uint32_t x) { return x; }
static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))