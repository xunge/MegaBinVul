#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;

typedef struct {
    void *cinfo;
    struct {
        struct {
            unsigned int visited;
        } flags;
    } *fd;
} packet_info;

typedef struct proto_tree proto_tree;

typedef struct {
    int infolevel;
    int extra_info_type;
    void *extra_info;
} saved_info_t;

typedef struct {
    saved_info_t *saved;
} smb2_info_t;

typedef struct offset_length_buffer {
    size_t len;
    // other members...
} offset_length_buffer_t;

enum {
    FID_MODE_USE,
    OLB_O_UINT16_S_UINT16,
    OLB_TYPE_UNICODE_STRING,
    COL_INFO,
    SMB2_EI_FINDPATTERN
};

#define ENC_LITTLE_ENDIAN 0

typedef uint8_t guint8;
typedef uint32_t guint32;

extern const int hf_smb2_find_flags_restart_scans;
extern const int hf_smb2_find_flags_single_entry;
extern const int hf_smb2_find_flags_index_specified;
extern const int hf_smb2_find_flags_reopen;
extern const int hf_smb2_find_info_level;
extern const int hf_smb2_find_flags;
extern const int hf_smb2_file_index;
extern const int hf_smb2_find_pattern;
extern const int hf_smb2_output_buffer_len;
extern const int ett_smb2_find_flags;

typedef struct {
    const char *name;
    int value;
} value_string;
extern const value_string smb2_find_info_levels[];

guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
int dissect_smb2_buffercode(proto_tree *tree, tvbuff_t *tvb, int offset, void*);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, int offset, int hfindex, int ett, const int *fields, int encoding);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
int dissect_smb2_fid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si, int mode);
int dissect_smb2_olb_length_offset(tvbuff_t *tvb, int offset, offset_length_buffer_t *olb, int type, int hfindex);
const char *dissect_smb2_olb_string(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, offset_length_buffer_t *olb, int type);
int dissect_smb2_olb_tvb_max_offset(int offset, offset_length_buffer_t *olb);
void col_append_fstr(void *cinfo, int column, const char *format, ...);
const char *val_to_str(guint32 value, const value_string *vs, const char *fmt);

void *g_malloc(size_t size);
int g_snprintf(char *str, size_t size, const char *format, ...);