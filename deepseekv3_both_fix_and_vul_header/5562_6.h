#include <stdlib.h>
#include <string.h>

typedef struct asn1_string_st {
    int length;
    int flags;
    unsigned char *data;
} ASN1_OCTET_STRING;

typedef struct stack_st {
    void **data;
    int num;
} STACK;

typedef struct x509_attribute_st {
    void *object;
} X509_ATTRIBUTE;

typedef struct stack_st_X509_ATTRIBUTE {
    X509_ATTRIBUTE **data;
    int num;
} STACK_OF_X509_ATTRIBUTE;

typedef struct stack_st_PKCS7_SIGNER_INFO {
    struct pkcs7_signer_info_st **data;
    int num;
} STACK_OF_PKCS7_SIGNER_INFO;

typedef struct pkcs7_signer_info_st {
    void *pkey;
    struct {
        void *algorithm;
    } *digest_alg;
    STACK_OF_X509_ATTRIBUTE *auth_attr;
    ASN1_OCTET_STRING *enc_digest;
} PKCS7_SIGNER_INFO;

typedef struct pkcs7_enc_content_st {
    ASN1_OCTET_STRING *enc_data;
} PKCS7_ENC_CONTENT;

typedef struct pkcs7_signedandenveloped_st {
    STACK_OF_PKCS7_SIGNER_INFO *signer_info;
    PKCS7_ENC_CONTENT *enc_data;
} PKCS7_SIGNEDANDENVELOPED;

typedef struct pkcs7_enveloped_st {
    PKCS7_ENC_CONTENT *enc_data;
} PKCS7_ENVELOPED;

typedef struct pkcs7_signed_st {
    STACK_OF_PKCS7_SIGNER_INFO *signer_info;
    struct {
        int type;
        union {
            ASN1_OCTET_STRING *data;
        } d;
    } *contents;
} PKCS7_SIGNED;

typedef struct pkcs7_digest_st {
    struct {
        int type;
        union {
            ASN1_OCTET_STRING *data;
        } d;
    } *contents;
    struct {
        void *algorithm;
    } *md;
    ASN1_OCTET_STRING *digest;
} PKCS7_DIGEST;

typedef struct pkcs7_st {
    int type;
    int state;
    union {
        void *ptr;
        ASN1_OCTET_STRING *data;
        PKCS7_SIGNEDANDENVELOPED *signed_and_enveloped;
        PKCS7_ENVELOPED *enveloped;
        PKCS7_SIGNED *sign;
        PKCS7_DIGEST *digest;
    } d;
    int detached;
} PKCS7;

typedef struct evp_md_ctx_st {
    void *digest;
    void *md_data;
} EVP_MD_CTX;

typedef struct bio_st {
    int type;
    int flags;
    void *ptr;
} BIO;

#define PKCS7_F_PKCS7_DATAFINAL 0
#define PKCS7_R_INVALID_NULL_POINTER 0
#define PKCS7_R_NO_CONTENT 0
#define PKCS7_R_UNSUPPORTED_CONTENT_TYPE 0
#define PKCS7_R_UNABLE_TO_FIND_MEM_BIO 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_EVP_LIB 0

#define PKCS7_S_HEADER 0
#define NID_pkcs7_data 0
#define NID_pkcs7_signed 1
#define NID_pkcs7_enveloped 2
#define NID_pkcs7_signedAndEnveloped 3
#define NID_pkcs7_digest 4

#define BIO_TYPE_MEM 0
#define BIO_FLAGS_MEM_RDONLY 0
#define ASN1_STRING_FLAG_NDEF 0

#define EVP_MAX_MD_SIZE 64

void PKCS7err(int f, int r);
int OBJ_obj2nid(int o);
int PKCS7_type_is_data(void *a);
int PKCS7_is_detached(PKCS7 *p7);
BIO *PKCS7_find_digest(EVP_MD_CTX **pmd, BIO *bio, int nid);
ASN1_OCTET_STRING *PKCS7_get_octet_string(void *contents);
int do_pkcs7_signed_attrib(PKCS7_SIGNER_INFO *si, EVP_MD_CTX *mctx);
int sk_num(void *sk);
void *sk_value(void *sk, int idx);
void *OPENSSL_malloc(int size);
void EVP_MD_CTX_init(EVP_MD_CTX *ctx);
int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out, EVP_MD_CTX *in);
void EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx);
int EVP_SignFinal(EVP_MD_CTX *ctx, unsigned char *sigret, unsigned int *siglen, void *pkey);
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s);
int EVP_PKEY_size(void *pkey);
BIO *BIO_find_type(BIO *bio, int type);
long BIO_get_mem_data(BIO *bio, char **pp);
void BIO_set_flags(BIO *bio, int flags);
void BIO_set_mem_eof_return(BIO *bio, int v);
int ASN1_STRING_set0(ASN1_OCTET_STRING *str, void *data, int len);
void M_ASN1_OCTET_STRING_free(ASN1_OCTET_STRING *a);
ASN1_OCTET_STRING *M_ASN1_OCTET_STRING_new(void);
int M_ASN1_OCTET_STRING_set(ASN1_OCTET_STRING *str, const unsigned char *data, int len);

#define STACK_OF(type) struct stack_st_##type
#define sk_PKCS7_SIGNER_INFO_num(st) sk_num((void *)(st))
#define sk_PKCS7_SIGNER_INFO_value(st,i) ((PKCS7_SIGNER_INFO *)sk_value((void *)(st),(i)))
#define sk_X509_ATTRIBUTE_num(st) sk_num((void *)(st))