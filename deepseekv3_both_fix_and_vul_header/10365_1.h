#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Image {
    char filename[4096];
    char magick_filename[4096];
    char magick[4096];
    void *blob;
    size_t depth;
    size_t rows;
    size_t columns;
} Image;

typedef struct _ImageInfo {
    void *blob;
    size_t length;
    char magick[4096];
    char filename[4096];
} ImageInfo;

typedef struct _ExceptionInfo {
    int severity;
} ExceptionInfo;

typedef struct _MagicInfo {
    char *name;
} MagicInfo;

typedef long long MagickOffsetType;
typedef long ssize_t;

#define MagickPathExtent 4096
#define UndefinedException 0

static void *CopyMagickMemory(void *dest, const void *src, size_t n) {
    return memcpy(dest, src, n);
}
static void DestroyBlob(Image *image) {}
static void *ReferenceBlob(void *blob) { return blob; }
static void DestroyImageInfo(ImageInfo *image_info) {}
static ImageInfo *CloneImageInfo(const ImageInfo *image_info) { return NULL; }
static int SeekBlob(Image *image, MagickOffsetType offset, int whence) { return 0; }
static size_t ReadBlob(Image *image, size_t count, unsigned char *data) { return 0; }
static int ReadBlobByte(Image *image) { return 0; }
static const MagicInfo *GetMagicInfo(const unsigned char *magick, size_t length, ExceptionInfo *exception) { return NULL; }
static Image *ReadImage(ImageInfo *image_info, ExceptionInfo *exception) { return NULL; }
static void DeleteImageFromList(Image **image) {}
static void AppendImageToList(Image **image, Image *image2) {}
static char *AcquireUniqueFilename(char *filename) { return filename; }
static void RelinquishUniqueFileResource(const char *filename) {}
static char *FormatLocaleString(char *string, size_t length, const char *format, ...) { return string; }
static FILE *fopen_utf8(const char *filename, const char *mode) { return fopen(filename, mode); }