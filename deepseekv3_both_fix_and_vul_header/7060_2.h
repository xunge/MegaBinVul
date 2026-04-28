#include <stdint.h>
#include <string.h>

typedef uint32_t guint32;

#define ENC_UTF_8 0

extern int ett_nfs4_dirlist;
extern int ett_nfs4_dir_entry;
extern int hf_nfs_name;
extern int hf_nfs4_value_follows;
extern int hf_nfs4_cookie;
extern int hf_nfs4_dir_entry_name;
extern int hf_nfs4_dirlist_eof;
extern int FATTR4_DISSECT_VALUES;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct rpc_call_info_value rpc_call_info_value;
typedef struct wmem_allocator wmem_allocator;

extern wmem_allocator* wmem_packet_scope(void);
extern void* wmem_alloc(wmem_allocator* allocator, size_t size);
extern char* tvb_get_string_enc(wmem_allocator* allocator, tvbuff_t* tvb, int offset, int length, int encoding);
extern void* tvb_memcpy(tvbuff_t* tvb, void* target, int offset, int length);
extern guint32 tvb_get_ntohl(tvbuff_t* tvb, int offset);
extern void tvb_ensure_bytes_exist(tvbuff_t* tvb, int offset, int length);
extern proto_item* proto_tree_add_string_format(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, const char* value, const char* format, ...);
extern proto_tree* proto_item_add_subtree(proto_item* item, int ett);
extern void proto_tree_add_boolean(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, guint32 value);
extern void proto_item_set_len(proto_item* item, int length);
extern proto_tree* proto_tree_add_subtree(proto_tree* parent_tree, tvbuff_t* tvb, int start, int length, int ett, proto_item** tree_item, const char* text);
extern int dissect_rpc_uint64(tvbuff_t* tvb, proto_tree* tree, int hfindex, int offset);
extern int dissect_nfs_utf8string(tvbuff_t* tvb, int offset, proto_tree* tree, int hfindex, void* data);
extern int dissect_nfs4_fattrs(tvbuff_t* tvb, int offset, packet_info* pinfo, proto_tree* tree, int dissect_flags, rpc_call_info_value* civ);
extern int dissect_rpc_bool(tvbuff_t* tvb, proto_tree* tree, int hfindex, int offset);