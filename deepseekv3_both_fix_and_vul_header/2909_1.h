#include <stdio.h>
#include <string.h>

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_REPORT_BLKCIPHER 1
#define EMSGSIZE 90

struct sk_buff;
struct crypto_alg;

struct crypto_blkcipher {
    char *geniv;
    unsigned int min_keysize;
    unsigned int max_keysize;
    unsigned int ivsize;
};

struct crypto_alg {
    unsigned int cra_blocksize;
    struct crypto_blkcipher cra_blkcipher;
};

struct crypto_report_blkcipher {
    char type[CRYPTO_MAX_ALG_NAME];
    char geniv[CRYPTO_MAX_ALG_NAME];
    unsigned int blocksize;
    unsigned int min_keysize;
    unsigned int max_keysize;
    unsigned int ivsize;
};

int nla_put(struct sk_buff *skb, int type, int len, void *data);