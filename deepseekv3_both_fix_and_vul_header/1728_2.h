#include <stdlib.h>
#include <string.h>

typedef struct ossl_param_st {
    const char *key;
    int data_type;
    void *data;
    size_t data_size;
} OSSL_PARAM;

typedef struct evp_md_st {
    int type;
    int ctx_size;
    void *prov;
    int origin;
    int (*init)(void *ctx);
    int (*update)(void *ctx, const void *data, size_t count);
    int (*final)(void *ctx, unsigned char *md);
    void *(*newctx)(void *provctx);
    void (*freectx)(void *ctx);
    int (*dinit)(void *ctx, const OSSL_PARAM params[]);
} EVP_MD;

typedef struct evp_md_ctx_st {
    const EVP_MD *digest;
    const EVP_MD *reqdigest;
    const EVP_MD *fetched_digest;
    void *algctx;
    void *md_data;
    void *pctx;
    void *engine;
    unsigned long flags;
    int (*update)(void *ctx, const void *data, size_t count);
} EVP_MD_CTX;

typedef struct engine_st ENGINE;
typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

#define OPENSSL_NO_ENGINE
#define FIPS_MODULE

#define EVP_PKEY_OP_SIGNCTX 0
#define EVP_PKEY_OP_VERIFYCTX 0
#define EVP_PKEY_OP_TYPE_SIG 0
#define EVP_PKEY_CTX_IS_SIGNATURE_OP(ctx) 0
#define EVP_PKEY_CTRL_DIGESTINIT 0

#define EVP_R_UPDATE_ERROR 0
#define EVP_R_INITIALIZATION_ERROR 0
#define EVP_R_NO_DIGEST_SET 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_LIB_EVP 0

#define EVP_MD_CTX_FLAG_CLEANED 0
#define EVP_MD_CTX_FLAG_NO_INIT 0
#define EVP_ORIG_METH 0

#define NID_undef 0

static int EVP_DigestSignInit(EVP_MD_CTX *ctx, void *a, const EVP_MD *type, ENGINE *impl, void *b) { return 0; }
static int EVP_DigestVerifyInit(EVP_MD_CTX *ctx, void *a, const EVP_MD *type, ENGINE *impl, void *b) { return 0; }
static void ERR_raise(int lib, int reason) {}
static int ossl_assert(int test) { return test; }
static void EVP_MD_CTX_clear_flags(EVP_MD_CTX *ctx, int flags) {}
static void cleanup_old_md_data(EVP_MD_CTX *ctx, int flag) {}
static void ENGINE_finish(ENGINE *e) {}
static ENGINE *ENGINE_get_digest_engine(int nid) { return NULL; }
static int ENGINE_init(ENGINE *e) { return 0; }
static const EVP_MD *ENGINE_get_digest(ENGINE *e, int nid) { return NULL; }
static void *OPENSSL_zalloc(size_t size) { return calloc(1, size); }
static int EVP_PKEY_CTX_ctrl(EVP_PKEY_CTX *ctx, int optype, int cmd, int p1, int p2, void *p3) { return 0; }
static EVP_MD *EVP_MD_fetch(void *a, const char *b, const char *c) { return NULL; }
static char *OBJ_nid2sn(int nid) { return NULL; }
static int EVP_MD_up_ref(EVP_MD *md) { return 0; }
static void EVP_MD_free(EVP_MD *md) { free(md); }
static void *ossl_provider_ctx(void *prov) { return NULL; }