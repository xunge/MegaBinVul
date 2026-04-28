#include <assert.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

typedef long ssize_t;
typedef unsigned char Quantum;
typedef unsigned char MagickBooleanType;

#define MagickCoreSignature 0
#define MagickFalse 0
#define MagickTrue 1

typedef struct {
    unsigned long signature;
    char *filename;
    unsigned char debug;
    unsigned long columns;
    unsigned long rows;
    unsigned long colors;
    unsigned long depth;
    unsigned long colorspace;
} Image;

typedef struct {
    unsigned long signature;
} ImageInfo;

typedef struct {
    unsigned long signature;
} ExceptionInfo;

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

typedef struct {
} QuantumInfo;
typedef struct {
} CacheView;

#define TraceEvent 0
#define GetMagickModule() ""
#define WriteBinaryBlobMode 0
#define sRGBColorspace 0
#define SaveImageTag 0
#define ResourceLimitError 0
#define MemoryAllocationFailed ""
#define GrayQuantum 0

#define LogMagickEvent(a,b,c,d) 0
#define OpenBlob(a,b,c,d) 0
#define TransformImageColorspace(a,b,c) 0
#define SetImageMonochrome(a,b) 0
#define ResetMagickMemory(a,b,c) 0
#define CopyMagickString(a,b,c) 0
#define CopyMagickMemory(a,b,c) 0
#define GetImageProperty(a,b,c) NULL
#define WriteBlob(a,b,c) 0
#define WriteBlobMSBShort(a,b) 0
#define WriteBlobMSBLong(a,b) 0
#define WriteBlobByte(a,b) 0
#define AcquireQuantumMemory(a,b) NULL
#define ThrowWriterException(a,b) 0
#define IssRGBCompatibleColorspace(a) 0
#define AcquireQuantumInfo(a,b) NULL
#define GetVirtualPixels(a,b,c,d,e,f) NULL
#define ExportQuantumPixels(a,b,c,d,e,f) 0
#define EncodeRLE(a,b,c,d) NULL
#define SetImageProgress(a,b,c,d) 0
#define RelinquishMagickMemory(a) NULL
#define DestroyQuantumInfo(a) NULL
#define TellBlob(a) 0
#define WriteBlobString(a,b) 0
#define CloseBlob(a) 0