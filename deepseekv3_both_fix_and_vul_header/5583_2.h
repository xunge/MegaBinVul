#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _zval_struct {
    /* zval structure fields */
} zval;

typedef struct _zend_class_entry {
    /* class entry fields */
    struct _zend_function *constructor;
} zend_class_entry;

typedef unsigned char zend_bool;

typedef struct _phar_archive_data {
    char *fname;
    int fname_len;
    char *ext;
    int ext_len;
    char *alias;
    int alias_len;
    zend_bool is_zip;
    zend_bool is_tar;
    zend_bool is_data;
    zend_bool is_temporary_alias;
    int flags;
    void *fp;
    int refcount;
    void *manifest;
    /* other fields */
} phar_archive_data;

typedef struct _php_stream_statbuf {
    /* stat buffer fields */
} php_stream_statbuf;

typedef struct _phar_globals {
    void *phar_fname_map;
    void *phar_alias_map;
    int manifest_cached;
} phar_globals;

#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0
#define PHAR_FILE_COMPRESSED_GZ 1
#define PHAR_FILE_COMPRESSED_BZ2 2

extern phar_globals *PHAR_GLOBALS;
#define PHAR_G(v) (PHAR_GLOBALS->v)

extern zend_class_entry *spl_ce_BadMethodCallException;
extern zend_class_entry *phar_ce_data;
extern zend_class_entry *phar_ce_archive;

extern char *estrndup(const char *s, size_t length);
extern int spprintf(char **message, size_t max_len, const char *format, ...);
extern void efree(void *ptr);
extern int zend_hash_find(void *ht, const char *arKey, uint32_t nKeyLength, void **pData);
extern int zend_hash_update(void *ht, const char *arKey, uint32_t nKeyLength, void *pData, uint32_t nDataSize, void **pDest);
extern int zend_hash_num_elements(void *ht);
extern int php_stream_stat_path(const char *path, php_stream_statbuf *ssb);
extern int phar_detect_phar_fname_ext(const char *filename, int filename_len, const char **ret, int *ret_len, int executable, int for_create, int for_phar);
extern int phar_flush(phar_archive_data *phar, int convert, int copy, int save, char **error);
extern void phar_destroy_phar_data(phar_archive_data *phar);
extern void zend_call_method_with_1_params(zval **object_pp, zend_class_entry *obj_ce, void **fn_proxy, const char *function_name, zval **retval_ptr, zval *param1);
extern int object_init_ex(zval *arg, zend_class_entry *ce);
extern void zval_dtor(zval *z);
extern void MAKE_STD_ZVAL(zval *z);
extern void INIT_PZVAL(zval *z);
extern void ZVAL_STRINGL(zval *z, char *s, int l, int duplicate);
extern void *zend_memrchr(const void *s, int c, size_t n);
extern int phar_path_check(char **ext, int *ext_len, const char **pcr_error);
extern void zend_throw_exception_ex(zend_class_entry *exception_ce, long code, const char *format, ...);

extern void *cached_phars;

#define pcr_is_ok 0