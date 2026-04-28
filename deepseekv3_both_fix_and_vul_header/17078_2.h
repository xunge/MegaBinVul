#include <assert.h>
#include <string.h>

#define MaxTextExtent 4096
#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct _ExceptionInfo ExceptionInfo;

typedef enum {
  DirectClass
} ClassType;

typedef enum {
  NoCompression
} CompressionType;

typedef enum {
  WriteBinaryBlobMode
} BlobMode;

typedef enum {
  TraceEvent
} LogEventType;

typedef struct _ImageInfo {
  unsigned long signature;
  char *filename;
  char *magick;
  int compression;
} ImageInfo;

typedef struct _Image {
  unsigned long signature;
  MagickBooleanType debug;
  char *filename;
  ExceptionInfo *exception;
  ClassType storage_class;
  unsigned long colors;
} Image;

typedef struct _QuantizeInfo {
  MagickBooleanType dither;
} QuantizeInfo;

typedef struct {
  unsigned long magick;
  unsigned char *postscript;
  size_t postscript_length;
  unsigned char *tiff;
  size_t tiff_length;
} EPTInfo;

extern void *RelinquishMagickMemory(void *);
extern MagickBooleanType OpenBlob(const ImageInfo *,Image *,BlobMode,ExceptionInfo *);
extern Image *CloneImage(const Image *,size_t,size_t,MagickBooleanType,ExceptionInfo *);
extern ImageInfo *CloneImageInfo(const ImageInfo *);
extern void CopyMagickString(char *,const char *,const size_t);
extern int LocaleCompare(const char *,const char *);
extern void *ImageToBlob(const ImageInfo *,Image *,size_t *,ExceptionInfo *);
extern Image *DestroyImage(Image *);
extern ImageInfo *DestroyImageInfo(ImageInfo *);
extern void GetQuantizeInfo(QuantizeInfo *);
extern MagickBooleanType IsPaletteImage(const Image *,ExceptionInfo *);
extern MagickBooleanType QuantizeImage(const QuantizeInfo *,Image *);
extern void TransformImage(Image **,char *,const char *);
extern void FormatLocaleString(char *,const size_t,const char *,...);
extern void WriteBlobLSBLong(Image *,unsigned int);
extern void WriteBlobLSBShort(Image *,unsigned short);
extern void WriteBlob(Image *,const size_t,const void *);
extern MagickBooleanType CloseBlob(Image *);
extern void LogMagickEvent(LogEventType,const char *,const char *,...);
extern const char *GetMagickModule(void);