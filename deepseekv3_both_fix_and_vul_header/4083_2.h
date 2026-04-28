#include <stdbool.h>
#include <string.h>

typedef bool gboolean;
#define _U_ 

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct asn1_ctx asn1_ctx_t;

struct asn1_ctx {
    struct {
        const char *direct_reference;
    } external;
};

extern int hf_x509af_algorithm_id;
extern const char *algorithm_id;

const char *oid_resolved_from_string(void *scope, const char *oid);
void *wmem_packet_scope(void);
void proto_item_append_text(proto_tree *tree, const char *format, ...);
int dissect_ber_object_identifier_str(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, const char **direct_reference);