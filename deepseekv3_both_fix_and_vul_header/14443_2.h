#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef int Fixed;

typedef struct {
    int fieldType;
    char *name;
    void *far_ptr;
} GF_FieldInfo;

typedef struct {
    Fixed x;
    Fixed y;
} SVG_Point;

typedef struct {
    int type;
    float clock;
    char *element_id;
    void *element;
    struct {
        int type;
    } event;
} SMIL_Time;

typedef struct {
    int type;
} SVG_Length;

typedef struct {
    int type;
} SVG_Coordinate;

typedef struct GF_Node GF_Node;
typedef struct GF_List GF_List;

enum {
    SVG_PointerEvents_datatype,
    XMLRI_List_datatype,
    SVG_Points_datatype,
    SMIL_KeyPoints_datatype,
    SMIL_KeyTimes_datatype,
    SMIL_KeySplines_datatype,
    SVG_Coordinates_datatype,
    SVG_ViewBox_datatype,
    SVG_StrokeDashArray_datatype,
    SMIL_Times_datatype
};

enum {
    GF_SMIL_TIME_CLOCK,
    GF_SMIL_TIME_INDEFINITE,
    GF_SMIL_TIME_WALLCLOCK,
    GF_SMIL_TIME_EVENT,
    GF_EVENT_KEYDOWN
};

enum {
    GF_LOG_WARNING,
    GF_LOG_PARSER
};

#define DUMP_COORDINATES 0
#define _FIX2FLT(x) ((float)(x))

char *gf_strdup(const char *str);
void GF_LOG(int level, int category, const char *fmt, ...);
GF_Node *gf_node_get_parent(GF_Node *node, int index);
const char *gf_node_get_name(GF_Node *node);
int gf_node_get_id(GF_Node *node);
const char *gf_dom_event_get_name(int type);
char *svg_dump_number(SVG_Length *len);
char *svg_dump_access_key(void *event, char *buf);
const char *gf_svg_attribute_type_to_string(int type);
void *gf_list_get(GF_List *list, u32 index);