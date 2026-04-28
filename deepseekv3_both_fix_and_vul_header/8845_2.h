#include <stdint.h>
#include <stddef.h>

#define MODE_OUT 0
#define SSH_ERR_INTERNAL_ERROR -1
#define SSH_ERR_ALLOC_FAIL -2

struct sshbuf;
struct sshcipher_ctx;

struct sshenc {
    const char *name;
    void *cipher;
    uint32_t enabled;
    uint32_t block_size;
    uint8_t *key;
    uint32_t key_len;
    uint8_t *iv;
    uint32_t iv_len;
};

struct sshmac {
    const char *name;
    uint32_t enabled;
    uint8_t *key;
    uint32_t key_len;
};

struct sshcomp {
    uint32_t type;
    uint32_t enabled;
    const char *name;
};

struct newkeys {
    struct sshenc enc;
    struct sshmac mac;
    struct sshcomp comp;
};

struct ssh {
    struct {
        struct newkeys *newkeys[2];
        struct sshcipher_ctx *send_context;
        struct sshcipher_ctx *receive_context;
    } *state;
};

int cipher_get_keyiv(struct sshcipher_ctx *cc, uint8_t *iv, uint32_t iv_len);
int cipher_authlen(void *cipher);
struct sshbuf *sshbuf_new(void);
int sshbuf_put_cstring(struct sshbuf *buf, const char *v);
int sshbuf_put(struct sshbuf *buf, const void *v, size_t len);
int sshbuf_put_u32(struct sshbuf *buf, uint32_t v);
int sshbuf_put_string(struct sshbuf *buf, const void *v, uint32_t len);
int sshbuf_put_stringb(struct sshbuf *buf, struct sshbuf *v);
void sshbuf_free(struct sshbuf *buf);