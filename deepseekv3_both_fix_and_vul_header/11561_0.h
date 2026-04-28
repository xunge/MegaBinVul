#include <stdlib.h>
#include <string.h>
#include <gmp.h>

typedef char *err_t;

struct RSA_public_key {
    MP_INT e;
    MP_INT n;
};

typedef struct {
    unsigned char *ptr;
    size_t len;
} chunk_t;

extern struct oswcrypto_struct {
    void (*mod_exp)(MP_INT *out, MP_INT *base, MP_INT *e, MP_INT *n);
} oswcrypto;

#define DBG(level, args)
#define DBG_CRYPT 0
#define DBG_dump(label, data, len)
#define DBG_log(fmt, ...)

void n_to_mpz(MP_INT *mpz, const unsigned char *n, size_t len);
chunk_t mpz_to_n(MP_INT *mpz, size_t len);
void pfree(void *ptr);