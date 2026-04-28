#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define magick_restrict

typedef enum {
  VP8_STATUS_OK = 0,
  VP8_STATUS_OUT_OF_MEMORY,
  VP8_STATUS_INVALID_PARAM,
  VP8_STATUS_BITSTREAM_ERROR,
  VP8_STATUS_UNSUPPORTED_FEATURE,
  VP8_STATUS_SUSPENDED,
  VP8_STATUS_USER_ABORT,
  VP8_STATUS_NOT_ENOUGH_DATA
} VP8StatusCode;

typedef enum {
  MODE_RGBA
} WEBP_CSP_MODE;

typedef struct {
  int width;
  int height;
  int has_alpha;
} WebPBitstreamFeatures;

typedef struct {
  WEBP_CSP_MODE colorspace;
  union {
    struct {
      unsigned char* rgba;
    } RGBA;
  } u;
} WebPDecBuffer;

typedef struct {
  WebPBitstreamFeatures input;
  WebPDecBuffer output;
} WebPDecoderConfig;

typedef int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef struct {
  unsigned long signature;
  int debug;
  const char* filename;
  MagickBooleanType ping;
} ImageInfo;

typedef struct {
  unsigned long signature;
  size_t columns;
  size_t rows;
  unsigned int depth;
  MagickBooleanType matte;
  unsigned int quality;
  void* exception;
} Image;

typedef struct {
  unsigned long signature;
} ExceptionInfo;

#define MagickSignature 0x12345678
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define ResourceLimitError 0
#define CorruptImageError 0
#define CoderError 0
#define LoadImageTag 0

typedef long MagickOffsetType;
typedef unsigned char Quantum;
typedef struct {
  Quantum red;
  Quantum green;
  Quantum blue;
  Quantum alpha;
} PixelPacket;

Image* AcquireImage(const ImageInfo*);
Image* DestroyImageList(Image*);
Image* GetFirstImageInList(Image*);
MagickBooleanType OpenBlob(const ImageInfo*, Image*, int, ExceptionInfo*);
void LogMagickEvent(int, const char*, const char*, const char*);
const char* GetMagickModule(void);
void ThrowReaderException(int, const char*);
ssize_t ReadBlob(Image*, size_t, unsigned char*);
MagickBooleanType IsWEBP(const unsigned char*, ssize_t);
unsigned int ReadWebPLSBWord(const unsigned char*);
void* AcquireQuantumMemory(size_t, size_t);
void* RelinquishMagickMemory(void*);
MagickBooleanType CloseBlob(Image*);
MagickBooleanType SetImageExtent(Image*, size_t, size_t);
void InheritException(ExceptionInfo*, void**);
PixelPacket* QueueAuthenticPixels(Image*, ssize_t, ssize_t, size_t, size_t, ExceptionInfo*);
MagickBooleanType SyncAuthenticPixels(Image*, ExceptionInfo*);
MagickBooleanType SetImageProgress(Image*, int, MagickOffsetType, size_t);
Quantum ScaleCharToQuantum(unsigned char);
void SetPixelRed(PixelPacket*, Quantum);
void SetPixelGreen(PixelPacket*, Quantum);
void SetPixelBlue(PixelPacket*, Quantum);
void SetPixelAlpha(PixelPacket*, Quantum);
int WebPInitDecoderConfig(WebPDecoderConfig*);
VP8StatusCode WebPGetFeatures(const unsigned char*, size_t, WebPBitstreamFeatures*);
VP8StatusCode WebPDecode(const unsigned char*, size_t, WebPDecoderConfig*);
void WebPFreeDecBuffer(WebPDecBuffer*);
MagickBooleanType IsWEBPImageLossless(const unsigned char*, size_t);