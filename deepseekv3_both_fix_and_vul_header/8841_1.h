#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include <time.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

struct ssh;
struct sshbuf;
struct session_state {
    uint32_t remote_protocol_flags;
    uint64_t rekey_limit;
    uint32_t rekey_interval;
    struct {
        uint32_t seqnr;
        uint64_t blocks;
        uint32_t packets;
        uint64_t bytes;
    } p_send, p_read;
    void *send_context;
    void *receive_context;
    struct sshbuf *input;
    struct sshbuf *output;
    time_t rekey_time;
};

struct kex;
struct ssh {
    struct session_state *state;
    struct kex *kex;
};

#define MODE_IN 0
#define MODE_OUT 1
#define SSH_ERR_KEY_UNKNOWN_CIPHER -1
#define SSH_ERR_INVALID_FORMAT -2
#define NULL ((void*)0)

extern int compat20;
extern time_t monotime(void);
extern int cipher_get_keyiv_len(void *);
extern int cipher_set_keyiv(void *, const u_char *);
extern int cipher_get_keycontext(void *, void *);
extern void cipher_set_keycontext(void *, const u_char *);
extern int ssh_packet_set_encryption_key(struct ssh *, const u_char *, size_t, int);
extern int kex_from_blob(struct sshbuf *, struct kex **);
extern int newkeys_from_blob(struct sshbuf *, struct ssh *, int);
extern int ssh_set_newkeys(struct ssh *, int);
extern int ssh_packet_set_compress_state(struct ssh *, struct sshbuf *);
extern int ssh_packet_set_postauth(struct ssh *);
extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
extern int sshbuf_get_string_direct(struct sshbuf *, const u_char **, size_t *);
extern int sshbuf_put(struct sshbuf *, const void *, size_t);
extern size_t sshbuf_len(struct sshbuf *);
extern void sshbuf_reset(struct sshbuf *);
extern void debug3(const char *, ...);