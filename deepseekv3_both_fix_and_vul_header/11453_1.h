#include <stddef.h>
#include <string.h>

typedef struct _StringInfo StringInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { PixelsPerInchResolution } ResolutionType;

#define MSBEndian 1
#define MagickPathExtent 4096

struct _Image {
    struct {
        double x;
        double y;
    } resolution;
    ResolutionType units;
};

StringInfo *BlobToStringInfo(const unsigned char *, size_t);
void SetStringInfoDatum(StringInfo *, const unsigned char *);
void SetStringInfoName(StringInfo *, const char *);
int LocaleNCompare(const char *, const char *, size_t);
unsigned char *PushShortPixel(int, const unsigned char *, unsigned short *);
unsigned char *PushCharPixel(const unsigned char *, unsigned char *);
unsigned char *PushLongPixel(int, const unsigned char *, unsigned int *);
int FormatLocaleString(char *, size_t, const char *, ...);
void *SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);