#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef uint32_t guint32;

#define ENC_LITTLE_ENDIAN 0

struct mbim_pair_list {
    guint32 offset;
    guint32 size;
};

typedef struct wmem_array_t wmem_array_t;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

extern int hf_mbim_multiflow_tft_info_session_id;
extern int hf_mbim_multiflow_tft_info_elem_count;
extern int hf_mbim_multiflow_tft_info_tft_list_offset;
extern int hf_mbim_multiflow_tft_info_tft_list_size;
extern int ett_mbim_pair_list;

void de_sm_tflow_temp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint offset, gint size, void *data, int idx);