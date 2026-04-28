#include <assert.h>
#include <stddef.h>

#define MagickExport
#define MagickCoreSignature 0x12345678
#define MagickFalse 0
#define MagickMax(a, b) ((a) > (b) ? (a) : (b))

typedef enum {
  GrayAlphaQuantum,
  IndexAlphaQuantum,
  RGBQuantum,
  BGRQuantum,
  RGBAQuantum,
  RGBOQuantum,
  BGRAQuantum,
  CMYKQuantum,
  CMYKAQuantum
} QuantumType;

typedef struct _Image {
  size_t columns;
  size_t rows;
} Image;

typedef struct _QuantumInfo {
  unsigned long signature;
  size_t depth;
  unsigned int pack;
} QuantumInfo;