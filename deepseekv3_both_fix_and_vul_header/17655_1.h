#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long ExifLong;
typedef unsigned char ExifByteOrder;

#define EXIF_BYTE_ORDER_INTEL 0
#define EXIF_LOG_CODE_CORRUPT_DATA 0
#define EXIF_LOG_CODE_DEBUG 0
#define EXIF_LOG_NO_MEMORY(log, tag, size)

typedef struct _ExifLog ExifLog;
typedef struct _ExifMem ExifMem;

typedef struct _ExifMnoteData ExifMnoteData;
typedef struct _ExifMnoteDataFuji ExifMnoteDataFuji;
typedef struct _MnoteFujiEntry MnoteFujiEntry;

struct _ExifMnoteData {
    ExifLog *log;
    ExifMem *mem;
};

struct _ExifMnoteDataFuji {
    ExifMnoteData parent;
    size_t offset;
    ExifByteOrder order;
    unsigned int count;
    MnoteFujiEntry *entries;
};

struct _MnoteFujiEntry {
    unsigned short tag;
    unsigned short format;
    ExifLong components;
    ExifByteOrder order;
    size_t size;
    unsigned char *data;
};

static ExifLong exif_get_long(const unsigned char *buf, ExifByteOrder order);
static unsigned short exif_get_short(const unsigned char *buf, ExifByteOrder order);
static size_t exif_format_get_size(unsigned short format);
static void exif_log(ExifLog *log, int code, const char *tag, const char *format, ...);
static void exif_mnote_data_fuji_clear(ExifMnoteDataFuji *n);
static void *exif_mem_alloc(ExifMem *mem, size_t size);
static const char *mnote_fuji_tag_get_name(unsigned tag);

#define CHECKOVERFLOW(offset, size, count) ((offset) + (count) > (size))