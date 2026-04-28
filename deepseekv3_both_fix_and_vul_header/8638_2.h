#include <stdbool.h>
#include <stdatomic.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

struct completion {
    unsigned int done;
};

struct sock {
    void (*sk_destruct)(struct sock *);
};

struct crypto_skcipher {
    unsigned int dummy;
};

struct skcipher_request {
    unsigned int dummy;
};

struct skcipher_ctx {
    unsigned char *iv;
    struct list_head tsgl;
    unsigned int len;
    unsigned int used;
    unsigned int more;
    unsigned int merge;
    unsigned int enc;
    atomic_int inflight;
    struct completion completion;
    struct skcipher_request req;
};

struct alg_sock {
    void *private;
};

struct skcipher_tfm {
    struct crypto_skcipher *skcipher;
    bool has_key;
};

#define GFP_KERNEL 0
#define ENOKEY 1
#define ENOMEM 2
#define CRYPTO_TFM_REQ_MAY_BACKLOG 0

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void atomic_set(atomic_int *v, int i) {
    *v = i;
}

static void skcipher_sock_destruct(struct sock *sk) {}
static void af_alg_complete(void *req, int err) {}
static void af_alg_init_completion(struct completion *completion) {}
static struct alg_sock *alg_sk(struct sock *sk) { return 0; }
static void *sock_kmalloc(struct sock *sk, unsigned int len, int flags) { return 0; }
static void sock_kfree_s(struct sock *sk, void *mem, unsigned int len) {}
static unsigned int crypto_skcipher_reqsize(struct crypto_skcipher *tfm) { return 0; }
static unsigned int crypto_skcipher_ivsize(struct crypto_skcipher *tfm) { return 0; }
static void skcipher_request_set_tfm(struct skcipher_request *req, struct crypto_skcipher *tfm) {}
static void skcipher_request_set_callback(struct skcipher_request *req, unsigned int flags, void (*complete)(void *req, int err), void *data) {}