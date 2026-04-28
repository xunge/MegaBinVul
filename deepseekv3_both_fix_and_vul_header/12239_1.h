#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct tiff TIFF;
typedef struct {
    uint32_t td_nstrips;
    uint32_t td_stripsperimage;
    uint64_t* td_stripbytecount_p;
    uint64_t* td_stripoffset_p;
#ifdef STRIPBYTECOUNTSORTED_UNUSED
    int td_stripbytecountsorted;
#endif
} TIFFDirectory;

struct tiff {
    TIFFDirectory tif_dir;
    unsigned long tif_flags;
};

extern uint64_t TIFFGetStrileOffset(TIFF* tif, uint32_t strip);
extern uint64_t TIFFGetStrileByteCount(TIFF* tif, uint32_t strip);
extern uint64_t TIFFGetFileSize(TIFF* tif);
extern void* _TIFFCheckMalloc(TIFF* tif, size_t nmemb, size_t elem_size, const char* what);
extern void _TIFFfreeExt(TIFF* tif, void* ptr);
extern void TIFFWarningExtR(TIFF* tif, const char* module, const char* fmt, ...);
extern void TIFFSetField(TIFF* tif, int tag, ...);

#define TIFFTAG_ROWSPERSTRIP 278
#define TIFF_CHOPPEDUPARRAYS 0x80000000UL