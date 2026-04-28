#include <stddef.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned short ExifShort;
typedef unsigned int ExifLong;

typedef enum {
    EXIF_BYTE_ORDER_INTEL,
    EXIF_BYTE_ORDER_MOTOROLA
} ExifByteOrder;

typedef enum {
    EXIF_LOG_CODE_CORRUPT_DATA,
    EXIF_LOG_CODE_DEBUG
} ExifLogCode;

typedef enum {
    pentaxV1,
    pentaxV2,
    pentaxV3,
    casioV2
} PentaxVersion;

typedef struct {
    unsigned int tag;
    unsigned short format;
    unsigned int components;
    ExifByteOrder order;
    size_t size;
    unsigned char *data;
} MnotePentaxEntry;

typedef struct _ExifLog ExifLog;
typedef struct _ExifMem ExifMem;

typedef struct _ExifMnoteData {
    ExifLog *log;
    ExifMem *mem;
} ExifMnoteData;

typedef struct _ExifMnoteDataPentax {
    ExifMnoteData parent;
    PentaxVersion version;
    ExifByteOrder order;
    unsigned int offset;
    MnotePentaxEntry *entries;
    unsigned int count;
} ExifMnoteDataPentax;

#define MNOTE_PENTAX2_TAG_BASE 0
#define MNOTE_CASIO2_TAG_BASE 0

static void exif_log(ExifLog *log, ExifLogCode code, const char *domain, const char *format, ...);
static ExifShort exif_get_short(const unsigned char *buf, ExifByteOrder order);
static ExifLong exif_get_long(const unsigned char *buf, ExifByteOrder order);
static size_t exif_format_get_size(unsigned short format);
static void exif_mnote_data_pentax_clear(ExifMnoteDataPentax *n);
static const char *mnote_pentax_tag_get_name(unsigned int tag);
static void *exif_mem_alloc(ExifMem *mem, size_t size);
#define EXIF_LOG_NO_MEMORY(log, domain, size) exif_log(log, EXIF_LOG_CODE_CORRUPT_DATA, domain, "No memory for %zu bytes", size)