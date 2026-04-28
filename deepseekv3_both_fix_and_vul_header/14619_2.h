#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef double SFTime;
typedef float SFFloat;
typedef int SFInt32;
typedef unsigned int SFBool;

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
    float red, green, blue;
} SFColor;

typedef struct {
    char *buffer;
} SFString;

typedef struct {
    u32 OD_ID;
    char *url;
} SFURL;

typedef struct {
    u32 width, height;
    u32 numComponents;
    unsigned char *pixels;
} SFImage;

typedef struct {
    unsigned char *buffer;
    u32 bufferSize;
    void *commandList;
} SFCommandBuffer;

typedef struct {
    void *node;
    u32 fieldIndex;
} SFAttrRef;

typedef struct {
    struct {
        u32 tag;
    } *sgprivate;
} GF_Node;

typedef struct {
    u32 fieldType;
    void *far_ptr;
    u32 fieldIndex;
    u32 NDTtype;
} GF_FieldInfo;

typedef struct {
    u32 data_len;
    u8 *data;
} M_CacheTexture;

typedef struct {
    struct {
        char *buffer;
    } buffer;
    u32 buffer_len;
} M_BitWrapper;

typedef struct {
    void *current_graph;
    struct {
        struct {
            u32 NodeIDBits;
        } config;
    } *info;
    void *ActiveQP;
    void *command_buffers;
    int LastError;
    Bool dec_memory_mode;
} GF_BifsDecoder;

typedef struct {
    void *node;
    void *cb;
} CommandBufferItem;

typedef struct GF_Command GF_Command;

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_NON_COMPLIANT_BITSTREAM,
    GF_NOT_SUPPORTED,
    GF_EOS
} GF_Err;

typedef enum {
    TAG_MPEG4_CacheTexture,
    TAG_MPEG4_BitWrapper,
    TAG_MPEG4_InputSensor
} GF_NodeTags;

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
} GF_FieldTypeEnum;

typedef enum {
    GF_SG_FIELD_CODING_DEF
} GF_FieldCodingMode;

typedef struct {
    void *bs;
} GF_BitStream;

GF_Err gf_bifs_dec_unquant_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field);
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
float BD_ReadSFFloat(GF_BifsDecoder *codec, GF_BitStream *bs);
double gf_bs_read_double(GF_BitStream *bs);
void BD_CheckSFTimeOffset(GF_BifsDecoder *codec, GF_Node *node, GF_FieldInfo *field);
u32 gf_bs_available(GF_BitStream *bs);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
void gf_bs_read_data(GF_BitStream *bs, char *data, u32 length);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
void gf_list_rem(void *list, u32 index);
void gf_sg_command_del(GF_Command *com);
void SFCommandBufferChanged(GF_BifsDecoder *codec, GF_Node *node);
void gf_list_add(void *list, void *item);
void gf_node_unregister(GF_Node *node, GF_Node *parent);
GF_Node *gf_bifs_dec_node(GF_BifsDecoder *codec, GF_BitStream *bs, u32 NDTtype);
GF_Err gf_node_register(GF_Node *node, GF_Node *parent);
GF_Node *gf_sg_find_node(void *graph, u32 nodeID);
u32 gf_get_bit_size(u32 max_val);
u32 gf_node_get_num_fields_in_mode(GF_Node *node, GF_FieldCodingMode mode);
GF_Err gf_bifs_get_field_index(GF_Node *node, u32 field_ref, GF_FieldCodingMode mode, u32 *fieldIndex);