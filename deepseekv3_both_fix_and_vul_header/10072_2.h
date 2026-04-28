#include <assert.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

typedef unsigned char Quantum;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  PseudoClass,
  DirectClass
} ClassType;

typedef enum {
  BlendPixelTrait
} AlphaTraitType;

typedef enum {
  CoderEvent
} EventType;

typedef enum {
  CorruptImageError,
  ResourceLimitError
} ExceptionType;

typedef enum {
  LoadImageTag,
  LoadImagesTag
} ProgressTag;

typedef enum {
  TransparentAlpha,
  OpaqueAlpha
} AlphaType;

typedef struct _ImageInfo {
  unsigned long signature;
  char *filename;
  char *magick;
  MagickBooleanType ping;
  size_t scene;
  size_t number_scenes;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _Image {
  unsigned long signature;
  char *filename;
  size_t columns;
  size_t rows;
  size_t depth;
  size_t colors;
  ClassType storage_class;
  AlphaTraitType alpha_trait;
  MagickBooleanType debug;
  size_t scene;
  struct _Image *previous;
  struct _Image *next;
  void *blob;
  struct {
    Quantum red;
    Quantum green;
    Quantum blue;
  } *colormap;
} Image;

typedef long long MagickOffsetType;

typedef struct {
  short reserved;
  short resource_type;
  short count;
  struct {
    unsigned char width;
    unsigned char height;
    unsigned char colors;
    unsigned char reserved;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned long size;
    unsigned long offset;
  } directory[256];
} IconFile;

typedef struct {
  unsigned long size;
  unsigned char width;
  unsigned char height;
  unsigned short planes;
  unsigned short bits_per_pixel;
  unsigned long compression;
  unsigned long image_size;
  unsigned long x_pixels;
  unsigned long y_pixels;
  unsigned long number_colors;
  unsigned long colors_important;
} IconInfo;

#define MagickSignature 0xabacadabUL
#define MagickPathExtent 4096
#define MaxIcons 256

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, BlobMode, ExceptionInfo *);
Image *DestroyImageList(Image *);
short ReadBlobLSBShort(Image *);
unsigned char ReadBlobByte(Image *);
unsigned long ReadBlobLSBLong(Image *);
MagickBooleanType EOFBlob(const Image *);
void ThrowReaderException(ExceptionType, const char *);
void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
ssize_t SeekBlob(Image *, MagickOffsetType, int);
void *AcquireQuantumMemory(size_t, size_t);
void CopyMagickMemory(void *, const void *, size_t);
ImageInfo *CloneImageInfo(const ImageInfo *);
void CopyMagickString(char *, const char *, size_t);
Image *BlobToImage(ImageInfo *, const void *, size_t, ExceptionInfo *);
ImageInfo *DestroyImageInfo(ImageInfo *);
void *RelinquishMagickMemory(void *);
void DestroyBlob(Image *);
void *ReferenceBlob(void *);
void ReplaceImageInList(Image **, Image *);
MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
Quantum ScaleCharToQuantum(unsigned char);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelIndex(Image *, size_t, Quantum *);
size_t GetPixelChannels(const Image *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, ProgressTag, size_t, size_t);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, AlphaType, Quantum *);
Quantum *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SyncImage(Image *, ExceptionInfo *);
void AcquireNextImage(const ImageInfo *, Image *, ExceptionInfo *);
Image *GetNextImageInList(const Image *);
Image *SyncNextImageInList(Image *);
MagickOffsetType TellBlob(const Image *);
MagickOffsetType GetBlobSize(const Image *);
MagickBooleanType CloseBlob(Image *);
Image *GetFirstImageInList(const Image *);
void LogMagickEvent(EventType, const char *, const char *, ...);
const char *GetMagickModule(void);