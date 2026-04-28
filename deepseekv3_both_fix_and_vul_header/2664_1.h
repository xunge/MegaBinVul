#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;

typedef struct {
    fz_stream *file;
} fz_archive;

typedef struct {
    fz_archive super;
    int count;
    struct {
        char *name;
        int offset;
        int csize;
        int usize;
    } *entries;
} fz_zip_archive;

#define ZIP_END_OF_CENTRAL_DIRECTORY_SIG 0x06054b50
#define ZIP64_END_OF_CENTRAL_DIRECTORY_LOCATOR_SIG 0x07064b50
#define ZIP64_END_OF_CENTRAL_DIRECTORY_SIG 0x06064b50
#define ZIP_CENTRAL_DIRECTORY_SIG 0x02014b50
#define ZIP64_EXTRA_FIELD_SIG 0x0001
#define FZ_ERROR_GENERIC 1

static void fz_seek(fz_context *ctx, fz_stream *file, int offset, int whence);
static int fz_read_int16_le(fz_context *ctx, fz_stream *file);
static int fz_read_int32_le(fz_context *ctx, fz_stream *file);
static int64_t fz_read_int64_le(fz_context *ctx, fz_stream *file);
static size_t fz_read(fz_context *ctx, fz_stream *file, unsigned char *buf, size_t len);
static void *fz_malloc(fz_context *ctx, size_t size);
static void *fz_resize_array(fz_context *ctx, void *p, size_t count, size_t size);
static void fz_throw(fz_context *ctx, int error, const char *fmt, ...);