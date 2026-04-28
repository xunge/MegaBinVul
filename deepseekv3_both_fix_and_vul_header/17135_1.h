#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct _header_field_info header_field_info;
typedef struct _e_internal_error e_internal_error;
typedef struct _wmem_allocator wmem_allocator_t;
typedef struct _ethertype_data ethertype_data_t;
typedef void* dissector_handle_t;

#define _U_ __attribute__((unused))

extern const header_field_info *hfi_vlan;
extern const header_field_info hfi_vlan_priority;
extern const header_field_info hfi_vlan_cfi;
extern const header_field_info hfi_vlan_id;
extern const header_field_info hfi_vlan_id_name;
extern const header_field_info hfi_vlan_len;
extern const header_field_info hfi_vlan_trailer;
extern const header_field_info hfi_vlan_etype;
extern const e_internal_error ei_vlan_len;
extern const e_internal_error ei_vlan_too_many_tags;

extern int ett_vlan;
extern bool vlan_summary_in_tree;
extern struct global_resolv_flags gbl_resolv_flags;
extern dissector_handle_t ethertype_handle;
extern int proto_vlan;

#define IEEE_802_3_MAX_LEN 1500
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define COL_PROTOCOL 0
#define COL_INFO 1
#define TRUE true
#define FALSE false
#define VLAN_MAX_NESTED_TAGS 8

typedef uint16_t guint16;
typedef uint32_t guint;
typedef bool gboolean;
typedef void* gpointer;

struct packet_info {
    struct {
        int vlan_id;
    };
    struct {
        void* cinfo;
    };
    void* pool;
};

struct _header_field_info {
    int id;
};

struct _ethertype_data {
    guint16 etype;
    int offset_after_ethertype;
    proto_tree* fh_tree;
    int etype_id;
    int trailer_id;
    int fcs_len;
};

struct global_resolv_flags {
    bool vlan_name;
};

#define GPOINTER_TO_UINT(p) ((guint)(p))
#define GUINT_TO_POINTER(u) ((gpointer)(u))

wmem_allocator_t* wmem_packet_scope(void);
void* p_get_proto_data(void* pool, packet_info* pinfo, int proto, int id);
void p_add_proto_data(void* pool, packet_info* pinfo, int proto, int id, gpointer data);
void expert_add_info(packet_info* pinfo, proto_item* item, const e_internal_error* ei);

void col_set_str(void* cinfo, int column, const char* str);
void col_clear(void* cinfo, int column);
void columns_set_vlan(void* cinfo, guint16 tci);
guint16 tvb_get_ntohs(tvbuff_t* tvb, int offset);
int tvb_captured_length_remaining(tvbuff_t* tvb, int offset);
int tvb_captured_length(tvbuff_t* tvb);
proto_item* proto_tree_add_item(proto_tree* tree, const header_field_info* hfi, tvbuff_t* tvb, int start, int length, int encoding);
void proto_item_append_text(proto_item* item, const char* format, ...);
proto_tree* proto_item_add_subtree(proto_item* item, int ett);
proto_item* proto_tree_add_string(proto_tree* tree, const header_field_info* hfi, tvbuff_t* tvb, int start, int length, const char* str);
#define PROTO_ITEM_SET_GENERATED(item)
void dissect_802_3(guint16 encap_proto, gboolean is_802_2, tvbuff_t* tvb, int offset, packet_info* pinfo, proto_tree* tree, proto_tree* vlan_tree, int len_id, int trailer_id, const e_internal_error* ei, int fcs_len);
void call_dissector_with_data(dissector_handle_t handle, tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data);
char* get_vlan_name(wmem_allocator_t* allocator, guint16 vlan_id);