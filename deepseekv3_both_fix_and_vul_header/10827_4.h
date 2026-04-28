#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef uint16_t u16;
typedef uint16_t __le16;
typedef uint32_t u32;
typedef uint32_t __u32;
typedef uint8_t u8;

#define NTLMSSP_SIGNATURE "NTLMSSP"
#define NtLmAuthenticate 3
#define NTLMSSP_NEGOTIATE_56 0x80000000
#define NTLMSSP_REQUEST_TARGET 0x00000004
#define NTLMSSP_NEGOTIATE_TARGET_INFO 0x00800000
#define NTLMSSP_NEGOTIATE_128 0x20000000
#define NTLMSSP_NEGOTIATE_UNICODE 0x00000001
#define NTLMSSP_NEGOTIATE_NTLM 0x00000200
#define NTLMSSP_NEGOTIATE_EXTENDED_SEC 0x00080000
#define NTLMSSP_NEGOTIATE_SEAL 0x00000020
#define NTLMSSP_NEGOTIATE_SIGN 0x00000010
#define NTLMSSP_NEGOTIATE_KEY_XCH 0x00000040
#define CIFS_SESS_KEY_SIZE 16
#define CIFS_MAX_DOMAINNAME_LEN 256
#define CIFS_MAX_USERNAME_LEN 256
#define CIFS_CPHTXT_SIZE 16
#define VFS 1
#define GFP_KERNEL 0

struct SEC_BUFFER {
    u16 Length;
    u16 MaximumLength;
    u32 BufferOffset;
};

struct AUTHENTICATE_MESSAGE {
    u8 Signature[8];
    u32 MessageType;
    u32 NegotiateFlags;
    struct SEC_BUFFER LmChallengeResponse;
    struct SEC_BUFFER NtChallengeResponse;
    struct SEC_BUFFER DomainName;
    struct SEC_BUFFER UserName;
    struct SEC_BUFFER WorkstationName;
    struct SEC_BUFFER SessionKey;
};

struct auth_key {
    unsigned char *response;
    u16 len;
};

struct ntlmssp_auth {
    u32 server_flags;
    unsigned char ciphertext[CIFS_CPHTXT_SIZE];
    int sesskey_per_smbsess;
};

struct TCP_Server_Info {
    int sign;
    int session_estab;
};

struct cifs_ses {
    struct TCP_Server_Info *server;
    char *user_name;
    char *domainName;
    struct ntlmssp_auth *ntlmssp;
    struct auth_key auth_key;
};

struct nls_table;

static inline u16 cpu_to_le16(u16 x) { return x; }
static inline u32 cpu_to_le32(u32 x) { return x; }

void *kmalloc(size_t size, int flags);
int setup_ntlmv2_rsp(struct cifs_ses *ses, const struct nls_table *nls_cp);
int cifs_strtoUTF16(__le16 *dest, const char *src, int maxlen, const struct nls_table *cp);
int calc_seckey(struct cifs_ses *ses);
size_t size_of_ntlmssp_blob(struct cifs_ses *ses);
void cifs_dbg(int level, const char *fmt, ...);

typedef struct AUTHENTICATE_MESSAGE AUTHENTICATE_MESSAGE;