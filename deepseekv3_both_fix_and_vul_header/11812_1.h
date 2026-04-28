#include <string.h>
#include <stddef.h>

struct sk_buff;
struct crypto_alg;
struct crypto_report_comp {
    char type[64];  // Using arbitrary size since CRYPTO_MAX_ALG_NAME isn't defined
};

#define CRYPTOCFGA_REPORT_COMPRESS 1
#define EMSGSIZE 90

int nla_put(struct sk_buff *skb, int type, int len, const void *data);