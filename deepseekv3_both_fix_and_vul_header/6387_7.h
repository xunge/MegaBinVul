#include <stdint.h>
#include <stddef.h>

typedef uint64_t BITCODE_BL;
typedef uint8_t BITCODE_B;

typedef struct _dwg_object_ref {
    struct _dwg_object *obj;
    struct {
        uint64_t value;
    } handleref;
} Dwg_Object_Ref;

typedef struct _dwg_header {
    int version;
} Dwg_Header;

typedef struct _dwg_data {
    Dwg_Header header;
} Dwg_Data;

typedef struct _dwg_entity {
    Dwg_Object_Ref *layer;
    struct {
        struct _dwg_entity_polyline_2d *POLYLINE_2D;
    } tio;
} Dwg_Entity;

typedef struct _dwg_entity_polyline_2d {
    BITCODE_BL num_owned;
    Dwg_Object_Ref **vertex;
    Dwg_Object_Ref *seqend;
} Dwg_Entity_POLYLINE_2D;

typedef struct _dwg_object {
    struct {
        Dwg_Entity *entity;
    } tio;
    Dwg_Data *parent;
    int type;
    int fixedtype;
    char *dxfname;
    struct {
        uint64_t value;
    } handle;
} Dwg_Object;

#define DWG_TYPE_LAYER 0
#define DWG_TYPE_DICTIONARY 1
#define DWG_TYPE_SEQEND 2
#define DWG_TYPE_VERTEX_2D 3
#define DWG_TYPE_VERTEX_3D 4
#define DWG_TYPE_VERTEX_MESH 5
#define DWG_TYPE_VERTEX_PFACE 6
#define DWG_TYPE_VERTEX_PFACE_FACE 7

#define R_2004 0

#define LOG_WARN(...)

Dwg_Object* dwg_ref_object_relative(Dwg_Data *dwg, Dwg_Object_Ref *ref, Dwg_Object *obj);
Dwg_Object* dwg_next_object(Dwg_Object *obj);
Dwg_Object_Ref* dwg_find_objectref(Dwg_Data *dwg, Dwg_Object *obj);