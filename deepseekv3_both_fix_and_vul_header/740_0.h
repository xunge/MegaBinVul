#include <stdint.h>
#include <string.h>

typedef struct _ExifData ExifData;
typedef struct _ExifEntry ExifEntry;
typedef struct _ExifLog ExifLog;

struct _ExifData {
    struct {
        ExifLog *log;
        int order;
        unsigned int offset_mnote;
    } *priv;
};

struct _ExifEntry {
    uint16_t tag;
    uint16_t format;
    uint32_t components;
    unsigned char *data;
    unsigned int size;
};

#define EXIF_TAG_MAKER_NOTE 0x927C
#define EXIF_LOG_CODE_DEBUG 0

static uint16_t exif_get_short(const unsigned char *buf, int order);
static uint32_t exif_get_long(const unsigned char *buf, int order);
static unsigned int exif_format_get_size(uint16_t format);
static const char *exif_tag_get_name(uint16_t tag);
static void exif_log(ExifLog *log, int code, const char *domain, const char *format, ...);
static void *exif_data_alloc(ExifData *data, unsigned int size);
#define EXIF_LOG_NO_MEMORY(log, domain, size)