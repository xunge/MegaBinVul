#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint32;

extern int hf_bzr_prefixed_bencode;
extern int hf_bzr_prefixed_bencode_len;
extern int ett_prefixed_bencode;
extern void* bencode_handle;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

proto_item* proto_tree_add_item(proto_tree*, int, tvbuff_t*, int, int, int);
proto_tree* proto_item_add_subtree(proto_item*, int);
tvbuff_t* tvb_new_subset_length(tvbuff_t*, int, int);
guint32 tvb_get_ntohl(tvbuff_t*, int);
void call_dissector(void*, tvbuff_t*, packet_info*, proto_tree*);

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1