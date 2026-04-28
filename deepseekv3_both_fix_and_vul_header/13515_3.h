#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MagickExport
#define magick_restrict

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum
{
  ReadBlobMode,
  ReadBinaryBlobMode,
  WriteBlobMode,
  WriteBinaryBlobMode,
  AppendBlobMode,
  AppendBinaryBlobMode
} BlobMode;

typedef enum
{
  ReadPolicyRights,
  WritePolicyRights
} PolicyRights;

typedef enum
{
  UndefinedStream,
  FileStream,
  StandardStream,
  PipeStream,
  ZipStream,
  BZipStream,
  CustomStream,
  FifoStream
} StreamType;

typedef void (*StreamHandler)(void);

typedef struct _CustomStreamInfo
{
  int dummy;
} CustomStreamInfo;

typedef struct _FileInfo
{
  FILE *file;
  void *gzfile;
  void *bzfile;
} FileInfo;

typedef struct _BlobInfo
{
  StreamType type;
  StreamHandler stream;
  CustomStreamInfo *custom_stream;
  FileInfo file_info;
  MagickBooleanType exempt;
  MagickBooleanType synchronize;
  MagickBooleanType status;
  MagickBooleanType mapped;
  int error_number;
  size_t size;
  struct stat properties;
  BlobMode mode;
} BlobInfo;

typedef struct _ImageInfo
{
  unsigned long signature;
  void *blob;
  StreamHandler stream;
  size_t length;
  CustomStreamInfo *custom_stream;
  char *filename;
  FILE *file;
  MagickBooleanType synchronize;
  MagickBooleanType adjoin;
  char *magick;
} ImageInfo;

typedef struct _Image
{
  unsigned long signature;
  BlobInfo *blob;
  char *filename;
  size_t scene;
  struct _Image *previous;
  struct _Image *next;
} Image;

typedef struct _ExceptionInfo
{
  int dummy;
} ExceptionInfo;

typedef struct _MagickInfo
{
  MagickBooleanType blob_support;
} MagickInfo;

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096
#define MagickMaxBufferExtent 0x7fffffff
#define MapResource "MapResource"
#define ReadMode 0

#define PathPolicyDomain "Path"
#define BlobError 400
#define PolicyError 400

#define ExtensionPath 1
#define RootPath 2

#define TraceEvent 0
#define BlobEvent 0

extern MagickBooleanType IsEventLogging(void);
extern void *LogMagickEvent(int, const char *, const char *, ...);
extern const char *GetMagickModule(void);
extern void AttachBlob(BlobInfo *, const void *, const size_t);
extern void DetachBlob(BlobInfo *);
extern MagickBooleanType CopyMagickString(char *, const char *, const size_t);
extern MagickBooleanType IsRightsAuthorized(const char *, PolicyRights, const char *);
extern void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
extern MagickBooleanType LocaleCompare(const char *, const char *);
extern MagickBooleanType LocaleNCompare(const char *, const char *, const size_t);
extern MagickBooleanType IsGeometry(const char *);
extern long StringToLong(const char *);
extern void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
extern char *SanitizeString(const char *);
extern char *DestroyString(char *);
extern MagickBooleanType GetPathAttributes(const char *, struct stat *);
extern void GetPathComponent(const char *, int, char *);
extern MagickBooleanType InterpretImageFilename(const ImageInfo *, Image *, const char *, int, char *, ExceptionInfo *);
extern Image *GetPreviousImageInList(const Image *);
extern Image *GetNextImageInList(const Image *);
extern char *FormatLocaleString(char *, const size_t, const char *, ...);
extern MagickBooleanType SetStreamBuffering(const ImageInfo *, BlobInfo *);
extern size_t GetBlobSize(const Image *);
extern void *MapBlob(int, int, off_t, size_t);
extern MagickBooleanType AcquireMagickResource(const char *, const size_t);
extern void RelinquishMagickResource(const char *, const size_t);
extern const MagickInfo *GetMagickInfo(const char *, ExceptionInfo *);
extern MagickBooleanType GetMagickBlobSupport(const MagickInfo *);
extern ExceptionInfo *AcquireExceptionInfo(void);
extern ExceptionInfo *DestroyExceptionInfo(ExceptionInfo *);
extern FILE *fopen_utf8(const char *, const char *);
extern FILE *popen_utf8(const char *, const char *);
extern int setmode(int, int);
extern int fileno(FILE *);