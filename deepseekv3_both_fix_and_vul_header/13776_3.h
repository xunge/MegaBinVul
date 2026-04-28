#include <stdbool.h>
#include <stddef.h>

typedef bool gboolean;
typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx {
    struct pinfo *pinfo;
} asn1_ctx_t;
typedef struct proto_tree proto_tree;
typedef struct pinfo pinfo_t;

#define _U_ __attribute__((unused))

extern int call_ber_oid_callback(const char *id, tvbuff_t *tvb, int offset, pinfo_t *pinfo, proto_tree *tree, void *data);
extern const char *object_identifier_id;