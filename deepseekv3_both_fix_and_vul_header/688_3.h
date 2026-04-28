#include <stdlib.h>
#include <stddef.h>

typedef struct EVP_PKEY_st EVP_PKEY;
typedef struct EVP_PKEY_CTX_st EVP_PKEY_CTX;
typedef struct EVP_CIPHER_st EVP_CIPHER;

struct CMS_RecipientInfo_st {
    union {
        struct CMS_KeyTransRecipientInfo_st *ktri;
    } d;
};

struct CMS_KeyTransRecipientInfo_st {
    EVP_PKEY *pkey;
    EVP_PKEY_CTX *pctx;
    struct {
        unsigned char *data;
        size_t length;
    } *encryptedKey;
};

struct CMS_ContentInfo_st {
    union {
        struct {
            struct {
                struct CMS_EncryptedContentInfo_st *encryptedContentInfo;
            } *envelopedData;
        } d;
    };
};

struct CMS_EncryptedContentInfo_st {
    unsigned char *key;
    size_t keylen;
    int havenocert;
    int debug;
    struct X509_ALGOR_st *contentEncryptionAlgorithm;
};

struct X509_ALGOR_st {
    int algorithm;
};

typedef struct CMS_ContentInfo_st CMS_ContentInfo;
typedef struct CMS_RecipientInfo_st CMS_RecipientInfo;
typedef struct CMS_KeyTransRecipientInfo_st CMS_KeyTransRecipientInfo;
typedef struct CMS_EncryptedContentInfo_st CMS_EncryptedContentInfo;
typedef struct X509_ALGOR_st X509_ALGOR;

#define CMS_F_CMS_RECIPIENTINFO_KTRI_DECRYPT 0
#define CMS_R_NO_PRIVATE_KEY 0
#define CMS_R_UNKNOWN_CIPHER 0
#define CMS_R_CTRL_ERROR 0
#define CMS_R_CMS_LIB 0
#define ERR_R_MALLOC_FAILURE 0

#define EVP_PKEY_OP_DECRYPT 0
#define EVP_PKEY_CTRL_CMS_DECRYPT 0

#define OPENSSL_malloc malloc
#define OPENSSL_free free
#define OPENSSL_clear_free(ptr, len) free(ptr)

static void CMSerr(int a, int b) {}
static EVP_PKEY_CTX *EVP_PKEY_CTX_new(EVP_PKEY *pkey, void *a) { return NULL; }
static int EVP_PKEY_decrypt_init(EVP_PKEY_CTX *ctx) { return 0; }
static int cms_env_asn1_ctrl(void *a, int b) { return 0; }
static int EVP_PKEY_CTX_ctrl(EVP_PKEY_CTX *ctx, int a, int b, int c, int d, void *e) { return 0; }
static int EVP_PKEY_decrypt(EVP_PKEY_CTX *ctx, unsigned char *out, size_t *outlen, const unsigned char *in, size_t inlen) { return 0; }
static const EVP_CIPHER *EVP_get_cipherbyobj(int a) { return NULL; }
static int EVP_CIPHER_key_length(const EVP_CIPHER *c) { return 0; }
static void EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx) {}