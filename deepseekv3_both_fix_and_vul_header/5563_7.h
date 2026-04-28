#include <stdlib.h>
#include <string.h>

#define PKCS7_S_HEADER 0
#define PKCS7_F_PKCS7_DATAINIT 0
#define PKCS7_R_INVALID_NULL_POINTER 0
#define PKCS7_R_NO_CONTENT 0
#define PKCS7_R_CIPHER_NOT_INITIALIZED 0
#define PKCS7_R_UNSUPPORTED_CONTENT_TYPE 0
#define ERR_R_BIO_LIB 0
#define EVP_MAX_KEY_LENGTH 64
#define EVP_MAX_IV_LENGTH 16
#define NID_pkcs7_signed 1
#define NID_pkcs7_signedAndEnveloped 2
#define NID_pkcs7_enveloped 3
#define NID_pkcs7_digest 4
#define NID_pkcs7_data 5

typedef struct bio_st BIO;
typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
typedef struct stack_st STACK;

struct asn1_type_st {
    int type;
    union {
        char *ptr;
    } value;
};

struct asn1_string_st {
    int length;
    unsigned char *data;
};

struct X509_algor_st {
    void *algorithm;
    struct asn1_type_st *parameter;
};

struct pkcs7_recip_info_st {
    // Minimal definition
    int dummy;
};

struct pkcs7_enc_data_st {
    struct X509_algor_st *algorithm;
    EVP_CIPHER *cipher;
};

struct pkcs7_signed_st {
    STACK *md_algs;
    void *contents;
};

struct pkcs7_signedandenveloped_st {
    STACK *recipientinfo;
    STACK *md_algs;
    struct pkcs7_enc_data_st *enc_data;
};

struct pkcs7_enveloped_st {
    STACK *recipientinfo;
    struct pkcs7_enc_data_st *enc_data;
};

struct pkcs7_digest_st {
    struct X509_algor_st *md;
    void *contents;
};

struct pkcs7_st {
    int type;
    int state;
    union {
        struct pkcs7_signed_st *sign;
        struct pkcs7_signedandenveloped_st *signed_and_enveloped;
        struct pkcs7_enveloped_st *enveloped;
        struct pkcs7_digest_st *digest;
        void *ptr;
    } d;
};

typedef struct X509_algor_st X509_ALGOR;
typedef struct pkcs7_recip_info_st PKCS7_RECIP_INFO;
typedef struct pkcs7_st PKCS7;
typedef struct asn1_string_st ASN1_OCTET_STRING;
typedef struct asn1_type_st ASN1_TYPE;

#define STACK_OF(type) struct stack_st
#define sk_X509_ALGOR_num(sk) sk_num((STACK *)sk)
#define sk_X509_ALGOR_value(sk,i) ((X509_ALGOR *)sk_value((STACK *)sk,i))
#define sk_PKCS7_RECIP_INFO_num(sk) sk_num((STACK *)sk)
#define sk_PKCS7_RECIP_INFO_value(sk,i) ((PKCS7_RECIP_INFO *)sk_value((STACK *)sk,i))

int PKCS7_is_detached(PKCS7 *p7);
int PKCS7_bio_add_digest(BIO **pbio, X509_ALGOR *alg);
ASN1_OCTET_STRING *PKCS7_get_octet_string(PKCS7 *p7);
int pkcs7_encode_rinfo(PKCS7_RECIP_INFO *ri, unsigned char *key, int keylen);
void PKCS7err(int f, int r);
void OPENSSL_cleanse(void *ptr, size_t len);
int OBJ_obj2nid(void *obj);
void *OBJ_nid2obj(int nid);
int EVP_CIPHER_key_length(const EVP_CIPHER *cipher);
int EVP_CIPHER_iv_length(const EVP_CIPHER *cipher);
int EVP_CIPHER_type(const EVP_CIPHER *cipher);
int RAND_pseudo_bytes(unsigned char *buf, int num);
int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher, void *impl, unsigned char *key, unsigned char *iv, int enc);
int EVP_CIPHER_CTX_rand_key(EVP_CIPHER_CTX *ctx, unsigned char *key);
int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *ctx, ASN1_TYPE *type);
BIO *BIO_new(void *method);
void BIO_free_all(BIO *bio);
void BIO_push(BIO *b, BIO *append);
void BIO_get_cipher_ctx(BIO *b, EVP_CIPHER_CTX **pctx);
void BIO_set_mem_eof_return(BIO *b, int v);
int sk_num(STACK *sk);
void *sk_value(STACK *sk, int idx);
void *BIO_f_cipher(void);
void *BIO_s_null(void);
void *BIO_s_mem(void);
BIO *BIO_new_mem_buf(const void *buf, int len);
ASN1_TYPE *ASN1_TYPE_new(void);