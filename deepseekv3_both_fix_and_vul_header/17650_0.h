#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long ExifLong;
typedef unsigned char ExifByte;

typedef enum {
    EXIF_BYTE_ORDER_INTEL,
    EXIF_BYTE_ORDER_MOTOROLA
} ExifByteOrder;

typedef enum {
    EXIF_LOG_CODE_CORRUPT_DATA,
    EXIF_LOG_CODE_DEBUG
} ExifLogCode;

typedef struct _ExifLog ExifLog;
typedef struct _ExifMem ExifMem;

typedef struct {
    ExifMem *mem;
    ExifLog *log;
} ExifMnoteData;

typedef struct {
    ExifMnoteData parent;
    unsigned int offset;
    ExifByteOrder order;
    size_t count;
    struct _MnoteFujiEntry *entries;
} ExifMnoteDataFuji;

typedef struct _MnoteFujiEntry {
    unsigned short tag;
    unsigned short format;
    ExifLong components;
    ExifByteOrder order;
    size_t size;
    unsigned char *data;
} MnoteFujiEntry;

extern void exif_log(ExifLog *log, ExifLogCode code, const char *domain, const char *format, ...);
extern ExifLong exif_get_long(const unsigned char *buf, ExifByteOrder order);
extern unsigned short exif_get_short(const unsigned char *buf, ExifByteOrder order);
extern size_t exif_format_get_size(unsigned short format);
extern void exif_mnote_data_fuji_clear(ExifMnoteDataFuji *n);
extern void *exif_mem_alloc(ExifMem *mem, size_t size);
extern const char *mnote_fuji_tag_get_name(unsigned tag);

#define EXIF_LOG_NO_MEMORY(log, domain, size) \
    exif_log(log, EXIF_LOG_CODE_CORRUPT_DATA, domain, "No memory (%lu bytes)", (unsigned long)size)