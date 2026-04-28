#include <stddef.h>
#include <string.h>

typedef struct FT_StreamRec_*  FT_Stream;
typedef struct FT_LibraryRec_* FT_Library;
typedef struct FT_MemoryRec_*  FT_Memory;
typedef struct FT_DriverRec_*  FT_Driver;
typedef struct FT_ModuleRec_*  FT_Module;

typedef int FT_Error;
typedef int FT_Int;
typedef unsigned int FT_UInt;
typedef unsigned long FT_ULong;
typedef unsigned short FT_UShort;
typedef long FT_Long;
typedef unsigned char FT_Byte;

typedef struct FT_Parameter_ {
    FT_ULong tag;
    void*    data;
} FT_Parameter;

struct FT_FaceRec_ {
    FT_Memory memory;
    struct FT_DriverRec_* driver;
    FT_Stream stream;
    FT_Long style_flags;
    FT_Int num_faces;
    FT_Int face_index;
    void* psnames;
};

struct FT_DriverRec_ {
    struct {
        FT_Library library;
    } root;
};

struct FT_LibraryRec_ {
    void* library;
};

struct TT_FaceRec_ {
    struct FT_FaceRec_ root;
    void* sfnt;
    FT_Error (*goto_table)(struct TT_FaceRec_*, FT_ULong, FT_Stream, FT_ULong*);
    void* mm;
    void* var;
    struct {
        FT_ULong count;
        FT_ULong* offsets;
    } ttc_header;
    FT_ULong variation_support;
    FT_Int is_default_instance;
};

typedef struct TT_FaceRec_* TT_Face;

typedef struct SFNT_ServiceRec_ {
    FT_Error (*goto_table)(struct TT_FaceRec_*, FT_ULong, FT_Stream, FT_ULong*);
    FT_Error (*load_font_dir)(struct TT_FaceRec_*, FT_Stream);
} *SFNT_Service;

#define FT_LOCAL_DEF(x) x
#define FT_UNUSED(x) (void)(x)
#define FT_ERROR(x) 
#define FT_THROW(x) (-1)
#define FT_FACE_FIND_GLOBAL_SERVICE(face, field, id)
#define FT_TRACE2(x)
#define FT_ABS(x) ((x) < 0 ? -(x) : (x))
#define FT_STREAM_SEEK(x) 0
#define FT_READ_ULONG(x) 0
#define FT_READ_USHORT(x) 0
#define FT_STREAM_SKIP(x) (error = 0)
#define FT_STREAM_POS() 0
#define FT_STREAM_READ_AT(offset, buf, count) 0
#define FT_ALLOC(ptr, size) 0
#define FT_FREE(ptr) 
#define ft_memcmp memcmp

#define TTAG_fvar 0x66766172
#define TTAG_glyf 0x676C7966
#define TTAG_CFF  0x43464620
#define TT_FACE_FLAG_VAR_FVAR (1 << 0)

#define TT_CONFIG_OPTION_GX_VAR_SUPPORT
#define FT_SERVICE_ID_MULTI_MASTERS "multi-masters"
#define FT_SERVICE_ID_METRICS_VARIATIONS "metrics-variations"
#define POSTSCRIPT_CMAPS "postscript-cmaps"

#define Missing_Module 0
#define Invalid_Argument 0

FT_Error sfnt_open_font(FT_Stream stream, TT_Face face);
void* FT_Get_Module_Interface(FT_Library library, const char* name);
FT_Module FT_Get_Module(FT_Library library, const char* name);
void* ft_module_get_service(FT_Module module, const char* service_id, FT_UInt flags);