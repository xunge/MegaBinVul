#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

#define magick_restrict restrict

typedef unsigned char Quantum;
typedef unsigned long QuantumAny;
typedef size_t MagickSizeType;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { MagickCoreSignature } SignatureType;
typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _QuantumInfo {
    unsigned int depth;
    MagickBooleanType pack;
    MagickBooleanType endian;
    size_t pad;
} QuantumInfo;

typedef struct _Image {
    SignatureType signature;
} Image;

static Quantum ScaleShortToQuantum(unsigned short value);
static Quantum ScaleAnyToQuantum(unsigned int value, QuantumAny range);
static const unsigned char *PushLongPixel(MagickBooleanType endian, const unsigned char *p, unsigned int *pixel);
static const unsigned char *PushQuantumPixel(const QuantumInfo *quantum_info, const unsigned char *p, unsigned int *pixel);
static void SetPixelRed(const Image *image, Quantum red, Quantum *pixel);
static void SetPixelGreen(const Image *image, Quantum green, Quantum *pixel);
static void SetPixelBlue(const Image *image, Quantum blue, Quantum *pixel);
static size_t GetPixelChannels(const Image *image);
static QuantumAny GetQuantumRange(unsigned int depth);