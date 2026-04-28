#include <stdlib.h>

typedef unsigned int u32;

typedef struct GF_SceneGraph GF_SceneGraph;
typedef struct GF_List GF_List;
typedef struct SVG_Paint SVG_Paint;

typedef struct XMLRI {
    char *string;
} XMLRI;

typedef struct SVG_Focus {
    XMLRI target;
} SVG_Focus;

typedef struct SVG_ClipPath {
    XMLRI target;
} SVG_ClipPath;

typedef struct GF_Path GF_Path;
typedef char* SVG_String;

typedef struct {
    float *vals;
    char *units;
} SVG_NumberArray;

typedef struct SVG_StrokeDashArray {
    SVG_NumberArray array;
} SVG_StrokeDashArray;

typedef struct SVG_FontFamily {
    char *value;
} SVG_FontFamily;

typedef struct SMIL_AttributeName {
    char *name;
} SMIL_AttributeName;

typedef struct SMIL_Times {
    void *data;
} SMIL_Times;

typedef struct SMIL_AnimateValue {
    u32 type;
    void *value;
} SMIL_AnimateValue;

typedef struct SMIL_AnimateValues {
    void *data;
} SMIL_AnimateValues;

enum {
    SVG_Paint_datatype = 1,
    XMLRI_datatype,
    XML_IDREF_datatype,
    SVG_Focus_datatype,
    SVG_ClipPath_datatype,
    SVG_PathData_datatype,
    SVG_ID_datatype,
    DOM_String_datatype,
    SVG_ContentType_datatype,
    SVG_LanguageID_datatype,
    SVG_StrokeDashArray_datatype,
    SMIL_KeyTimes_datatype,
    SMIL_KeyPoints_datatype,
    SMIL_KeySplines_datatype,
    SVG_Numbers_datatype,
    SVG_Coordinates_datatype,
    SVG_Points_datatype,
    SVG_FontFamily_datatype,
    SMIL_AttributeName_datatype,
    SMIL_Times_datatype,
    SMIL_AnimateValue_datatype,
    SMIL_AnimateValues_datatype,
    DOM_StringList_datatype,
    XMLRI_List_datatype,
    SVG_NodeList_datatype,
    SMIL_RepeatCount_datatype,
    SMIL_Duration_datatype,
    SVG_Length_datatype,
    SVG_Coordinate_datatype,
    SVG_Visibility_datatype,
    SVG_Display_datatype
};

void gf_svg_delete_paint(GF_SceneGraph *sg, SVG_Paint *paint);
void gf_svg_reset_iri(GF_SceneGraph *sg, XMLRI *iri);
void gf_path_del(GF_Path *path);
void gf_smil_delete_times(SMIL_Times times);
void svg_delete_one_anim_value(u32 type, void *value, GF_SceneGraph *sg);
void gf_svg_reset_animate_values(SMIL_AnimateValues values, GF_SceneGraph *sg);
void gf_free(void *ptr);
unsigned int gf_list_count(GF_List *list);
void *gf_list_last(GF_List *list);
void gf_list_rem_last(GF_List *list);
void gf_list_del(GF_List *list);