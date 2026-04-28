#include <stddef.h>
#include <string.h>

typedef struct FT_StreamRec_* FT_Stream;
typedef struct FT_FaceRec_* FT_Face;
typedef struct FT_LibraryRec_* FT_Library;
typedef struct FT_ModuleRec_* FT_Module;
typedef struct FT_MemoryRec_* FT_Memory;

typedef int FT_Error;
typedef int FT_Int;
typedef unsigned int FT_UInt;
typedef long FT_Long;
typedef unsigned long FT_ULong;
typedef unsigned short FT_UShort;
typedef signed long FT_Long;
typedef void* FT_Pointer;
typedef unsigned char FT_Byte;

typedef struct FT_Parameter_ {
    FT_ULong tag;
    FT_Pointer data;
} FT_Parameter;

typedef struct FT_DriverRec_ {
    struct {
        FT_Library library;
    } root;
} *FT_Driver;

typedef struct TT_FaceRec_ {
    struct {
        FT_Driver driver;
        FT_Stream stream;
        FT_Memory memory;
        FT_Long num_faces;
        FT_Int face_index;
        FT_Long style_flags;
    } root;
    void* sfnt;
    FT_Error (*goto_table)(struct TT_FaceRec_*, FT_ULong, FT_Stream, FT_ULong*);
    void* psnames;
    void* mm;
    void* tt_var;
    void* face_var;
    void* var;
    struct {
        FT_ULong count;
        FT_ULong* offsets;
    } ttc_header;
    FT_ULong variation_support;
} *TT_Face;

typedef struct SFNT_ServiceRec_ {
    FT_Error (*goto_table)(TT_Face, FT_ULong, FT_Stream, FT_ULong*);
    FT_Error (*load_font_dir)(TT_Face, FT_Stream);
} *SFNT_Service;

#define FT_LOCAL_DEF(x) x
#define FT_UNUSED(x) (void)(x)
#define FT_ERROR(x) 
#define FT_THROW(x) (-1)
#define FT_FACE_FIND_GLOBAL_SERVICE(face, ptr, id)
#define FT_TRACE2(x)
#define TT_CONFIG_OPTION_GX_VAR_SUPPORT
#define TTAG_fvar 0x66766172
#define TTAG_glyf 0x676C7966
#define TTAG_CFF2 0x43464632
#define TTAG_CFF  0x43464620
#define FT_SERVICE_ID_MULTI_MASTERS 0
#define FT_SERVICE_ID_METRICS_VARIATIONS 0
#define TT_FACE_FLAG_VAR_FVAR (1 << 0)
#define FT_READ_ULONG(x) 0
#define FT_READ_USHORT(x) 0
#define FT_STREAM_SKIP(x) 0
#define FT_STREAM_SEEK(x) 0
#define FT_STREAM_POS() 0
#define FT_STREAM_READ_AT(x,y,z) 0
#define FT_QALLOC(x,y) 0
#define FT_FREE(x)
#define FT_ABS(x) ((x) < 0 ? -(x) : (x))
#define POSTSCRIPT_CMAPS 0
#define Missing_Module 0
#define Invalid_Argument 0

static inline int ft_memcmp(const void* a, const void* b, size_t n) {
    return memcmp(a, b, n);
}

FT_Error sfnt_open_font(FT_Stream stream, TT_Face face, FT_Int* face_instance_index, FT_Long* woff2_num_faces);
FT_Module FT_Get_Module(FT_Library library, const char* name);
void* FT_Get_Module_Interface(FT_Library library, const char* name);
void* ft_module_get_service(FT_Module module, int service_id, int flags);