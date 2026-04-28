#include <stddef.h>

#define ASN1_DER_ERROR -1
#define ASN1_SUCCESS 0

#define DECR_LEN(len, decr) (len) -= (decr)
#define IS_ERR(len, flags) ((len) < 0)

typedef struct asn1_node *asn1_node;

int asn1_get_length_der(const unsigned char *der, int der_len, int *len3);
void _asn1_append_value(asn1_node node, const unsigned char *data, int len);
void warn(void);