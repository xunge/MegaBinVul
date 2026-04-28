#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bio_st BIO;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct x509_st X509;
typedef struct X509_algor_st {
    void *algorithm;
    void *parameter;
} X509_ALGOR;
typedef struct asn1_string_st {
    unsigned char *data;
    int length;
} ASN1_OCTET_STRING;
typedef struct evp_md_st EVP_MD;
typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

typedef struct pkcs7_recip_info_st PKCS7_RECIP_INFO;

typedef struct pkcs7_signed_st {
    void *contents;
    void *md_algs;
} PKCS7_SIGNED;

typedef struct pkcs7_signedandenveloped_st {
    void *recipientinfo;
    void *md_algs;
    struct {
        X509_ALGOR *algorithm;
        ASN1_OCTET_STRING *enc_data;
    } *enc_data;
} PKCS7_SIGNED_ENVELOPED;

typedef struct pkcs7_enveloped_st {
    void *recipientinfo;
    struct {
        X509_ALGOR *algorithm;
        ASN1_OCTET_STRING *enc_data;
    } *enc_data;
} PKCS7_ENVELOPED;

typedef struct pkcs7_st {
    int type;
    int state;
    union {
        PKCS7_SIGNED *sign;
        PKCS7_SIGNED_ENVELOPED *signed_and_enveloped;
        PKCS7_ENVELOPED *enveloped;
        void *ptr;
    } d;
} PKCS7;

typedef struct stack_st {
    int dummy;
} STACK_OF;

#define STACK_OF(type) struct stack_st
#define sk_X509_ALGOR_num(st) 0
#define sk_X509_ALGOR_value(st,i) NULL
#define sk_PKCS7_RECIP_INFO_num(st) 0
#define sk_PKCS7_RECIP_INFO_value(st,i) NULL

#define NID_pkcs7_signed 1
#define NID_pkcs7_signedAndEnveloped 2
#define NID_pkcs7_enveloped 3

#define PKCS7_S_HEADER 0
#define PKCS7_F_PKCS7_DATADECODE 0
#define PKCS7_R_INVALID_NULL_POINTER 0
#define PKCS7_R_NO_CONTENT 0
#define PKCS7_R_INVALID_SIGNED_DATA_TYPE 0
#define PKCS7_R_UNSUPPORTED_CIPHER_TYPE 0
#define PKCS7_R_UNSUPPORTED_CONTENT_TYPE 0
#define PKCS7_R_UNKNOWN_DIGEST_TYPE 0
#define PKCS7_R_NO_RECIPIENT_MATCHES_CERTIFICATE 0
#define ERR_R_BIO_LIB 0

int OBJ_obj2nid(int x) { return 0; }
void PKCS7err(int a, int b) {}
int PKCS7_is_detached(PKCS7 *x) { return 0; }
ASN1_OCTET_STRING *PKCS7_get_octet_string(void *x) { return NULL; }
BIO *BIO_new(void *x) { return NULL; }
void BIO_set_md(BIO *x, const EVP_MD *y) {}
void BIO_push(BIO *x, BIO *y) {}
const EVP_MD *EVP_get_digestbynid(int x) { return NULL; }
const EVP_CIPHER *EVP_get_cipherbyobj(void *x) { return NULL; }
int pkcs7_cmp_ri(PKCS7_RECIP_INFO *x, X509 *y) { return 0; }
int pkcs7_decrypt_rinfo(unsigned char **x, int *y, PKCS7_RECIP_INFO *z, EVP_PKEY *a) { return 0; }
void ERR_clear_error(void) {}
void BIO_get_cipher_ctx(BIO *x, EVP_CIPHER_CTX **y) {}
int EVP_CipherInit_ex(EVP_CIPHER_CTX *x, const EVP_CIPHER *y, void *z, void *a, void *b, int c) { return 0; }
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *x, void *y) { return 0; }
int EVP_CIPHER_CTX_key_length(EVP_CIPHER_CTX *x) { return 0; }
void *OPENSSL_malloc(int x) { return NULL; }
int EVP_CIPHER_CTX_rand_key(EVP_CIPHER_CTX *x, unsigned char *y) { return 0; }
int EVP_CIPHER_CTX_set_key_length(EVP_CIPHER_CTX *x, int y) { return 0; }
void OPENSSL_clear_free(void *x, int y) {}
BIO *BIO_new_mem_buf(void *x, int y) { return NULL; }
void BIO_set_mem_eof_return(BIO *x, int y) {}
void BIO_free_all(BIO *x) {}
void *BIO_f_md() { return NULL; }
void *BIO_f_cipher() { return NULL; }
void *BIO_s_mem() { return NULL; }