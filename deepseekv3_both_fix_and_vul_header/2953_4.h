#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>
#include <stddef.h>

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock;
struct alg_sock {
    void *private;
};
struct skcipher_ctx {
    void *req;
    unsigned int used;
    unsigned int more;
    void *tsgl;
    struct {
        void *sg;
    } rsgl;
    void *iv;
    int enc;
    void *completion;
};
struct skcipher_sg_list {
    void *sg;
    void *list;
};
struct scatterlist {
    unsigned int length;
};

#define EAGAIN 11
#define EINVAL 22
#define __user

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define list_first_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

static inline struct alg_sock *alg_sk(struct sock *sk) { return (struct alg_sock *)sk; }
static void lock_sock(struct sock *sk) {}
static void release_sock(struct sock *sk) {}
static int skcipher_wait_for_data(struct sock *sk, int flags) { return 0; }
static int af_alg_make_sg(void *rsgl, char *from, int used, int flag) { return 0; }
static void af_alg_free_sg(void *rsgl) {}
static void ablkcipher_request_set_crypt(void *req, void *src, void *dst, unsigned int nbytes, void *iv) {}
static int af_alg_wait_for_completion(int err, void *completion) { return 0; }
static void skcipher_pull_sgl(struct sock *sk, int used) {}
static void skcipher_wmem_wakeup(struct sock *sk) {}
static unsigned int crypto_ablkcipher_blocksize(void *tfm) { return 0; }
static void *crypto_ablkcipher_reqtfm(void *req) { return NULL; }
static int crypto_ablkcipher_encrypt(void *req) { return 0; }
static int crypto_ablkcipher_decrypt(void *req) { return 0; }