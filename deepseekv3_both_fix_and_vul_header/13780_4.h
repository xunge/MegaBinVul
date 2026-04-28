#include <stdint.h>
#include <stddef.h>

typedef int gboolean;
typedef uint32_t guint32;

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))

extern int dissect_ber_integer(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int, int, guint32*);
extern void proto_item_append_text(proto_tree*, const char*, ...);

extern proto_tree* cap_tree;