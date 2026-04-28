#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _zval_struct {
    int refcount;
    void *value;
} zval;

typedef struct _phar_entry_info {
    char *filename;
    size_t filename_len;
    char *link;
    char *tmp;
    zval *metadata;
    struct {
        char *c;
        size_t len;
    } metadata_str;
    int is_zip;
    int is_tar;
    int is_dir;
    char tar_type;
    int is_modified;
    struct _phar_archive_data *phar;
    unsigned int flags;
    unsigned int old_flags;
} phar_entry_info;

typedef struct _phar_archive_data {
    unsigned int flags;
    int is_data;
    int is_tar;
    int is_zip;
    void *fp;
    char *fname;
    size_t fname_len;
    int is_temporary_alias;
    char *alias;
    zval *metadata;
    size_t metadata_len;
    struct {
        void *manifest;
        void *mounted_dirs;
        void *virtual_dirs;
    };
} phar_archive_data;

#define PHAR_FORMAT_TAR 1
#define PHAR_FORMAT_ZIP 2
#define PHAR_ENT_COMPRESSION_MASK 0x0000F000
#define TAR_DIR '5'
#define TAR_FILE '0'
#define SUCCESS 0
#define FAILURE -1

#define PHAR_G(v) (phar_globals.v)
#define TSRMLS_CC
#define TSRMLS_DC

typedef unsigned int php_uint32;

struct _phar_globals {
    void *last_phar;
    char *last_phar_name;
    char *last_alias;
} phar_globals;

#define ALLOC_ZVAL(z) z = (zval *)malloc(sizeof(zval))
#define Z_SET_REFCOUNT_P(z, rc) (z)->refcount = (rc)
#define ZVAL_COPY_CTOR(z)

void *ecalloc(size_t nmemb, size_t size);
void efree(void *ptr);
char *estrdup(const char *s);
char *estrndup(const char *s, size_t length);

void zend_hash_init(void *ht, size_t size, unsigned long (*hash_func)(const void *), void (*destructor)(void *), int persistent);
int zend_hash_get_current_data(void *ht, void **data);
int zend_hash_has_more_elements(void *ht);
void zend_hash_move_forward(void *ht);
void zend_hash_internal_pointer_reset(void *ht);
int zend_hash_add(void *ht, const char *key, unsigned int key_len, void *data, unsigned int data_size, void **dest);
void zend_hash_destroy(void *ht);
unsigned long zend_get_hash_value(const void *key);

void phar_set_inode(phar_entry_info *entry);
int phar_copy_file_contents(phar_entry_info *entry, void *fp);
void phar_add_virtual_dirs(phar_archive_data *phar, const char *filename, size_t filename_len);
zval *phar_rename_archive(phar_archive_data *phar, char *ext, int flags);

void destroy_phar_manifest_entry(void *pDest);

void *php_stream_fopen_tmpfile();
void php_stream_close(void *stream);

void zend_throw_exception_ex(void *exception, long code, const char *format, ...);

extern void *phar_ce_PharException;
extern void *spl_ce_UnexpectedValueException;