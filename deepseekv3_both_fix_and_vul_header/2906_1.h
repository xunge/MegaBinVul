#include <stdio.h>
#include <string.h>

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_REPORT_BLKCIPHER 0
#define EMSGSIZE 90

struct sk_buff;
struct nlattr;

struct crypto_report_blkcipher {
    char type[CRYPTO_MAX_ALG_NAME];
    char geniv[CRYPTO_MAX_ALG_NAME];
    unsigned int blocksize;
    unsigned int min_keysize;
    unsigned int max_keysize;
    unsigned int ivsize;
};

struct crypto_alg {
    unsigned int cra_blocksize;
    struct {
        char *geniv;
        unsigned int min_keysize;
        unsigned int max_keysize;
        unsigned int ivsize;
    } cra_ablkcipher;
};

int nla_put(struct sk_buff *skb, int type, int len, const void *data);