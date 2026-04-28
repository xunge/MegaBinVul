#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct TIFF TIFF;
typedef struct TIFFDirEntry TIFFDirEntry;
typedef struct TIFFDirectory TIFFDirectory;

enum {
    COMPRESSION_NONE = 1,
    PLANARCONFIG_SEPARATE = 2,
    FIELD_STRIPBYTECOUNTS = 1,
    FIELD_ROWSPERSTRIP = 2,
    TIFF_BIGTIFF = 0x8000
};

typedef struct {
    uint16_t tiff_magic;
    uint16_t tiff_version;
    uint32_t tiff_diroff;
} TIFFHeaderClassic;

typedef struct {
    uint16_t tiff_magic;
    uint16_t tiff_version;
    uint64_t tiff_diroff;
} TIFFHeaderBig;

struct TIFFDirEntry {
    uint16_t tdir_tag;
    uint16_t tdir_type;
    uint64_t tdir_count;
    union {
        uint16_t toff_short;
        uint32_t toff_long;
        uint64_t toff_long8;
    } tdir_offset;
};

struct TIFFDirectory {
    uint32_t td_nstrips;
    uint64_t* td_stripbytecount_p;
    uint64_t* td_stripoffset_p;
    uint16_t td_compression;
    uint16_t td_planarconfig;
    uint16_t td_samplesperpixel;
    uint32_t td_imagelength;
    uint32_t td_stripsperimage;
    uint32_t td_rowsperstrip;
};

struct TIFF {
    TIFFDirectory tif_dir;
    uint32_t tif_flags;
};

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

int _TIFFFillStrilesInternal(TIFF* tif, int flags);
void* _TIFFfreeExt(TIFF* tif, void* ptr);
void* _TIFFCheckMalloc(TIFF* tif, size_t nmemb, size_t size, const char* what);
void TIFFErrorExtR(TIFF* tif, const char* module, const char* fmt, ...);
uint64_t TIFFGetFileSize(TIFF* tif);
int isTiled(TIFF* tif);
uint64_t TIFFTileSize64(TIFF* tif);
uint64_t TIFFScanlineSize64(TIFF* tif);
void TIFFSetFieldBit(TIFF* tif, int field);
int TIFFFieldSet(TIFF* tif, int field);
uint32_t TIFFDataWidth(TIFFDataType type);