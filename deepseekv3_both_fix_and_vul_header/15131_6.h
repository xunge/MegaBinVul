#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <wchar.h>

typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint8_t __u8;
typedef __u16 __le16;

#define MAX_TREE_SIZE 256
#define CIFS_SESS_KEY_SIZE 16
#define SMB_COM_TREE_CONNECT_ANDX 0x75
#define SECMODE_USER 0x01
#define SECMODE_PW_ENCRYPT 0x02
#define SECMODE_SIGN_REQUIRED 0x04
#define SECMODE_SIGN_ENABLED 0x08
#define CAP_UNICODE 0x00000004
#define CAP_STATUS32 0x00000040
#define CAP_DFS 0x00001000
#define SMBFLG2_SECURITY_SIGNATURE 0x0004
#define SMBFLG2_ERR_STATUS 0x4000
#define SMBFLG2_DFS 0x1000
#define SMBFLG2_UNICODE 0x8000
#define CIFSSEC_MAY_LANMAN 0x00002
#define TCON_EXTENDED_SECINFO 0x0008
#define CifsGood 0
#define GFP_KERNEL 0
#define CIFS_STD_OP 0

struct cifsSesInfo {
    struct cifs_server *server;
    __u32 Suid;
    __u32 capabilities;
    __u32 ipc_tid;
};

struct cifsTconInfo {
    char *password;
    char *nativeFileSystem;
    char treeName[MAX_TREE_SIZE];
    __u16 tid;
    __u16 Flags;
    __u8 tidStatus;
    bool need_reconnect;
    bool ipc;
};

struct nls_table;

struct smb_hdr {
    __u8 Command;
    __u8 WordCount;
    __u16 Tid;
    __u16 Mid;
    __u16 Uid;
    __u16 Flags2;
    __u32 smb_buf_length;
};

struct cifs_server {
    __u8 secMode;
    __u8 secType;
    char *cryptKey;
};

struct TCONX_REQ {
    __u8 AndXCommand;
    __u8 Flags;
    __le16 PasswordLength;
    unsigned char Password[1];
    struct smb_hdr hdr;
    __le16 ByteCount;
};

struct TCONX_RSP {
    __le16 OptionalSupport;
};

static inline __u16 cpu_to_le16(__u16 val) { return val; }
static inline __u16 le16_to_cpu(__u16 val) { return val; }

extern struct smb_hdr *cifs_buf_get(void);
extern void cifs_buf_release(struct smb_hdr *);
extern int SendReceive(unsigned int, struct cifsSesInfo *, struct smb_hdr *, struct smb_hdr *, int *, int);
extern unsigned int GetNextMid(struct cifs_server *);
extern void header_assemble(struct smb_hdr *, __u8, __u16, __u8);
extern void SMBNTencrypt(const char *, const char *, unsigned char *);
extern void calc_lanman_hash(const char *, const char *, bool, unsigned char *);
extern int cifs_strtoUCS(__le16 *, const char *, int, const struct nls_table *);
extern int UniStrnlen(const wchar_t *, int);
extern void cifs_strfromUCS_le(char *, const __le16 *, int, const struct nls_table *);
extern unsigned char *pByteArea(struct smb_hdr *);
#define BCC(x) (x->WordCount * 2 + sizeof(struct smb_hdr))
#define cFYI(level, args) do {} while (0)

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }

typedef struct TCONX_REQ TCONX_REQ;
typedef struct TCONX_RSP TCONX_RSP;