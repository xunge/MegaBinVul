#include <stdlib.h>
#include <string.h>

typedef int GF_Err;
typedef unsigned char Bool;
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

#define GF_EOS 1
#define GF_NON_COMPLIANT_BITSTREAM 2
#define GF_BAD_PARAM 3
#define GF_NOT_SUPPORTED 4

#define GF_SG_VRML_SFBOOL 0
#define GF_SG_VRML_SFCOLOR 1
#define GF_SG_VRML_SFFLOAT 2
#define GF_SG_VRML_SFINT32 3
#define GF_SG_VRML_SFTIME 4
#define GF_SG_VRML_SFVEC2F 5
#define GF_SG_VRML_SFVEC3F 6
#define GF_SG_VRML_SFROTATION 7
#define GF_SG_VRML_SFSTRING 8
#define GF_SG_VRML_SFURL 9
#define GF_SG_VRML_SFIMAGE 10
#define GF_SG_VRML_SFCOMMANDBUFFER 11
#define GF_SG_VRML_SFNODE 12
#define GF_SG_VRML_SFSCRIPT 13
#define GF_SG_VRML_SFATTRREF 14

#define GF_SG_FIELD_CODING_DEF 0

#define TAG_MPEG4_CacheTexture 0
#define TAG_MPEG4_BitWrapper 1
#define TAG_MPEG4_InputSensor 2

typedef struct {
    u32 red;
    u32 green;
    u32 blue;
} SFColor;

typedef float SFFloat;
typedef u32 SFBool;
typedef s32 SFInt32;
typedef double SFTime;

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
    char *buffer;
} SFString;

typedef struct {
    char *url;
    u32 OD_ID;
} SFURL;

typedef struct {
    u32 width;
    u32 height;
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
    u8 *data;
    u32 data_len;
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
    GF_Err LastError;
    Bool dec_memory_mode;
} GF_BifsDecoder;

typedef struct {
    void *node;
    void *cb;
} CommandBufferItem;

typedef struct {
    void *commandList;
} GF_Command;

typedef struct {
    void *sgprivate;
} SFScript;

typedef struct GF_BitStream GF_BitStream;

GF_Err gf_bifs_dec_unquant_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field);
float BD_ReadSFFloat(GF_BifsDecoder *codec, GF_BitStream *bs);
void BD_CheckSFTimeOffset(GF_BifsDecoder *codec, GF_Node *node, GF_FieldInfo *field);
GF_Node *gf_bifs_dec_node(GF_BifsDecoder *codec, GF_BitStream *bs, u32 NDTtype);
GF_Err gf_node_register(GF_Node *node, GF_Node *parent);
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
double gf_bs_read_double(GF_BitStream *bs);
u32 gf_bs_available(GF_BitStream *bs);
void gf_bs_read_data(GF_BitStream *bs, char *data, u32 length);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 pos);
void gf_list_rem(void *list, u32 pos);
void gf_sg_command_del(GF_Command *com);
void SFCommandBufferChanged(GF_BifsDecoder *codec, GF_Node *node);
GF_Err gf_bifs_get_field_index(GF_Node *node, u32 field_ref, u32 coding, u32 *fieldIndex);
GF_Node *gf_sg_find_node(void *graph, u32 nodeID);
u32 gf_node_get_num_fields_in_mode(GF_Node *node, u32 mode);
u32 gf_get_bit_size(u32 max_val);
void gf_list_add(void *list, void *item);
GF_Err SFScript_Parse(GF_BifsDecoder *codec, SFScript *script, GF_BitStream *bs, GF_Node *node);