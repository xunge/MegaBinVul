#include <stddef.h>
#include <string.h>

typedef unsigned short ExifShort;
typedef unsigned long ExifLong;

typedef enum {
    EXIF_LOG_CODE_CORRUPT_DATA,
    EXIF_LOG_CODE_DEBUG
} ExifLogCode;

typedef struct {
    void *mem;
    void *log;
} ExifMnoteData;

typedef struct {
    ExifShort tag;
    ExifShort format;
    ExifLong components;
    ExifShort order;
    size_t size;
    void *data;
} MnoteCanonEntry;

typedef struct {
    ExifMnoteData parent;
    size_t offset;
    ExifShort order;
    MnoteCanonEntry *entries;
    unsigned int count;
} ExifMnoteDataCanon;

void exif_log(void *log, ExifLogCode code, const char *module, const char *format, ...);
void *exif_mem_alloc(void *mem, size_t size);
ExifShort exif_get_short(const unsigned char *buf, ExifShort order);
ExifLong exif_get_long(const unsigned char *buf, ExifShort order);
size_t exif_format_get_size(ExifShort format);
void exif_mnote_data_canon_clear(ExifMnoteDataCanon *n);
const char *mnote_canon_tag_get_name(ExifShort tag);