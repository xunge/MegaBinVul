#include <stdbool.h>
#include <stddef.h>

#define _U_ __attribute__((unused))

typedef bool gboolean;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct {
    int dummy;
} asn1_par_t;

extern proto_tree *top_tree;
extern tvbuff_t *content_tvb;
extern const char *object_identifier_id;
extern int ett_cms_ContentInfo;
extern asn1_par_t ContentInfo_sequence[];
extern int dissect_ber_sequence(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int, asn1_par_t*, int, int);