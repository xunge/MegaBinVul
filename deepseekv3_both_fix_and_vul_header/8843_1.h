#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

struct ssh {
    struct session_state *state;
    struct kex *kex;
};

struct sshbuf;

struct session_state {
    void *receive_context;
    void *send_context;
    uint32_t remote_protocol_flags;
    uint8_t *ssh1_key;
    size_t ssh1_keylen;
    uint64_t rekey_limit;
    uint32_t rekey_interval;
    struct {
        uint32_t seqnr;
        uint64_t blocks;
        uint32_t packets;
        uint64_t bytes;
    } p_send, p_read;
    struct sshbuf *input;
    struct sshbuf *output;
};

#define MODE_IN 0
#define MODE_OUT 1
#define SSH_ERR_INTERNAL_ERROR -1

extern int compat20;

int cipher_ctx_get_number(void *ctx);
size_t cipher_get_keyiv_len(void *ctx);
int cipher_get_keyiv(void *ctx, uint8_t *iv, size_t len);
size_t cipher_get_keycontext(void *ctx, uint8_t *keycontext);
int kex_to_blob(struct sshbuf *m, struct kex *kex);
int newkeys_to_blob(struct sshbuf *m, struct ssh *ssh, int mode);
int ssh_packet_get_compress_state(struct sshbuf *m, struct ssh *ssh);
int sshbuf_put_u32(struct sshbuf *m, uint32_t val);
int sshbuf_put_u64(struct sshbuf *m, uint64_t val);
int sshbuf_put_string(struct sshbuf *m, const void *v, size_t len);
int sshbuf_put_stringb(struct sshbuf *m, const struct sshbuf *v);
int sshbuf_reserve(struct sshbuf *m, size_t len, uint8_t **dpp);