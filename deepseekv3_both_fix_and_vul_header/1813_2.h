#include <stdlib.h>
#include <string.h>

typedef struct GF_BifsDecoder GF_BifsDecoder;
typedef struct GF_Node GF_Node;
typedef struct GF_FieldInfo GF_FieldInfo;

struct GF_FieldInfo {
    char *name;
    void *far_ptr;
};

#define TAG_ProtoNode 0

int gf_node_get_tag(GF_Node *node);
int gf_sg_proto_field_is_sftime_offset(GF_Node *node, GF_FieldInfo *inf);
void BD_OffsetSFTime(GF_BifsDecoder *codec, double *ptr);
int stricmp(const char *s1, const char *s2);

#define Double double