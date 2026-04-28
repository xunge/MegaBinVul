#include <stdlib.h>

struct rand_drbg_st {
    int secure;
    int fork_id;
    int fork_count;
    struct rand_drbg_st *parent;
    size_t (*get_entropy)(struct rand_drbg_st *, unsigned char **, int, size_t, size_t);
    void (*cleanup_entropy)(struct rand_drbg_st *, unsigned char *, size_t);
    size_t (*get_nonce)(struct rand_drbg_st *, unsigned char **, int, size_t, size_t);
    void (*cleanup_nonce)(struct rand_drbg_st *, unsigned char *, size_t);
    unsigned int reseed_interval;
    unsigned int reseed_time_interval;
    unsigned int strength;
};

typedef struct rand_drbg_st RAND_DRBG;

unsigned int master_reseed_interval;
unsigned int master_reseed_time_interval;
unsigned int slave_reseed_interval;
unsigned int slave_reseed_time_interval;
int rand_fork_count;

void *OPENSSL_secure_zalloc(size_t size);
void *OPENSSL_zalloc(size_t size);
int CRYPTO_secure_allocated(void *ptr);
int openssl_get_fork_id(void);
int RAND_DRBG_set(RAND_DRBG *drbg, int type, unsigned int flags);
void RAND_DRBG_free(RAND_DRBG *drbg);
void rand_drbg_lock(RAND_DRBG *drbg);
void rand_drbg_unlock(RAND_DRBG *drbg);
void RANDerr(int lib, int reason);

size_t rand_drbg_get_entropy(RAND_DRBG *drbg, unsigned char **pout, int entropy, size_t min_len, size_t max_len);
void rand_drbg_cleanup_entropy(RAND_DRBG *drbg, unsigned char *out, size_t outlen);
size_t rand_drbg_get_nonce(RAND_DRBG *drbg, unsigned char **pout, int entropy, size_t min_len, size_t max_len);
void rand_drbg_cleanup_nonce(RAND_DRBG *drbg, unsigned char *out, size_t outlen);

#define RAND_F_RAND_DRBG_NEW 0
#define ERR_R_MALLOC_FAILURE 0
#define RAND_R_PARENT_STRENGTH_TOO_WEAK 0