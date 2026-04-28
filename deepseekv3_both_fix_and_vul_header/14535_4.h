#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned char Bool;
typedef unsigned int u32;

#define GF_TRUE 1
#define GF_FALSE 0
#define GF_BIFS_V1 1
#define GF_BIFS_NUM_VERSION 2

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_SG_UNKNOWN_NODE,
    GF_BIFS_UNKNOWN_VERSION,
    GF_NON_COMPLIANT_BITSTREAM,
    GF_NOT_SUPPORTED
} GF_Err;

typedef enum {
    GF_LOG_ERROR = 1,
    GF_LOG_CODING
} GF_LogLevel;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Node GF_Node;

typedef struct {
    u32 count;
} GF_List;

typedef struct {
    u32 NodeIDBits;
    u32 ProtoIDBits;
    Bool Use3DMeshCoding;
} GF_Config;

typedef struct {
    GF_Config config;
} GF_Info;

typedef struct {
    GF_List point;
} M_Coordinate;

typedef struct {
    GF_List point;
} M_Coordinate2D;

struct GF_Proto {
    GF_List ExternProto;
};
typedef struct GF_Proto GF_Proto;

typedef struct {
    GF_Info *info;
    GF_Node *current_graph;
    GF_Node *scenegraph;
    GF_Proto *pCurrentProto;
    Bool UseName;
    Bool coord_stored;
    GF_Err LastError;
} GF_BifsDecoder;

#define TAG_MPEG4_Coordinate 1
#define TAG_MPEG4_Coordinate2D 2
#define TAG_MPEG4_IndexedFaceSet 3
#define TAG_ProtoNode 4
#define TAG_MPEG4_Script 5
#define TAG_MPEG4_Conditional 6

/* Function declarations */
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
u32 gf_bs_available(GF_BitStream *bs);
void GF_LOG(GF_LogLevel level, GF_LogLevel coding, const char *fmt, ...);
GF_Node *gf_sg_find_node(void *graph, u32 nodeID);
Bool gf_node_in_table(GF_Node *node, u32 NDT_Tag);
const char *gf_node_get_class_name(GF_Node *node);
u32 gf_node_get_tag(GF_Node *node);
GF_Proto *gf_node_get_proto(GF_Node *node);
void gf_bifs_dec_qp14_enter(GF_BifsDecoder *codec, Bool enter);
void gf_bifs_dec_qp14_set_length(GF_BifsDecoder *codec, u32 length);
void gf_bifs_dec_qp14_reset(GF_BifsDecoder *codec);
u32 gf_bifs_get_ndt_bits(u32 NDT_Tag, u32 BVersion);
GF_Proto *gf_sg_find_proto(void *graph, u32 ProtoID, void *unused);
u32 gf_bifs_ndt_get_node_type(u32 NDT_Tag, u32 node_type, u32 BVersion);
void gf_bifs_dec_name(GF_BitStream *bs, char *name, u32 size);
GF_Node *gf_sg_proto_create_instance(void *graph, GF_Proto *proto);
GF_Node *gf_node_new(void *graph, u32 tag);
void gf_node_set_id(GF_Node *node, u32 id, const char *name);
void UpdateTimeNode(GF_BifsDecoder *codec, GF_Node *node);
GF_Err gf_bifs_dec_node_mask(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, Bool is_proto);
GF_Err gf_bifs_dec_node_list(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, Bool is_proto);
void gf_node_register(GF_Node *node, void *unused);
void gf_node_unregister(GF_Node *node, void *unused);
void gf_node_init(GF_Node *node);
void gf_sg_script_load(GF_Node *node);
void SetupConditional(GF_BifsDecoder *codec, GF_Node *node);