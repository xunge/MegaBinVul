#include <stdbool.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct packet_info packet_info;
typedef struct asn1_ctx_t {
    proto_item *created_item;
    packet_info *pinfo;
} asn1_ctx_t;

#define _U_ __attribute__((unused))
typedef bool gboolean;

extern int object_identifier_id;
extern int dissect_ber_octet_string(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int, int, tvbuff_t**);
extern void PBE_decrypt_data(int, tvbuff_t*, packet_info*, asn1_ctx_t*, proto_item*);