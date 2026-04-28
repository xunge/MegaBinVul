#include <stddef.h>

typedef signed int FT_Int;
typedef unsigned int FT_UInt;
typedef long FT_Fixed;

enum {
    PSH_DIR_VERTICAL,
    PSH_DIR_HORIZONTAL
};

#define PSH_STRONG_THRESHOLD 0
#define PSH_STRONG_THRESHOLD_MAXIMUM 0

struct PSH_PointRec_ {
    void* hint;
};
typedef struct PSH_PointRec_* PSH_Point;

struct PS_MaskRec_ {
    FT_UInt end_point;
};
typedef struct PS_MaskRec_* PS_Mask;

struct PSH_DimensionRec_ {
    FT_Fixed scale_mult;
};
typedef struct PSH_DimensionRec_* PSH_Dimension;

struct PSH_Hint_TableRec_ {
    struct {
        PS_Mask masks;
        FT_UInt num_masks;
    } *hint_masks;
};
typedef struct PSH_Hint_TableRec_* PSH_Hint_Table;

struct PSH_GlyphRec_ {
    PSH_Hint_Table hint_tables[2];
    FT_UInt num_points;
    PSH_Point points;
    struct {
        PSH_Dimension dimension[2];
    } *globals;
};
typedef struct PSH_GlyphRec_* PSH_Glyph;

FT_Fixed FT_DivFix(FT_Fixed a, FT_Fixed b);

static int psh_point_is_strong(PSH_Point point);
static void psh_point_set_strong(PSH_Point point);
static void psh_hint_table_activate_mask(PSH_Hint_Table table, PS_Mask mask);
static void psh_hint_table_find_strong_points(PSH_Hint_Table table, PSH_Point points, FT_UInt count, FT_Int threshold, FT_Int major_dir);