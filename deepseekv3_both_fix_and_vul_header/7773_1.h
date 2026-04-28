#include <stddef.h>

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

struct gost_pmeth_data {
    int cipher_nid;
};

#define NID_id_Gost28147_89 1
#define NID_undef 2
#define NID_kuznyechik_ctr 3
#define NID_magma_ctr 4
#define ERR_R_INTERNAL_ERROR 5
#define GOST_F_PKEY_GOST_DECRYPT 6

#define GOSTerr(a,b) 

struct gost_pmeth_data *EVP_PKEY_CTX_get_data(EVP_PKEY_CTX *ctx);

int pkey_GOST_ECcp_decrypt(EVP_PKEY_CTX *pctx, unsigned char *key, size_t *key_len, const unsigned char *in, size_t in_len);
int pkey_gost2018_decrypt(EVP_PKEY_CTX *pctx, unsigned char *key, size_t *key_len, const unsigned char *in, size_t in_len);