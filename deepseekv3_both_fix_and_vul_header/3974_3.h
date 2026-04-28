#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;
typedef int32_t Fixed;
typedef uint8_t Bool;

typedef struct {
    Fixed value;
} SVG_Number;

typedef struct {
    Fixed x;
    Fixed y;
} SVG_Point;

typedef struct {
    struct {
        Fixed *vals;
        u32 count;
    } array;
} SVG_StrokeDashArray;

typedef struct GF_LASeRCodec {
    u32 last_error;
} GF_LASeRCodec;

typedef struct GF_Node GF_Node;

typedef void* ListOfXXX;

Fixed lsr_read_fixed_16_8(GF_LASeRCodec *lsr, const char *name);
Fixed lsr_read_fixed_clamp(GF_LASeRCodec *lsr, const char *name);
Fixed* lsr_read_fraction_12_item(GF_LASeRCodec *lsr);
void* lsr_read_smil_time(GF_LASeRCodec *lsr, GF_Node *node);
void lsr_read_coordinate(GF_LASeRCodec *lsr, SVG_Number *num, u32 flags, const char *name);
void lsr_read_extension(GF_LASeRCodec *lsr, const char *name);

#define GF_SAFEALLOC(ptr, type) ptr = (type*)malloc(sizeof(type))
#define gf_malloc malloc
#define gf_list_new() NULL
#define gf_list_add(list, item) ((void)0)
#define GF_OUT_OF_MEM 1

enum {
    SVG_Points_datatype,
    SMIL_KeySplines_datatype,
    SVG_StrokeDashArray_datatype,
    SVG_ViewBox_datatype,
    SMIL_KeyTimes_datatype,
    SMIL_KeyPoints_datatype,
    SMIL_Times_datatype
};