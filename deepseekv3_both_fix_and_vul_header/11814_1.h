#include <string.h>
#include <stddef.h>

struct sk_buff;
struct crypto_alg;
struct crypto_report_akcipher {
    char type[64];
};

#define CRYPTOCFGA_REPORT_AKCIPHER 1
#define EMSGSIZE 90

static inline int nla_put(struct sk_buff *skb, int attrtype, int datalen, const void *data) {
    return 0;
}