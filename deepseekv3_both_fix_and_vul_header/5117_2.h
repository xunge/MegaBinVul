#include <stddef.h>
#include <string.h>

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum
{
  ZipCompression,
  RLECompression
} CompressionType;

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image {
    size_t depth;
    size_t rows;
    size_t columns;
} Image;
typedef struct _ImageInfo {
    int quality;
} ImageInfo;
typedef struct _PSDInfo PSDInfo;
typedef struct _QuantumInfo QuantumInfo;
typedef struct _CacheView CacheView;

typedef unsigned short Quantum;

typedef enum
{
  UndefinedQuantum,
  IndexQuantum,
  RedQuantum,
  GreenQuantum,
  BlueQuantum,
  AlphaQuantum,
  BlackQuantum,
  CyanQuantum,
  MagentaQuantum,
  YellowQuantum,
  GrayQuantum
} QuantumType;

typedef long long MagickOffsetType;
typedef long ssize_t;

#ifdef MAGICKCORE_ZLIB_DELEGATE
#define CHUNK 16384
typedef unsigned int uInt;
typedef unsigned char Bytef;
#define Z_NO_FLUSH 0
#define Z_FINISH 4
#define Z_STREAM_ERROR (-2)
#define Z_OK 0
#define Z_BINARY 0
#define Z_DEFAULT_COMPRESSION (-1)

typedef struct z_stream_s {
    Bytef *next_in;
    uInt avail_in;
    Bytef *next_out;
    uInt avail_out;
    int data_type;
} z_stream;
#endif