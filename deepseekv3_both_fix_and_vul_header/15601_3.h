#include <stdlib.h>
#include <string.h>

#define EVP_MAX_MD_SIZE 64
#define TK26_MAC_KEY_LEN 32
#define PKCS12_MAC_ID 1
#define NID_id_GostR3411_94 0
#define NID_id_GostR3411_2012_256 0
#define NID_id_GostR3411_2012_512 0
#define ERR_LIB_PKCS12 0
#define PKCS12_R_CONTENT_TYPE_NOT_DATA 0
#define PKCS12_R_DECODE_ERROR 0
#define PKCS12_R_UNKNOWN_DIGEST_ALGORITHM 0
#define PKCS12_R_KEY_GEN_ERROR 0

typedef struct PKCS12 {
    struct {
        struct {
            void *libctx;
            char *propq;
        } ctx;
        struct {
            struct {
                unsigned char *data;
                int length;
            } *data;
        } d;
    } *authsafes;
    struct {
        struct {
            unsigned char *data;
            int length;
        } *salt;
        struct ASN1_INTEGER *iter;
        struct X509_SIG *dinfo;
    } *mac;
} PKCS12;

typedef struct EVP_MD EVP_MD;
typedef struct HMAC_CTX HMAC_CTX;
typedef struct X509_ALGOR X509_ALGOR;
typedef struct ASN1_OBJECT ASN1_OBJECT;
typedef struct ASN1_INTEGER ASN1_INTEGER;
typedef struct X509_SIG X509_SIG;

int PKCS7_type_is_data(void *p);
void ERR_raise(int lib, int reason);
int ASN1_INTEGER_get(struct ASN1_INTEGER *a);
void X509_SIG_get0(struct X509_SIG *x, const struct X509_ALGOR **palg, void **pdigest);
void X509_ALGOR_get0(const struct ASN1_OBJECT **paobj, int *pptype, void **ppval, const struct X509_ALGOR *algor);
int OBJ_obj2txt(char *buf, int buf_len, const struct ASN1_OBJECT *a, int no_name);
int OBJ_obj2nid(const struct ASN1_OBJECT *a);
void ERR_set_mark(void);
struct EVP_MD *EVP_MD_fetch(void *ctx, const char *algorithm, const char *properties);
const struct EVP_MD *EVP_get_digestbynid(int nid);
void ERR_clear_last_mark(void);
void ERR_pop_to_mark(void);
int EVP_MD_get_size(const struct EVP_MD *md);
int EVP_MD_get_type(const struct EVP_MD *md);
char *ossl_safe_getenv(const char *name);
int pkcs12_gen_gost_mac_key(const char *pass, int passlen, unsigned char *salt, int slen, int iter, int n, unsigned char *out, const struct EVP_MD *md);
int PKCS12_key_gen_utf8_ex(const char *pass, int passlen, unsigned char *salt, int saltlen, int id, int iter, int n, unsigned char *out, const struct EVP_MD *md, void *ctx, const char *propq);
struct HMAC_CTX *HMAC_CTX_new(void);
int HMAC_Init_ex(struct HMAC_CTX *ctx, const void *key, int len, const struct EVP_MD *md, void *impl);
int HMAC_Update(struct HMAC_CTX *ctx, const unsigned char *data, size_t len);
int HMAC_Final(struct HMAC_CTX *ctx, unsigned char *md, unsigned int *len);
void OPENSSL_cleanse(void *ptr, size_t len);
void HMAC_CTX_free(struct HMAC_CTX *ctx);
void EVP_MD_free(struct EVP_MD *md);