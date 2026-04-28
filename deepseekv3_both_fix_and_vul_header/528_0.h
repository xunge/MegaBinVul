#include <stdio.h>
#include <assert.h>

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { UndefinedStream } StreamType;
typedef void (*StreamHandler)(void);

typedef struct {
    FILE *file;
} FileInfo;

typedef struct {
    unsigned char *data;
    size_t length;
    off_t offset;
    MagickBooleanType eof;
    int error;
    MagickBooleanType exempt;
    StreamType type;
    FileInfo file_info;
    StreamHandler stream;
    MagickBooleanType mapped;
    MagickBooleanType debug;
} BlobInfo;

typedef enum { TraceEvent } LogEventType;
typedef enum { MapResource } ResourceType;

void *RelinquishMagickResource(ResourceType, size_t);
void *UnmapBlob(void *, size_t);
void *LogMagickEvent(LogEventType, const char *, const char *);
const char *GetMagickModule(void);