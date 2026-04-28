#include <stddef.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct _BlobInfo BlobInfo;
typedef struct _CustomStreamInfo CustomStreamInfo;
typedef struct _StringInfo StringInfo;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _Image {
  struct _Image *next;
  BlobInfo *blob;
  char *filename;
  int endian;
} Image;

typedef struct _StringInfo {
  size_t length;
  unsigned char *datum;
} StringInfo;

typedef struct {
  size_t offset;
  size_t quantum;
  size_t extent;
  StringInfo *data;
} PhotoshopProfile;

typedef struct {
  int unused;
} PSDInfo;

#define MagickMinBlobExtent 0
#define HOST_FILLORDER 0
#define FILLORDER_LSB2MSB 0

enum {
  UndefinedEndian,
  LSBEndian,
  MSBEndian
};

#define ThrowBinaryException(a,b,c) return(MagickFalse)

ImageInfo *CloneImageInfo(const ImageInfo *);
StringInfo *AcquireStringInfo(size_t);
ImageInfo *DestroyImageInfo(ImageInfo *);
CustomStreamInfo *TIFFAcquireCustomStreamForWriting(PhotoshopProfile *, ExceptionInfo *);
StringInfo *DestroyStringInfo(StringInfo *);
CustomStreamInfo *DestroyCustomStreamInfo(CustomStreamInfo *);
BlobInfo *CloneBlobInfo(BlobInfo *);
void DestroyBlob(Image *);
Image *SyncNextImageInList(Image *);
void AttachCustomStream(BlobInfo *, CustomStreamInfo *);
void InitPSDInfo(Image *, PSDInfo *);
void WriteBlobString(Image *, const char *);
void WriteBlobByte(Image *, unsigned char);
MagickBooleanType WritePSDLayers(Image *, ImageInfo *, PSDInfo *, ExceptionInfo *);
void SetStringInfoLength(StringInfo *, size_t);
MagickBooleanType SetImageProfile(Image *, const char *, StringInfo *, ExceptionInfo *);
void CloseBlob(Image *);