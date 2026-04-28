#include <assert.h>
#include <stddef.h>

#define MagickExport

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { FloatingPointQuantumFormat } QuantumFormat;
typedef unsigned char Quantum;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
} Image;

typedef struct _QuantumInfo {
    unsigned long signature;
    size_t depth;
    QuantumFormat format;
    unsigned char **pixels;
    size_t pad;
} QuantumInfo;

MagickBooleanType LogMagickEvent(int, const char *, const char *, ...);
void DestroyQuantumPixels(QuantumInfo *);
MagickBooleanType AcquireQuantumPixels(QuantumInfo *, size_t);

#define MagickSignature 0xabacadabUL
#define TraceEvent 0
#define GetMagickModule() ""