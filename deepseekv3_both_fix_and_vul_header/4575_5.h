#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _zval_struct {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
        void *ptr;
    } value;
} zval;

typedef struct _zend_class_entry {
    char *name;
    struct _zend_class_entry *parent;
    struct _zend_function_entry *function_table;
    void (*constructor)(zval *this_ptr);
} zend_class_entry;

typedef unsigned char zend_bool;

typedef struct _phar_archive_data {
    int is_zip;
    int is_tar;
    int is_data;
    int flags;
    char *fname;
    int fname_len;
    char *ext;
    int ext_len;
    char *alias;
    int alias_len;
    int is_temporary_alias;
    void *fp;
    int refcount;
    void *manifest;
} phar_archive_data;

typedef struct {
    int dummy;
} php_stream_statbuf;

#define TSRMLS_DC
#define TSRMLS_CC
#define PHAR_FILE_COMPRESSED_GZ 1
#define PHAR_FILE_COMPRESSED_BZ2 2
#define SUCCESS 0
#define FAILURE -1
#define pcr_is_ok 0

#define PHAR_G(v) (PHAR_GLOBALS->v)
#define estrndup(str, len) strndup(str, len)
#define efree(ptr) free(ptr)
#define spprintf(buf, max_len, format, ...) (*(buf) = malloc(1024), sprintf(*(buf), format, __VA_ARGS__))
#define zend_memrchr(haystack, needle, haystack_len) strrchr(haystack, needle)
#define zend_hash_find(ht, key, key_len, result) 0
#define zend_hash_update(ht, key, key_len, data, data_size, retval) 0
#define zend_hash_num_elements(ht) 0
#define zend_throw_exception_ex(ce, code, format, ...) 0
#define zend_call_method_with_1_params(object, obj_ce, ce_ptr, method_name, retval_ptr, param1) 0
#define object_init_ex(arg, ce) 0
#define zval_dtor(z) 
#define MAKE_STD_ZVAL(z) ((z) = malloc(sizeof(zval)))
#define INIT_PZVAL(z) 
#define ZVAL_STRINGL(z, s, l, dup) ((z)->value.str.val = (dup ? estrndup(s, l) : (char*)(s)), (z)->value.str.len = l)

typedef struct {
    int manifest_cached;
    void *phar_fname_map;
    void *phar_alias_map;
} phar_globals;

extern phar_globals *PHAR_GLOBALS;
extern phar_globals *cached_phars;
extern zend_class_entry *spl_ce_BadMethodCallException;
extern zend_class_entry *phar_ce_data;
extern zend_class_entry *phar_ce_archive;

int phar_path_check(char **ext, int *ext_len, const char **pcr_error);
int phar_detect_phar_fname_ext(char *newpath, int fname_len, const char **ext, int *ext_len, int a, int b, int c TSRMLS_DC);
int phar_flush(phar_archive_data *phar, int a, int b, int c, char **error TSRMLS_DC);
void phar_destroy_phar_data(phar_archive_data *phar TSRMLS_DC);
int php_stream_stat_path(char *newpath, php_stream_statbuf *ssb);