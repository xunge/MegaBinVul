#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _php_stream php_stream;
typedef unsigned int php_uint32;
typedef unsigned short php_uint16;

typedef struct _phar_archive_data {
    char *fname;
    size_t fname_len;
    char *alias;
    size_t alias_len;
    int is_persistent;
    int is_data;
    int is_temporary_alias;
    int is_brandnew;
    int donotflush;
    int sig_flags;
    void *metadata;
    php_stream *fp;
    php_stream *ufp;
    void *manifest;
} phar_archive_data;

typedef struct _phar_entry_info {
    php_stream *fp;
    char *filename;
    size_t filename_len;
    size_t uncompressed_filesize;
    size_t compressed_filesize;
    int flags;
    time_t timestamp;
    int is_modified;
    int is_zip;
    phar_archive_data *phar;
    int fp_type;
} phar_entry_info;

typedef struct _phar_zip_pass {
    php_stream *old;
    php_stream *filefp;
    php_stream *centralfp;
    int free_fp;
    int free_ufp;
    char **error;
} phar_zip_pass;

typedef struct _phar_zip_dir_end {
    char signature[4];
    php_uint16 counthere;
    php_uint16 count;
    php_uint32 cdir_size;
    php_uint32 cdir_offset;
    php_uint16 comment_len;
} phar_zip_dir_end;

typedef struct _smart_str {
    char *c;
    size_t len;
    size_t a;
} smart_str;

typedef int php_serialize_data_t;

#define PHAR_ENT_PERM_DEF_FILE 0
#define PHAR_MOD 0
#define PHAR_SIG_SHA1 0
#define SUCCESS 0
#define FAILURE -1
#define PHP_STREAM_COPY_ALL 0
#define IGNORE_URL 0
#define STREAM_MUST_SEEK 0
#define REPORT_ERRORS 0

#define PHAR_SET_16(var, val) (var) = (val)
#define PHAR_SET_32(var, val) (var) = (val)

#define estrndup(str, len) strndup(str, len)
#define efree(ptr) free(ptr)
#define spprintf(buf, max_len, format, ...) \
    do { \
        if (buf) { \
            *(buf) = malloc(max_len); \
            if (*(buf)) snprintf(*(buf), max_len, format, ##__VA_ARGS__); \
        } \
    } while (0)

#define TSRMLS_DC
#define TSRMLS_CC

typedef struct _zval {
    /* dummy zval structure */
    long lval;
} zval;

int phar_get_archive(phar_archive_data **pphar, const char *fname, size_t fname_len, const char *alias, size_t alias_len, char **error TSRMLS_DC);
int phar_zip_applysignature(phar_archive_data *phar, phar_zip_pass *pass, smart_str *metadata_str TSRMLS_DC);
int phar_stream_copy_to_stream(php_stream *src, php_stream *dest, size_t maxlen, size_t *len);
int zend_hash_num_elements(void *ht);
int zend_hash_update(void *ht, const char *key, size_t key_len, void *data, size_t data_size, void **pData);
int zend_hash_add(void *ht, const char *key, size_t key_len, void *data, size_t data_size, void **pData);
int zend_hash_del(void *ht, const char *key, size_t key_len);
int zend_hash_exists(void *ht, const char *key, size_t key_len);
void zend_hash_apply_with_argument(void *ht, int (*apply_func)(void *pDest TSRMLS_DC, void *argument TSRMLS_DC), void *arg TSRMLS_DC);
int phar_zip_changed_apply(void *pDest TSRMLS_DC, void *argument TSRMLS_DC);

void PHP_VAR_SERIALIZE_INIT(php_serialize_data_t metadata_hash);
void PHP_VAR_SERIALIZE_DESTROY(php_serialize_data_t metadata_hash);
void php_var_serialize(smart_str *buf, void *struc, php_serialize_data_t *metadata_hash TSRMLS_DC);
void smart_str_free(smart_str *str);

php_stream *php_stream_fopen_tmpfile(void);
php_stream *php_stream_open_wrapper(const char *path, const char *mode, int options, char **opened_path);
size_t php_stream_write(php_stream *stream, const char *buf, size_t count);
int php_stream_seek(php_stream *stream, off_t offset, int whence);
off_t php_stream_tell(php_stream *stream);
int php_stream_rewind(php_stream *stream);
int php_stream_close(php_stream *stream);
size_t php_stream_copy_to_mem(php_stream *src, char **buf, size_t maxlen, int persistent);
int php_stream_from_zval_no_verify(php_stream **pstream, zval **ppzval);

char *php_stristr(char *haystack, const char *needle, size_t haystack_len, size_t needle_len);