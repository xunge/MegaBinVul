#include <string.h>
#include <stdlib.h>

typedef unsigned short ExifShort;
typedef unsigned int ExifLong;

#define EXIF_LOG_CODE_DEBUG 0
#define EXIF_LOG_CODE_CORRUPT_DATA 1
#define EXIF_BYTE_ORDER_INTEL 0
#define EXIF_BYTE_ORDER_MOTOROLA 1
#define EXIF_IFD_0 0
#define EXIF_IFD_1 1
#define EXIF_DATA_OPTION_FOLLOW_SPECIFICATION (1 << 0)
#define JPEG_MARKER_SOI 0xd8
#define JPEG_MARKER_APP1 0xe1
#define LOG_TOO_SMALL do {} while(0)

static const unsigned char ExifHeader[] = {'E', 'x', 'i', 'f', 0, 0};

typedef struct _ExifLog ExifLog;

typedef struct {
    ExifLog *log;
    int order;
    unsigned int options;
} ExifDataPrivate;

typedef struct {
    ExifDataPrivate *priv;
} ExifData;

#define _(x) x

void exif_log(ExifLog *log, int code, const char *domain, const char *format, ...);
void exif_data_load_data_content(ExifData *data, int ifd, const unsigned char *d, unsigned int ds, ExifLong offset, int recursion);
void interpret_maker_note(ExifData *data, const unsigned char *d, unsigned int fullds);
void exif_data_fix(ExifData *data);
ExifShort exif_get_short(const unsigned char *buf, int order);
ExifLong exif_get_long(const unsigned char *buf, int order);