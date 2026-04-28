#include <stddef.h>
#include <sys/types.h>

typedef unsigned char Bytef;
typedef unsigned int uInt;

typedef enum {
    ZipWithPrediction
} PSDCompressionType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    CoderEvent,
    ResourceLimitError
} MagickEventType;

typedef struct _Image {
    size_t columns;
    size_t rows;
    char *filename;
    MagickBooleanType debug;
} Image;

typedef struct _ExceptionInfo {
    // Placeholder for exception info structure
} ExceptionInfo;

typedef struct {
    Bytef *next_in;
    uInt avail_in;
    Bytef *next_out;
    uInt avail_out;
    int data_type;
} z_stream;

#define Z_BINARY 0
#define Z_OK 0
#define Z_STREAM_END 1
#define Z_SYNC_FLUSH 2

void *AcquireQuantumMemory(size_t count, size_t size);
void *RelinquishMagickMemory(void *memory);
void ResetMagickMemory(void *memory, int value, size_t size);
ssize_t ReadBlob(Image *image, size_t length, unsigned char *data);
int inflateInit(z_stream *strm);
int inflate(z_stream *strm, int flush);
MagickBooleanType ReadPSDChannelPixels(Image *image, const size_t channels, 
    ssize_t y, const ssize_t type, unsigned char *pixels, ExceptionInfo *exception);
size_t GetPSDPacketSize(Image *image);
void LogMagickEvent(MagickEventType event, const char *module, const char *format, ...);
const char *GetMagickModule(void);
void ThrowBinaryException(MagickEventType error, const char *reason, const char *description);