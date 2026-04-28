#include <stdlib.h>
#include <string.h>

#define EVP_MAX_MD_SIZE 64
#define TK26_MAC_KEY_LEN 32
#define PKCS12_MAC_ID 1
#define ERR_LIB_PKCS12 0
#define PKCS12_R_CONTENT_TYPE_NOT_DATA 0
#define PKCS12_R_DECODE_ERROR 0
#define PKCS12_R_UNKNOWN_DIGEST_ALGORITHM 0
#define PKCS12_R_KEY_GEN_ERROR 0
#define NID_id_GostR3411_94 0
#define NID_id_GostR3411_2012_256 0
#define NID_id_GostR3411_2012_512 0

typedef struct PKCS12_MAC_DATA_st {
    struct {
        unsigned char *data;
        int length;
    } *salt;
    void *iter;
    void *dinfo;
} PKCS12_MAC_DATA;

typedef struct PKCS7_st {
    int type;
    union {
        struct {
            unsigned char *data;
            int length;
        } *data;
    } d;
    struct {
        void *libctx;
        char *propq;
    } ctx;
} PKCS7;

typedef struct PKCS12_st {
    PKCS7 *authsafes;
    PKCS12_MAC_DATA *mac;
} PKCS12;

typedef struct EVP_MD_st EVP_MD;
typedef struct HMAC_CTX_st HMAC_CTX;
typedef struct X509_ALGOR_st X509_ALGOR;
typedef struct ASN1_OBJECT_st ASN1_OBJECT;
typedef struct X509_SIG_st X509_SIG;

int PKCS7_type_is_data(PKCS7 *p);
int ASN1_INTEGER_get(void *a);
int OBJ_obj2txt(char *buf, int buf_len, const ASN1_OBJECT *a, int no_name);
int OBJ_obj2nid(const ASN1_OBJECT *a);
void X509_SIG_get0(const X509_SIG *sig, const X509_ALGOR **palg, void **pdigest);
void X509_ALGOR_get0(const ASN1_OBJECT **pa, int *pptype, void **ppval, const X509_ALGOR *algor);
const EVP_MD *EVP_get_digestbynid(int type);
int EVP_MD_get_size(const EVP_MD *md);
int EVP_MD_get_type(const EVP_MD *md);
HMAC_CTX *HMAC_CTX_new(void);
int HMAC_Init_ex(HMAC_CTX *ctx, const void *key, int key_len, const EVP_MD *md, void *impl);
int HMAC_Update(HMAC_CTX *ctx, const unsigned char *data, int len);
int HMAC_Final(HMAC_CTX *ctx, unsigned char *md, unsigned int *len);
void HMAC_CTX_free(HMAC_CTX *ctx);
void OPENSSL_cleanse(void *ptr, size_t len);
void ERR_raise(int lib, int reason);
void ERR_set_mark(void);
void ERR_clear_last_mark(void);
void ERR_pop_to_mark(void);
const EVP_MD *EVP_MD_fetch(void *libctx, const char *algorithm, const char *properties);
void EVP_MD_free(EVP_MD *md);
int PKCS12_key_gen_utf8_ex(const char *pass, int passlen, unsigned char *salt, int saltlen, int id, int iter, int n, unsigned char *out, const EVP_MD *md_type, void *libctx, const char *propq);
int pkcs12_gen_gost_mac_key(const char *pass, int passlen, unsigned char *salt, int slen, int iter, int keylen, unsigned char *key, const EVP_MD *md);
const char *ossl_safe_getenv(const char *name);