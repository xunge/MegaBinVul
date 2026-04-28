#include <stdbool.h>
#include <stddef.h>

#define _U_ __attribute__((unused))
#define FALSE false
#define TRUE true

typedef bool gboolean;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    proto_item *created_item;
    void *pinfo;
} asn1_ctx_t;

extern tvbuff_t *content_tvb;
extern const char *object_identifier_id;
extern proto_tree *top_tree;

int dissect_ber_octet_string(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int, int, tvbuff_t**);
unsigned int tvb_reported_length(const tvbuff_t*);
void proto_item_set_text(proto_item*, const char*, ...);
void call_ber_oid_callback(const char*, tvbuff_t*, int, void*, proto_tree*, void*);