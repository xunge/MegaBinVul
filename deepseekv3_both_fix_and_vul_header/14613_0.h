#include <stdint.h>

typedef int32_t GF_Err;
#define GF_OK 0
#define GF_BAD_PARAM -1

typedef struct _GF_Node GF_Node;

typedef enum {
    GF_SG_EVENT_IN,
    GF_SG_EVENT_EXPOSED_FIELD
} GF_EventType;

typedef enum {
    GF_SG_VRML_SFNODE,
    GF_SG_VRML_SFINT32,
    GF_SG_VRML_SFVEC3F,
    GF_SG_VRML_MFNODE,
    GF_SG_VRML_MFFLOAT,
    GF_SG_VRML_SFROTATION,
    GF_SG_VRML_MFINT32
} GF_FieldType;

typedef enum {
    NDT_SF3DNode
} GF_NodeDataType;

typedef void (*GF_EventIn)(void);

typedef struct {
    const char *name;
    GF_EventType eventType;
    GF_EventIn on_event_in;
    GF_FieldType fieldType;
    GF_NodeDataType NDTtype;
    void *far_ptr;
    uint32_t fieldIndex;
} GF_FieldInfo;

typedef struct {
    void *addChildren;
    GF_EventIn on_addChildren;
    void *removeChildren;
    GF_EventIn on_removeChildren;
    int32_t boneID;
    float center[3];
    void *children;
    float endpoint[3];
    int32_t falloff;
    int32_t ikChainPosition;
    float *ikPitchLimit;
    float *ikRollLimit;
    float *ikTxLimit;
    float *ikTyLimit;
    float *ikTzLimit;
    float *ikYawLimit;
    float rotation[4];
    int32_t rotationOrder;
    float scale[3];
    float scaleOrientation[4];
    float *sectionInner;
    float *sectionOuter;
    float *sectionPosition;
    int32_t *skinCoordIndex;
    float *skinCoordWeight;
    float translation[3];
} M_SBBone;