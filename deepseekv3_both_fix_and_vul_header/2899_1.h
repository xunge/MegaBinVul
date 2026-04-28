#include <stdio.h>
#include <string.h>

struct sk_buff;
struct crypto_alg;
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
    char type[64];
    char geniv[64];
    unsigned int blocksize;
    unsigned int maxauthsize;
    unsigned int ivsize;
};

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_REPORT_AEAD 1
#define EMSGSIZE 90

int nla_put(struct sk_buff *skb, int type, int size, struct crypto_report_aead *raead);