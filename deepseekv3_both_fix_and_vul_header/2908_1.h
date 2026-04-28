#include <stdio.h>
#include <string.h>

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_REPORT_COMPRESS 1
#define EMSGSIZE 90

struct sk_buff;
struct crypto_alg;

struct crypto_report_comp {
    char type[CRYPTO_MAX_ALG_NAME];
};

int nla_put(struct sk_buff *skb, int type, int len, struct crypto_report_comp *rpcomp);