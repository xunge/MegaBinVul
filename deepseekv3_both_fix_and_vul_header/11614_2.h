#include <assert.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef long MagickOffsetType;
typedef ssize_t ssize_t;

typedef struct _ExceptionInfo {
  int severity;
  char *reason;
  /* other members omitted */
} ExceptionInfo;

typedef enum {
  BilevelType,
  sRGBColorspace
} ImageType;

typedef struct _ImageInfo {
  unsigned long signature;
  char *filename;
  /* other members omitted */
} ImageInfo;

typedef struct _Image {
  unsigned long signature;
  unsigned long debug;
  char *filename;
  ExceptionInfo exception;
  unsigned long colors;
  unsigned long columns;
  unsigned long rows;
  unsigned long depth;
  ImageType colorspace;
  /* other members omitted */
} Image;

typedef struct _QuantumInfo {
  /* members omitted */
} QuantumInfo;

typedef struct _CacheView {
  /* members omitted */
} CacheView;

typedef struct _PixelPacket {
  /* members omitted */
} PixelPacket;

typedef struct {
  char name[256];
  unsigned short attributes;
  unsigned short version;
  unsigned int create_time;
  unsigned int modify_time;
  unsigned int archive_time;
  unsigned int modify_number;
  unsigned int application_info;
  unsigned int sort_info;
  char type[4];
  char id[4];
  unsigned int seed;
  unsigned int next_record;
  unsigned short number_records;
} PDBInfo;

typedef struct {
  char name[256];
  unsigned char version;
  unsigned char type;
  unsigned int reserved_1;
  unsigned int note;
  unsigned short x_last;
  unsigned short y_last;
  unsigned int reserved_2;
  unsigned short x_anchor;
  unsigned short y_anchor;
  short width;
  short height;
} PDBImage;

typedef enum {
  GrayQuantum
} QuantumType;

typedef enum {
  ResourceLimitError
} ExceptionType;

typedef enum {
  TraceEvent
} LogEventType;

typedef enum {
  SaveImageTag
} ProgressMonitorTag;

typedef enum {
  WriteBinaryBlobMode
} BlobMode;

#define MagickCoreSignature 0x12345678

const char *GetMagickModule(void);
void *AcquireQuantumMemory(size_t count, size_t size);
void *RelinquishMagickMemory(void *memory);
void LogMagickEvent(LogEventType event, const char *module, const char *format, ...);
void *ResetMagickMemory(void *target, int c, size_t size);
void *CopyMagickString(char *destination, const char *source, size_t length);
const char *GetImageProperty(const Image *image, const char *property);
const PixelPacket *GetVirtualPixels(Image *image, ssize_t x, ssize_t y, size_t columns, size_t rows, ExceptionInfo *exception);
MagickBooleanType OpenBlob(const ImageInfo *image_info, Image *image, BlobMode mode, ExceptionInfo *exception);
MagickBooleanType TransformImageColorspace(Image *image, ImageType colorspace);
MagickBooleanType SetImageProgress(Image *image, ProgressMonitorTag tag, MagickOffsetType offset, size_t span);
MagickBooleanType SetQuantumDepth(Image *image, QuantumInfo *quantum_info, unsigned long depth);
MagickBooleanType ExportQuantumPixels(Image *image, const CacheView *cache_view, QuantumInfo *quantum_info, QuantumType quantum_type, unsigned char *pixels, ExceptionInfo *exception);
MagickBooleanType IssRGBCompatibleColorspace(ImageType colorspace);
MagickBooleanType CloseBlob(Image *image);
ImageType GetImageType(const Image *image, ExceptionInfo *exception);
ssize_t TellBlob(const Image *image);
size_t WriteBlob(Image *image, size_t length, const unsigned char *data);
size_t WriteBlobByte(Image *image, unsigned char value);
size_t WriteBlobMSBShort(Image *image, unsigned short value);
size_t WriteBlobMSBLong(Image *image, unsigned int value);
size_t WriteBlobString(Image *image, const char *string);
unsigned char *EncodeRLE(unsigned char *destination, const unsigned char *source, size_t literal, size_t repeat);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *image_info, const Image *image);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *quantum_info);
void ThrowWriterException(ExceptionType severity, const char *reason);