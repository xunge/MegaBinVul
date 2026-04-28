#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef unsigned char Quantum;
typedef unsigned long QuantumAny;
typedef size_t MagickSizeType;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { LSBEndian, MSBEndian } EndianType;
typedef enum { UndefinedQuantumFormat, FloatingPointQuantumFormat } QuantumFormat;

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _QuantumInfo {
    unsigned int depth;
    MagickBooleanType min_is_white;
    MagickBooleanType pack;
    EndianType endian;
    unsigned int pad;
    QuantumFormat format;
} QuantumInfo;

typedef struct _Image {
    unsigned long signature;
    EndianType endian;
} Image;

#define MagickCoreSignature 0x12345678
#define QuantumRange ((Quantum) ~0)
#define OpaqueAlpha QuantumRange

static QuantumAny GetQuantumRange(unsigned int depth);
static void SetPixelGray(const Image *image, Quantum value, Quantum *pixel);
static void SetPixelAlpha(const Image *image, Quantum value, Quantum *pixel);
static unsigned int GetPixelChannels(const Image *image);
static unsigned char *PushCharPixel(const unsigned char *p, unsigned char *pixel);
static unsigned char *PushShortPixel(EndianType endian, const unsigned char *p, unsigned short *pixel);
static unsigned char *PushLongPixel(EndianType endian, const unsigned char *p, unsigned int *pixel);
static unsigned char *PushFloatPixel(const QuantumInfo *quantum_info, const unsigned char *p, float *pixel);
static unsigned char *PushDoublePixel(const QuantumInfo *quantum_info, const unsigned char *p, double *pixel);
static unsigned char *PushQuantumPixel(const QuantumInfo *quantum_info, const unsigned char *p, unsigned int *pixel);
static Quantum ScaleCharToQuantum(unsigned char value);
static Quantum ScaleShortToQuantum(unsigned short value);
static Quantum ScaleLongToQuantum(unsigned int value);
static Quantum ScaleAnyToQuantum(QuantumAny value, QuantumAny range);
static float HalfToSinglePrecision(unsigned short value);
static Quantum ClampToQuantum(double value);

#define magick_restrict