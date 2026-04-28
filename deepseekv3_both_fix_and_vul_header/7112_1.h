#include <stdlib.h>
#include <string.h>

typedef struct bio_st BIO;
typedef struct bio_method_st BIO_METHOD;
typedef struct evp_encode_ctx_st EVP_ENCODE_CTX;
typedef struct buf_mem_st BUF_MEM;

struct buf_mem_st {
    size_t length;
    char *data;
};

#define PEM_FLAG_EAY_COMPATIBLE 0x1
#define PEM_FLAG_ONLY_B64 0x2
#define PEM_FLAG_SECURE 0x4

#define PEM_F_PEM_READ_BIO_EX 0
#define PEM_R_BAD_BASE64_DECODE 0
#define ERR_R_PASSED_INVALID_ARGUMENT 0
#define ERR_R_MALLOC_FAILURE 0

static void PEMerr(int a, int b) {}
static void pem_free(void *a, unsigned int b, int c) {}
static void *pem_malloc(size_t a, unsigned int b) { return malloc(a); }
static int get_name(BIO *a, char **b, unsigned int c) { return 0; }
static int get_header_and_data(BIO *a, BIO **b, BIO **c, char *d, unsigned int e) { return 0; }

static BIO *BIO_new(const BIO_METHOD *a) { return NULL; }
static int BIO_read(BIO *a, void *b, int c) { return 0; }
static void BIO_free(BIO *a) {}
static int BIO_get_mem_data(BIO *a, void *b) { return 0; }
static void BIO_get_mem_ptr(BIO *a, BUF_MEM **b) {}

static const BIO_METHOD *BIO_s_mem(void) { return NULL; }
static const BIO_METHOD *BIO_s_secmem(void) { return NULL; }

static EVP_ENCODE_CTX *EVP_ENCODE_CTX_new(void) { return NULL; }
static void EVP_ENCODE_CTX_free(EVP_ENCODE_CTX *a) {}
static void EVP_DecodeInit(EVP_ENCODE_CTX *a) {}
static int EVP_DecodeUpdate(EVP_ENCODE_CTX *a, unsigned char *b, int *c, unsigned char *d, int e) { return 0; }
static int EVP_DecodeFinal(EVP_ENCODE_CTX *a, unsigned char *b, int *c) { return 0; }