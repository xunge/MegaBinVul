#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

typedef unsigned char u8;
typedef int GF_Err;
typedef bool Bool;
typedef struct GF_BifsDecoder GF_BifsDecoder;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Node GF_Node;
typedef struct GF_FieldInfo GF_FieldInfo;
typedef struct GF_ChildNodeItem GF_ChildNodeItem;

#define GF_OK 0
#define GF_NOT_SUPPORTED 1
#define GF_NON_COMPLIANT_BITSTREAM 2
#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2
#define GPAC_ENABLE_BIFS_PMF

enum {
    GF_SG_VRML_UNKNOWN,
    GF_SG_VRML_SF_FIELD,
    GF_SG_VRML_MFNODE
};

enum {
    GF_SG_EVENT_IN
};

struct GF_FieldInfo {
    int fieldType;
    int eventType;
    void* far_ptr;
};

struct GF_BifsDecoder_Config {
    bool UsePredictiveMFField;
};

struct GF_BifsDecoder_Info {
    struct GF_BifsDecoder_Config config;
};

struct GF_BifsDecoder {
    GF_Err LastError;
    struct GF_BifsDecoder_Info *info;
};

GF_Err gf_bifs_dec_sf_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field, Bool is_mem_com);
void gf_node_unregister_children(GF_Node *node, GF_ChildNodeItem *child);
GF_Err gf_sg_vrml_mf_reset(void *far_ptr, int fieldType);
bool gf_sg_vrml_is_sf_field(int fieldType);
void GF_LOG(int level, int category, const char* format);
u8 gf_bs_read_int(GF_BitStream *bs, int bits);
GF_Err gf_bifs_dec_pred_mf_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field);
GF_Err BD_DecMFFieldList(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field, Bool is_mem_com);
GF_Err BD_DecMFFieldVec(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field, Bool is_mem_com);