#include <linux/types.h>

struct crypto_tfm {
    struct {
        struct {
            void *cra_type;
        } *__crt_alg;
    };
};

struct crypto_skcipher {
    void (*setkey)(void);
    void (*encrypt)(void);
    void (*decrypt)(void);
    unsigned int ivsize;
    unsigned int keysize;
    struct {
        void (*exit)(struct crypto_tfm *tfm);
    } base;
};

struct skcipher_alg {
    void (*setkey)(void);
    void (*encrypt)(void);
    void (*decrypt)(void);
    unsigned int ivsize;
    unsigned int max_keysize;
    int (*init)(struct crypto_skcipher *skcipher);
    void (*exit)(void);
};

extern struct crypto_skcipher *__crypto_skcipher_cast(struct crypto_tfm *tfm);
extern struct skcipher_alg *crypto_skcipher_alg(struct crypto_skcipher *skcipher);
extern int crypto_init_skcipher_ops_blkcipher(struct crypto_tfm *tfm);
extern int crypto_init_skcipher_ops_ablkcipher(struct crypto_tfm *tfm);
extern void crypto_skcipher_exit_tfm(struct crypto_tfm *tfm);
extern void skcipher_setkey(void);

extern struct crypto_blkcipher_type crypto_blkcipher_type;
extern struct crypto_ablkcipher_type crypto_ablkcipher_type;
extern struct crypto_givcipher_type crypto_givcipher_type;