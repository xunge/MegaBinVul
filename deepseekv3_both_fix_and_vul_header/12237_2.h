#include <stdint.h>
#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

typedef int32_t tmsize_t;

typedef struct tiff {
    uint64_t tif_diroff;
    char* tif_name;
    uint32_t tif_flags;
    uint8_t* tif_base;
    tmsize_t tif_size;
} TIFF;

typedef struct {
    uint16_t tdir_tag;
    uint16_t tdir_type;
    uint64_t tdir_count;
    union {
        uint32_t toff_long;
        uint64_t toff_long8;
    } tdir_offset;
    bool tdir_ignore;
} TIFFDirEntry;

#define TIFF_BIGTIFF 0x8000
#define TIFF_SWAB 0x4000
#define FALSE false
#define NULL ((void*)0)

static int isMapped(TIFF* tif) { return 0; }
static int SeekOK(TIFF* tif, uint64_t off) { return 0; }
static int ReadOK(TIFF* tif, void* buf, tmsize_t size) { return 0; }
static void TIFFErrorExtR(TIFF* tif, const char* module, const char* fmt, ...) {}
static void TIFFWarningExtR(TIFF* tif, const char* module, const char* fmt, ...) {}
static void TIFFSwabShort(uint16_t* p) {}
static void TIFFSwabLong(uint32_t* p) {}
static void TIFFSwabLong8(uint64_t* p) {}
static void* _TIFFCheckMalloc(TIFF* tif, size_t nmemb, size_t elem_size, const char* what) { return NULL; }
static void _TIFFfreeExt(TIFF* tif, void* p) {}
static void _TIFFmemcpy(void* dst, const void* src, size_t n) {}
static uint64_t TIFFGetFileSize(TIFF* tif) { return 0; }
static uint64_t TIFFReadUInt64(uint8_t* p) { return 0; }