#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define M_EXIF 1

typedef unsigned char uchar;

typedef struct {
    uchar *Data;
    int Size;
} Section_t;

typedef struct {
    int ThumbnailOffset;
    int ThumbnailSize;
    int ThumbnailSizeOffset;
    int ThumbnailAtEnd;
} ImageInfo_t;

extern ImageInfo_t ImageInfo;
extern Section_t *FindSection(int);
extern void ErrFatal(const char *);
extern void Put32u(uchar *, int);