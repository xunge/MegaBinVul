#include <stddef.h>
#include <stdlib.h>

typedef int FT_Error;
typedef int FT_Int;
typedef short FT_Short;
typedef struct FT_StreamRec_* FT_Stream;
typedef struct FT_FaceRec_* FT_Face;
typedef struct FT_Parameter_* FT_Parameter;
typedef struct T42_FaceRec_* T42_Face;
typedef struct FT_Service_PsCMapsRec_* FT_Service_PsCMaps;
typedef struct PSAux_ServiceRec_* PSAux_Service;
typedef struct FT_CharMapRec_ FT_CharMapRec;
typedef struct T1_CMap_ClassesRec_* T1_CMap_Classes;
typedef struct FT_CMap_ClassRec_* FT_CMap_Class;
typedef struct FT_Open_Args_ FT_Open_Args;

struct PS_FontInfoRec_ {
    char* family_name;
    char* full_name;
    int is_fixed_pitch;
    int italic_angle;
    int underline_position;
    int underline_thickness;
};

struct T1_FontRec {
    struct PS_FontInfoRec_ font_info;
    char* font_name;
    int num_glyphs;
    int encoding_type;
};

struct PSAux_ServiceRec_ {
    struct T1_CMap_ClassesRec_* t1_cmap_classes;
};

struct T1_CMap_ClassesRec_ {
    FT_CMap_Class unicode;
    FT_CMap_Class standard;
    FT_CMap_Class expert;
    FT_CMap_Class custom;
};

typedef struct T1_FontRec* T1_Font;
typedef struct PS_FontInfoRec_* PS_FontInfo;

#define FT_LOCAL_DEF(x) x
#define FT_UNUSED(x) (void)(x)
#define FT_FACE_FIND_GLOBAL_SERVICE(face, ptr, id) 
#define FT_THROW(e) (-1)
#define FT_ERROR(x) 
#define FT_TRACE2(x) 
#define FT_ENCODING_UNICODE 0
#define FT_ENCODING_ADOBE_STANDARD 1
#define FT_ENCODING_ADOBE_EXPERT 2
#define FT_ENCODING_ADOBE_CUSTOM 3
#define FT_ENCODING_ADOBE_LATIN_1 4
#define TT_PLATFORM_MICROSOFT 0
#define TT_MS_ID_UNICODE_CS 0
#define TT_PLATFORM_ADOBE 0
#define TT_ADOBE_ID_STANDARD 0
#define TT_ADOBE_ID_EXPERT 0
#define TT_ADOBE_ID_CUSTOM 0
#define TT_ADOBE_ID_LATIN_1 0
#define FT_FACE_FLAG_SCALABLE (1 << 0)
#define FT_FACE_FLAG_HORIZONTAL (1 << 1)
#define FT_FACE_FLAG_GLYPH_NAMES (1 << 2)
#define FT_FACE_FLAG_FIXED_WIDTH (1 << 3)
#define FT_FACE_FLAG_HINTER (1 << 4)
#define FT_FACE_FLAG_VERTICAL (1 << 5)
#define FT_STYLE_FLAG_ITALIC (1 << 0)
#define FT_STYLE_FLAG_BOLD (1 << 1)
#define FT_OPEN_MEMORY (1 << 0)
#define FT_OPEN_DRIVER (1 << 1)
#define FT_OPEN_PARAMS (1 << 2)
#define POSTSCRIPT_CMAPS "postscript-cmaps"
#define FT_ERR_NEQ(e1, e2) ((e1) != (e2))
#define No_Unicode_Glyph_Name (-1)
#define FT_Err_Ok 0

enum {
    T1_ENCODING_TYPE_STANDARD,
    T1_ENCODING_TYPE_EXPERT,
    T1_ENCODING_TYPE_ARRAY,
    T1_ENCODING_TYPE_ISOLATIN1
};

struct FT_FaceRec_ {
    int num_faces;
    int num_glyphs;
    int num_charmaps;
    int face_index;
    long face_flags;
    int style_flags;
    char* family_name;
    char* style_name;
    int num_fixed_sizes;
    void* available_sizes;
    void* bbox;
    unsigned int units_per_EM;
    int ascender;
    int descender;
    int height;
    int max_advance_width;
    int max_advance_height;
    short underline_position;
    short underline_thickness;
    void* size;
    void* charmap;
    void* charmaps[1];
    void* driver;
    void* memory;
    void* stream;
    void* sizes_list;
    void* generic;
};

struct T42_FaceRec_ {
    struct FT_FaceRec_ root;
    FT_Face ttf_face;
    unsigned char* ttf_data;
    unsigned long ttf_size;
    FT_Service_PsCMaps psnames;
    void* psaux;
    struct T1_FontRec type1;
};

struct FT_CharMapRec_ {
    FT_Face face;
    int platform_id;
    int encoding_id;
    int encoding;
};

struct FT_Open_Args_ {
    unsigned int flags;
    void* memory_base;
    unsigned long memory_size;
    void* driver;
    int num_params;
    FT_Parameter* params;
};

extern FT_Error T42_Open_Face(T42_Face face);
extern FT_Error FT_CMap_New(FT_CMap_Class clazz, void* init_data, FT_CharMapRec* charmap, void* cmap);
extern void* FT_Get_Module_Interface(void* library, const char* name);
extern void* FT_FACE_LIBRARY(FT_Face face);
extern void* FT_Get_Module(void* library, const char* name);
extern FT_Error FT_Open_Face(void* library, FT_Open_Args* args, int face_index, FT_Face* aface);
extern void FT_Done_Size(void* size);