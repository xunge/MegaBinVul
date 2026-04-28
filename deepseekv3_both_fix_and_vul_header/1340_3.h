#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define magick_restrict __restrict
#define ImageError 1

typedef unsigned char Quantum;
typedef unsigned long MagickSizeType;
typedef unsigned char IndexPacket;
typedef void* ExceptionInfo;
typedef long ssize_t;
typedef Quantum QuantumAny;

typedef struct _PixelPacket {
    Quantum opacity;
    Quantum alpha;
} PixelPacket;

typedef struct _QuantumInfo {
    size_t depth;
    int format;
    size_t pad;
    int endian;
} QuantumInfo;

typedef struct _Image {
    int storage_class;
    char *filename;
} Image;

#define PseudoClass 0
#define FloatingPointQuantumFormat 1
#define QuantumRange 255
#define TransparentOpacity 0
#define QuantumScale (1.0/QuantumRange)

static void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
static const char *GetMagickModule(void);
static Quantum GetPixelOpacity(const PixelPacket *);
static Quantum GetPixelAlpha(const PixelPacket *);
static unsigned char GetPixelIndex(const IndexPacket *);
static unsigned char *PopCharPixel(unsigned char, unsigned char *);
static unsigned char *PopShortPixel(int, unsigned short, unsigned char *);
static unsigned char *PopLongPixel(int, unsigned int, unsigned char *);
static unsigned char *PopFloatPixel(QuantumInfo *, float, unsigned char *);
static unsigned char *PopDoublePixel(QuantumInfo *, double, unsigned char *);
static unsigned char *PopQuantumPixel(QuantumInfo *, Quantum, unsigned char *);
static unsigned short SinglePrecisionToHalf(float);
static unsigned char ScaleQuantumToChar(Quantum);
static unsigned short ScaleQuantumToShort(Quantum);
static unsigned int ScaleQuantumToLong(Quantum);
static Quantum ScaleQuantumToAny(Quantum, Quantum);
static Quantum GetQuantumRange(size_t);