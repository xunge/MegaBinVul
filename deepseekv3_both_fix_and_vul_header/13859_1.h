#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define MagickExport
#define MagickCoreSignature 0x12345678

typedef enum {
  UndefinedStream,
  StandardStream,
  FileStream,
  PipeStream,
  ZipStream,
  BZipStream,
  FifoStream,
  BlobStream,
  CustomStream
} StreamType;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef long long MagickOffsetType;

typedef struct _BlobInfo BlobInfo;
typedef struct _Image Image;

typedef struct {
  FILE *file;
  void *gzfile;
  void *bzfile;
} FileInfo;

typedef struct {
  ssize_t (*writer)(const unsigned char *, size_t, void *);
  void *data;
} CustomStreamInfo;

struct _BlobInfo {
  unsigned int signature;
  StreamType type;
  FileInfo file_info;
  MagickBooleanType mapped;
  size_t extent;
  size_t quantum;
  size_t length;
  unsigned char *data;
  MagickOffsetType offset;
  ssize_t (*stream)(Image *, const void *, size_t);
  CustomStreamInfo *custom_stream;
};

struct _Image {
  unsigned int signature;
  BlobInfo *blob;
};