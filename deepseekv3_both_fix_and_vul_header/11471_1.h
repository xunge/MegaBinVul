#include <stddef.h>

typedef unsigned int MagickBooleanType;
typedef enum { LSBEndian, MSBEndian } EndianType;

typedef struct _BlobInfo {
    void *dummy;
} BlobInfo;

typedef struct _CustomStreamInfo {
    void *dummy;
} CustomStreamInfo;

typedef struct _Image {
    BlobInfo *blob;
    EndianType endian;
    char *filename;
    struct _Image *next;
} Image;

typedef struct _ImageInfo {
    void *dummy;
} ImageInfo;

typedef struct _ExceptionInfo {
    void *dummy;
} ExceptionInfo;

typedef struct _StringInfo {
    size_t length;
    void *dummy;
} StringInfo;

typedef struct {
    size_t offset;
    size_t quantum;
    StringInfo *data;
    size_t extent;
} PhotoshopProfile;

typedef struct {
    void *dummy;
} PSDInfo;

#define MagickFalse 0
#define MagickTrue 1
#define MagickMinBlobExtent 4096
#define ResourceLimitError 1

Image *CloneImage(Image *, size_t, size_t, MagickBooleanType, ExceptionInfo *);
ImageInfo *CloneImageInfo(const ImageInfo *);
void ThrowBinaryException(int, const char *, const char *);
StringInfo *AcquireStringInfo(size_t);
ImageInfo *DestroyImageInfo(ImageInfo *);
StringInfo *DestroyStringInfo(StringInfo *);
CustomStreamInfo *TIFFAcquireCustomStreamForWriting(PhotoshopProfile *, ExceptionInfo *);
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