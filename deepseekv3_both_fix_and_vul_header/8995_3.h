#include <stddef.h>

typedef struct asn1_string_st {
    int type;
    union {
        struct {
            unsigned char *data;
            int length;
        } *sequence;
    } value;
} ASN1_TYPE;

typedef struct X509_algor_st {
    void *algorithm;
    ASN1_TYPE *parameter;
} X509_ALGOR;

typedef struct rsa_pss_params_st {
    X509_ALGOR *maskGenAlgorithm;
} RSA_PSS_PARAMS;

#define V_ASN1_SEQUENCE 16
#define NID_mgf1 911

int OBJ_obj2nid(const void *obj);
RSA_PSS_PARAMS *d2i_RSA_PSS_PARAMS(RSA_PSS_PARAMS **a, const unsigned char **in, long len);
X509_ALGOR *d2i_X509_ALGOR(X509_ALGOR **a, const unsigned char **in, long len);