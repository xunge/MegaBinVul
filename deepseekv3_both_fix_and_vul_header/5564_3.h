#include <stdlib.h>
#include <string.h>

typedef struct bio_st BIO;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct x509_st X509;

struct X509_algor_st {
    void *algorithm;
    void *parameter;
};
typedef struct X509_algor_st X509_ALGOR;

struct asn1_string_st {
    int length;
    unsigned char *data;
};
typedef struct asn1_string_st ASN1_OCTET_STRING;

typedef struct evp_md_st EVP_MD;
typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

struct pkcs7_recip_info_st {
    void *cert;
    void *key;
};
typedef struct pkcs7_recip_info_st PKCS7_RECIP_INFO;

struct stack_st_X509_ALGOR;
struct stack_st_PKCS7_RECIP_INFO;
#define STACK_OF(type) struct stack_st_##type
typedef STACK_OF(X509_ALGOR) *sk_X509_ALGOR;
typedef STACK_OF(PKCS7_RECIP_INFO) *sk_PKCS7_RECIP_INFO;

typedef struct pkcs7_st {
    int type;
    int state;
    union {
        struct {
            sk_X509_ALGOR *md_algs;
            void *contents;
        } *sign;
        struct {
            sk_X509_ALGOR *md_algs;
            sk_PKCS7_RECIP_INFO *recipientinfo;
            struct {
                X509_ALGOR *algorithm;
                ASN1_OCTET_STRING *enc_data;
            } *enc_data;
        } *signed_and_enveloped;
        struct {
            sk_PKCS7_RECIP_INFO *recipientinfo;
            struct {
                X509_ALGOR *algorithm;
                ASN1_OCTET_STRING *enc_data;
            } *enc_data;
        } *enveloped;
        void *ptr;
    } d;
} PKCS7;

#define PKCS7_F_PKCS7_DATADECODE 0
#define PKCS7_R_INVALID_NULL_POINTER 0
#define PKCS7_R_NO_CONTENT 0
#define PKCS7_R_INVALID_SIGNED_DATA_TYPE 0
#define PKCS7_R_UNSUPPORTED_CIPHER_TYPE 0
#define PKCS7_R_UNSUPPORTED_CONTENT_TYPE 0
#define PKCS7_R_NO_RECIPIENT_MATCHES_CERTIFICATE 0
#define PKCS7_R_UNKNOWN_DIGEST_TYPE 0
#define ERR_R_BIO_LIB 0

#define PKCS7_S_HEADER 0
#define NID_pkcs7_signed 1
#define NID_pkcs7_signedAndEnveloped 2
#define NID_pkcs7_enveloped 3

void PKCS7err(int a, int b);
int OBJ_obj2nid(void *a);
int PKCS7_is_detached(PKCS7 *a);
ASN1_OCTET_STRING *PKCS7_get_octet_string(void *a);
const EVP_CIPHER *EVP_get_cipherbyobj(void *a);
const EVP_MD *EVP_get_digestbynid(int a);
BIO *BIO_new(void *a);
void BIO_set_md(BIO *a, const EVP_MD *b);
void BIO_push(BIO *a, BIO *b);
void BIO_free_all(BIO *a);
void *BIO_f_md(void);
void *BIO_f_cipher(void);
void BIO_get_cipher_ctx(BIO *a, EVP_CIPHER_CTX **b);
int EVP_CipherInit_ex(EVP_CIPHER_CTX *a, const EVP_CIPHER *b, void *c, void *d, void *e, int f);
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *a, void *b);
int EVP_CIPHER_CTX_key_length(EVP_CIPHER_CTX *a);
int EVP_CIPHER_CTX_set_key_length(EVP_CIPHER_CTX *a, int b);
int EVP_CIPHER_CTX_rand_key(EVP_CIPHER_CTX *a, unsigned char *b);
void *OPENSSL_malloc(int a);
void OPENSSL_free(void *a);
void OPENSSL_cleanse(void *a, int b);
void ERR_clear_error(void);
int sk_X509_ALGOR_num(sk_X509_ALGOR *a);
X509_ALGOR *sk_X509_ALGOR_value(sk_X509_ALGOR *a, int b);
int sk_PKCS7_RECIP_INFO_num(sk_PKCS7_RECIP_INFO *a);
PKCS7_RECIP_INFO *sk_PKCS7_RECIP_INFO_value(sk_PKCS7_RECIP_INFO *a, int b);
int pkcs7_cmp_ri(PKCS7_RECIP_INFO *a, X509 *b);
int pkcs7_decrypt_rinfo(unsigned char **a, int *b, PKCS7_RECIP_INFO *c, EVP_PKEY *d);
BIO *BIO_new_mem_buf(void *a, int b);
void *BIO_s_mem(void);
void BIO_set_mem_eof_return(BIO *a, int b);