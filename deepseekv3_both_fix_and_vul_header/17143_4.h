#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct {
    struct {
        struct {
            int visited;
        } flags;
    } *fd;
    struct {
        char *cinfo;
    } *cinfo;
} packet_info;

typedef struct {
    int extra_info_type;
    char *extra_info;
} smb2_saved_t;

typedef struct {
    smb2_saved_t *saved;
} smb2_info_t;

typedef struct {
    int len;
    int offset;
} offset_length_buffer_t;

typedef enum {
    OLB_O_UINT16_S_UINT16,
    OLB_O_UINT32_S_UINT32
} olb_format_t;

typedef enum {
    OLB_TYPE_UNICODE_STRING
} olb_type_t;

enum {
    SMB2_EI_NONE,
    SMB2_EI_FILENAME
};

enum {
    ENC_NA,
    ENC_LITTLE_ENDIAN
};

enum {
    COL_INFO
};

#define g_free free
#define g_malloc malloc
#define g_snprintf snprintf
#define gchar char

extern int hf_smb2_impersonation_level;
extern int hf_smb2_create_flags;
extern int hf_smb2_reserved;
extern int hf_smb2_create_disposition;
extern int hf_smb2_filename;
extern int hf_smb2_extrainfo;

void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding);
void col_append_fstr(void *cinfo, int col, const char *format, const char *str);

int dissect_smb2_buffercode(proto_tree *tree, tvbuff_t *tvb, int offset, void *data);
int dissect_smb2_oplock(proto_tree *tree, tvbuff_t *tvb, int offset);
int dissect_smb_access_mask(tvbuff_t *tvb, proto_tree *tree, int offset);
int dissect_file_ext_attr(tvbuff_t *tvb, proto_tree *tree, int offset);
int dissect_nt_share_access(tvbuff_t *tvb, proto_tree *tree, int offset);
int dissect_nt_create_options(tvbuff_t *tvb, proto_tree *tree, int offset);
int dissect_smb2_olb_length_offset(tvbuff_t *tvb, int offset, offset_length_buffer_t *olb, olb_format_t format, int hf_index);
const char *dissect_smb2_olb_string(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, offset_length_buffer_t *olb, olb_type_t type);
void dissect_smb2_olb_buffer(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, offset_length_buffer_t *olb, smb2_info_t *si, void (*dissector)());
int dissect_smb2_olb_tvb_max_offset(int offset, offset_length_buffer_t *olb);
void dissect_smb2_create_extra_info(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, offset_length_buffer_t *olb, smb2_info_t *si);