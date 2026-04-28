#include <stddef.h>
#include <sys/socket.h>
#include <sys/uio.h>

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock;
struct alg_sock {
    void *private;
};
struct hash_ctx {
    void *req;
    unsigned char *result;
    unsigned int more;
    void *completion;
};
struct ahash_request;
struct completion;
struct crypto_ahash;

unsigned int crypto_ahash_digestsize(struct crypto_ahash *tfm);
struct crypto_ahash *crypto_ahash_reqtfm(struct ahash_request *req);
int af_alg_wait_for_completion(int err, void *completion);
int crypto_ahash_final(struct ahash_request *req);
void ahash_request_set_crypt(struct ahash_request *req, void *src, void *result, unsigned int len);
void lock_sock(struct sock *sk);
void release_sock(struct sock *sk);
int memcpy_toiovec(struct iovec *iov, unsigned char *kdata, int len);
struct alg_sock *alg_sk(struct sock *sk);