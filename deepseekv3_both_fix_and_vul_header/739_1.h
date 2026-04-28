#include <stdlib.h>
#include <string.h>

typedef unsigned int ExifLong;

#define EXIF_LOG_CODE_DEBUG 0

typedef struct {
    void *log;
    void *mem;
} ExifDataPrivate;

typedef struct {
    ExifDataPrivate *priv;
    unsigned char *data;
    unsigned int size;
} ExifData;

void exif_log(void *log, int code, const char *domain, const char *format, ...);
void exif_mem_free(void *mem, void *ptr);
void *exif_data_alloc(ExifData *data, unsigned int size);
#define EXIF_LOG_NO_MEMORY(log, domain, size)