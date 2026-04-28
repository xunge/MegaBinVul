#include <stdbool.h>
#include <stddef.h>

struct socket {
    struct sock *sk;
};

struct sock {
};

struct alg_sock {
    void *private;
    void *parent;
};

struct ahash_request {
    // 添加必要的成员
    void *base;
    void *priv;
};

struct hash_ctx {
    struct ahash_request req;
    bool more;
};

static inline struct alg_sock *alg_sk(struct sock *sk) { return (struct alg_sock *)sk; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int af_alg_accept(void *parent, struct socket *newsock) { return 0; }
static inline void sock_orphan(struct sock *sk) {}
static inline void sock_put(struct sock *sk) {}
static inline int crypto_ahash_export(struct ahash_request *req, char *state) { return 0; }
static inline int crypto_ahash_import(struct ahash_request *req, const char *state) { return 0; }
static inline int crypto_ahash_statesize(void *tfm) { return 0; }
static inline void *crypto_ahash_reqtfm(struct ahash_request *req) { return NULL; }