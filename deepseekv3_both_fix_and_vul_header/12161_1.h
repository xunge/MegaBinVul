#include <stddef.h>
#include <stdio.h>

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

struct crypto_shash;
static struct crypto_shash *crypto_alloc_shash(const char *name, unsigned int type, unsigned int mask);
static void crypto_free_shash(struct crypto_shash *tfm);
static int calc_hash(struct crypto_shash *alg, const unsigned char *data, unsigned int datalen, unsigned char *digest);