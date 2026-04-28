#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct Image Image;
typedef struct tiff TIFF;
typedef unsigned int ttag_t;
typedef long ssize_t;
typedef unsigned int uint32;

typedef struct {
  ttag_t field_tag;
} TIFFFieldInfo;

void *AcquireQuantumMemory(size_t count, size_t size);
void *RelinquishMagickMemory(void *memory);
void ResetMagickMemory(void *memory, int value, size_t size);
const char *GetImageArtifact(Image *image, const char *artifact);
int TIFFReadBlob(TIFF *tiff);
void *TIFFClientdata(TIFF *tiff);
void *TIFFGetReadProc(TIFF *tiff);
int TIFFMergeFieldInfo(TIFF *tiff, TIFFFieldInfo *info, uint32 count);