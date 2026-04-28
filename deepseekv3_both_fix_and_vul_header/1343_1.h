#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef size_t MagickSizeType;
typedef unsigned char Quantum;

struct _Image {
    int storage_class;
    const char *filename;
    int channels;
};

struct _QuantumInfo {
    int depth;
    int format;
    int endian;
    size_t pad;
};

typedef struct _Image Image;
typedef struct _QuantumInfo QuantumInfo;
typedef struct _ExceptionInfo ExceptionInfo;

#define magick_restrict restrict
#define GetMagickModule() NULL
#define ImageError 0
#define PseudoClass 0
#define FloatingPointQuantumFormat 0
#define QuantumScale 1.0

static void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
static unsigned char *PopCharPixel(unsigned char, unsigned char *);
static unsigned char *PopShortPixel(int, unsigned short, unsigned char *);
static unsigned char *PopFloatPixel(QuantumInfo *, float, unsigned char *);
static unsigned char *PopLongPixel(int, unsigned int, unsigned char *);
static unsigned char *PopDoublePixel(QuantumInfo *, double, unsigned char *);
static unsigned char *PopQuantumPixel(QuantumInfo *, unsigned int, unsigned char *);
static unsigned int GetPixelIndex(const Image *, const Quantum *);
static int GetPixelChannels(const Image *);
static float SinglePrecisionToHalf(float);