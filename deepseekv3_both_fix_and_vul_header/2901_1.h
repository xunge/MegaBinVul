#include <stdio.h>
#include <string.h>

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_REPORT_RNG 5
#define EMSGSIZE 90

struct sk_buff;
struct crypto_alg;

struct crypto_report_rng {
    char type[CRYPTO_MAX_ALG_NAME];
    unsigned int seedsize;
};

struct crypto_rng {
    unsigned int seedsize;
};

struct crypto_alg {
    struct crypto_rng cra_rng;
};

int nla_put(struct sk_buff *skb, int type, int len, const void *data);