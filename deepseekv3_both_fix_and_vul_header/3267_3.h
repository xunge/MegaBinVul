#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef struct ByteIOContext {
    int le;
    int dummy;
} ByteIOContext;

typedef struct TiffContext {
    struct {
        void *metadata;
    } picture;
    ByteIOContext gb;
    int le;
} TiffContext;

double tget_double(ByteIOContext *gb, int le);
char *doubles2str(double *dp, int count, const char *sep);
void av_freep(void *ptr);
void *av_malloc(size_t size);
int av_dict_set(void **pm, const char *key, const char *value, int flags);
int bytestream2_get_bytes_left(ByteIOContext *gb);

#define AVERROR_INVALIDDATA 1
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define AV_DICT_DONT_STRDUP_VAL (1 << 1)