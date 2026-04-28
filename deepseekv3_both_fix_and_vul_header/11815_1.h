#include <string.h>

struct sk_buff;
struct crypto_alg;
struct crypto_report_acomp {
    char type[64];
};

#define CRYPTOCFGA_REPORT_ACOMP 0
#define EMSGSIZE 90

int nla_put(struct sk_buff *skb, int type, int len, const void *data);