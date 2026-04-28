#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long MagickOffsetType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    NoCompression,
    RLECompression
} CompressionType;

typedef enum {
    PseudoClass,
    DirectClass
} ClassType;

typedef enum {
    TraceEvent
} EventType;

typedef enum {
    CorruptImageError,
    CoderError,
    ResourceLimitError
} ErrorType;

typedef unsigned long Quantum;

typedef struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    ClassType storage_class;
    CompressionType compression;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    MagickBooleanType ping;
    const char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _PDBImage {
    char name[32];
    unsigned char version;
    unsigned char type;
    unsigned long reserved_1;
    unsigned long note;
    short x_last;
    short y_last;
    unsigned long reserved_2;
    short x_anchor;
    short y_anchor;
    short width;
    short height;
} PDBImage;

typedef struct _PDBInfo {
    char name[32];
    short attributes;
    short version;
    unsigned long create_time;
    unsigned long modify_time;
    unsigned long archive_time;
    unsigned long modify_number;
    unsigned long application_info;
    unsigned long sort_info;
    char type[4];
    char id[4];
    unsigned long seed;
    unsigned long next_record;
    short number_records;
} PDBInfo;

typedef struct _ModuleInfo {
    const char *name;
} ModuleInfo;

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096
#define ReadBinaryBlobMode 0
#define LoadImageTag "LoadImage"

extern ModuleInfo *GetMagickModule(void);
extern void LogMagickEvent(EventType, ModuleInfo *, const char *, ...);
extern Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
extern MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
extern Image *DestroyImageList(Image *);
extern ssize_t ReadBlob(Image *, size_t, unsigned char *);
extern short ReadBlobMSBShort(Image *);
extern unsigned long ReadBlobMSBLong(Image *);
extern int ReadBlobByte(Image *);
extern long ReadBlobMSBSignedLong(Image *);
extern long TellBlob(Image *);
extern MagickBooleanType AcquireImageColormap(Image *, size_t, ExceptionInfo *);
extern Image *GetFirstImageInList(Image *);
extern MagickBooleanType CloseBlob(Image *);
extern MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void *RelinquishMagickMemory(void *);
extern Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
extern MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
extern MagickBooleanType SetImageProgress(Image *, const char *, MagickOffsetType, size_t);
extern MagickBooleanType SyncImage(Image *, ExceptionInfo *);
extern Quantum ConstrainColormapIndex(Image *, unsigned long, ExceptionInfo *);
extern size_t GetPixelChannels(const Image *);
extern void SetPixelIndex(Image *, Quantum, Quantum *);
extern MagickBooleanType EOFBlob(const Image *);
extern void ThrowFileException(ExceptionInfo *, ErrorType, const char *, const char *);
extern void ThrowReaderException(ErrorType, const char *);
extern char *AcquireString(const char *);
extern char *ResizeQuantumMemory(char *, size_t, size_t);
extern char *DestroyString(char *);
extern MagickBooleanType SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
extern MagickBooleanType DecodeImage(Image *, unsigned char *, size_t);