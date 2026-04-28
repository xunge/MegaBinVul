#include <stddef.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned short ExifShort;
typedef unsigned long ExifLong;

typedef enum {
    olympusV1,
    sanyoV1,
    epsonV1,
    olympusV2,
    nikonV1,
    nikonV2,
    nikonV0
} OlympusVariant;

typedef enum {
    EXIF_BYTE_ORDER_INTEL,
    EXIF_BYTE_ORDER_MOTOROLA
} ExifByteOrder;

typedef struct {
    unsigned int tag;
    unsigned int format;
    ExifLong components;
    ExifByteOrder order;
    size_t size;
    unsigned char *data;
} MnoteOlympusEntry;

typedef struct {
    void *log;
    void *mem;
    OlympusVariant version;
    size_t offset;
    ExifByteOrder order;
    MnoteOlympusEntry *entries;
    unsigned int count;
} ExifMnoteDataOlympus;

typedef struct {
    void *log;
    void *mem;
} ExifMnoteData;

#define MNOTE_NIKON1_TAG_BASE 0
#define EXIF_LOG_CODE_CORRUPT_DATA 0
#define EXIF_LOG_CODE_DEBUG 1
#define EXIF_LOG_NO_MEMORY(log, domain, size)

static void exif_log(void *log, int code, const char *domain, const char *format, ...);
static OlympusVariant exif_mnote_data_olympus_identify_variant(const unsigned char *buf, unsigned int buf_size);
static void exif_mnote_data_olympus_clear(ExifMnoteDataOlympus *n);
static void *exif_mem_alloc(void *mem, size_t size);
static ExifShort exif_get_short(const unsigned char *buf, ExifByteOrder order);
static ExifLong exif_get_long(const unsigned char *buf, ExifByteOrder order);
static size_t exif_format_get_size(unsigned int format);
static const char *mnote_olympus_tag_get_name(unsigned int tag);