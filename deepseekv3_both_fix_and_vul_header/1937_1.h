#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define SAPI_API
#define SAPI_POST_HANDLER_FUNC(name) void name(void *arg)
#define INI_INT(name) 0
#define SG(var) (var)
#define PG(var) (var)
#define TSRMLS_CC
#define TSRMLS_DC
#define FILLUNIT 8192
#define MAX_SIZE_ANONNAME 32
#define MAX_SIZE_OF_INDEX 64
#define DEBUG_FILE_UPLOAD 0
#define UPLOAD_ERROR_A 1
#define UPLOAD_ERROR_B 2
#define UPLOAD_ERROR_C 3
#define UPLOAD_ERROR_D 4
#define UPLOAD_ERROR_E 5
#define UPLOAD_ERROR_F 6
#define UPLOAD_ERROR_X 7
#define SAFE_RETURN return
#define COMPILE_DL_MBSTRING 0
#define HAVE_MBSTRING 0
#define PHP_WIN32 0
#define TRACK_VARS_FILES 0
#define E_WARNING 0
#define E_NOTICE 0
#define FAILURE -1
#define SUCCESS 0
#define MULTIPART_EVENT_START 0
#define MULTIPART_EVENT_FORMDATA 1
#define MULTIPART_EVENT_FILE_START 2
#define MULTIPART_EVENT_FILE_DATA 3
#define MULTIPART_EVENT_FILE_END 4
#define MULTIPART_EVENT_END 5
#define PARSE_POST 0
#define IS_LONG 1

typedef void (*dtor_func_t)(void *);
typedef int (*llist_dtor_func_t)(void *);

typedef struct _zval_struct {
    union {
        long lval;
        char *str;
    } value;
    int type;
} zval;

typedef struct _HashTable {
    int dummy;
} HashTable;

typedef struct _zend_llist {
    int dummy;
} zend_llist;

typedef struct _multipart_buffer {
    int dummy;
} multipart_buffer;

typedef struct _mime_header_entry {
    int dummy;
} mime_header_entry;

typedef struct {
    long content_length;
} multipart_event_start;

typedef struct {
    long post_bytes_processed;
    char *name;
    char **value;
    unsigned int length;
    size_t *newlength;
} multipart_event_formdata;

typedef struct {
    long post_bytes_processed;
    char *name;
    char **filename;
} multipart_event_file_start;

typedef struct {
    long post_bytes_processed;
    off_t offset;
    char *data;
    size_t length;
    size_t *newlength;
} multipart_event_file_data;

typedef struct {
    long post_bytes_processed;
    char *temp_filename;
    int cancel_upload;
} multipart_event_file_end;

typedef struct {
    long post_bytes_processed;
} multipart_event_end;

struct sapi_module_struct {
    void (*sapi_error)(int type, const char *format, ...);
    int (*input_filter)(int type, char *param, char **value, unsigned int value_len, unsigned int *new_val_len);
};

struct _request_info {
    long content_length;
};

struct _sapi_globals_struct {
    long post_max_size;
    struct _request_info request_info;
    long read_post_bytes;
    HashTable *rfc1867_uploaded_files;
};

extern struct sapi_module_struct sapi_module;
extern struct _sapi_globals_struct SG;
extern zval *PG_http_globals[];
extern int PG_max_input_vars;
extern int PG_file_uploads;
extern long PG_upload_max_filesize;
extern char *PG_upload_tmp_dir;
extern int PG_magic_quotes_gpc;
extern HashTable PG_rfc1867_protected_variables;

long post_max_size;
struct _request_info request_info;
long read_post_bytes;
HashTable *rfc1867_uploaded_files;
HashTable rfc1867_protected_variables;
zval *http_globals[10];
int max_input_vars;
int file_uploads;
long upload_max_filesize;
char *upload_tmp_dir;
int magic_quotes_gpc;

char *content_type_dup;
int (*php_rfc1867_callback)(int, void *, void **);
void *php_mb_encoding_translation(void);
int php_mb_gpc_stack_variable(char *, char *, char ***, int **, int *, int *);
int php_mb_gpc_encoding_detector(char **, int *, int, void *);
int php_mb_gpc_encoding_converter(char **, int *, int, void *, void *);
char *php_mb_strrchr(char *, char);
void safe_php_register_variable(char *, char *, int, zval *, int);
void safe_php_register_variable_ex(char *, zval *, zval *, int);
void register_http_post_files_variable(char *, char *, zval *, int);
void register_http_post_files_variable_ex(char *, zval *, zval *, int);
void add_protected_variable(char *);
multipart_buffer *multipart_buffer_new(char *, int);
int multipart_buffer_eof(multipart_buffer *);
int multipart_buffer_headers(multipart_buffer *, zend_llist *);
char *multipart_buffer_read_body(multipart_buffer *, unsigned int *);
size_t multipart_buffer_read(multipart_buffer *, char *, size_t, int *);
char *php_mime_get_hdr_value(zend_llist, const char *);
char *php_ap_getword(char **, char);
char *php_ap_getword_conf(char **);
void php_free_hdr_entry(mime_header_entry *);
int php_open_temporary_fd_ex(char *, char *, char **, int);
void free_estring(void *);
char *estrndup(const char *, size_t);
char *ecalloc(size_t, size_t);
void efree(void *);
void *safe_erealloc(void *, size_t, size_t, size_t);
void php_strtolower(char *, int);
void ZVAL_STRING(zval *, char *, int);
void zend_hash_init(HashTable *, int, void *, dtor_func_t, int);
void ALLOC_HASHTABLE(HashTable *);
void ALLOC_ZVAL(zval *);
void array_init(zval *);
void INIT_PZVAL(zval *);
void zend_llist_init(zend_llist *, size_t, llist_dtor_func_t, int);
void zend_llist_clean(zend_llist *);
void zend_hash_add(HashTable *, char *, int, void *, int, void *);
char *estrdup(const char *);
char *emalloc(size_t);
void php_error_docref(void *, int, const char *, ...);