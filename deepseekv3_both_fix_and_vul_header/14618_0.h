#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned char u8;

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_NON_COMPLIANT_BITSTREAM,
    GF_NOT_SUPPORTED,
    GF_EOS
} GF_Err;

typedef struct {
    u32 tag;
} GF_SGPrivate;

typedef struct {
    GF_SGPrivate *sgprivate;
} GF_Node;

typedef struct {
    u32 fieldType;
    void *far_ptr;
    u32 fieldIndex;
    u32 NDTtype;
} GF_FieldInfo;

typedef struct {
    u32 NodeIDBits;
} GF_BifsDecoderInfoConfig;

typedef struct {
    GF_BifsDecoderInfoConfig config;
} GF_BifsDecoderInfo;

typedef struct {
    GF_BifsDecoderInfo *info;
    GF_Node *current_graph;
    GF_Err LastError;
    void *ActiveQP;
    u32 dec_memory_mode;
    void *command_buffers;
} GF_BifsDecoder;

typedef struct {
    void *buffer;
    u32 buffer_len;
} GF_BitStreamBuffer;

typedef struct {
    GF_BitStreamBuffer buffer;
    u32 buffer_len;
} M_BitWrapper;

typedef struct {
    u8 *data;
    u32 data_len;
} M_CacheTexture;

typedef struct {
    char *buffer;
} SFString;

typedef struct {
    float red, green, blue;
} SFColor;

typedef struct {
    float x, y;
} SFVec2f;

typedef struct {
    float x, y, z;
} SFVec3f;

typedef struct {
    float x, y, z, q;
} SFRotation;

typedef struct {
    char *url;
    u32 OD_ID;
} SFURL;

typedef struct {
    unsigned char *pixels;
    u32 width, height, numComponents;
} SFImage;

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
    void *far_ptr;
} SFScript;

typedef struct {
    GF_Node *node;
    SFCommandBuffer *cb;
} CommandBufferItem;

typedef struct GF_BitStream GF_BitStream;

typedef Bool SFBool;
typedef float SFFloat;
typedef s32 SFInt32;
typedef double SFTime;
typedef void GF_Command;

int gf_bs_read_int(GF_BitStream *bs, int bits);
double gf_bs_read_double(GF_BitStream *bs);
int gf_bs_read_data(GF_BitStream *bs, char *buffer, int length);
int gf_bs_available(GF_BitStream *bs);

void *gf_malloc(size_t size);
void gf_free(void *ptr);

GF_Node *gf_bifs_dec_node(GF_BifsDecoder *codec, GF_BitStream *bs, u32 NDTtype);
GF_Err gf_node_register(GF_Node *node, GF_Node *parent);
void gf_node_unregister(GF_Node *node, GF_Node *parent);
GF_Err gf_bifs_dec_unquant_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field);
GF_Err gf_bifs_get_field_index(GF_Node *node, u32 field_ref, u32 coding_mode, u32 *fieldIndex);
GF_Node *gf_sg_find_node(GF_Node *graph, u32 nodeID);
u32 gf_node_get_num_fields_in_mode(GF_Node *node, u32 mode);
u32 gf_get_bit_size(u32 max_val);

void SFCommandBufferChanged(GF_BifsDecoder *codec, GF_Node *node);
void gf_sg_command_del(GF_Command *com);

float BD_ReadSFFloat(GF_BifsDecoder *codec, GF_BitStream *bs);
void BD_CheckSFTimeOffset(GF_BifsDecoder *codec, GF_Node *node, GF_FieldInfo *field);

enum {
    TAG_MPEG4_CacheTexture,
    TAG_MPEG4_BitWrapper,
    TAG_MPEG4_InputSensor
};

enum {
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
};

enum {
    GF_SG_FIELD_CODING_DEF
};

#ifdef GPAC_HAS_QJS
GF_Err SFScript_Parse(GF_BifsDecoder *codec, SFScript *script, GF_BitStream *bs, GF_Node *node);
#endif