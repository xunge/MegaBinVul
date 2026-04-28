#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>
#include <limits.h>

typedef struct _phar_archive_data phar_archive_data;
typedef struct _phar_entry_info phar_entry_info;
typedef struct _php_stream php_stream;

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C
#define FAILURE (-1)
#define SUCCESS 0
#define PHAR_G(v) (v)
#define PHAR_ENT_PERM_MASK 0777
#define TAR_FILE '0'
#define TAR_LINK '1'
#define TAR_SYMLINK '2'
#define TAR_DIR '5'
#define PHAR_FP 1
#define WORDS_BIGENDIAN 0
#define PHP_WIN32 0

typedef struct {
    char name[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char checksum[8];
    char typeflag;
    char linkname[100];
    char magic[6];
    char version[2];
    char uname[32];
    char gname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
} tar_header;

typedef struct {
    char name[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char checksum[8];
    char linkflag;
    char linkname[100];
} old_tar_header;

typedef uint32_t php_uint32;
typedef int zend_bool;

struct _phar_archive_data {
    int is_persistent;
    int is_tar;
    int is_data;
    int flags;
    size_t fname_len;
    char *fname;
    char *ext;
    size_t ext_len;
    char *alias;
    size_t alias_len;
    int is_temporary_alias;
    php_stream *fp;
    php_uint32 sig_flags;
    char *signature;
    size_t sig_len;
    void *manifest;
    void *mounted_dirs;
    void *virtual_dirs;
};

struct _phar_entry_info {
    int is_tar;
    int is_crc_checked;
    phar_archive_data *phar;
    size_t filename_len;
    char *filename;
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

struct phar_globals {
    void *phar_fname_map;
    void *phar_alias_map;
};

extern struct phar_globals *PHAR_GLOBALS;
extern int persist;
extern int require_hash;

extern void *pecalloc(size_t nmemb, size_t size, int persistent);
extern void *pemalloc(size_t size, int persistent);
extern char *pestrndup(const char *s, size_t length, int persistent);
extern void pefree(void *ptr, int persistent);
extern char *estrdup(const char *s);
extern void efree(void *ptr);
extern int zend_hash_init(void *ht, uint nSize, uint (*pHashFunction)(const void *), void (*pDestructor)(void *), zend_bool persistent);
extern int zend_hash_add(void *ht, const char *arKey, uint nKeyLength, void *pData, uint nDataSize, void **pDest);
extern int zend_hash_exists(void *ht, const char *arKey, uint nKeyLength);
extern int zend_hash_find(void *ht, const char *arKey, uint nKeyLength, void **pData);
extern void zend_hash_del(void *ht, const char *arKey, uint nKeyLength);
extern uint zend_get_hash_value(const void *arKey);
extern void destroy_phar_manifest_entry(void *pDest);
extern int phar_tar_number(const char *buf, size_t len);
extern uint32_t phar_tar_checksum(char *buf, size_t len);
extern int phar_verify_signature(php_stream *fp, off_t end_of_phar, int sig_type, char *sig, size_t sig_len, const char *fname, char **signature, size_t *signature_len, char **error TSRMLS_DC);
extern void phar_destroy_phar_data(phar_archive_data *phar TSRMLS_DC);
extern void phar_add_virtual_dirs(phar_archive_data *phar, char *filename, size_t filename_len TSRMLS_CC);
extern void phar_set_inode(phar_entry_info *entry TSRMLS_CC);
extern int phar_tar_process_metadata(phar_entry_info *entry, php_stream *fp TSRMLS_CC);
extern int phar_validate_alias(char *alias, size_t alias_len);
extern void phar_unixify_path_separators(char *path, size_t path_len);
extern void phar_request_initialize(TSRMLS_D);
extern int phar_free_alias(phar_archive_data *phar, char *alias, size_t alias_len TSRMLS_DC);
extern char *spprintf(char **message, size_t max_len, const char *format, ...);
extern int php_stream_seek(php_stream *stream, off_t offset, int whence);
extern off_t php_stream_tell(php_stream *stream);
extern size_t php_stream_read(php_stream *stream, char *buf, size_t count);
extern int php_stream_close(php_stream *stream);

#ifndef S_ISDIR
#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#endif