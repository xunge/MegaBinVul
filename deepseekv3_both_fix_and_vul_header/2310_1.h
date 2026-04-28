#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _PSDInfo PSDInfo;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  MSBEndian
} EndianType;

typedef enum {
  TraceEvent,
  CoderEvent
} LogEventType;

typedef enum {
  CorruptImageError,
  ResourceLimitError
} ErrorType;

typedef enum {
  LabMode,
  CMYKMode,
  BitmapMode,
  GrayscaleMode,
  DuotoneMode
} PSDImageType;

typedef enum {
  LabColorspace,
  CMYKColorspace,
  GRAYColorspace
} ColorspaceType;

typedef enum {
  ActivateAlphaChannel,
  TransparentAlphaChannel
} AlphaChannelOption;

typedef enum {
  UndefinedPixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef enum {
  PseudoClass
} ClassType;

typedef enum {
  FlattenLayer
} LayerMethod;

typedef struct {
    PixelTrait alpha_trait;
    unsigned char alpha;
} BackgroundColor;

typedef struct {
    double red;
    double green;
    double blue;
} ColorInfo;

#define MagickCoreSignature 0x12345678
#define MaxPSDChannels 56
#define SEEK_SET 0
#define TransparentAlpha 0

struct _Image {
  unsigned long signature;
  EndianType endian;
  unsigned long columns;
  unsigned long rows;
  unsigned short depth;
  MagickBooleanType debug;
  ClassType storage_class;
  unsigned long colors;
  PixelTrait alpha_trait;
  BackgroundColor background_color;
  ColorInfo *colormap;
};

struct _ImageInfo {
  unsigned long signature;
  MagickBooleanType debug;
  const char *filename;
  MagickBooleanType ping;
  unsigned long number_scenes;
  unsigned long scene;
};

struct _ExceptionInfo {
  unsigned long signature;
};

struct _PSDInfo {
  char signature[4];
  unsigned short version;
  char reserved[6];
  unsigned short channels;
  unsigned long rows;
  unsigned long columns;
  unsigned short depth;
  PSDImageType mode;
};

static void *AcquireQuantumMemory(size_t, size_t);
static void *RelinquishMagickMemory(void *);