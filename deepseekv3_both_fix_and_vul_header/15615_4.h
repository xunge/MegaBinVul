#include <stdlib.h>
#include <string.h>

#define EVP_MAX_MD_SIZE 64
#define NID_pkcs7_data 1
#define NID_pkcs7_encrypted 2

typedef struct stack_st {
    int num;
    void **data;
} STACK;

#define STACK_OF(type) struct stack_st_##type
typedef STACK_OF(PKCS7) {
    STACK stack;
} STACK_OF_PKCS7;

typedef STACK_OF(PKCS12_SAFEBAG) {
    STACK stack;
} STACK_OF_PKCS12_SAFEBAG;

typedef struct asn1_string_st {
    int length;
    unsigned char *data;
} ASN1_OCTET_STRING;

typedef struct pkcs12_st {
    int version;
    struct {
        void *dinfo;
    } *mac;
    struct {
        union {
            ASN1_OCTET_STRING *data;
        } d;
    } *authsafes;
} PKCS12;

typedef struct pkcs7_st {
    int type;
    union {
        void *data;
        struct {
            struct {
                void *algorithm;
            } *enc_data;
        } *encrypted;
    } d;
} PKCS7;

typedef struct pkcs12_safebag_st PKCS12_SAFEBAG;
typedef struct X509_sig_st X509_SIG;

STACK_OF_PKCS7 *PKCS12_unpack_authsafes(PKCS12 *p12);
STACK_OF_PKCS7 *sk_PKCS7_new_null();
int sk_PKCS7_num(STACK_OF_PKCS7 *sk);
PKCS7 *sk_PKCS7_value(STACK_OF_PKCS7 *sk, int idx);
int OBJ_obj2nid(int obj);
STACK_OF_PKCS12_SAFEBAG *PKCS12_unpack_p7data(PKCS7 *p7);
STACK_OF_PKCS12_SAFEBAG *PKCS12_unpack_p7encdata(PKCS7 *p7, const char *pass, int passlen);
int alg_get(void *alg, int *pbe_nid, int *pbe_iter, int *pbe_saltlen);
int newpass_bags(STACK_OF_PKCS12_SAFEBAG *bags, const char *oldpass, const char *newpass);
PKCS7 *PKCS12_pack_p7data(STACK_OF_PKCS12_SAFEBAG *bags);
PKCS7 *PKCS12_pack_p7encdata(int pbe_nid, const char *pass, int passlen, unsigned char *salt, int saltlen, int iter, STACK_OF_PKCS12_SAFEBAG *bags);
int sk_PKCS7_push(STACK_OF_PKCS7 *sk, PKCS7 *p7);
void sk_PKCS12_SAFEBAG_pop_free(STACK_OF_PKCS12_SAFEBAG *sk, void (*freefunc)(PKCS12_SAFEBAG *));
void PKCS12_SAFEBAG_free(PKCS12_SAFEBAG *bag);
ASN1_OCTET_STRING *ASN1_OCTET_STRING_new();
int PKCS12_pack_authsafes(PKCS12 *p12, STACK_OF_PKCS7 *safes);
int PKCS12_gen_mac(PKCS12 *p12, const char *pass, int passlen, unsigned char *mac, unsigned int *maclen);
void X509_SIG_getm(X509_SIG *sig, void **palg, ASN1_OCTET_STRING **pdigest);
int ASN1_OCTET_STRING_set(ASN1_OCTET_STRING *str, const unsigned char *data, int len);
void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING *a);
void sk_PKCS7_pop_free(STACK_OF_PKCS7 *sk, void (*freefunc)(PKCS7 *));
void PKCS7_free(PKCS7 *p7);