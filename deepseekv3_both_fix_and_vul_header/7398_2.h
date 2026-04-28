#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <stddef.h>

typedef struct TIFFField TIFFField;

typedef struct TIFF {
    void* tif_clientdata;
    const TIFFField* const* tif_fields;
} TIFF;

typedef struct TIFFDirEntry {
    uint16_t tdir_tag;
    uint64_t tdir_count;
} TIFFDirEntry;

struct TIFFField {
    const char* field_name;
    int field_readcount;
    int field_passcount;
    int set_field_type;
};

enum TIFFReadDirEntryErr {
    TIFFReadDirEntryErrOk,
    TIFFReadDirEntryErrCount,
    TIFFReadDirEntryErrOther
};

enum {
    TIFF_SETGET_UNDEFINED,
    TIFF_SETGET_ASCII,
    TIFF_SETGET_UINT8,
    TIFF_SETGET_UINT16,
    TIFF_SETGET_UINT32,
    TIFF_SETGET_UINT64,
    TIFF_SETGET_FLOAT,
    TIFF_SETGET_DOUBLE,
    TIFF_SETGET_IFD8,
    TIFF_SETGET_UINT16_PAIR,
    TIFF_SETGET_C0_UINT8,
    TIFF_SETGET_C0_UINT16,
    TIFF_SETGET_C0_UINT32,
    TIFF_SETGET_C0_FLOAT,
    TIFF_SETGET_C0_DOUBLE,
    TIFF_SETGET_C16_ASCII,
    TIFF_SETGET_C16_UINT8,
    TIFF_SETGET_C16_UINT16,
    TIFF_SETGET_C16_UINT32,
    TIFF_SETGET_C16_UINT64,
    TIFF_SETGET_C16_FLOAT,
    TIFF_SETGET_C16_DOUBLE,
    TIFF_SETGET_C16_IFD8,
    TIFF_SETGET_C32_ASCII,
    TIFF_SETGET_C32_UINT8,
    TIFF_SETGET_C32_SINT8,
    TIFF_SETGET_C32_UINT16,
    TIFF_SETGET_C32_SINT16,
    TIFF_SETGET_C32_UINT32,
    TIFF_SETGET_C32_SINT32,
    TIFF_SETGET_C32_UINT64,
    TIFF_SETGET_C32_SINT64,
    TIFF_SETGET_C32_FLOAT,
    TIFF_SETGET_C32_DOUBLE,
    TIFF_SETGET_C32_IFD8,
    TIFF_SETGET_OTHER,
    TIFF_SETGET_INT
};

#define FAILED_FII ((uint32_t)-1)
#define TIFF_VARIABLE (-1)
#define TIFF_VARIABLE2 (-2)

void TIFFErrorExt(void*, const char*, const char*, ...);
void TIFFWarningExt(void*, const char*, const char*, ...);
int TIFFSetField(TIFF*, uint32_t, ...);
void* _TIFFmalloc(size_t);
void _TIFFfree(void*);
void* _TIFFmemcpy(void*, const void*, size_t);
uint32_t TIFFReadDirectoryFindFieldInfo(TIFF*, uint16_t, uint32_t*);
void TIFFReadDirEntryOutputErr(TIFF*, enum TIFFReadDirEntryErr, const char*, const char*, int);
enum TIFFReadDirEntryErr TIFFReadDirEntryByteArray(TIFF*, TIFFDirEntry*, uint8_t**);
enum TIFFReadDirEntryErr TIFFReadDirEntryByte(TIFF*, TIFFDirEntry*, uint8_t*);
enum TIFFReadDirEntryErr TIFFReadDirEntryShort(TIFF*, TIFFDirEntry*, uint16_t*);
enum TIFFReadDirEntryErr TIFFReadDirEntryLong(TIFF*, TIFFDirEntry*, uint32_t*);
enum TIFFReadDirEntryErr TIFFReadDirEntryLong8(TIFF*, TIFFDirEntry*, uint64_t*);
enum TIFFReadDirEntryErr TIFFReadDirEntryFloat(TIFF*, TIFFDirEntry*, float*);
enum TIFFReadDirEntryErr TIFFReadDirEntryDouble(TIFF*, TIFFDirEntry*, double*);
enum TIFFReadDirEntryErr TIFFReadDirEntryIfd8(TIFF*, TIFFDirEntry*, uint64_t*);
enum TIFFReadDirEntryErr TIFFReadDirEntryShortArray(TIFF*, TIFFDirEntry*, uint16_t**);
enum TIFFReadDirEntryErr TIFFReadDirEntryLongArray(TIFF*, TIFFDirEntry*, uint32_t**);
enum TIFFReadDirEntryErr TIFFReadDirEntryLong8Array(TIFF*, TIFFDirEntry*, uint64_t**);
enum TIFFReadDirEntryErr TIFFReadDirEntryFloatArray(TIFF*, TIFFDirEntry*, float**);
enum TIFFReadDirEntryErr TIFFReadDirEntryDoubleArray(TIFF*, TIFFDirEntry*, double**);
enum TIFFReadDirEntryErr TIFFReadDirEntryIfd8Array(TIFF*, TIFFDirEntry*, uint64_t**);
enum TIFFReadDirEntryErr TIFFReadDirEntrySbyteArray(TIFF*, TIFFDirEntry*, int8_t**);
enum TIFFReadDirEntryErr TIFFReadDirEntrySshortArray(TIFF*, TIFFDirEntry*, int16_t**);
enum TIFFReadDirEntryErr TIFFReadDirEntrySlongArray(TIFF*, TIFFDirEntry*, int32_t**);
enum TIFFReadDirEntryErr TIFFReadDirEntrySlong8Array(TIFF*, TIFFDirEntry*, int64_t**);