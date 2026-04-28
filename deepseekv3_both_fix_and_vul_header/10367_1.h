#include <assert.h>
#include <stddef.h>

#define MagickExport
typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickCoreSignature 0
#define MagickMax(a, b) ((a) > (b) ? (a) : (b))

typedef enum {
    FloatingPointQuantumFormat
} QuantumFormat;

typedef struct _Image {
    size_t signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
} Image;

typedef struct _QuantumInfo {
    size_t signature;
    size_t depth;
    QuantumFormat format;
    size_t pad;
    unsigned char **pixels;
} QuantumInfo;

void DestroyQuantumPixels(QuantumInfo *);
MagickBooleanType AcquireQuantumPixels(QuantumInfo *, size_t);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
#define TraceEvent 0