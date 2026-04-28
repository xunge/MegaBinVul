#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef unsigned long FT_ULong;
typedef unsigned short FT_UShort;
typedef unsigned int FT_UInt;
typedef int FT_Error;
typedef int FT_Int;
typedef unsigned char FT_Byte;
typedef char FT_Char;
typedef void* FT_Memory;

#define FT_FACE_FLAG_EXTERNAL_STREAM (1 << 8)

struct FT_StreamRec_ {
    FT_Memory memory;
    size_t size;
    FT_Byte* cursor;
    void (*close)(struct FT_StreamRec_* stream);
};
typedef struct FT_StreamRec_* FT_Stream;

struct TT_FaceRec_ {
    struct {
        FT_Stream stream;
        unsigned long face_flags;
    } root;
};
typedef struct TT_FaceRec_* TT_Face;

struct WOFF_HeaderRec_ {
    FT_ULong  signature;
    FT_ULong  flavor;
    FT_ULong  length;
    FT_UShort num_tables;
    FT_UShort reserved;
    FT_ULong  totalSfntSize;
    FT_UShort majorVersion;
    FT_UShort minorVersion;
    FT_ULong  metaOffset;
    FT_ULong  metaLength;
    FT_ULong  metaOrigLength;
    FT_ULong  privOffset;
    FT_ULong  privLength;
};
typedef struct WOFF_HeaderRec_ WOFF_HeaderRec;

struct WOFF_TableRec_ {
    FT_ULong  Tag;
    FT_ULong  Offset;
    FT_ULong  CompLength;
    FT_ULong  OrigLength;
    FT_ULong  CheckSum;
    FT_ULong  OrigOffset;
};
typedef struct WOFF_TableRec_* WOFF_Table;

struct FT_Frame_Field_ {
    size_t size;
    size_t offset;
};
typedef struct FT_Frame_Field_ FT_Frame_Field;

#define TTAG_wOFF 0x774F4646
#define TTAG_ttcf 0x74746366

#define FT_Err_Ok 0
#define Invalid_Table 1
#define Unimplemented_Feature 2

#define FT_THROW(e) (e)

#define FT_FRAME_START(size) { (size), 0 }
#define FT_FRAME_END { 0, 0 }
#define FT_FRAME_ULONG(field) { sizeof(FT_ULong), offsetof(WOFF_HeaderRec, field) }
#define FT_FRAME_USHORT(field) { sizeof(FT_UShort), offsetof(WOFF_HeaderRec, field) }

#define WRITE_ULONG(p, value)  { *(FT_ULong*)(p) = (value); (p) += sizeof(FT_ULong); }
#define WRITE_USHORT(p, value) { *(FT_UShort*)(p) = (value); (p) += sizeof(FT_UShort); }

#define FT_STREAM_POS() (0)
#define FT_STREAM_SEEK(pos) (0)
#define FT_STREAM_READ_FIELDS(fields, data) (0)
#define FT_FRAME_ENTER(size) (0)
#define FT_FRAME_EXIT()
#define FT_GET_TAG4() (0)
#define FT_GET_ULONG() (0)
#define FT_TRACE2(args)

#define FT_ALLOC(ptr, size) (0)
#define FT_NEW(ptr) (0)
#define FT_NEW_ARRAY(ptr, count) (0)
#define FT_FREE(ptr) free(ptr)

#define FT_ASSERT(expr)

static int compare_offsets(const void* a, const void* b) {
    const WOFF_Table table1 = *(const WOFF_Table*)a;
    const WOFF_Table table2 = *(const WOFF_Table*)b;
    if (table1->Offset < table2->Offset) return -1;
    if (table1->Offset > table2->Offset) return 1;
    return 0;
}

static void ft_qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*)) {
    qsort(base, nmemb, size, compar);
}

static void* ft_memcpy(void* dest, const void* src, size_t n) {
    return memcpy(dest, src, n);
}

static void sfnt_stream_close(FT_Stream stream) {}
static void FT_Stream_OpenMemory(FT_Stream stream, FT_Byte* base, size_t size) {}
static void FT_Stream_Free(FT_Stream stream, int external) {}
static void FT_Stream_Close(FT_Stream stream) {}

#ifdef FT_CONFIG_OPTION_USE_ZLIB
static FT_Error FT_Gzip_Uncompress(FT_Memory memory, FT_Byte* output, FT_ULong* output_len, FT_Byte* input, FT_ULong input_len) {
    return FT_Err_Ok;
}
#endif