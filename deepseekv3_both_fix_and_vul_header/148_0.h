#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MagickPathExtent 4096
#define THUMBNAIL_ID 1037
#define IPTC_ID 1028

typedef struct _Image Image;

int ReadBlobByte(Image *);
int ReadBlobMSBSignedShort(Image *);
long ReadBlobMSBSignedLong(Image *);
size_t GetBlobSize(Image *);
void *AcquireQuantumMemory(size_t, size_t);
void *RelinquishMagickMemory(void *);
int FormatLocaleString(char *, size_t, const char *, ...);
int WriteBlobString(Image *, const char *);
void formatString(Image *, const char *, ssize_t);
void formatIPTCfromBuffer(Image *, char *, ssize_t);