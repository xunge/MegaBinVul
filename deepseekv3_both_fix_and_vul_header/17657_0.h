#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short ExifShort;
typedef unsigned long ExifLong;

typedef enum {
    EXIF_LOG_CODE_CORRUPT_DATA,
    EXIF_LOG_CODE_DEBUG
} ExifLogCode;

typedef struct {
    ExifLogCode code;
} ExifLog;

typedef struct {
    void *(*alloc)(void *, size_t);
} ExifMem;

typedef struct {
    ExifShort tag;
    ExifShort format;
    ExifLong components;
    ExifShort order;
    size_t size;
    void *data;
} MnoteCanonEntry;

typedef struct {
    ExifMem *mem;
    ExifLog *log;
    ExifShort order;
    size_t offset;
    MnoteCanonEntry *entries;
    unsigned int count;
} ExifMnoteDataCanon;

typedef struct {
    ExifMem *mem;
    ExifLog *log;
} ExifMnoteData;

#define CHECKOVERFLOW(offset, size, count) ((offset) + (count) > (size))

void exif_log(ExifLog *log, ExifLogCode code, const char *domain, const char *format, ...);
ExifShort exif_get_short(const unsigned char *buf, ExifShort order);
ExifLong exif_get_long(const unsigned char *buf, ExifShort order);
size_t exif_format_get_size(ExifShort format);
void exif_mnote_data_canon_clear(ExifMnoteDataCanon *n);
const char *mnote_canon_tag_get_name(ExifShort tag);
#define EXIF_LOG_NO_MEMORY(log, domain, size)