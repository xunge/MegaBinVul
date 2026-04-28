#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef uint32_t guint32;
typedef uint32_t guint;
typedef int gboolean;

#define FALSE 0
#define TRUE 1
#define ENC_LITTLE_ENDIAN 0

struct mbim_pair_list {
    guint32 offset;
    guint32 size;
};

typedef struct wmem_array_t wmem_array_t;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

extern int hf_mbim_provisioned_contexts_info_elem_count;
extern int hf_mbim_provisioned_contexts_info_provisioned_context_offset;
extern int hf_mbim_provisioned_contexts_info_provisioned_context_size;
extern int ett_mbim_pair_list;

static void mbim_dissect_context(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, gboolean false);