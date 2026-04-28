#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _PixelPacket PixelPacket;
typedef double tCTM[3][3];
typedef long long MagickOffsetType;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define QuantumRange 65535
#define CorruptImageError 1
#define CoderError 2
#define ResourceLimitError 3

#define EOF (-1)
#define SEEK_SET 0

typedef enum {
  PixelsPerCentimeterResolution,
  PixelsPerInchResolution
} ResolutionType;

typedef enum {
  ReadBinaryBlobMode
} AccessMode;

struct _Image {
  unsigned int columns;
  unsigned int rows;
  unsigned int depth;
  unsigned int colors;
  double x_resolution;
  double y_resolution;
  ResolutionType units;
  struct {
    unsigned int width;
    unsigned int height;
    int x;
    int y;
  } page;
  PixelPacket *colormap;
  Image *previous;
  Image *next;
  size_t scene;
  void *blob;
};

struct _ImageInfo {
  unsigned long signature;
  int ping;
};

struct _ExceptionInfo {
  unsigned long signature;
};

struct _PixelPacket {
  unsigned short red;
  unsigned short green;
  unsigned short blue;
};

typedef struct {
  unsigned char Red;
  unsigned char Green;
  unsigned char Blue;
} WPG1_PaletteType;

static WPG1_PaletteType WPG1_Palette[256];

static unsigned short ScaleCharToQuantum(unsigned char value) {
  return (value * QuantumRange + 127) / 255;
}

static Image *AcquireImage(const ImageInfo *image_info) { return NULL; }
static unsigned int OpenBlob(const ImageInfo *image_info, Image *image, AccessMode mode, ExceptionInfo *exception) { return 0; }
static Image *DestroyImageList(Image *image) { return NULL; }
static MagickOffsetType ReadBlobLSBLong(Image *image) { return 0; }
static unsigned int ReadBlobLSBShort(Image *image) { return 0; }
static int ReadBlobByte(Image *image) { return 0; }
static void Rd_WP_DWORD(Image *image, size_t *value) { *value = 0; }
static MagickOffsetType TellBlob(Image *image) { return 0; }
static void SeekBlob(Image *image, MagickOffsetType offset, int whence) {}
static int EOFBlob(Image *image) { return 0; }
static size_t GetBlobSize(Image *image) { return 0; }
static void ThrowReaderException(int error, const char *reason) {}
static unsigned int SetImageExtent(Image *image, unsigned int columns, unsigned int rows) { return 0; }
static unsigned int AcquireImageColormap(Image *image, unsigned int colors) { return 0; }
static void *ResizeQuantumMemory(void *memory, size_t count, size_t size) { return NULL; }
static int UnpackWPGRaster(Image *image, int bpp) { return 0; }
static Image *FlopImage(Image *image, ExceptionInfo *exception) { return NULL; }
static void DuplicateBlob(Image *clone, const Image *image) {}
static void ReplaceImageInList(Image **images, Image *replace_with) {}
static Image *FlipImage(Image *image, ExceptionInfo *exception) { return NULL; }
static Image *RotateImage(Image *image, unsigned int degrees, ExceptionInfo *exception) { return NULL; }
static void AcquireNextImage(const ImageInfo *image_info, Image *image) {}
static Image *SyncNextImageInList(Image *image) { return NULL; }
static Image *ExtractPostscript(Image *image, const ImageInfo *image_info, MagickOffsetType offset, ssize_t length, ExceptionInfo *exception) { return NULL; }
static void *AcquireQuantumMemory(size_t count, size_t size) { return NULL; }
static ssize_t ReadBlob(Image *image, ssize_t length, unsigned char *buffer) { return 0; }
static void InsertRow(unsigned char *row, ssize_t y, Image *image, int bpp) {}
static void *RelinquishMagickMemory(void *memory) { return NULL; }
static int UnpackWPG2Raster(Image *image, int bpp) { return 0; }
static int LoadWPG2Flags(Image *image, unsigned char precision, void *unused, tCTM ctm) { return 0; }
static void CloseBlob(Image *image) {}
static void DeleteImageFromList(Image **image) {}