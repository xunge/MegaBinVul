#include <stdio.h>
#include <string.h>

#define MaxTextExtent 4096
#define UndefinedException 0

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

typedef long long MagickOffsetType;
typedef long ssize_t;