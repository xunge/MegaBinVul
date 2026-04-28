#include <stddef.h>

#define LTC_ARGCHK(cond) do { if (!(cond)) return CRYPT_INVALID_ARG; } while(0)
#define CRYPT_OK 0
#define CRYPT_MEM 1
#define CRYPT_INVALID_ARG 2

typedef void* mpanum;
typedef struct mpa_fmm_context* mpa_fmm_context;

struct mpa_fmm_context {
    void* r_ptr;
    void* r2_ptr;
    void* n_inv;
};

extern int montgomery_setup(void* c, mpa_fmm_context* c_mont);
extern int init(void** d_tmp);
extern void mod(void* a, void* c, void* d_tmp);
extern void mpa_exp_mod(mpanum d, const mpanum d_tmp, const mpanum b, const mpanum c, void* r_ptr, void* r2_ptr, void* n_inv, void* external_mem_pool);
extern void montgomery_deinit(mpa_fmm_context c_mont);
extern void deinit(void* d_tmp);
extern void* external_mem_pool;