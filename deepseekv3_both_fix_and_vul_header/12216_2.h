#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned char u8;
typedef unsigned int u32;

struct sk_msg {
    struct {
        size_t size;
    } sg;
    size_t cork_bytes;
    size_t apply_bytes;
};

struct sock {
    int sk_err;
};

struct tls_context;
struct tls_sw_context_tx {
    struct tls_rec *open_rec;
};
struct tls_rec {
    struct sk_msg msg_plaintext;
};
struct sk_psock {
    int eval;
    bool redir_ingress;
    struct sock *sk_redir;
};

#define MSG_SENDPAGE_NOPOLICY 0
#define __SK_NONE 0
#define __SK_PASS 1
#define __SK_REDIRECT 2
#define __SK_DROP 3
#define EBADMSG 74
#define ENOSPC 28
#define EACCES 13
#define EINPROGRESS 115

static inline struct tls_context *tls_get_ctx(struct sock *sk) { return NULL; }
static inline struct tls_sw_context_tx *tls_sw_ctx_tx(struct tls_context *ctx) { return NULL; }
static inline int tls_push_record(struct sock *sk, int flags, u8 record_type) { return 0; }
static inline int sk_msg_free(struct sock *sk, struct sk_msg *msg) { return 0; }
static inline void tls_free_open_rec(struct sock *sk) {}
static inline struct sk_psock *sk_psock_get(struct sock *sk) { return NULL; }
static inline void sk_psock_put(struct sock *sk, struct sk_psock *psock) {}
static inline int sk_psock_msg_verdict(struct sock *sk, struct sk_psock *psock, struct sk_msg *msg) { return 0; }
static inline void sk_msg_return_zero(struct sock *sk, struct sk_msg *msg, ssize_t bytes) {}
static inline int tcp_bpf_sendmsg_redir(struct sock *sk_redir, bool redir_ingress, struct sk_msg *msg_redir, int send, int flags) { return 0; }
static inline void sk_msg_free_partial(struct sock *sk, struct sk_msg *msg, int send) {}
static inline int sk_msg_free_nocharge(struct sock *sk, struct sk_msg *msg) { return 0; }
static inline void release_sock(struct sock *sk) {}
static inline void lock_sock(struct sock *sk) {}
static inline void sock_put(struct sock *sk) {}
static inline bool sk_msg_full(struct sk_msg *msg) { return false; }
#define likely(x) (x)