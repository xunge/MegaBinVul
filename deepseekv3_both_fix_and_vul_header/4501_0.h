#include <stddef.h>

typedef struct asn1_node_st *asn1_node;

#define ASN1_DER_ERROR -1
#define ASN1_SUCCESS 0

#define DECR_LEN(len, dec) len -= (dec)

static int asn1_get_length_der(const unsigned char *der, int der_len, int *len3);
static void _asn1_append_value(asn1_node node, const unsigned char *data, int len);
static void warn(void);

#define IS_ERR(len, flags) ((len) < 0)