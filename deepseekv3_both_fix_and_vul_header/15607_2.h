#include <stdlib.h>
#include <string.h>

#define TK26_MAC_KEY_LEN 32
#define PKCS12_MAC_ID 1
#define EVP_MAX_MD_SIZE 64
#define ERR_LIB_PKCS12 0
#define PKCS12_R_CONTENT_TYPE_NOT_DATA 0
#define PKCS12_R_DECODE_ERROR 0
#define PKCS12_R_UNKNOWN_DIGEST_ALGORITHM 0
#define PKCS12_R_KEY_GEN_ERROR 0
#define NID_id_GostR3411_94 0
#define NID_id_GostR3411_2012_256 0
#define NID_id_GostR3411_2012_512 0

typedef struct ASN1_OBJECT_st ASN1_OBJECT;
typedef struct ASN1_INTEGER_st ASN1_INTEGER;
typedef struct X509_ALGOR_st X509_ALGOR;
typedef struct X509_SIG_st X509_SIG;
typedef struct EVP_MD_st EVP_MD;
typedef struct HMAC_CTX_st HMAC_CTX;

typedef struct {
    void *libctx;
    char *propq;
} OSSL_LIB_CTX;

typedef struct {
    unsigned char *data;
    int length;
} ASN1_OCTET_STRING;

typedef struct {
    ASN1_OCTET_STRING *salt;
    ASN1_INTEGER *iter;
    X509_SIG *dinfo;
} PKCS12_MAC_DATA;

typedef struct {
    int type;
    union {
        ASN1_OCTET_STRING *data;
    } d;
    OSSL_LIB_CTX ctx;
} PKCS7;

typedef struct {
    PKCS7 *authsafes;
    PKCS12_MAC_DATA *mac;
} PKCS12;

int PKCS7_type_is_data(PKCS7 *);
void ERR_raise(int, int);
int ASN1_INTEGER_get(ASN1_INTEGER *);
void X509_SIG_get0(X509_SIG *, const X509_ALGOR **, void **);
void X509_ALGOR_get0(const ASN1_OBJECT **, int *, void **, X509_ALGOR *);
int OBJ_obj2txt(char *, int, const ASN1_OBJECT *, int);
int OBJ_obj2nid(const ASN1_OBJECT *);
void ERR_set_mark(void);
void ERR_clear_last_mark(void);
void ERR_pop_to_mark(void);
EVP_MD *EVP_MD_fetch(void *, const char *, const char *);
const EVP_MD *EVP_get_digestbynid(int);
int EVP_MD_get_size(const EVP_MD *);
int EVP_MD_get_type(const EVP_MD *);
char *ossl_safe_getenv(const char *);
int pkcs12_gen_gost_mac_key(const char *, int, unsigned char *, int, int, int, unsigned char *, const EVP_MD *);
int PKCS12_key_gen_utf8_ex(const char *, int, unsigned char *, int, int, int, int, unsigned char *, const EVP_MD *, void *, const char *);
HMAC_CTX *HMAC_CTX_new(void);
int HMAC_Init_ex(HMAC_CTX *, const unsigned char *, int, const EVP_MD *, void *);
int HMAC_Update(HMAC_CTX *, const unsigned char *, int);
int HMAC_Final(HMAC_CTX *, unsigned char *, unsigned int *);
void OPENSSL_cleanse(void *, size_t);
void HMAC_CTX_free(HMAC_CTX *);
void EVP_MD_free(EVP_MD *);