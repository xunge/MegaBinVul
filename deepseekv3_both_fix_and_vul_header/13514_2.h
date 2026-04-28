#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MagickExport
#define magick_restrict restrict

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  ReadBlobMode,
  ReadBinaryBlobMode,
  WriteBlobMode,
  WriteBinaryBlobMode,
  AppendBlobMode,
  AppendBinaryBlobMode
} BlobMode;

typedef enum {
  UndefinedStream,
  FileStream,
  StandardStream,
  PipeStream,
  FifoStream,
  CustomStream,
  ZipStream,
  BZipStream
} StreamType;

typedef enum {
  ReadPolicyRights,
  WritePolicyRights
} PolicyRights;

typedef enum {
  TraceEvent,
  BlobEvent
} EventType;

typedef enum {
  PolicyError,
  BlobError
} ErrorType;

typedef enum {
  PathPolicyDomain
} PolicyDomain;

typedef enum {
  ExtensionPath,
  RootPath
} PathType;

typedef enum {
  ReadMode,
  WriteMode
} MapMode;

typedef struct _BlobInfo BlobInfo;
typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _CustomStreamInfo CustomStreamInfo;
typedef struct _MagickInfo MagickInfo;
typedef void (*StreamHandler)(void);

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096
#define MagickMaxBufferExtent 0x7fffffff
#define MapResource "MapResource"

struct _BlobInfo {
  StreamType type;
  MagickBooleanType exempt;
  MagickBooleanType status;
  int error_number;
  off_t size;
  StreamHandler stream;
  CustomStreamInfo *custom_stream;
  union {
    FILE *file;
    void *gzfile;
    void *bzfile;
  } file_info;
  struct stat properties;
  MagickBooleanType synchronize;
  BlobMode mode;
  MagickBooleanType mapped;
};

struct _ImageInfo {
  unsigned long signature;
  char *filename;
  void *blob;
  size_t length;
  StreamHandler stream;
  CustomStreamInfo *custom_stream;
  FILE *file;
  MagickBooleanType synchronize;
  MagickBooleanType adjoin;
  char *magick;
};

struct _Image {
  unsigned long signature;
  char filename[1];
  BlobInfo *blob;
  Image *previous;
  Image *next;
  size_t scene;
};

extern const char *GetMagickModule(void);
extern MagickBooleanType IsEventLogging(void);
extern void *LogMagickEvent(EventType,const char *,const char *,...);
extern void AttachBlob(BlobInfo *,const void *,const size_t);
extern void DetachBlob(BlobInfo *);
extern int LocaleCompare(const char *,const char *);
extern int LocaleNCompare(const char *,const char *,const size_t);
extern char *CopyMagickString(char *,const char *,const size_t);
extern MagickBooleanType IsRightsAuthorized(PolicyDomain,PolicyRights,const char *);
extern void *ThrowMagickException(ExceptionInfo *,const char *,ErrorType,const char *,const char *,...);
extern void *ThrowFileException(ExceptionInfo *,ErrorType,const char *,const char *);
extern MagickBooleanType GetPathAttributes(const char *,struct stat *);
extern void GetPathComponent(const char *,PathType,char *);
extern char *InterpretImageFilename(const ImageInfo *,Image *,const char *,int,char *,ExceptionInfo *);
extern char *FormatLocaleString(char *,const size_t,const char *,...);
extern off_t GetBlobSize(const Image *);
extern MagickBooleanType SetStreamBuffering(const ImageInfo *,BlobInfo *);
extern MagickBooleanType IsGeometry(const char *);
extern long StringToLong(const char *);
extern char *SanitizeString(const char *);
extern void *DestroyString(char *);
extern FILE *fopen_utf8(const char *,const char *);
extern FILE *fdopen(int,const char *);
extern FILE *popen_utf8(const char *,const char *);
extern int setmode(int,int);
extern void *AcquireExceptionInfo(void);
extern void *DestroyExceptionInfo(ExceptionInfo *);
extern const MagickInfo *GetMagickInfo(const char *,ExceptionInfo *);
extern MagickBooleanType GetMagickBlobSupport(const MagickInfo *);
extern MagickBooleanType AcquireMagickResource(const char *,const size_t);
extern void RelinquishMagickResource(const char *,const size_t);
extern void *MapBlob(int,MapMode,const off_t,const size_t);
extern Image *GetPreviousImageInList(const Image *);
extern Image *GetNextImageInList(const Image *);