#include <stdio.h>
#include <string.h>

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_REPORT_CIPHER 1
#define EMSGSIZE 90

struct sk_buff;
struct nlattr;

struct crypto_report_cipher {
    char type[CRYPTO_MAX_ALG_NAME];
    unsigned int blocksize;
    unsigned int min_keysize;
    unsigned int max_keysize;
};

struct crypto_alg {
    unsigned int cra_blocksize;
    struct {
        unsigned int cia_min_keysize;
        unsigned int cia_max_keysize;
    } cra_cipher;
};

int nla_put(struct sk_buff *skb, int attrtype, int attrlen, const void *data);