#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned int Quantum;
typedef int MagickBooleanType;
typedef long long MagickOffsetType;

#define MagickCoreSignature 0xABACADABUL
#define MagickFalse 0
#define QuantumRange ((Quantum) 65535)
#define MaxTextExtent 4096
#define CorruptImageError 410
#define ResourceLimitError 430
#define TraceEvent 0
#define PseudoClass 1
#define ReadBinaryBlobMode 0

typedef struct _ExceptionInfo {
    unsigned long signature;
    char *reason;
    char *description;
} ExceptionInfo;

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
} PixelPacket;

typedef struct _Image {
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    size_t colors;
    int storage_class;
    PixelPacket *colormap;
    ExceptionInfo exception;
    char *filename;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    MagickBooleanType ping;
    char filename[MaxTextExtent];
    FILE *file;
} ImageInfo;

typedef struct {
    unsigned short Width;
    unsigned short Height;
    unsigned short Reserved;
} CUTHeader;

typedef struct {
    char FileId[2];
    unsigned short Version;
    unsigned short Size;
    char FileType;
    char SubType;
    unsigned short BoardID;
    unsigned short GraphicsMode;
    unsigned short MaxIndex;
    unsigned short MaxRed;
    unsigned short MaxGreen;
    unsigned short MaxBlue;
    char PaletteId[20];
} CUTPalHeader;

static void LogMagickEvent(int event, const char *module, const char *format, ...);
static const char *GetMagickModule(void);
static void ThrowReaderException(int severity, const char *tag);
static unsigned long GetQuantumRange(unsigned long);