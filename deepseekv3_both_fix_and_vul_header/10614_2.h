#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef int MagickBooleanType;
typedef long MagickOffsetType;

typedef struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    unsigned storage_class;
    unsigned compression;
    void *exception;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
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

typedef unsigned long IndexPacket;
typedef unsigned char PixelPacket;

enum {
    MagickFalse,
    MagickTrue
};

enum {
    NoCompression,
    RLECompression
};

enum {
    PseudoClass,
    DirectClass
};

enum {
    TraceEvent,
    LoadImageTag
};

enum {
    CorruptImageError,
    CoderError,
    ResourceLimitError
};

#define MagickSignature 0xabacadabUL
#define MaxTextExtent 2048
#define ReadBinaryBlobMode 0

/* Function prototypes */
Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
void ThrowReaderException(int, const char *);
short ReadBlobMSBShort(Image *);
unsigned long ReadBlobMSBLong(Image *);
long ReadBlobMSBSignedLong(Image *);
int ReadBlobByte(Image *);
long TellBlob(Image *);
MagickBooleanType AcquireImageColormap(Image *, size_t);
void CloseBlob(Image *);
Image *GetFirstImageInList(Image *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
void InheritException(ExceptionInfo *, void **);
unsigned char *AcquireQuantumMemory(size_t, size_t);
MagickBooleanType DecodeImage(Image *, unsigned char *, size_t);
PixelPacket *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
IndexPacket *GetAuthenticIndexQueue(Image *);
void SetPixelIndex(IndexPacket *, IndexPacket);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
void SyncImage(Image *);
IndexPacket ConstrainColormapIndex(Image *, unsigned long);
unsigned char *RelinquishMagickMemory(void *);
MagickBooleanType EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
char *AcquireString(const char *);
char *ResizeQuantumMemory(char *, size_t, size_t);
MagickBooleanType SetImageProperty(Image *, const char *, const char *);
char *DestroyString(char *);