#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef uint64_t guint64;
typedef uint32_t guint32;
typedef int32_t gint;
typedef int gboolean;

#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 1

#define NULL ((void*)0)

typedef struct {
    guint64 end_of_file;
    guint32 attr_mask;
} eo_file_info_t;

typedef struct {
    gint extra_info_type;
    void* extra_info;
} saved_info_t;

typedef struct {
    guint32 status;
    eo_file_info_t *eo_file_info;
    saved_info_t *saved;
} smb2_info_t;

typedef struct {
    guint32 length;
    guint32 offset;
} offset_length_buffer_t;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

#define OLB_O_UINT32_S_UINT32 0
#define FID_MODE_OPEN 0
#define SMB2_EI_NONE 0
#define SMB2_EI_FILENAME 1

extern int hf_smb2_create_rep_flags;
extern int hf_smb2_create_rep_flags_reparse_point;
extern int hf_smb2_create_action;
extern int hf_smb2_create_timestamp;
extern int hf_smb2_last_access_timestamp;
extern int hf_smb2_last_write_timestamp;
extern int hf_smb2_last_change_timestamp;
extern int hf_smb2_allocation_size;
extern int hf_smb2_end_of_file;
extern int hf_smb2_reserved;
extern int hf_smb2_extrainfo;
extern int ett_smb2_create_rep_flags;

static inline guint64 tvb_get_letoh64(tvbuff_t *tvb, int offset) { return 0; }
static inline guint32 tvb_get_letohl(tvbuff_t *tvb, int offset) { return 0; }
static inline void g_free(void *ptr) { free(ptr); }

int dissect_smb2_buffercode(proto_tree *tree, tvbuff_t *tvb, int offset, void *data);
int dissect_smb2_error_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si, gboolean *continue_dissection);
int dissect_smb2_oplock(proto_tree *tree, tvbuff_t *tvb, int offset);
int dissect_nt_64bit_time(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_index);
int dissect_file_ext_attr(tvbuff_t *tvb, proto_tree *tree, int offset);
int dissect_smb2_fid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si, int mode);
int dissect_smb2_olb_length_offset(tvbuff_t *tvb, int offset, offset_length_buffer_t *olb, int type, int hf_index);
void dissect_smb2_olb_buffer(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, offset_length_buffer_t *olb, smb2_info_t *si, void (*dissector)(tvbuff_t *, packet_info *, proto_tree *, int, smb2_info_t *));
int dissect_smb2_olb_tvb_max_offset(int offset, offset_length_buffer_t *olb);
void dissect_smb2_create_extra_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si);
void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, int ett_index, const int **fields, int encoding);
void proto_tree_add_item(proto_tree *tree, int hf_index, tvbuff_t *tvb, int offset, int length, int encoding);