#include <stddef.h>
#include <sys/types.h>

typedef struct _Image {
    int storage_class;
    const char *filename;
} Image;

typedef struct _QuantumInfo {
    unsigned int depth;
    int format;
    int endian;
    size_t pad;
} QuantumInfo;

typedef struct _PixelPacket {
    unsigned char r, g, b, a;
} PixelPacket;

typedef unsigned long IndexPacket;

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
    char *description;
} ExceptionInfo;

typedef unsigned long long MagickSizeType;

#define PseudoClass 1
#define ImageError 1
#define FloatingPointQuantumFormat 1
#define QuantumScale 1.0

#define magick_restrict restrict

void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
const char *GetMagickModule(void);

unsigned char *PopCharPixel(unsigned char, unsigned char *);
unsigned char *PopShortPixel(int, unsigned short, unsigned char *);
unsigned char *PopFloatPixel(QuantumInfo *, float, unsigned char *);
unsigned char *PopLongPixel(int, unsigned int, unsigned char *);
unsigned char *PopDoublePixel(QuantumInfo *, double, unsigned char *);
unsigned char *PopQuantumPixel(QuantumInfo *, unsigned long, unsigned char *);
unsigned short SinglePrecisionToHalf(float);
unsigned long GetPixelIndex(const IndexPacket *);