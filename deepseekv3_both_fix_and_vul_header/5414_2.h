#include <stddef.h>

typedef int CF2_Fixed;
typedef unsigned char FT_Byte;
typedef unsigned int FT_Bool;
#define TRUE 1
#define FALSE 0

typedef struct CF2_HintRec_ {
    int flags;
    int scale;
    int csCoord;
    int dsCoord;
    size_t index;
    FT_Bool used;
} CF2_HintRec;

typedef struct CF2_BluesRec_ {
    FT_Bool doEmBoxHints;
    CF2_HintRec emBoxBottomEdge;
    CF2_HintRec emBoxTopEdge;
} CF2_BluesRec;

typedef struct CF2_FontRec_ {
    CF2_BluesRec blues;
} *CF2_Font;

typedef struct CF2_HintMaskRec_ {
    FT_Byte* error;
    size_t bitCount;
    FT_Bool isNew;
    FT_Byte* mask;
} CF2_HintMaskRec, *CF2_HintMask;

typedef struct CF2_StemHintRec_ {
    CF2_Fixed minDS;
    CF2_Fixed maxDS;
    FT_Bool used;
} *CF2_StemHint;

typedef struct CF2_HintMapRec_ {
    CF2_Font font;
    struct CF2_HintMapRec_* initialHintMap;
    size_t count;
    size_t lastIndex;
    int scale;
    CF2_HintRec* edge;
    FT_Bool isValid;
} *CF2_HintMap;

typedef struct CF2_ArrStackRec_* CF2_ArrStack;

#define FT_LOCAL_DEF(x) x
#define CF2_GhostBottom (1 << 0)
#define CF2_Locked (1 << 1)
#define CF2_Synthetic (1 << 2)

FT_Bool cf2_hintmap_isValid(CF2_HintMap hintmap);
void cf2_hintmask_init(CF2_HintMask hintMask, FT_Byte* error);
FT_Bool cf2_hintmask_isValid(CF2_HintMask hintMask);
void cf2_hintmask_setAll(CF2_HintMask hintMask, size_t size);
size_t cf2_arrstack_size(CF2_ArrStack arrstack);
FT_Byte* cf2_hintmask_getMaskPtr(CF2_HintMask hintMask);
void cf2_hint_initZero(CF2_HintRec* hint);
void cf2_hintmap_insertHint(CF2_HintMap hintmap, CF2_HintRec* bottom, CF2_HintRec* top);
void cf2_hint_init(CF2_HintRec* hint, CF2_ArrStack hStemHintArray, size_t index, CF2_Font font, CF2_Fixed hintOrigin, int scale, FT_Bool isBottom);
FT_Bool cf2_hint_isLocked(CF2_HintRec* hint);
FT_Bool cf2_blues_capture(CF2_BluesRec* blues, CF2_HintRec* bottom, CF2_HintRec* top);
void cf2_hintmap_adjustHints(CF2_HintMap hintmap);
FT_Bool cf2_hint_isSynthetic(CF2_HintRec* hint);
FT_Bool cf2_hint_isTop(CF2_HintRec* hint);
void* cf2_arrstack_getPointer(CF2_ArrStack arrstack, size_t index);
void cf2_hintmask_setNew(CF2_HintMask hintMask, FT_Bool isNew);