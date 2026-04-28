#include <stdlib.h>
#include <string.h>

typedef struct bignum_st BIGNUM;
typedef struct asn1_string_st ASN1_STRING;
typedef struct asn1_object_st ASN1_OBJECT;
typedef struct asn1_bit_string_st ASN1_BIT_STRING;
typedef struct asn1_octet_string_st ASN1_OCTET_STRING;

typedef enum {
    POINT_CONVERSION_COMPRESSED,
    POINT_CONVERSION_UNCOMPRESSED,
    POINT_CONVERSION_HYBRID
} point_conversion_form_t;

typedef struct ec_group_st EC_GROUP;
typedef struct ec_point_st EC_POINT;

typedef struct ec_key_st {
    int version;
    EC_GROUP *group;
    EC_POINT *pub_key;
    BIGNUM *priv_key;
    point_conversion_form_t conv_form;
} EC_KEY;

typedef struct ec_privatekey_st {
    long version;
    ASN1_OCTET_STRING *privateKey;
    ASN1_OBJECT *parameters;
    ASN1_BIT_STRING *publicKey;
} EC_PRIVATEKEY;

#define EC_F_D2I_ECPRIVATEKEY 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_EC_LIB 0
#define ERR_R_BN_LIB 0
#define EC_R_MISSING_PRIVATE_KEY 0

void ECerr(int a, int b);
EC_KEY *EC_KEY_new(void);
void EC_KEY_free(EC_KEY *key);
EC_GROUP *EC_GROUP_clear_free(EC_GROUP *group);
EC_POINT *EC_POINT_new(const EC_GROUP *group);
void EC_POINT_clear_free(EC_POINT *point);
int EC_POINT_oct2point(const EC_GROUP *group, EC_POINT *p, 
                      const unsigned char *buf, size_t len, void *ctx);
BIGNUM *BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret);
unsigned char *M_ASN1_STRING_data(ASN1_STRING *x);
int M_ASN1_STRING_length(ASN1_STRING *x);
EC_PRIVATEKEY *EC_PRIVATEKEY_new(void);
void EC_PRIVATEKEY_free(EC_PRIVATEKEY *key);
EC_PRIVATEKEY *d2i_EC_PRIVATEKEY(EC_PRIVATEKEY **a, const unsigned char **in, long len);
EC_GROUP *ec_asn1_pkparameters2group(EC_PRIVATEKEY *key);