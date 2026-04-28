#include <stddef.h>
#include <string.h>

typedef unsigned short ExifShort;
typedef unsigned long ExifLong;
typedef unsigned int ExifTag;

typedef enum {
    EXIF_IFD_0,
    EXIF_IFD_1,
    EXIF_IFD_EXIF,
    EXIF_IFD_GPS,
    EXIF_IFD_INTEROPERABILITY,
    EXIF_IFD_COUNT
} ExifIfd;

typedef enum {
    EXIF_LOG_CODE_DEBUG,
    EXIF_LOG_CODE_CORRUPT_DATA,
    EXIF_LOG_CODE_NO_MEMORY
} ExifLogCode;

typedef struct {
    unsigned int options;
    void *log;
    void *mem;
    int order;
} ExifDataPrivate;

typedef struct {
    ExifDataPrivate *priv;
    void *ifd[EXIF_IFD_COUNT];
} ExifData;

typedef struct {
} ExifEntry;
typedef struct {
} ExifContent;

#define EXIF_TAG_EXIF_IFD_POINTER 0x8769
#define EXIF_TAG_GPS_INFO_IFD_POINTER 0x8825
#define EXIF_TAG_INTEROPERABILITY_IFD_POINTER 0xA005
#define EXIF_TAG_JPEG_INTERCHANGE_FORMAT_LENGTH 0x201
#define EXIF_TAG_JPEG_INTERCHANGE_FORMAT 0x202

#define EXIF_DATA_OPTION_IGNORE_UNKNOWN_TAGS (1 << 0)

#define CHECK_REC(ifd) do { } while(0)

static ExifShort exif_get_short(const unsigned char *buf, int order);
static ExifLong exif_get_long(const unsigned char *buf, int order);
static const char *exif_tag_get_name(ExifTag tag);
static int exif_tag_get_name_in_ifd(ExifTag tag, ExifIfd ifd);
static const char *exif_ifd_get_name(ExifIfd ifd);
static void exif_log(void *log, ExifLogCode code, const char *domain, const char *format, ...);
static ExifEntry *exif_entry_new_mem(void *mem);
static void exif_entry_unref(ExifEntry *entry);
static int exif_data_load_data_entry(ExifData *data, ExifEntry *entry, const unsigned char *d, unsigned int ds, unsigned int offset);
static void exif_content_add_entry(ExifContent *content, ExifEntry *entry);
static void exif_data_load_data_thumbnail(ExifData *data, const unsigned char *d, unsigned int ds, unsigned int offset, unsigned int length);