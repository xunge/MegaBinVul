#include <stddef.h>
#include <errno.h>

#define CRYPTO_ALG_ASYNC 0
#define GFP_KERNEL 0
#define VFS 0
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define ENOMEM (-1)

struct crypto_skcipher {
    int dummy;
};

struct skcipher_request {
    int dummy;
};

struct scatterlist {
    int dummy;
};

void str_to_key(unsigned char *key, unsigned char *key2);
void cifs_dbg(int level, const char *fmt, ...);
struct crypto_skcipher *crypto_alloc_skcipher(const char *name, int type, int mask);
void crypto_free_skcipher(struct crypto_skcipher *tfm);
int crypto_skcipher_setkey(struct crypto_skcipher *tfm, const unsigned char *key, unsigned int keylen);
struct skcipher_request *skcipher_request_alloc(struct crypto_skcipher *tfm, int flags);
void skcipher_request_free(struct skcipher_request *req);
void sg_init_one(struct scatterlist *sg, const void *addr, unsigned int len);
void skcipher_request_set_callback(struct skcipher_request *req, unsigned int flags, void *callback, void *data);
void skcipher_request_set_crypt(struct skcipher_request *req, struct scatterlist *src, struct scatterlist *dst, unsigned int cryptlen, void *iv);
int crypto_skcipher_encrypt(struct skcipher_request *req);