#include <stddef.h>
#include <stdint.h>

typedef unsigned char QuantumAny;
typedef size_t MagickSizeType;
typedef uint32_t Quantum;
typedef ptrdiff_t ssize_t;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { UndefinedQuantumFormat, FloatingPointQuantumFormat } QuantumFormat;

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
} PixelPacket;

typedef struct _QuantumInfo {
    size_t depth;
    size_t pad;
    MagickBooleanType pack;
    unsigned long quantum;
    QuantumFormat format;
    MagickBooleanType endian;
} QuantumInfo;

#define magick_restrict restrict
#define ScaleQuantumToChar(x) ((unsigned char)(x))
#define ScaleQuantumToShort(x) ((unsigned short)(x))
#define ScaleQuantumToLong(x) ((unsigned int)(x))
#define ScaleQuantumToAny(x, range) ((QuantumAny)(x))
#define GetQuantumRange(depth) ((QuantumAny)((1UL << depth) - 1))
#define QuantumScale (1.0)
#define SinglePrecisionToHalf(x) ((unsigned short)(x))

static unsigned char *PopCharPixel(unsigned char pixel, unsigned char *q);
static unsigned char *PopShortPixel(MagickBooleanType endian, unsigned short pixel, unsigned char *q);
static unsigned char *PopLongPixel(MagickBooleanType endian, unsigned int pixel, unsigned char *q);
static unsigned char *PopFloatPixel(QuantumInfo *quantum_info, float pixel, unsigned char *q);
static unsigned char *PopDoublePixel(QuantumInfo *quantum_info, double pixel, unsigned char *q);
static unsigned char *PopQuantumPixel(QuantumInfo *quantum_info, QuantumAny pixel, unsigned char *q);
static unsigned char *PopQuantumLongPixel(QuantumInfo *quantum_info, unsigned int pixel, unsigned char *q);

static Quantum GetPixelRed(const PixelPacket *p);
static Quantum GetPixelGreen(const PixelPacket *p);
static Quantum GetPixelBlue(const PixelPacket *p);