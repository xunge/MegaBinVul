#include <stdlib.h>
#include <string.h>

typedef struct PKCS12 {
    struct {
        struct {
            void *data;
        } d;
    } *authsafes;
    struct {
        struct {
            void *dinfo;
        } *mac;
    };
} PKCS12;

typedef struct PKCS7 {
    int type;
    union {
        struct {
            struct {
                struct {
                    void *algorithm;
                } *enc_data;
            } *encrypted;
        } d;
    };
} PKCS7;

typedef struct PKCS12_SAFEBAG PKCS12_SAFEBAG;
typedef struct ASN1_OCTET_STRING ASN1_OCTET_STRING;
typedef struct X509_SIG X509_SIG;

struct stack_st_PKCS7;
struct stack_st_PKCS12_SAFEBAG;

#define STACK_OF(type) struct stack_st_##type
#define NID_pkcs7_data 0
#define NID_pkcs7_encrypted 0
#define EVP_MAX_MD_SIZE 64

typedef void (*sk_PKCS12_SAFEBAG_freefunc)(PKCS12_SAFEBAG*);
typedef void (*sk_PKCS7_freefunc)(PKCS7*);

static inline STACK_OF(PKCS7)* sk_PKCS7_new_null(void) { return NULL; }
static inline int sk_PKCS7_num(STACK_OF(PKCS7)* sk) { return 0; }
static inline PKCS7* sk_PKCS7_value(STACK_OF(PKCS7)* sk, int i) { return NULL; }
static inline int sk_PKCS7_push(STACK_OF(PKCS7)* sk, PKCS7* p7) { return 0; }
static inline void sk_PKCS7_pop_free(STACK_OF(PKCS7)* sk, sk_PKCS7_freefunc freefunc) {}
static inline void sk_PKCS12_SAFEBAG_pop_free(STACK_OF(PKCS12_SAFEBAG)* sk, sk_PKCS12_SAFEBAG_freefunc freefunc) {}

static inline ASN1_OCTET_STRING* ASN1_OCTET_STRING_new(void) { return NULL; }
static inline void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING* a) {}
static inline int ASN1_OCTET_STRING_set(ASN1_OCTET_STRING* a, const unsigned char* d, int len) { return 0; }

static inline int OBJ_obj2nid(void* obj) { return 0; }
static inline int alg_get(void* alg, int* pbe_nid, int* pbe_iter, int* pbe_saltlen) { return 0; }
static inline int newpass_bags(STACK_OF(PKCS12_SAFEBAG)* bags, const char* oldpass, const char* newpass) { return 0; }
static inline STACK_OF(PKCS12_SAFEBAG)* PKCS12_unpack_p7data(PKCS7* p7) { return NULL; }
static inline STACK_OF(PKCS12_SAFEBAG)* PKCS12_unpack_p7encdata(PKCS7* p7, const char* pass, int passlen) { return NULL; }
static inline PKCS7* PKCS12_pack_p7data(STACK_OF(PKCS12_SAFEBAG)* bags) { return NULL; }
static inline PKCS7* PKCS12_pack_p7encdata(int pbe_nid, const char* pass, int passlen, unsigned char* salt, int saltlen, int iter, STACK_OF(PKCS12_SAFEBAG)* bags) { return NULL; }
static inline STACK_OF(PKCS7)* PKCS12_unpack_authsafes(PKCS12* p12) { return NULL; }
static inline int PKCS12_pack_authsafes(PKCS12* p12, STACK_OF(PKCS7)* safes) { return 0; }
static inline int PKCS12_gen_mac(PKCS12* p12, const char* pass, int passlen, unsigned char* mac, unsigned int* maclen) { return 0; }
static inline void X509_SIG_getm(X509_SIG* sig, void** palg, ASN1_OCTET_STRING** pdigest) {}
static inline void PKCS12_SAFEBAG_free(PKCS12_SAFEBAG* bag) {}
static inline void PKCS7_free(PKCS7* p7) {}