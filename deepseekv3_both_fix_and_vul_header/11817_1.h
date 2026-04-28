#include <string.h>

struct sk_buff;
struct crypto_alg;
struct crypto_report_kpp {
    char type[64];
};

#define CRYPTOCFGA_REPORT_KPP 1
#define EMSGSIZE 90

int nla_put(struct sk_buff *skb, int type, int len, const void *data);
size_t strlcpy(char *dest, const char *src, size_t size);