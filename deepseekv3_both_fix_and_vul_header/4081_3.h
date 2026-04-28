#include <string.h>

#define _U_ __attribute__((unused))
#define FALSE 0
#define TRUE 1

typedef int gboolean;
typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

static inline int g_strcmp0(const char *str1, const char *str2) {
    if (!str1 || !str2) return str1 != str2;
    return strcmp(str1, str2);
}

extern const char *algorithm_id;

int dissect_ber_bitstring(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int, void*, int, int, tvbuff_t**);
int dissect_pkcs1_RSAPublicKey(gboolean, tvbuff_t*, int, asn1_ctx_t*, proto_tree*, int);