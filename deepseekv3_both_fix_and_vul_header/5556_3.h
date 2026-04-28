#include <stddef.h>

typedef struct evp_md_ctx_st EVP_MD_CTX;
typedef struct asn1_item_st ASN1_ITEM;
typedef struct X509_algor_st {
    void *algorithm;
} X509_ALGOR;
typedef struct asn1_string_st ASN1_BIT_STRING;
typedef struct evp_pkey_st EVP_PKEY;

#define NID_rsassaPss 912
#define RSA_F_RSA_ITEM_VERIFY 0
#define RSA_R_UNSUPPORTED_SIGNATURE_TYPE 0

int OBJ_obj2nid(void *obj);
void RSAerr(int lib, int reason);
int rsa_pss_to_ctx(EVP_MD_CTX *ctx, void *a, X509_ALGOR *sigalg, EVP_PKEY *pkey);