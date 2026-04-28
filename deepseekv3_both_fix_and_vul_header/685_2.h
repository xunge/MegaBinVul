#include <stdlib.h>
#include <time.h>

enum {
    DRBG_UNINITIALISED,
    DRBG_READY,
    DRBG_ERROR
};

enum {
    RAND_F_RAND_DRBG_GENERATE,
    RAND_R_IN_ERROR_STATE,
    RAND_R_NOT_INSTANTIATED,
    RAND_R_REQUEST_TOO_LARGE_FOR_DRBG,
    RAND_R_ADDITIONAL_INPUT_TOO_LONG,
    RAND_R_RESEED_ERROR,
    RAND_R_GENERATE_ERROR
};

struct rand_drbg_st;
typedef struct rand_meth_st {
    int (*generate)(struct rand_drbg_st *drbg, unsigned char *out, size_t outlen,
                    const unsigned char *adin, size_t adinlen);
} RAND_METHOD;

typedef struct rand_drbg_st {
    int state;
    size_t max_request;
    size_t max_adinlen;
    int fork_id;
    int fork_count;
    unsigned int reseed_interval;
    unsigned int reseed_gen_counter;
    time_t reseed_time_interval;
    time_t reseed_time;
    struct rand_drbg_st *parent;
    unsigned int reseed_prop_counter;
    const RAND_METHOD *meth;
} RAND_DRBG;

extern int rand_fork_count;
extern int openssl_get_fork_id(void);
extern unsigned int tsan_load(unsigned int *counter);
extern int RAND_DRBG_reseed(RAND_DRBG *drbg, const unsigned char *adin, size_t adinlen, int prediction_resistance);
extern void rand_drbg_restart(RAND_DRBG *drbg, const unsigned char *adin, size_t adinlen, int prediction_resistance);
extern void RANDerr(int lib, int reason);