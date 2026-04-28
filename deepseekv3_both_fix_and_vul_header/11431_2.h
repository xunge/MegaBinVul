#include <sys/socket.h>
#include <stdlib.h>

struct sock {
    // dummy definition
};

struct alg_sock {
    void *private;
    struct sock *parent;
    // other members
};

struct af_alg_ctx {
    unsigned int used;
    void *iv;
    size_t len;
    // other members
};

struct aead_tfm {
    struct crypto_aead *aead;
    // other members
};

struct crypto_aead {
    // dummy definition
};

static inline struct alg_sock *alg_sk(struct sock *sk) { return (struct alg_sock *)sk; }
static inline unsigned int crypto_aead_ivsize(struct crypto_aead *tfm) { return 0; }
static inline void af_alg_pull_tsgl(struct sock *sk, unsigned int used, void *buf, int flags) {}
static inline void crypto_put_default_null_skcipher2(void) {}
static inline void sock_kzfree_s(struct sock *sk, void *mem, unsigned int size) {}
static inline void sock_kfree_s(struct sock *sk, void *mem, size_t size) {}
static inline void af_alg_release_parent(struct sock *sk) {}