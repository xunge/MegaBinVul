#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char MagickBooleanType;
typedef unsigned char Quantum;
typedef unsigned short QuantumType;
typedef long ssize_t;
typedef unsigned long size_t;
typedef unsigned short ushort;
typedef unsigned int uint;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL

typedef struct _ImageInfo {
    unsigned long signature;
    char *filename;
    // Other members omitted
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    unsigned long debug;
    char *filename;
    unsigned long colors;
    unsigned long depth;
    unsigned long columns;
    unsigned long rows;
    // Other members omitted
    struct _ExceptionInfo *exception;
} Image;

typedef struct _ExceptionInfo {
    // Members omitted
} ExceptionInfo;

typedef struct _QuantumInfo {
    // Members omitted
} QuantumInfo;

typedef struct _CacheView {
    // Members omitted
} CacheView;

typedef struct _PixelPacket {
    // Members omitted
} PixelPacket;

typedef struct _PDBInfo {
    char name[256];
    unsigned short attributes;
    unsigned short version;
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
    unsigned short number_records;
} PDBInfo;

typedef struct _PDBImage {
    char name[256];
    unsigned char version;
    unsigned char type;
    unsigned long reserved_1;
    unsigned long note;
    unsigned short x_last;
    unsigned short y_last;
    unsigned long reserved_2;
    unsigned short x_anchor;
    unsigned short y_anchor;
    short width;
    short height;
} PDBImage;

enum {
    BilevelType,
    sRGBColorspace,
    GrayQuantum,
    SaveImageTag,
    TraceEvent,
    WriteBinaryBlobMode,
    ResourceLimitError
};

#define GetMagickModule() ""
#define LogMagickEvent(a,b,c,d) 0
#define OpenBlob(a,b,c,d) 0
#define TransformImageColorspace(a,b) 0
#define GetImageType(a,b) 0
#define ResetMagickMemory(a,b,c) memset(a,b,c)
#define CopyMagickString(a,b,c) strncpy(a,b,c)
#define CopyMagickMemory(a,b,c) memcpy(a,b,c)
#define WriteBlob(a,b,c) 0
#define WriteBlobMSBShort(a,b) 0
#define WriteBlobMSBLong(a,b) 0
#define WriteBlobByte(a,b) 0
#define WriteBlobString(a,b) 0
#define GetImageProperty(a,b) NULL
#define AcquireQuantumMemory(a,b) malloc((a)*(b))
#define AcquireQuantumInfo(a,b) ((QuantumInfo*)malloc(sizeof(QuantumInfo)))
#define ThrowWriterException(a,b) return MagickFalse
#define IssRGBCompatibleColorspace(a) MagickTrue
#define GetVirtualPixels(a,b,c,d,e,f) NULL
#define ExportQuantumPixels(a,b,c,d,e,f) 0
#define EncodeRLE(a,b,c,d) (a)
#define SetImageProgress(a,b,c,d) MagickTrue
#define RelinquishMagickMemory(a) (free(a), NULL)
#define DestroyQuantumInfo(a) (free(a), NULL)
#define TellBlob(a) 0
#define CloseBlob(a) 0