#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct TIFF TIFF;
typedef struct TIFFDirEntry TIFFDirEntry;
typedef struct TIFFDirectory TIFFDirectory;

#define COMPRESSION_NONE 1
#define PLANARCONFIG_SEPARATE 2
#define TIFF_BIGTIFF 0x8000
#define FIELD_STRIPBYTECOUNTS 1
#define FIELD_ROWSPERSTRIP 2

typedef enum {
    TIFF_NOTYPE = 0,
    TIFF_BYTE = 1,
    TIFF_ASCII = 2,
    TIFF_SHORT = 3,
    TIFF_LONG = 4,
    TIFF_RATIONAL = 5,
    TIFF_SBYTE = 6,
    TIFF_UNDEFINED = 7,
    TIFF_SSHORT = 8,
    TIFF_SLONG = 9,
    TIFF_SRATIONAL = 10,
    TIFF_FLOAT = 11,
    TIFF_DOUBLE = 12,
    TIFF_IFD = 13,
    TIFF_LONG8 = 16,
    TIFF_SLONG8 = 17,
    TIFF_IFD8 = 18
} TIFFDataType;

typedef struct {
    uint16_t tiff_magic;
    uint16_t tiff_version;
    uint32_t tiff_diroff;
} TIFFHeaderClassic;

typedef struct {
    uint16_t tiff_magic;
    uint16_t tiff_version;
    uint16_t tiff_offsetsize;
    uint16_t tiff_unused;
    uint64_t tiff_diroff;
} TIFFHeaderBig;

struct TIFFDirEntry {
    uint16_t tdir_type;
    uint16_t tdir_tag;
    uint64_t tdir_count;
    union {
        uint16_t toff_short;
        uint32_t toff_long;
        uint64_t toff_long8;
    } tdir_offset;
};

struct TIFFDirectory {
    uint32_t td_nstrips;
    uint64_t *td_stripbytecount_p;
    uint16_t td_compression;
    uint16_t td_planarconfig;
    uint16_t td_samplesperpixel;
    uint32_t td_imagelength;
    uint32_t td_stripsperimage;
    uint32_t td_rowsperstrip;
    uint64_t *td_stripoffset_p;
};

struct TIFF {
    TIFFDirectory tif_dir;
    uint64_t tif_flags;
};

extern int _TIFFFillStrilesInternal(TIFF *, int);
extern void TIFFWarningExtR(TIFF *, const char *, const char *, ...);
extern void TIFFErrorExtR(TIFF *, const char *, const char *, ...);
extern void _TIFFfreeExt(TIFF *, void *);
extern void *_TIFFCheckMalloc(TIFF *, size_t, size_t, const char *);
extern uint64_t TIFFGetFileSize(TIFF *);
extern uint64_t TIFFTileSize64(TIFF *);
extern uint64_t TIFFScanlineSize64(TIFF *);
extern void TIFFSetFieldBit(TIFF *, int);
extern int TIFFFieldSet(TIFF *, int);
extern int isTiled(TIFF *);
extern uint32_t TIFFDataWidth(TIFFDataType);