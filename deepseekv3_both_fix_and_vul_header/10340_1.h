#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum
{
  GIMP_GRAY,
  GIMP_RGB
} GimpImageType;

typedef unsigned char Quantum;

typedef struct _Image
{
  size_t rows;
  size_t columns;
  char *filename;
} Image;

typedef struct
{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned char alpha;
} XCFPixelInfo;

typedef struct
{
  GimpImageType image_type;
} XCFDocInfo;

typedef struct
{
  unsigned char alpha;
} XCFLayerInfo;

typedef struct _ExceptionInfo ExceptionInfo;

#define TransparentAlpha 0U
#define ResourceLimitError 0
#define CorruptImageError 0

#define AcquireQuantumMemory(size,element_size) malloc((size)*(element_size))
#define RelinquishMagickMemory(memory) (free(memory), NULL)
#define ThrowBinaryException(severity,tag,message)
#define ScaleCharToQuantum(value) (value)
#define GetAuthenticPixels(image,x,y,columns,rows,exception) NULL
#define SetPixelGray(image,value,q)
#define SetPixelRed(image,value,q)
#define SetPixelGreen(image,value,q)
#define SetPixelBlue(image,value,q)
#define SetPixelAlpha(image,value,q)
#define GetPixelChannels(image) 0
#define SyncAuthenticPixels(image,exception) MagickFalse
#define ReadBlob(image,count,data) 0