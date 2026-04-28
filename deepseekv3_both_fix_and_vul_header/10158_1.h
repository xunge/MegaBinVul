#include <stdio.h>
#include <string.h>

#define MaxTextExtent 4096
#define UndefinedException 0
#define SEEK_SET 0

typedef long long MagickOffsetType;
typedef long ssize_t;

typedef struct _Image {
    char filename[MaxTextExtent];
    char magick_filename[MaxTextExtent];
    char magick[MaxTextExtent];
    void *blob;
    size_t rows;
    size_t columns;
    size_t depth;
} Image;

typedef struct _ImageInfo {
    void *blob;
    size_t length;
    char magick[MaxTextExtent];
    char filename[MaxTextExtent];
} ImageInfo;

typedef struct _ExceptionInfo {
    int severity;
} ExceptionInfo;

typedef struct _MagicInfo {
    char *name;
} MagicInfo;

static void *CloneImageInfo(const ImageInfo *);
static void DestroyImageInfo(ImageInfo *);
static int AcquireUniqueFilename(char *);
static FILE *fopen_utf8(const char *, const char *);
static int SeekBlob(Image *, MagickOffsetType, int);
static size_t ReadBlob(Image *, size_t, unsigned char *);
static int ReadBlobByte(Image *);
static const MagicInfo *GetMagicInfo(const unsigned char *, size_t, ExceptionInfo *);
static void FormatLocaleString(char *, size_t, const char *, ...);
static Image *ReadImage(ImageInfo *, ExceptionInfo *);
static void CopyMagickString(char *, const char *, size_t);
static void DestroyBlob(Image *);
static void *ReferenceBlob(void *);
static void DeleteImageFromList(Image **);
static void AppendImageToList(Image **, Image *);
static int RelinquishUniqueFileResource(const char *);