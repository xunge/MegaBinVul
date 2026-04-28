#include <stddef.h>
#include <stdint.h>

typedef unsigned char QuantumAny;
typedef size_t MagickSizeType;
typedef ptrdiff_t ssize_t;

typedef enum {
    FloatingPointQuantumFormat
} QuantumFormatType;

typedef enum {
    UndefinedEndian,
    LSBEndian,
    MSBEndian
} EndianType;

typedef struct {
    unsigned char depth;
    unsigned char pad;
    QuantumFormatType format;
    EndianType endian;
} QuantumInfo;

typedef struct {
    unsigned char red;
} PixelPacket;

#define magick_restrict restrict

unsigned char ScaleQuantumToChar(QuantumAny);
unsigned short ScaleQuantumToShort(QuantumAny);
unsigned int ScaleQuantumToLong(QuantumAny);
QuantumAny ScaleQuantumToAny(QuantumAny, QuantumAny);
QuantumAny GetQuantumRange(unsigned char);
QuantumAny GetPixelRed(const PixelPacket *);
unsigned char *PopCharPixel(unsigned char, unsigned char *);
unsigned char *PopShortPixel(EndianType, unsigned short, unsigned char *);
unsigned char *PopLongPixel(EndianType, unsigned int, unsigned char *);
unsigned char *PopFloatPixel(QuantumInfo *, float, unsigned char *);
unsigned char *PopDoublePixel(QuantumInfo *, double, unsigned char *);
unsigned char *PopQuantumPixel(QuantumInfo *, QuantumAny, unsigned char *);
unsigned short SinglePrecisionToHalf(float);
#define QuantumScale 1.0