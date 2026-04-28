#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

typedef struct TIFF TIFF;
typedef uint64_t toff_t;
typedef struct TIFFFieldArray TIFFFieldArray;
typedef struct TIFFDirEntry TIFFDirEntry;
typedef struct TIFFField TIFFField;
typedef struct TIFFDirectory TIFFDirectory;
typedef uint16_t TIFFDataType;

#define TRUE 1
#define FAILED_FII 0xFFFF
#define FIELD_IGNORE 0
#define TIFF_VARIABLE (-1)
#define TIFF_VARIABLE2 (-2)
#define TIFF_SPP (-3)
#define TIFF_ANY 0
#define EXIFTAG_SUBJECTDISTANCE 37382

struct TIFFDirEntry {
    uint16_t tdir_tag;
    uint16_t tdir_type;
    uint32_t tdir_count;
    uint32_t tdir_offset;
    uint8_t tdir_ignore;
};

struct TIFFField {
    uint32_t field_tag;
    uint16_t field_type;
    int field_readcount;
    const char* field_name;
    uint32_t field_bit;
};

struct TIFFDirectory {
    uint16_t td_samplesperpixel;
};

struct TIFF {
    void* tif_clientdata;
    TIFFDirectory tif_dir;
    TIFFField** tif_fields;
    uint16_t tif_nfields;
    void (*tif_cleanup)(TIFF*);
};

extern void _TIFFSetupFields(TIFF*, const TIFFFieldArray*);
extern uint16_t TIFFFetchDirectory(TIFF*, toff_t, TIFFDirEntry**, void*);
extern void TIFFErrorExt(void*, const char*, const char*, ...);
extern void TIFFFreeDirectory(TIFF*);
extern void _TIFFmemset(void*, int, size_t);
extern void TIFFReadDirectoryCheckOrder(TIFF*, TIFFDirEntry*, uint16_t);
extern void TIFFReadDirectoryFindFieldInfo(TIFF*, uint16_t, uint32_t*);
extern void TIFFWarningExt(void*, const char*, const char*, ...);
extern int _TIFFMergeFields(TIFF*, TIFFField*, int);
extern TIFFField* _TIFFCreateAnonField(TIFF*, uint16_t, uint16_t);
extern int CheckDirCount(TIFF*, TIFFDirEntry*, uint32_t);
extern void* _TIFFfree(void*);
extern int TIFFFetchSubjectDistance(TIFF*, TIFFDirEntry*);
extern int TIFFFetchNormalTag(TIFF*, TIFFDirEntry*, int);