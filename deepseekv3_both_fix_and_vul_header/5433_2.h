#include <stddef.h>

typedef int FT_Error;
typedef unsigned int FT_UInt;
typedef unsigned long FT_ULong;
typedef long FT_Pos;
typedef int FT_Int;
typedef signed char FT_Char;
typedef unsigned char FT_Byte;

typedef struct FT_Bitmap {
    int rows;
    int width;
    int pitch;
    unsigned char pixel_mode;
    unsigned char num_grays;
    void* buffer;
} FT_Bitmap;

typedef struct FT_GlyphSlotRec_ {
    int format;
    FT_Bitmap bitmap;
    FT_Pos bitmap_left;
    FT_Pos bitmap_top;
    struct {
        FT_Pos x;
        FT_Pos y;
    } advance;
} FT_GlyphSlotRec;

typedef struct FT_FaceRec_ {
    FT_GlyphSlotRec* glyph;
} FT_FaceRec;

typedef struct FT_MemoryRec_ {
    void* memory;
} FT_MemoryRec;

typedef struct FTC_ManagerRec_ {
    FT_MemoryRec* memory;
} FTC_ManagerRec;

typedef struct FTC_FamilyClassRec_ {
    FT_Error (*family_load_glyph)(struct FTC_FamilyRec_*, FT_UInt, FTC_ManagerRec*, FT_FaceRec**);
} FTC_FamilyClassRec;

typedef struct FTC_FamilyRec_ {
    FTC_FamilyClassRec* clazz;
} FTC_FamilyRec;

typedef struct FTC_GNodeRec_ {
    FT_UInt gindex;
    FTC_FamilyRec* family;
} FTC_GNodeRec;

typedef struct FTC_SBitRec_ {
    FT_Byte width;
    FT_Byte height;
    FT_Char pitch;
    FT_Char left;
    FT_Char top;
    FT_Char xadvance;
    FT_Char yadvance;
    FT_Byte format;
    FT_Byte max_grays;
    void* buffer;
} FTC_SBitRec;

typedef struct FTC_SNodeRec_ {
    FTC_GNodeRec gnode;
    FT_UInt count;
    FTC_SBitRec* sbits;
} FTC_SNodeRec;

typedef FTC_ManagerRec* FTC_Manager;
typedef FTC_SNodeRec* FTC_SNode;
typedef FTC_GNodeRec* FTC_GNode;
typedef FTC_FamilyRec* FTC_Family;
typedef FT_FaceRec* FT_Face;
typedef FT_MemoryRec* FT_Memory;
typedef FT_GlyphSlotRec* FT_GlyphSlot;
typedef FTC_SBitRec* FTC_SBit;
typedef FTC_FamilyClassRec* FTC_SFamilyClass;

#define FTC_GNODE(x) ((FTC_GNode)(&((FTC_SNode)(x))->gnode))
#define FT_THROW(e) (e)
#define FT_ERR_NEQ(e1, e2) ((e1) != (e2))
#define FT_ERROR(x)
#define FT_TRACE0(x)
#define FT_TRACE2(x)
#define FT_GLYPH_FORMAT_BITMAP 1
#define FT_Err_Ok 0
#define Out_Of_Memory 1
#define Invalid_Argument 2
#define FT_ABS(x) ((x) < 0 ? -(x) : (x))

static FT_Error ftc_sbit_copy_bitmap(FTC_SBit sbit, FT_Bitmap* bitmap, FT_Memory memory);