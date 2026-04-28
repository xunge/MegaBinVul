#include <stddef.h>

typedef struct siv_hw_st {
    int (*cipher)(void *, unsigned char *, const unsigned char *, size_t);
} SIV_HW;

typedef struct prov_aes_siv_ctx_st {
    SIV_HW *hw;
} PROV_AES_SIV_CTX;

extern int ossl_prov_is_running(void);
#define ERR_LIB_PROV 0
#define PROV_R_OUTPUT_BUFFER_TOO_SMALL 0
void ERR_raise(int lib, int reason);