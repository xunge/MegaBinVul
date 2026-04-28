#include <stdio.h>
#include <string.h>

struct sk_buff {
    // dummy definition
};

struct crypto_alg {
    unsigned int cra_blocksize;
    // other members omitted
};

struct shash_alg {
    unsigned int digestsize;
    // other members omitted
};

struct crypto_report_hash {
    char type[64];
    unsigned int blocksize;
    unsigned int digestsize;
};

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_REPORT_HASH 1
#define EMSGSIZE 90

static inline struct shash_alg *__crypto_shash_alg(struct crypto_alg *alg) { 
    return (struct shash_alg *)alg; 
}

int nla_put(struct sk_buff *skb, int type, int len, const void *data) { 
    return 0; 
}