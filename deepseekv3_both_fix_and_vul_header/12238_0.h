#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct TIFF TIFF;
typedef struct TIFFDirEntry {
    uint16_t tdir_tag;
    uint64_t tdir_count;
} TIFFDirEntry;
typedef struct TIFFField {
    const char *field_name;
} TIFFField;

enum TIFFReadDirEntryErr {
    TIFFReadDirEntryErrOk,
    TIFFReadDirEntryErrCount
};

extern enum TIFFReadDirEntryErr TIFFReadDirEntryLong8ArrayWithLimit(TIFF *tif, TIFFDirEntry *dir, uint64_t **data, uint32_t nstrips);
extern const TIFFField *TIFFFieldWithTag(TIFF *tif, uint16_t tag);
extern void TIFFReadDirEntryOutputErr(TIFF *tif, enum TIFFReadDirEntryErr err, const char *module, const char *field_name, int arg);
extern uint64_t TIFFGetFileSize(TIFF *tif);
extern void *_TIFFCheckMalloc(TIFF *tif, uint32_t nmemb, size_t size, const char *what);
extern void _TIFFfreeExt(TIFF *tif, void *ptr);
extern void _TIFFmemcpy(void *dst, const void *src, size_t n);
extern void _TIFFmemset(void *p, int v, size_t n);
extern void TIFFWarningExtR(TIFF *tif, const char *module, const char *fmt, ...);