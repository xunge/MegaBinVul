#include <stdlib.h>
#include <string.h>

typedef int GF_Err;
typedef unsigned char Bool;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Node GF_Node;
typedef struct GF_ChildNodeItem GF_ChildNodeItem;
typedef struct GF_FieldInfo GF_FieldInfo;
typedef struct GF_BifsDecoder GF_BifsDecoder;
typedef struct M_QuantizationParameter M_QuantizationParameter;

struct GF_FieldInfo {
    u32 fieldIndex;
    u32 fieldType;
    u32 NDTtype;
    char *name;
    void *far_ptr;
};

struct GF_BifsDecoder {
    Bool ActiveQP;
    Bool force_keep_qp;
    void *pCurrentProto;
    GF_Err LastError;
};

struct M_QuantizationParameter {
    Bool isLocal;
};

#define GF_OK 0
#define GF_FALSE 0
#define GF_TRUE 1
#define GF_NON_COMPLIANT_BITSTREAM 1
#define TAG_MPEG4_QuantizationParameter 0
#define GF_SG_VRML_MFNODE 0