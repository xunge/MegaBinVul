#include <stdint.h>
#include <assert.h>
#include <stddef.h>
#include <inttypes.h>

enum TIFFReadDirEntryErr {
    TIFFReadDirEntryErrOk,
    TIFFReadDirEntryErrSizesan,
    TIFFReadDirEntryErrAlloc,
    TIFFReadDirEntryErrIo
};

typedef struct {
    uint32_t tdir_tag;
    uint32_t tdir_type;
    uint64_t tdir_count;
    union {
        uint32_t toff_long;
        uint64_t toff_long8;
    } tdir_offset;
} TIFFDirEntry;

typedef struct {
    uint32_t tif_flags;
    uint64_t tif_size;
} TIFF;

#define MAX_SIZE_TAG_DATA (2147483647U)
#define TIFF_BIGTIFF (1 << 0)
#define TIFF_SWAB (1 << 1)

typedef ptrdiff_t tmsize_t;

extern int TIFFDataWidth(uint32_t type);
extern uint64_t TIFFGetFileSize(TIFF *tif);
extern int isMapped(TIFF *tif);
extern void TIFFWarningExtR(TIFF *tif, const char *module, const char *fmt, ...);
extern void *_TIFFCheckMalloc(TIFF *tif, uint32_t count, int typesize, const char *what);
extern void _TIFFfreeExt(TIFF *tif, void *ptr);
extern void _TIFFmemcpy(void *dst, const void *src, size_t n);
extern void TIFFSwabLong(uint32_t *lp);
extern void TIFFSwabLong8(uint64_t *lp);
extern enum TIFFReadDirEntryErr TIFFReadDirEntryData(TIFF *tif, uint64_t offset, tmsize_t datasize, void *data);
extern enum TIFFReadDirEntryErr TIFFReadDirEntryDataAndRealloc(TIFF *tif, uint64_t offset, tmsize_t datasize, void **data);