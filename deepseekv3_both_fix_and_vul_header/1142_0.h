#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct TIFF TIFF;
typedef struct TIFFDirEntry {
    uint16_t tdir_tag;
    uint64_t tdir_count;
} TIFFDirEntry;
typedef struct TIFFField {
    const char* field_name;
} TIFFField;

enum TIFFReadDirEntryErr {
    TIFFReadDirEntryErrOk,
    TIFFReadDirEntryErrCount
};

extern enum TIFFReadDirEntryErr TIFFReadDirEntryLong8ArrayWithLimit(TIFF*, TIFFDirEntry*, uint64_t**, uint32_t);
extern const TIFFField* TIFFFieldWithTag(TIFF*, uint16_t);
extern void TIFFReadDirEntryOutputErr(TIFF*, enum TIFFReadDirEntryErr, const char*, const char*, int);
extern void* _TIFFCheckMalloc(TIFF*, uint32_t, size_t, const char*);
extern void _TIFFfree(void*);
extern void* _TIFFmemcpy(void*, const void*, size_t);
extern void* _TIFFmemset(void*, int, size_t);