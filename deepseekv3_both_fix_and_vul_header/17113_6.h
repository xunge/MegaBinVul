#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint;
typedef uint32_t guint32;
typedef int32_t gint;
typedef int gboolean;

typedef struct {
    void* cinfo;
    guint16 destport;
    void* pool;
} packet_info;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

typedef struct {
    guint8 flags;
    guint8 fragmentId;
    guint16 length;
    guint8 rssi;
    guint8 snr;
} LWAPP_Header;

#define LWAPP_FLAGS_T 0x01
#define LWAPP_MAX_NESTED_ENCAP 10
#define ENC_NA 0
#define _U_
#define COL_PROTOCOL 0
#define COL_INFO 1

extern int hf_lwapp_flags_type;
extern int hf_lwapp_flags_fragment;
extern int hf_lwapp_flags_fragment_type;
extern int hf_lwapp_flags;
extern int hf_lwapp_version;
extern int hf_lwapp_slotid;
extern int hf_lwapp_fragment_id;
extern int hf_lwapp_length;
extern int hf_lwapp_rssi;
extern int hf_lwapp_snr;
extern int hf_lwapp_control_mac;
extern int proto_lwapp;
extern int ett_lwapp;
extern int ett_lwapp_flags;
extern expert_field ei_lwapp_too_many_encap;
extern gboolean swap_frame_control;
extern void* wlan_bsfc_handle;
extern void* wlan_handle;

extern void* p_get_proto_data(void*, void*, int, int);
extern void p_add_proto_data(void*, void*, int, int, void*);
extern guint GPOINTER_TO_UINT(void*);
extern void* GUINT_TO_POINTER(guint);
extern void col_set_str(void*, int, const char*);
extern void col_append_str(void*, int, const char*);
extern void tvb_memcpy(tvbuff_t*, void*, int, int);
extern guint16 g_ntohs(guint16);
extern proto_item* proto_tree_add_item(proto_tree*, int, tvbuff_t*, int, int, int);
extern proto_tree* proto_item_add_subtree(proto_item*, int);
extern void expert_add_info(packet_info*, proto_item*, expert_field*);
extern void proto_tree_add_ether(proto_tree*, int, tvbuff_t*, int, int, const guint8*);
extern void proto_tree_add_uint(proto_tree*, int, tvbuff_t*, int, int, guint32);
extern void proto_tree_add_bitmask(proto_tree*, tvbuff_t*, int, int, int, const int**, int);
extern tvbuff_t* tvb_new_subset_remaining(tvbuff_t*, int);
extern void call_dissector(void*, tvbuff_t*, packet_info*, proto_tree*);
extern void dissect_control(tvbuff_t*, packet_info*, proto_tree*);
extern int tvb_captured_length(tvbuff_t*);