#include <stdlib.h>
#include <string.h>

typedef unsigned short ExifShort;
typedef unsigned long ExifLong;

#define EXIF_LOG_CODE_CORRUPT_DATA 1
#define EXIF_LOG_CODE_DEBUG 2
#define CHECKOVERFLOW(offset, size, count) ((offset) + (count) > (size))
#define EXIF_LOG_NO_MEMORY(log, tag, size)
#define FAILSAFE_SIZE_MAX 1000000

struct _ExifMnoteData {
    void *log;
    void *mem;
};
typedef struct _ExifMnoteData ExifMnoteData;

struct _MnoteCanonEntry {
    ExifShort tag;
    ExifShort format;
    ExifLong components;
    size_t size;
    unsigned char *data;
    int order;
};
typedef struct _MnoteCanonEntry MnoteCanonEntry;

struct _ExifMnoteDataCanon {
    ExifMnoteData parent;
    unsigned int offset;
    int order;
    unsigned int count;
    MnoteCanonEntry *entries;
};
typedef struct _ExifMnoteDataCanon ExifMnoteDataCanon;

ExifShort exif_get_short(const unsigned char *buf, int order);
ExifLong exif_get_long(const unsigned char *buf, int order);
size_t exif_format_get_size(ExifShort format);
void exif_log(void *log, int code, const char *module, const char *format, ...);
void exif_mem_free(void *mem, void *ptr);
void *exif_mem_alloc(void *mem, size_t size);
void exif_mnote_data_canon_clear(ExifMnoteDataCanon *n);
const char *mnote_canon_tag_get_name(ExifShort tag);
long mnote_canon_entry_count_values(MnoteCanonEntry *entry);