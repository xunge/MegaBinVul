#include <stdio.h>
#include <string.h>

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_REPORT_AEAD 1
#define EMSGSIZE 90

struct sk_buff;

struct aead_alg {
    char *geniv;
    unsigned int maxauthsize;
    unsigned int ivsize;
};

struct crypto_alg {
    struct aead_alg cra_aead;
    unsigned int cra_blocksize;
};

struct crypto_report_aead {
    char type[CRYPTO_MAX_ALG_NAME];
    char geniv[CRYPTO_MAX_ALG_NAME];
    unsigned int blocksize;
    unsigned int maxauthsize;
    unsigned int ivsize;
};

int nla_put(struct sk_buff *skb, int type, int len, const void *data);