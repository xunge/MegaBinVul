#include <stdint.h>
#include <string.h>

#define MagickPathExtent 4096
#define TIFFTAG_ARTIST 315
#define TIFFTAG_COPYRIGHT 33432
#define TIFFTAG_DATETIME 306
#define TIFFTAG_DOCUMENTNAME 269
#define TIFFTAG_HOSTCOMPUTER 316
#define TIFFTAG_IMAGEDESCRIPTION 270
#define TIFFTAG_MAKE 271
#define TIFFTAG_MODEL 272
#define TIFFTAG_OPIIMAGEID 32781
#define TIFFTAG_PAGENAME 285
#define TIFFTAG_SOFTWARE 305
#define TIFFTAG_SUBFILETYPE 254

typedef uint32_t uint32;
typedef struct _TIFF TIFF;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;

extern int TIFFGetField(TIFF*, int, ...);
extern void SetImageProperty(Image*, const char*, const char*, ExceptionInfo*);
extern void CopyMagickString(char*, const char*, size_t);
extern void FormatLocaleString(char*, size_t, const char*, ...);