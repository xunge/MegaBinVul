#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef int32_t Fixed;

typedef struct {
    int32_t m[6];
} GF_Matrix2D;

typedef struct {
    u32 type;
    union {
        struct {
            Fixed *vals;
            u8 *units;
            u32 count;
        } array;
    };
} SVG_StrokeDashArray;

typedef struct {
    Fixed x, y, width, height;
} SVG_ViewBox;

typedef struct {
    u32 type;
    Fixed value;
} SVG_Coordinate;

typedef struct {
    Fixed x, y;
} SVG_Point;

typedef void* SVG_Coordinates;
typedef void* GF_List;

typedef struct {
    u32 type;
    void *value;
} SMIL_AnimateValue;

typedef struct {
    u32 last_error;
} GF_LASeRCodec;

#define SVG_StrokeDashArray_datatype 0
#define SVG_ViewBox_datatype 1
#define SVG_Coordinates_datatype 2
#define SVG_Motion_datatype 3

#define SVG_STROKEDASHARRAY_INHERIT 0
#define SVG_STROKEDASHARRAY_ARRAY 1
#define SVG_NUMBER_VALUE 0

#define GF_OUT_OF_MEM 1

#define GF_SAFEALLOC(ptr, type) ptr = (type*)malloc(sizeof(type))
#define gf_malloc malloc
#define gf_free free
#define gf_list_new() NULL
#define gf_list_add(l, v) 
#define gf_list_count(l) 0
#define gf_list_get(l, i) NULL
#define gf_list_last(l) NULL
#define gf_list_rem(l, i) 
#define gf_list_rem_last(l) 
#define gf_list_del(l) 
#define gf_list_insert(l, v, i) 
#define gf_mx2d_init(m) 

static void lsr_delete_anim_value(GF_LASeRCodec *lsr, SMIL_AnimateValue *val, u32 coded_type);