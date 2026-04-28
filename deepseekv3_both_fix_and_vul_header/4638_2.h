#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAXPATHLEN 4096
#define ZIP_OPENBASEDIR_CHECKPATH(path) (0)
#define TSRMLS_DC
#define TSRMLS_CC
#define FS_EXISTS 0

typedef struct _zval_struct {
    int type;
    long value;
} zval;

#define Z_BVAL(z) ((z).value)

struct zip_error {
    char *str;
};

struct zip {
    struct zip_error error;
};

struct zip_source;

int expand_filepath(const char *filename, char *resolved_path);
void php_stat(const char *path, size_t path_len, int type, zval *result);
struct zip_source *zip_source_file(struct zip *za, const char *path, long start, long len);
int zip_name_locate(struct zip *za, const char *name, int flags);
void _zip_error_fini(struct zip_error *error);
void _zip_error_init(struct zip_error *error);
int zip_delete(struct zip *za, int index);
void zip_source_free(struct zip_source *zs);
int zip_add(struct zip *za, const char *name, struct zip_source *source);