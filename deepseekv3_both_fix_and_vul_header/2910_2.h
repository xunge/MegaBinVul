#include <stdio.h>
#include <string.h>

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_REPORT_HASH 1
#define EMSGSIZE 90

struct sk_buff {
    // dummy definition
};

struct crypto_alg {
    unsigned int cra_blocksize;
    // other members omitted
};

struct crypto_hash_alg_common {
    unsigned int digestsize;
    // other members omitted
};

struct crypto_report_hash {
    char type[CRYPTO_MAX_ALG_NAME];
    unsigned int blocksize;
    unsigned int digestsize;
};

static inline struct crypto_hash_alg_common *__crypto_hash_alg_common(struct crypto_alg *alg) {
    return (struct crypto_hash_alg_common *)alg; // dummy implementation
}

static inline int nla_put(struct sk_buff *skb, int attrtype, int attrlen, const void *data) {
    return 0; // dummy implementation
}