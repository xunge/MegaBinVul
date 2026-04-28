#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define AUTH 0
#define SMB2_NTLMV2_SESSKEY_SIZE 16
#define u64 uint64_t

struct authenticate_message {
    char Signature[8];
    uint32_t NegotiateFlags;
    struct {
        uint16_t Length;
        uint16_t MaximumLength;
        uint32_t BufferOffset;
    } LmChallengeResponse;
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
        unsigned int cryptkey;
        unsigned int client_flags;
    } ntlmssp;
};

struct ksmbd_session {
    uint8_t sess_key[SMB2_NTLMV2_SESSKEY_SIZE];
};

struct ntlmv2_resp {
    uint8_t response[16];
    uint8_t challenge[8];
    uint64_t timestamp;
    uint8_t client_challenge[8];
    uint8_t target_info[0];
};

struct arc4_ctx {
    uint32_t S[256];
    uint32_t x, y;
};

#define CIFS_AUTH_RESP_SIZE 24
#define CIFS_ENCPWD_SIZE 16
#define NTLMSSP_NEGOTIATE_EXTENDED_SEC 0x00080000
#define NTLMSSP_NEGOTIATE_KEY_XCH 0x40000000
#define EINVAL 22
#define ENOMEM 12

#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)

#define GFP_KERNEL 0
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void kfree_sensitive(void *ptr) { free(ptr); }
static inline void memzero_explicit(void *s, size_t n) { memset(s, 0, n); }

static inline void cifs_arc4_setkey(struct arc4_ctx *ctx, const uint8_t *in_key, unsigned int key_len) {}
static inline void cifs_arc4_crypt(struct arc4_ctx *ctx, uint8_t *out, const uint8_t *in, unsigned int len) {}

static inline char *smb_strndup_from_utf16(const char *src, int len, bool is_unicode, void *nls) { return NULL; }
static inline void ksmbd_debug(int type, const char *fmt, ...) {}
static inline int ksmbd_auth_ntlm(struct ksmbd_session *sess, char *ntlm, unsigned int key) { return 0; }
static inline int ksmbd_auth_ntlmv2(struct ksmbd_conn *conn, struct ksmbd_session *sess,
                                   struct ntlmv2_resp *resp, int len, char *domain, unsigned int key) { return 0; }
static inline int __ksmbd_auth_ntlmv2(struct ksmbd_session *sess, char *lm, char *nt, unsigned int key) { return 0; }

#define LINUX_VERSION_CODE 0
#define KERNEL_VERSION(a,b,c) 0