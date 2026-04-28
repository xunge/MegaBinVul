#include <stddef.h>

#define OSSL_MAX_NAME_SIZE 50

typedef struct pkcs7_ctx_st PKCS7_CTX;
typedef struct X509_algor_st {
    void *algorithm;
} X509_ALGOR;
typedef struct bio_st BIO;
typedef struct evp_md_st EVP_MD;

#define ERR_LIB_PKCS7 0
#define ERR_R_BIO_LIB 0
#define PKCS7_R_UNKNOWN_DIGEST_TYPE 0

static int BIO_f_md() { return 0; }
static void ERR_raise(int lib, int reason) {}
static void ERR_set_mark() {}
static void ERR_clear_last_mark() {}
static void ERR_pop_to_mark() {}
static void EVP_MD_free(EVP_MD *md) {}

static BIO* BIO_new(void* method) { return NULL; }
static int BIO_set_md(BIO *bio, const EVP_MD *md) { return 0; }
static int BIO_push(BIO *bio, BIO *append) { return 0; }
static void BIO_free(BIO *bio) {}

static EVP_MD* EVP_MD_fetch(void* ctx, const char* name, const char* propq) { return NULL; }
static const EVP_MD* EVP_get_digestbyname(const char* name) { return NULL; }

static int OBJ_obj2txt(char *buf, int buf_len, void *a, int no_name) { return 0; }

static void* ossl_pkcs7_ctx_get0_libctx(const PKCS7_CTX *ctx) { return NULL; }
static const char* ossl_pkcs7_ctx_get0_propq(const PKCS7_CTX *ctx) { return NULL; }