#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct tvbuff_t tvbuff_t;

typedef struct packet_info {
    struct {
        struct {
            bool visited;
        } flags;
        void *fd;
    } *fd;
    void *cinfo;
    char *info;
} packet_info;

typedef struct proto_tree {
    int hf_smb2_find_info_level;
    int hf_smb2_find_info_blob;
} proto_tree;

typedef struct proto_item proto_item;

typedef struct smb2_saved_info {
    uint32_t infolevel;
    int extra_info_type;
    void *extra_info;
} smb2_saved_info;

typedef struct smb2_info_t {
    uint32_t status;
    smb2_saved_info *saved;
} smb2_info_t;

typedef struct offset_length_buffer_t {
    // Define necessary fields for offset_length_buffer_t
    uint32_t offset;
    uint32_t length;
    void *buffer;
} offset_length_buffer_t;

typedef bool gboolean;

enum {
    SMB2_EI_NONE = 0,
    SMB2_EI_FINDPATTERN = 1
};

enum {
    COL_INFO = 0
};

#define OLB_O_UINT16_S_UINT32 0
#define _U_
#define hf_smb2_find_info_level 0
#define hf_smb2_find_info_blob 0

extern const void *smb2_find_info_levels;

extern int dissect_smb2_buffercode(proto_tree *tree, tvbuff_t *tvb, int offset, void *);
extern int dissect_smb2_error_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si, gboolean *continue_dissection);
extern int dissect_smb2_olb_length_offset(tvbuff_t *tvb, int offset, offset_length_buffer_t *olb, int type, int hf);
extern void dissect_smb2_olb_buffer(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, offset_length_buffer_t *olb, smb2_info_t *si, void (*func)());
extern int dissect_smb2_olb_tvb_max_offset(int offset, offset_length_buffer_t *olb);
extern const char *val_to_str(uint32_t val, const void *table, const char *fmt);
extern void col_append_fstr(void *cinfo, int column, const char *format, ...);
extern void PROTO_ITEM_SET_GENERATED(proto_item *item);
extern void g_free(void *ptr);
extern proto_item *proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, uint32_t value);
extern void dissect_smb2_find_data(void);