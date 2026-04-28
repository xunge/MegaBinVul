#include <string.h>
#include <stdint.h>

struct crypto_alg {
    char cra_name[64];
    char cra_driver_name[64];
    void *cra_module;
    uint32_t cra_flags;
    uint32_t cra_priority;
    struct {
        int (*report)(void *, struct crypto_alg *);
    } *cra_type;
    struct {
        int counter;
    } cra_refcnt;
};

struct crypto_user_alg {
    char cru_name[64];
    char cru_driver_name[64];
    char cru_module_name[64];
    uint32_t cru_type;
    uint32_t cru_mask;
    uint32_t cru_flags;
    uint32_t cru_refcnt;
};

struct sk_buff;
struct crypto_report_larval {
    char type[16];
};

#define CRYPTOCFGA_PRIORITY_VAL 0
#define CRYPTOCFGA_REPORT_LARVAL 1

#define CRYPTO_ALG_LARVAL 0x00000010
#define CRYPTO_ALG_TYPE_MASK 0x0000000f
#define CRYPTO_ALG_TYPE_CIPHER 0x00000001
#define CRYPTO_ALG_TYPE_COMPRESS 0x00000002
#define CRYPTO_ALG_TYPE_ACOMPRESS 0x00000003
#define CRYPTO_ALG_TYPE_AKCIPHER 0x00000004
#define CRYPTO_ALG_TYPE_KPP 0x00000005

#define EMSGSIZE 90

static inline char *module_name(void *module) { return "module"; }
static inline int refcount_read(const void *ref) { return 0; }
static inline int nla_put_u32(struct sk_buff *skb, int attr, uint32_t val) { return 0; }
static inline int nla_put(struct sk_buff *skb, int attr, int size, const void *data) { return 0; }
static inline int crypto_report_cipher(struct sk_buff *skb, struct crypto_alg *alg) { return 0; }
static inline int crypto_report_comp(struct sk_buff *skb, struct crypto_alg *alg) { return 0; }
static inline int crypto_report_acomp(struct sk_buff *skb, struct crypto_alg *alg) { return 0; }
static inline int crypto_report_akcipher(struct sk_buff *skb, struct crypto_alg *alg) { return 0; }
static inline int crypto_report_kpp(struct sk_buff *skb, struct crypto_alg *alg) { return 0; }