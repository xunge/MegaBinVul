#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

typedef enum {
    GF_OK,
    GF_EOS,
    GF_NON_COMPLIANT_BITSTREAM,
    GF_BAD_PARAM,
    GF_NOT_SUPPORTED
} GF_Err;

typedef enum {
    GF_SG_VRML_SFBOOL,
    GF_SG_VRML_SFCOLOR,
    GF_SG_VRML_SFFLOAT,
    GF_SG_VRML_SFINT32,
    GF_SG_VRML_SFTIME,
    GF_SG_VRML_SFVEC2F,
    GF_SG_VRML_SFVEC3F,
    GF_SG_VRML_SFROTATION,
    GF_SG_VRML_SFSTRING,
    GF_SG_VRML_SFURL,
    GF_SG_VRML_SFIMAGE,
    GF_SG_VRML_SFCOMMANDBUFFER,
    GF_SG_VRML_SFNODE,
    GF_SG_VRML_SFSCRIPT,
    GF_SG_VRML_SFATTRREF
} GF_FieldType;

typedef enum {
    GF_SG_FIELD_CODING_DEF
} GF_FieldCoding;

typedef enum {
    TAG_MPEG4_CacheTexture,
    TAG_MPEG4_BitWrapper,
    TAG_MPEG4_InputSensor
} GF_NodeTag;

typedef struct {
    GF_NodeTag tag;
} GF_SGPrivate;

typedef struct {
    GF_SGPrivate *sgprivate;
} GF_Node;

typedef struct {
    void *far_ptr;
    GF_FieldType fieldType;
    u32 fieldIndex;
    u32 NDTtype;
} GF_FieldInfo;

typedef struct {
    u32 width;
    u32 height;
    u32 numComponents;
    unsigned char *pixels;
} SFImage;

typedef struct {
    char *buffer;
} SFString;

typedef struct {
    char *url;
    u32 OD_ID;
} SFURL;

typedef struct {
    float red;
    float green;
    float blue;
} SFColor;

typedef struct {
    float x;
    float y;
} SFVec2f;

typedef struct {
    float x;
    float y;
    float z;
} SFVec3f;

typedef struct {
    float x;
    float y;
    float z;
    float q;
} SFRotation;

typedef struct {
    unsigned char *buffer;
    u32 bufferSize;
    void *commandList;
} SFCommandBuffer;

typedef struct {
    GF_Node *node;
    u32 fieldIndex;
} SFAttrRef;

typedef struct {
    void *data;
    u32 data_len;
} M_CacheTexture;

typedef struct {
    struct {
        char *buffer;
    } buffer;
    u32 buffer_len;
} M_BitWrapper;

typedef struct {
    u32 NodeIDBits;
} GF_BifsDecoderInfoConfig;

typedef struct {
    GF_BifsDecoderInfoConfig config;
} GF_BifsDecoderInfo;

typedef struct {
    GF_Node *node;
    SFCommandBuffer *cb;
} CommandBufferItem;

typedef struct {
    GF_Err LastError;
    GF_BifsDecoderInfo *info;
    void *current_graph;
    void *command_buffers;
    Bool dec_memory_mode;
    void *ActiveQP;
} GF_BifsDecoder;

typedef struct {
} GF_Command;

typedef struct {
} GF_BitStream;

typedef float SFFloat;
typedef double SFTime;
typedef u32 SFInt32;
typedef Bool SFBool;

GF_Err gf_bifs_dec_unquant_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field);
float BD_ReadSFFloat(GF_BifsDecoder *codec, GF_BitStream *bs);
void BD_CheckSFTimeOffset(GF_BifsDecoder *codec, GF_Node *node, GF_FieldInfo *field);
GF_Node *gf_bifs_dec_node(GF_BifsDecoder *codec, GF_BitStream *bs, u32 NDTtype);
GF_Err gf_node_register(GF_Node *node, GF_Node *parent);
void gf_node_unregister(GF_Node *node, GF_Node *parent);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
double gf_bs_read_double(GF_BitStream *bs);
u32 gf_bs_read_data(GF_BitStream *bs, char *data, u32 length);
u32 gf_bs_available(GF_BitStream *bs);
GF_Node *gf_sg_find_node(void *graph, u32 nodeID);
u32 gf_node_get_num_fields_in_mode(GF_Node *node, u32 mode);
u32 gf_get_bit_size(u32 val);
GF_Err gf_bifs_get_field_index(GF_Node *node, u32 field_ref, u32 mode, u32 *fieldIndex);
void SFCommandBufferChanged(GF_BifsDecoder *codec, GF_Node *node);
void gf_sg_command_del(GF_Command *com);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 pos);
void gf_list_rem(void *list, u32 pos);
void gf_list_add(void *list, void *item);