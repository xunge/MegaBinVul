#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXPATHLEN 4096
#define IS_SLASH(c) ((c) == '/')
#define DEFAULT_SLASH '\\'
#define PHP_STREAM_URL_STAT_QUIET 0
#define PHP_STREAM_MKDIR_RECURSIVE 1
#define REPORT_ERRORS 1
#define ENFORCE_SAFE_MODE 0
#define CWD_EXPAND 1
#define ZIP_OPENBASEDIR_CHECKPATH(path) (0)

typedef struct _cwd_state {
    char *cwd;
    size_t cwd_length;
} cwd_state;

typedef struct php_stream_statbuf {
    int dummy;
} php_stream_statbuf;

typedef struct php_stream {
    int dummy;
} php_stream;

struct zip {
    int dummy;
};

struct zip_file {
    int dummy;
};

struct zip_stat {
    int dummy;
};

#define TSRMLS_DC
#define TSRMLS_CC
#define spprintf(buffer, max_len, format, ...) \
    (*(buffer) = malloc(MAXPATHLEN), sprintf(*(buffer), format, __VA_ARGS__))
#define efree free
#define php_error_docref(a, b, c, ...)
#define php_stream_open_wrapper(a, b, c, d) NULL
#define php_stream_close(a)
#define php_stream_write(a, b, c) 0
#define php_stream_mkdir(a, b, c, d) 0
#define php_stream_stat_path_ex(a, b, c, d) -1
#define php_dirname(a, b) 0
#define php_basename(a, b, c, d, e, f) (*(e) = strdup(a), *(f) = strlen(a))
#define virtual_file_ex(a, b, c, d)
#define php_zip_make_relative_path(a, b) strdup(a)
#define zip_fopen(a, b, c) NULL
#define zip_fread(a, b, c) 0
#define zip_fclose(a) 0
#define zip_stat(a, b, c, d) -1