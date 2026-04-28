#include <stddef.h>

struct SM2_Ciphertext_st {
    struct ASN1_OCTET_STRING *C2;
};

struct ASN1_OCTET_STRING {
    size_t length;
};

typedef struct EC_KEY EC_KEY;
typedef struct EVP_MD EVP_MD;
typedef struct EC_GROUP EC_GROUP;

#define SM2_F_SM2_PLAINTEXT_SIZE 0
#define SM2_R_INVALID_ENCODING 0
#define SM2_R_INVALID_DIGEST 0
#define SM2_R_INVALID_FIELD 0

struct SM2_Ciphertext_st *d2i_SM2_Ciphertext(struct SM2_Ciphertext_st **a, const unsigned char **pp, long length);
void SM2_Ciphertext_free(struct SM2_Ciphertext_st *a);
int SM2err(int f, int r);
size_t ec_field_size(const EC_GROUP *group);
const EC_GROUP *EC_KEY_get0_group(const EC_KEY *key);
int EVP_MD_size(const EVP_MD *digest);