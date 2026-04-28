#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

typedef struct bytestream2 {
    int le;
} bytestream2;

typedef struct {
    void *metadata;
} AVPicture;

typedef struct TiffContext {
    AVPicture picture;
    bytestream2 gb;
    int le;
} TiffContext;

#define AVERROR_INVALIDDATA 1
#define AVERROR(ENOMEM) 2
#define ENOMEM 1
#define AV_DICT_DONT_STRDUP_VAL 0

void av_dict_set(void **metadata, const char *name, char *value, int flags);
void *av_malloc(size_t size);
void av_freep(void **ptr);
int bytestream2_get_bytes_left(bytestream2 *s);
int16_t tget_short(bytestream2 *s, int le);
char *shorts2str(int16_t *sp, int count, const char *sep);