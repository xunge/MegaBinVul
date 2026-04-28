#include <stddef.h>

typedef short FT_Short;
typedef int FT_Int;
typedef char FT_Char;

#define FT_LOCAL_DEF(x) x
#define FT_TRACE5(x) do {} while (0)

#define MVAR_TAG_HASC 0x68617363
#define MVAR_TAG_HDSC 0x68647363
#define MVAR_TAG_HLGP 0x686C6770
#define TT_FACE_FLAG_VAR_MVAR (1 << 0)

typedef struct FT_ListRec_ {
    void* head;
    void* tail;
} FT_List;

typedef struct FT_SizeRec_ FT_Size;

typedef struct GX_Value {
    unsigned int tag;
    FT_Short unmodified;
    unsigned int outerIndex;
    unsigned int innerIndex;
} *GX_Value;

typedef struct {
    GX_Value values;
    unsigned int valueCount;
    void* itemStore;
} MVAR_Table;

typedef struct {
    MVAR_Table* mvar_table;
} *GX_Blend;

typedef struct FT_FaceRec_ {
    FT_Short ascender;
    FT_Short descender;
    FT_Short height;
    FT_Short underline_position;
    FT_Short underline_thickness;
    FT_List sizes_list;
} FT_FaceRec;

typedef struct {
    FT_Short underlinePosition;
    FT_Short underlineThickness;
} Postscript;

typedef struct TT_FaceRec_ {
    GX_Blend blend;
    unsigned int variation_support;
    FT_FaceRec root;
    Postscript postscript;
    void* face_var;
} *TT_Face;

typedef struct FT_Service_MetricsVariations_ {
    void (*size_reset)(void);
} *FT_Service_MetricsVariations;

typedef FT_FaceRec* FT_Face;

FT_Short* ft_var_get_value_pointer(TT_Face face, unsigned int tag);
FT_Int ft_var_get_item_delta(TT_Face face, void* itemStore, unsigned int outerIndex, unsigned int innerIndex);
void FT_List_Iterate(FT_List* list, void (*iterator)(void*, void*), void* user);
void ft_size_reset_iterator(void* node, void* user);
void tt_size_reset_iterator(void* node, void* user);