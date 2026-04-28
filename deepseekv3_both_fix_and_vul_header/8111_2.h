#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAXPATHLEN 4096
#define ZIP_CREATE 0

typedef struct php_stream_wrapper php_stream_wrapper;
typedef struct php_stream_context php_stream_context;
typedef struct php_stream php_stream;

#define STREAMS_DC
#define TSRMLS_DC
#define TSRMLS_CC

struct zip;
struct zip_file;

struct php_zip_stream_data_t {
    struct zip *za;
    struct zip_file *zf;
    php_stream *stream;
    off_t cursor;
};

extern php_stream *php_stream_alloc(void *ops, void *data, void *context, const char *mode);
extern void *emalloc(size_t size);
extern void efree(void *ptr);
extern char *estrdup(const char *s);
extern void php_basename(const char *path, size_t path_len, const char *suffix, size_t suffix_len, char **out, size_t *out_len TSRMLS_DC);
extern int ZIP_OPENBASEDIR_CHECKPATH(const char *path);

extern struct _php_stream_ops php_stream_zipio_ops;

extern struct zip *zip_open(const char *path, int flags, int *errorp);
extern int zip_close(struct zip *archive);
extern struct zip_file *zip_fopen(struct zip *archive, const char *fname, int flags);