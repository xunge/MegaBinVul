#include <stdlib.h>
#include <string.h>

typedef struct _ExifLog ExifLog;
typedef struct _ExifMem ExifMem;

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
    ExifShort tag;
    ExifShort format;
    ExifLong components;
    ExifByteOrder order;
    size_t size;
    unsigned char *data;
} MnotePentaxEntry;

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

#define CHECKOVERFLOW(offset, size, count) ((offset) + (count) > (size))

#define EXIF_LOG_NO_MEMORY(log, domain, size) \
    exif_log(log, EXIF_LOG_CODE_CORRUPT_DATA, domain, "No memory for %zu bytes", size)

void exif_log(ExifLog *log, ExifLogCode code, const char *domain, const char *format, ...);
ExifShort exif_get_short(const unsigned char *buf, ExifByteOrder order);
ExifLong exif_get_long(const unsigned char *buf, ExifByteOrder order);
size_t exif_format_get_size(ExifShort format);
void exif_mnote_data_pentax_clear(ExifMnoteDataPentax *n);
void *exif_mem_alloc(ExifMem *mem, size_t size);
const char *mnote_pentax_tag_get_name(ExifShort tag);