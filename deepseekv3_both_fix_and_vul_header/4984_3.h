#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint16_t __le16;
typedef uint32_t __le32;

struct smb2_negotiate_ops {
    int (*validate_negotiate)(const unsigned int xid, struct cifs_tcon *tcon);
};

struct TCP_Server_Info {
    struct smb2_negotiate_ops *ops;
    uint32_t sec_mode;
};

struct cifs_ses {
    struct TCP_Server_Info *server;
    uint32_t Suid;
    uint32_t ipc_tid;
};

struct cifs_tcon {
    bool bad_network_name;
    bool need_reconnect;
    bool ipc;
    bool print;
    uint32_t share_flags;
    uint32_t capabilities;
    uint32_t maximal_access;
    uint32_t tidStatus;
    uint32_t tid;
    char treeName[256];
    struct cifs_ses *ses;
};

struct nls_table;

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct smb2_tree_connect_req {
    struct {
        __le32 SessionId;
        __le16 Flags;
        __le16 TreeId;
    } hdr;
    __le16 PathOffset;
    __le16 PathLength;
    uint8_t Buffer[0];
};

struct smb2_tree_connect_rsp {
    struct {
        __le32 SessionId;
        __le16 Flags;
        __le16 TreeId;
        __le32 Status;
    } hdr;
    uint8_t ShareType;
    __le32 ShareFlags;
    __le32 Capabilities;
    __le32 MaximalAccess;
};

#define MAX_SHARENAME_LENGTH 256
#define SMB2_TREE_CONNECT 0x0009
#define SMB2_SHARE_TYPE_DISK 0x01
#define SMB2_SHARE_TYPE_PIPE 0x02
#define SMB2_SHARE_TYPE_PRINT 0x03
#define SMB2_SHARE_CAP_DFS 0x08
#define SHI1005_FLAGS_DFS 0x00000001
#define STATUS_BAD_NETWORK_NAME 0xC00000CC
#define CifsGood 0
#define SMB2_TREE_CONNECT_HE 0
#define SMB2_FLAGS_SIGNED 0x0004
#define SECMODE_SIGN_REQUIRED 0x0002
#define FYI 0
#define VFS 0

#define ENOMEM 12
#define EIO 5
#define ENOENT 2
#define EINVAL 22
#define EOPNOTSUPP 95

#define GFP_KERNEL 0

static inline __le16 cpu_to_le16(uint16_t x) { return x; }
static inline __le32 cpu_to_le32(uint32_t x) { return x; }
static inline uint32_t le32_to_cpu(__le32 x) { return x; }

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
size_t get_rfc1002_length(void *req);
void inc_rfc1001_len(void *req, size_t len);
int cifs_strtoUTF16(__le16 *target, const char *source, int maxlen, const struct nls_table *cp);
void cifs_dbg(int level, const char *fmt, ...);
int small_smb2_init(int smb2_command, struct cifs_tcon *tcon, void **request_buf);
int SendReceive2(const unsigned int xid, struct cifs_ses *ses, struct kvec *iov, int n_vec, int *resp_buftype, int flags);
void free_rsp_buf(int resp_buftype, void *rsp);
void init_copy_chunk_defaults(struct cifs_tcon *tcon);
void cifs_stats_fail_inc(struct cifs_tcon *tcon, int stat_id);
size_t strlcpy(char *dest, const char *src, size_t size);