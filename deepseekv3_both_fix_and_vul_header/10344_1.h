#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _PDBImage PDBImage;
typedef struct _PDBInfo PDBInfo;
typedef unsigned char Quantum;
typedef int MagickBooleanType;
typedef long ssize_t;
typedef unsigned long size_t;
typedef long MagickOffsetType;

enum {
    MagickCoreSignature = 0xABACADAB,
    MagickFalse = 0,
    MagickTrue = 1,
    TraceEvent = 0,
    CorruptImageError = 0,
    CoderError = 0,
    ResourceLimitError = 0,
    NoCompression = 0,
    RLECompression = 1,
    PseudoClass = 0,
    ReadBinaryBlobMode = 0,
    LoadImageTag = 0,
    MagickPathExtent = 4096
};

struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    int storage_class;
    int compression;
    char *filename;
    void (*DestroyImageList)(Image*);
    void (*SyncImage)(Image*, ExceptionInfo*);
    void (*SetImageProperty)(Image*, const char*, const char*, ExceptionInfo*);
};

struct _ImageInfo {
    unsigned signature;
    int debug;
    const char *filename;
    int ping;
};

struct _ExceptionInfo {
    unsigned signature;
};

struct _PDBImage {
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
};

struct _PDBInfo {
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
};

static Image *DestroyImageList(Image*);
static Image *AcquireImage(const ImageInfo*, ExceptionInfo*);
static MagickBooleanType OpenBlob(const ImageInfo*, Image*, int, ExceptionInfo*);
static void LogMagickEvent(int, const char*, const char*, ...);
static const char *GetMagickModule(void);
static ssize_t ReadBlob(Image*, size_t, unsigned char*);
static short ReadBlobMSBShort(Image*);
static unsigned long ReadBlobMSBLong(Image*);
static unsigned char ReadBlobByte(Image*);
static ssize_t TellBlob(Image*);
static void ThrowReaderException(int, const char*);
static void ThrowFileException(ExceptionInfo*, int, const char*, const char*);
static MagickBooleanType SetImageExtent(Image*, size_t, size_t, ExceptionInfo*);
static MagickBooleanType AcquireImageColormap(Image*, size_t, ExceptionInfo*);
static Image *GetFirstImageInList(Image*);
static void CloseBlob(Image*);
static void *AcquireQuantumMemory(size_t, size_t);
static MagickBooleanType DecodeImage(Image*, unsigned char*, size_t);
static Quantum *QueueAuthenticPixels(Image*, ssize_t, ssize_t, size_t, size_t, ExceptionInfo*);
static MagickBooleanType SyncAuthenticPixels(Image*, ExceptionInfo*);
static MagickBooleanType SetImageProgress(Image*, int, MagickOffsetType, size_t);
static Quantum ConstrainColormapIndex(Image*, unsigned long, ExceptionInfo*);
static void SetPixelIndex(Image*, Quantum, Quantum*);
static size_t GetPixelChannels(Image*);
static void *RelinquishMagickMemory(void*);
static int EOFBlob(Image*);
static char *AcquireString(const char*);
static char *ResizeQuantumMemory(char*, size_t, size_t);
static char *DestroyString(char*);
static void SyncImage(Image*, ExceptionInfo*);
static void SetImageProperty(Image*, const char*, const char*, ExceptionInfo*);