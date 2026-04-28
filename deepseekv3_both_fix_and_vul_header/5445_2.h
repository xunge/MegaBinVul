#include <stddef.h>
#include <stdint.h>

typedef uint32_t FT_UInt;

typedef struct FT_StreamRec_ {
    FT_UInt size;
} *FT_Stream;

typedef struct FT_MemoryRec_* FT_Memory;

typedef enum {
    FT_Err_Ok,
    Cannot_Open_Resource,
    Invalid_File_Format,
    Out_Of_Memory,
    Invalid_Offset,
    Invalid_Table
} FT_Error;

typedef struct PCF_TableRec_ {
    FT_UInt type;
    FT_UInt format;
    FT_UInt size;
    FT_UInt offset;
} PCF_TableRec, *PCF_Table;

typedef struct PCF_TocRec_ {
    FT_UInt version;
    FT_UInt count;
    PCF_Table tables;
} PCF_TocRec, *PCF_Toc;

typedef struct FT_FaceRec_ {
    FT_Memory memory;
} FT_FaceRec;

typedef struct PCF_FaceRec_ {
    FT_FaceRec root;
    PCF_TocRec toc;
} *PCF_Face;

#define FT_ARRAY_MAX(a) (sizeof(a)/sizeof((a)[0]))
#define FT_FACE(face) (&(face)->root)
#define FT_STREAM_SEEK(pos) (0)
#define FT_STREAM_READ_FIELDS(format, ptr) (0)
#define FT_NEW_ARRAY(ptr, count) (0)
#define FT_FREE(ptr)
#define FT_THROW(error) (error)
#define FT_DEBUG_LEVEL_TRACE
#define FT_TRACE4(args)

static const char* tableNames[] = {
    "properties",
    "accelerators",
    "metrics",
    "bitmaps",
    "ink metrics",
    "encodings",
    "BDF encodings",
    "swidths",
    "glyph names",
    "BDF accelerators"
};

#define PCF_FILE_VERSION 0x70636601