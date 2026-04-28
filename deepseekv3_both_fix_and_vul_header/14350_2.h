#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef unsigned int u32;
typedef int Bool;
#define GF_FALSE 0
#define GF_TRUE 1

#define GF_LOG_ERROR 1
#define GF_LOG_PARSER 2
#define GF_LOG_CODING 3

typedef struct GF_LASeRCodec GF_LASeRCodec;
typedef struct GF_List GF_List;
typedef struct SMIL_AnimateValues SMIL_AnimateValues;
typedef struct SMIL_AnimateValue SMIL_AnimateValue;
typedef struct SVG_Point_Angle SVG_Point_Angle;
typedef struct SVG_Point SVG_Point;
typedef struct SVG_Number SVG_Number;

typedef int Fixed;
#define INT2FIX(x) ((x)<<16)
#define GF_PI 0x3243F

enum {
    SVG_TRANSFORM_TRANSLATE,
    SVG_TRANSFORM_SCALE,
    SVG_TRANSFORM_ROTATE,
    SVG_TRANSFORM_SKEWX,
    SVG_TRANSFORM_SKEWY,
    SVG_TRANSFORM_MATRIX
};

enum {
    SVG_Transform_Translate_datatype,
    SVG_Transform_Scale_datatype,
    SVG_Transform_Rotate_datatype,
    SVG_Transform_SkewX_datatype,
    SVG_Transform_SkewY_datatype,
    SVG_Transform_datatype
};

struct SVG_Point {
    Fixed x, y;
};

struct SVG_Point_Angle {
    Fixed angle, x, y;
};

struct SVG_Number {
    Fixed value;
};

struct SMIL_AnimateValue {
    u32 type;
    void *value;
};

struct SMIL_AnimateValues {
    u32 type;
    GF_List *values;
};

#define GF_SAFEALLOC(ptr, type) (ptr = (type*)gf_malloc(sizeof(type)))

void lsr_delete_anim_value(GF_LASeRCodec *lsr, SMIL_AnimateValue *a_val, u32 coded_type);
void GF_LOG(u32 log_level, u32 log_tool, const char *fmt, ...);
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 position);
void *gf_list_last(GF_List *list);
void *gf_list_pop_back(GF_List *list);
void gf_list_rem(GF_List *list, u32 position);
void gf_list_rem_last(GF_List *list);
void gf_list_insert(GF_List *list, void *item, u32 position);
void gf_list_del(GF_List *list);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
Fixed gf_muldiv(Fixed a, Fixed b, Fixed c);