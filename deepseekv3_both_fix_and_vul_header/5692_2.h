#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <time.h>

typedef struct _phar_archive_data phar_archive_data;
typedef struct _phar_entry_info phar_entry_info;
typedef struct _php_stream php_stream;

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C
#define FAILURE (-1)
#define SUCCESS 0
#define PHAR_ENT_PERM_MASK 0777
#define WORDS_BIGENDIAN 0
#define PHP_WIN32 0

typedef struct {
    char magic[6];
    char checksum[8];
    char mode[8];
    char mtime[12];
    char size[12];
    char name[100];
    char typeflag;
    char linkname[100];
    char prefix[155];
} tar_header;

typedef struct {
    char magic[6];
    char checksum[8];
    char mode[8];
    char mtime[12];
    char size[12];
    char name[100];
    char typeflag;
    char linkname[100];
} old_tar_header;

#define TAR_GLOBAL_HDR 'g'
#define TAR_FILE_HDR 'x'
#define TAR_FILE '\0'
#define TAR_DIR '5'
#define TAR_LINK '1'
#define TAR_SYMLINK '2'

typedef uint32_t php_uint32;
typedef int zend_bool;

#define PHAR_FP 1

struct _phar_globals {
    void *phar_fname_map;
    void *phar_alias_map;
    int require_hash;
    int persist;
};

extern struct _phar_globals phar_globals;
#define PHAR_GLOBALS (&phar_globals)
#define PHAR_G(v) (phar_globals.v)

struct _phar_archive_data {
    int is_persistent;
    int is_tar;
    int is_data;
    int flags;
    php_uint32 sig_flags;
    char *signature;
    size_t sig_len;
    char *fname;
    size_t fname_len;
    char *ext;
    size_t ext_len;
    char *alias;
    size_t alias_len;
    int is_temporary_alias;
    php_stream *fp;
    void *manifest;
    void *mounted_dirs;
    void *virtual_dirs;
};

struct _phar_entry_info {
    int is_tar;
    int is_crc_checked;
    phar_archive_data *phar;
    char *filename;
    size_t filename_len;
    php_uint32 uncompressed_filesize;
    php_uint32 compressed_filesize;
    char tar_type;
    off_t offset;
    off_t offset_abs;
    int fp_type;
    int flags;
    time_t timestamp;
    int is_persistent;
    int is_dir;
    char *link;
    int manifest_pos;
};

extern void *pecalloc(size_t nmemb, size_t size, int persistent);
extern void *pemalloc(size_t size, int persistent);
extern char *pestrndup(const char *s, size_t len, int persistent);
extern void pefree(void *ptr, int persistent);
extern void *zend_hash_init(void *ht, uint nSize, void *pHashFunction, void *pDestructor, zend_bool persistent);
extern int zend_hash_add(void *ht, const char *arKey, uint nKeyLength, void *pData, uint nDataSize, void **pDest);
extern int zend_hash_exists(void *ht, const char *arKey, uint nKeyLength);
extern int zend_hash_find(void *ht, const char *arKey, uint nKeyLength, void **pData);
extern int zend_hash_del(void *ht, const char *arKey, uint nKeyLength);
extern void *zend_get_hash_value(const char *arKey, uint nKeyLength);
extern void destroy_phar_manifest_entry(void *pDest);
extern void phar_destroy_phar_data(phar_archive_data *phar TSRMLS_DC);
extern int phar_verify_signature(php_stream *fp, off_t end_of_phar, int sig_type, char *sig, int sig_len, char *fname, char **signature, size_t *signature_length, char **error TSRMLS_DC);
extern void phar_add_virtual_dirs(phar_archive_data *phar, char *filename, int filename_len TSRMLS_DC);
extern void phar_set_inode(phar_entry_info *entry TSRMLS_DC);
extern int phar_tar_process_metadata(phar_entry_info *entry, php_stream *fp TSRMLS_DC);
extern int phar_validate_alias(char *alias, int alias_len);
extern int phar_free_alias(phar_archive_data *phar, char *alias, int alias_len TSRMLS_DC);
extern void phar_request_initialize();
extern void phar_unixify_path_separators(char *path, int path_len);
extern char *estrdup(const char *s);
extern void efree(void *ptr);
extern char *spprintf(char **message, size_t max_len, const char *format, ...);
extern int php_stream_seek(php_stream *stream, off_t offset, int whence);
extern off_t php_stream_tell(php_stream *stream);
extern size_t php_stream_read(php_stream *stream, char *buf, size_t count);
extern int php_stream_close(php_stream *stream);
extern php_uint32 phar_tar_number(char *buf, size_t len);
extern php_uint32 phar_tar_checksum(char *buf, size_t len);