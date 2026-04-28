#include <stdint.h>
#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

#define restrict __restrict

typedef enum {
  MagickFalse = 0,
  MagickTrue = 1
} MagickBooleanType;

typedef long MagickOffsetType;

typedef struct _ImageInfo {
  unsigned long signature;
  int debug;
  const char *filename;
  void *exception;
} ImageInfo;

typedef struct _Image {
  unsigned long signature;
  int debug;
  const char *filename;
  unsigned long columns;
  unsigned long rows;
  int quality;
  int matte;
  void *exception;
} Image;

typedef struct _MemoryInfo {
  void *blob;
} MemoryInfo;

typedef struct _PixelPacket {
  uint32_t red;
  uint32_t green;
  uint32_t blue;
  uint32_t alpha;
} PixelPacket;

typedef struct _StringInfo {
  const unsigned char *datum;
  size_t length;
} StringInfo;

typedef struct _ExceptionInfo {
  int code;
} ExceptionInfo;

typedef struct {
  int error_code;
} WebPAuxStats;

typedef struct {
  int width;
  int height;
  uint32_t* argb;
  int argb_stride;
  int use_argb;
  void* stats;
  int error_code;
  void* custom_ptr;
  void (*writer)(void*);
#if WEBP_DECODER_ABI_VERSION >= 0x0100
  void (*progress_hook)(void*);
#endif
} WebPPicture;

typedef struct {
  float quality;
  int lossless;
  int method;
  int image_hint;
  int target_size;
  float target_PSNR;
  int segments;
  int sns_strength;
  int filter_strength;
  int filter_sharpness;
  int filter_type;
  int autofilter;
  int alpha_compression;
  int alpha_filtering;
  int alpha_quality;
  int pass;
  int show_compressed;
  int preprocessing;
  int partitions;
  int partition_limit;
#if WEBP_DECODER_ABI_VERSION >= 0x0201
  int emulate_jpeg_size;
  int low_memory;
  int thread_level;
#endif
} WebPConfig;

#if defined(MAGICKCORE_WEBPMUX_DELEGATE)
typedef struct {
  unsigned char* mem;
  size_t size;
} WebPMemoryWriter;
#endif

#define MagickCoreSignature 0xabacadabUL
#define UndefinedCompressionQuality 0
#define sRGBColorspace 1
#define TraceEvent 1
#define SaveImageTag 1
#define CorruptImageError 1
#define ResourceLimitError 1
#define ImageError 1
#define WEBP_HINT_DEFAULT 0
#define WEBP_HINT_PHOTO 1
#define WEBP_HINT_PICTURE 2
#define WEBP_HINT_GRAPH 3
#define VP8_ENC_ERROR_OUT_OF_MEMORY 1
#define VP8_ENC_ERROR_BITSTREAM_OUT_OF_MEMORY 2
#define VP8_ENC_ERROR_NULL_PARAMETER 3
#define VP8_ENC_ERROR_INVALID_CONFIGURATION 4
#define VP8_ENC_ERROR_BAD_DIMENSION 5
#define VP8_ENC_ERROR_PARTITION0_OVERFLOW 6
#define VP8_ENC_ERROR_PARTITION_OVERFLOW 7
#define VP8_ENC_ERROR_BAD_WRITE 8
#define VP8_ENC_ERROR_FILE_TOO_BIG 9
#define VP8_ENC_ERROR_USER_ABORT 10
#define WEBP_MUX_OK 1
#define WriteBinaryBlobMode 1

static const char* MagickBooleanOptions[] = {"false", "true", NULL};

static int LogMagickEvent(int event, const char* module, const char* format, ...) { return 0; }
static const char* GetMagickModule() { return NULL; }
static void ThrowWriterException(int code, const char* message) {}
static MagickBooleanType OpenBlob(const ImageInfo* info, Image* image, int mode, void* exception) { return MagickFalse; }
static const char* GetImageOption(const ImageInfo* info, const char* option) { return NULL; }
static int ParseCommandOption(const char* options[], MagickBooleanType type, const char* value) { return 0; }
static int StringToInteger(const char* value) { return 0; }
static double StringToDouble(const char* value, char** endptr) { return 0.0; }
static int LocaleCompare(const char* a, const char* b) { return 0; }
static MagickBooleanType TransformImageColorspace(Image* image, int colorspace) { return MagickFalse; }
static MemoryInfo* AcquireVirtualMemory(size_t width, size_t size) { return NULL; }
static void* GetVirtualMemoryBlob(MemoryInfo* info) { return NULL; }
static const PixelPacket* GetVirtualPixels(Image* image, ssize_t x, ssize_t y, size_t columns, size_t rows, void* exception) { return NULL; }
static unsigned char ScaleQuantumToChar(uint32_t quantum) { return 0; }
static uint32_t GetPixelRed(const PixelPacket* p) { return 0; }
static uint32_t GetPixelGreen(const PixelPacket* p) { return 0; }
static uint32_t GetPixelBlue(const PixelPacket* p) { return 0; }
static uint32_t GetPixelAlpha(const PixelPacket* p) { return 0; }
static MagickBooleanType SetImageProgress(Image* image, int tag, MagickOffsetType y, size_t rows) { return MagickFalse; }
static void ThrowMagickException(void* exception, const char* module, int code, const char* message, const char* format, ...) {}
static MemoryInfo* RelinquishVirtualMemory(MemoryInfo* info) { return NULL; }
static int CloseBlob(Image* image) { return 0; }
static int WebPPictureInit(WebPPicture* picture) { return 0; }
static int WebPConfigInit(WebPConfig* config) { return 0; }
static int WebPValidateConfig(const WebPConfig* config) { return 0; }
static int WebPEncode(const WebPConfig* config, WebPPicture* picture) { return 0; }
static void WebPPictureFree(WebPPicture* picture) {}
static void WebPEncodeWriter(void* data, const void* ptr, size_t size) {}

#if defined(MAGICKCORE_WEBPMUX_DELEGATE)
static void WebPMemoryWriterInit(WebPMemoryWriter* writer) {}
static void WebPMemoryWriterClear(WebPMemoryWriter* writer) {}
static void WebPMemoryWrite(void* data, const void* ptr, size_t size) {}
static void* WebPMuxNew(void) { return NULL; }
static int WebPMuxSetChunk(void* mux, const char* id, const void* data, int copy) { return 0; }
static int WebPMuxSetImage(void* mux, const void* data, int copy) { return 0; }
static int WebPMuxAssemble(void* mux, void* output) { return 0; }
static void WebPMuxDelete(void* mux) {}
#endif

// Fix for magick_restrict pointer declarations
#define magick_restrict __restrict