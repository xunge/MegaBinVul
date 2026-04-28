#include <string.h>
#include <stdatomic.h>
#include <stdint.h>

#define CRYPTO_MAX_ALG_NAME 64
#define CRYPTOCFGA_PRIORITY_VAL 1
#define CRYPTOCFGA_REPORT_LARVAL 2
#define EMSGSIZE 90

struct module;
struct sk_buff;

struct crypto_alg {
    char cra_name[CRYPTO_MAX_ALG_NAME];
    char cra_driver_name[CRYPTO_MAX_ALG_NAME];
    struct module *cra_module;
    unsigned int cra_flags;
    int cra_priority;
    atomic_int cra_refcnt;
    struct crypto_type *cra_type;
};

struct crypto_user_alg {
    char cru_name[CRYPTO_MAX_ALG_NAME];
    char cru_driver_name[CRYPTO_MAX_ALG_NAME];
    char cru_module_name[CRYPTO_MAX_ALG_NAME];
    unsigned int cru_flags;
    unsigned int cru_type;
    unsigned int cru_mask;
    int cru_refcnt;
};

struct crypto_report_larval {
    char type[CRYPTO_MAX_ALG_NAME];
};

struct crypto_type {
    int (*report)(struct sk_buff *, struct crypto_alg *);
};

#define CRYPTO_ALG_LARVAL 0x00000010
#define CRYPTO_ALG_TYPE_MASK 0x0000000f
#define CRYPTO_ALG_TYPE_CIPHER 0x00000001
#define CRYPTO_ALG_TYPE_COMPRESS 0x00000002

const char *module_name(struct module *mod);
int nla_put_u32(struct sk_buff *skb, int attrtype, int value);
int nla_put(struct sk_buff *skb, int attrtype, int len, const void *data);
int crypto_report_cipher(struct sk_buff *skb, struct crypto_alg *alg);
int crypto_report_comp(struct sk_buff *skb, struct crypto_alg *alg);