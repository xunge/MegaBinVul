#include <stddef.h>

typedef int gboolean;
#define _U_ __attribute__((unused))

typedef struct asn1_ctx_t {
    void *pinfo;
} asn1_ctx_t;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;

extern int call_ber_oid_callback(const char *id, tvbuff_t *tvb, int offset, void *pinfo, proto_tree *tree, void *data);
extern const char object_identifier_id[];