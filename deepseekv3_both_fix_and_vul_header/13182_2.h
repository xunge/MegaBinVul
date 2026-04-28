#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct authenticate_message {
    char Signature[8];
    struct {
        uint16_t Length;
        uint16_t MaximumLength;
        uint32_t BufferOffset;
    } NtChallengeResponse;
    struct {
        uint16_t Length;
        uint16_t MaximumLength;
        uint32_t BufferOffset;
    } DomainName;
    struct {
        uint16_t Length;
        uint16_t MaximumLength;
        uint32_t BufferOffset;
    } SessionKey;
};

struct ksmbd_conn {
    void *local_nls;
    struct {
        unsigned int client_flags;
        unsigned char cryptkey[16];
    } ntlmssp;
};

struct ksmbd_session {
    unsigned char sess_key[16];
};

struct ntlmv2_resp {
    unsigned char data[0];
};

struct arc4_ctx {
    unsigned char state[256];
    unsigned char x, y;
};

#define CIFS_ENCPWD_SIZE 16
#define SMB2_NTLMV2_SESSKEY_SIZE 16
#define NTLMSSP_NEGOTIATE_KEY_XCH 0x40000000
#define AUTH 0
#define EINVAL 22
#define ENOMEM 12

#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define u64 uint64_t
#define GFP_KERNEL 0
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void kfree_sensitive(void *ptr) { free(ptr); }
static inline void cifs_arc4_setkey(struct arc4_ctx *ctx, const unsigned char *key, unsigned int keylen) {}
static inline void cifs_arc4_crypt(struct arc4_ctx *ctx, unsigned char *dst, const unsigned char *src, unsigned int len) {}

char *smb_strndup_from_utf16(const char *src, int len, bool uppercase, void *nls);
int ksmbd_debug(int level, const char *fmt, ...);
int ksmbd_auth_ntlmv2(struct ksmbd_conn *conn, struct ksmbd_session *sess, struct ntlmv2_resp *ntlmv2, int len, const char *domain_name, unsigned char *cryptkey);