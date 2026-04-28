#include <stdint.h>
#include <stddef.h>

#define _U_ __attribute__((unused))

typedef int gboolean;
typedef int8_t gint8;
typedef int32_t gint32;
typedef uint32_t guint32;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct pinfo_t pinfo_t;

typedef struct {
    pinfo_t *pinfo;
    struct {
        const char *direct_reference;
    } external;
} asn1_ctx_t;

int dissect_ber_identifier(pinfo_t *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gint8 *ber_class, gboolean *pc, gint32 *tag);
int dissect_ber_length(pinfo_t *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 *len, gboolean *ind);
int call_ber_oid_callback(const char *direct_reference, tvbuff_t *tvb, int offset, pinfo_t *pinfo, proto_tree *tree, void *user_data);