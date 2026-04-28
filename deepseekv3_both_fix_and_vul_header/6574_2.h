#include <stddef.h>
#include <sys/types.h>

typedef enum
{
  ZipWithPrediction
} PSDCompressionType;

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;

struct _Image
{
  size_t columns;
  size_t rows;
  MagickBooleanType debug;
  char *filename;
};

struct _ExceptionInfo
{
  // Placeholder for exception info structure
};

typedef unsigned char Bytef;
typedef unsigned int uInt;

typedef struct z_stream_s
{
  Bytef *next_in;
  uInt avail_in;
  Bytef *next_out;
  uInt avail_out;
  int data_type;
  // Other zlib stream fields
} z_stream;

#define Z_BINARY 0
#define Z_OK 0
#define Z_STREAM_END 1
#define Z_SYNC_FLUSH 2

void *AcquireQuantumMemory(size_t count, size_t size);
void *RelinquishMagickMemory(void *memory);
void ResetMagickMemory(void *memory, int value, size_t size);
ssize_t ReadBlob(Image *image, size_t length, unsigned char *data);
size_t GetPSDPacketSize(Image *image);
MagickBooleanType ReadPSDChannelPixels(Image *image, const size_t channels,
  ssize_t y, const ssize_t type, unsigned char *pixels, ExceptionInfo *exception);
void ThrowBinaryException(int error, const char *reason, const char *description);
void LogMagickEvent(int event, const char *module, const char *message);
const char *GetMagickModule(void);

#define CoderEvent 0
#define ResourceLimitError 0
#define CorruptImageError 0

int inflateInit(z_stream *strm);
int inflate(z_stream *strm, int flush);
int inflateEnd(z_stream *strm);