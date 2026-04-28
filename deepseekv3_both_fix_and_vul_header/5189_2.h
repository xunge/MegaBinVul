#include <assert.h>
#include <stdlib.h>

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef unsigned int MagickStatusType;
#define MagickCoreSignature 0x12345678

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct Image {
    unsigned int signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
} Image;

#define TraceEvent 0
#define ResourceLimitError 0
#define CorruptImageError 0
#define CorruptImageWarning 0

static size_t ReadBlob(Image *image, size_t size, unsigned char *buffer) {
    return 0;
}

static void *AcquireQuantumMemory(size_t count, size_t size) {
    return calloc(count, size);
}

static void *RelinquishMagickMemory(void *memory) {
    free(memory);
    return NULL;
}

static void LogMagickEvent(int event, const char *module, const char *format, ...) {}

static void ThrowBinaryException(int error, const char *reason, const char *description) {}

static void ThrowMagickException(ExceptionInfo *exception, const char *module, 
                               int severity, const char *tag, const char *format, ...) {}

static const char *GetMagickModule(void) {
    return "";
}