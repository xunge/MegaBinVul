#include <stdlib.h>

#define NID_undef 0
#define NID_pkcs7_data 21
#define NID_pkcs7_encrypted 26
#define EVP_MAX_MD_SIZE 64

typedef struct pkcs7_st {
    int type;
    struct {
        struct {
            struct {
                void *algorithm;
            } *enc_data;
        } *encrypted;
    } d;
    struct {
        void *libctx;
        const char *propq;
    } ctx;
} PKCS7;

typedef struct pkcs12_st {
    struct {
        struct {
            void *data;
        } d;
    } *authsafes;
    struct {
        void *dinfo;
    } *mac;
} PKCS12;

typedef struct pkcs12_safebag_st PKCS12_SAFEBAG;
typedef struct asn1_octet_string_st ASN1_OCTET_STRING;
typedef struct X509_sig_st X509_SIG;

typedef struct stack_st {
    int count;
    void **data;
} STACK;

typedef STACK *STACK_OF_PKCS7;
typedef STACK *STACK_OF_PKCS12_SAFEBAG;

STACK_OF_PKCS7 PKCS12_unpack_authsafes(PKCS12* p12);
STACK_OF_PKCS7 sk_PKCS7_new_null();
int sk_PKCS7_num(STACK_OF_PKCS7 sk);
PKCS7* sk_PKCS7_value(STACK_OF_PKCS7 sk, int idx);
int OBJ_obj2nid(int type);
STACK_OF_PKCS12_SAFEBAG PKCS12_unpack_p7data(PKCS7* p7);
STACK_OF_PKCS12_SAFEBAG PKCS12_unpack_p7encdata(PKCS7* p7, const char* pass, int passlen);
int alg_get(void* alg, int* pbe_nid, int* pbe_iter, int* pbe_saltlen, int* cipherid);
int newpass_bags(STACK_OF_PKCS12_SAFEBAG bags, const char* oldpass, const char* newpass, void* libctx, const char* propq);
PKCS7* PKCS12_pack_p7data(STACK_OF_PKCS12_SAFEBAG bags);
PKCS7* PKCS12_pack_p7encdata_ex(int pbe_nid, const char* pass, int passlen, unsigned char* salt, int saltlen, int iter, STACK_OF_PKCS12_SAFEBAG bags, void* libctx, const char* propq);
int sk_PKCS7_push(STACK_OF_PKCS7 sk, PKCS7* p7);
void sk_PKCS12_SAFEBAG_pop_free(STACK_OF_PKCS12_SAFEBAG sk, void (*freefunc)(PKCS12_SAFEBAG*));
void PKCS12_SAFEBAG_free(PKCS12_SAFEBAG* bag);
ASN1_OCTET_STRING* ASN1_OCTET_STRING_new();
int PKCS12_pack_authsafes(PKCS12* p12, STACK_OF_PKCS7 safes);
int PKCS12_gen_mac(PKCS12* p12, const char* pass, int passlen, unsigned char* mac, unsigned int* maclen);
void X509_SIG_getm(X509_SIG* sig, void** palg, ASN1_OCTET_STRING** pdigest);
int ASN1_OCTET_STRING_set(ASN1_OCTET_STRING* str, const unsigned char* data, int len);
void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING* a);
void sk_PKCS7_pop_free(STACK_OF_PKCS7 sk, void (*freefunc)(PKCS7*));
void PKCS7_free(PKCS7* p7);

#define STACK_OF(type) struct stack_st_##type
#define DECLARE_STACK_OF(type) typedef STACK_OF(type) *STACK_OF_##type