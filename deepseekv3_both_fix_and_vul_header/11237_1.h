#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

typedef int MagickBooleanType;
typedef int MagickStatusType;
typedef int ExceptionInfo;

typedef struct _Image {
    unsigned int signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
} Image;

#define MagickCoreSignature 0x12345678
#define MagickFalse 0
#define MagickTrue 1
#define TraceEvent 0
#define ResourceLimitError 0
#define CorruptImageError 0
#define CorruptImageWarning 0

static void* AcquireQuantumMemory(size_t count, size_t size) {
    return calloc(count, size);
}

static void* RelinquishMagickMemory(void *memory) {
    free(memory);
    return NULL;
}

static ssize_t ReadBlob(Image *image, size_t length, unsigned char *buffer) {
    return 0;
}

static void ThrowBinaryException(int error, const char *reason, const char *description) {
    abort();
}

static void ThrowMagickException(ExceptionInfo *exception, const char *module, 
                               int severity, const char *tag, const char *format, ...) {
    abort();
}

static const char* GetMagickModule(void) {
    return "";
}

static void LogMagickEvent(int event, const char *module, const char *format, ...) {
}