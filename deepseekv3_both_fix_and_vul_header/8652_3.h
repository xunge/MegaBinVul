#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;

struct crypto_skcipher;
struct crypto_rng;
struct key_type;

static struct crypto_rng *big_key_rng;
static struct crypto_skcipher *big_key_skcipher;
static const char big_key_rng_name[] = "stdrng";
static const char big_key_alg_name[] = "ecb(aes)";

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define CRYPTO_ALG_ASYNC 0x00000001
#define __init

extern struct crypto_rng *crypto_alloc_rng(const char *alg_name, u32 type, u32 mask);
extern int crypto_rng_reset(struct crypto_rng *rng, const u8 *seed, unsigned int seedlen);
extern unsigned int crypto_rng_seedsize(struct crypto_rng *rng);
extern void crypto_free_rng(struct crypto_rng *rng);
extern struct crypto_skcipher *crypto_alloc_skcipher(const char *alg_name, u32 type, u32 mask);
extern void crypto_free_skcipher(struct crypto_skcipher *tfm);
extern int register_key_type(struct key_type *ktype);

extern struct key_type key_type_big_key;

int pr_err(const char *fmt, ...);