#include <stddef.h>
#include <stdint.h>

#define _U_ __attribute__((unused))

typedef unsigned int gboolean;
typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t {
    void *pinfo;
} asn1_ctx_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;

extern int call_ber_oid_callback(const char *oid, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data);
extern const char *object_identifier_id;