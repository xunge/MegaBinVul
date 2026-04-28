#include <stdint.h>
#include <stddef.h>

#define _U_ __attribute__((unused))

struct mbim_conv_info {
    uint32_t cellular_class;
};

struct mbim_pair_list {
    uint32_t offset;
    uint32_t size;
};

typedef int32_t gint;
typedef uint32_t guint32;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct wmem_array_t wmem_array_t;
typedef struct expert_field expert_field;

extern int hf_mbim_subscr_ready_status_ready_state;
extern int hf_mbim_subscr_ready_status_susbcr_id_offset;
extern int hf_mbim_subscr_ready_status_susbcr_id_size;
extern int hf_mbim_subscr_ready_status_sim_icc_id_offset;
extern int hf_mbim_subscr_ready_status_sim_icc_id_size;
extern int hf_mbim_subscr_ready_status_ready_info;
extern int hf_mbim_subscr_ready_status_elem_count;
extern int hf_mbim_subscr_ready_status_tel_nb_offset;
extern int hf_mbim_subscr_ready_status_tel_nb_size;
extern int hf_mbim_subscr_ready_status_susbcr_id;
extern int hf_mbim_subscr_ready_status_sim_icc_id;
extern int hf_mbim_subscr_ready_status_tel_nb;
extern int ett_mbim_pair_list;
extern expert_field ei_mbim_oversized_string;

#define MBIM_CELLULAR_CLASS_CDMA 0
#define ENC_LITTLE_ENDIAN 0
#define ENC_UTF_16 0

static inline void* wmem_array_sized_new(void* scope, size_t size, guint32 count) { return NULL; }
static inline void* wmem_packet_scope(void) { return NULL; }
static inline void wmem_array_append_one(wmem_array_t* array, struct mbim_pair_list item) {}
static inline void* wmem_array_index(wmem_array_t* array, guint32 index) { return NULL; }
static inline proto_item* proto_tree_add_item(proto_tree* tree, int hf, tvbuff_t* tvb, gint offset, gint length, int encoding) { return NULL; }
static inline proto_item* proto_tree_add_item_ret_uint(proto_tree* tree, int hf, tvbuff_t* tvb, gint offset, gint length, int encoding, guint32* retval) { return NULL; }
static inline proto_tree* proto_tree_add_subtree(proto_tree* tree, tvbuff_t* tvb, gint offset, gint length, int ett, proto_item** ti, const char* text) { return NULL; }
static inline void expert_add_info(packet_info* pinfo, proto_item* item, expert_field* ef) {}