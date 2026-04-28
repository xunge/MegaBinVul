#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#include <time.h>

typedef struct _phar_archive_data phar_archive_data;
typedef struct _phar_entry_info phar_entry_info;
typedef struct _tar_header tar_header;
typedef struct _old_tar_header old_tar_header;
typedef struct _phar_globals phar_globals;

#define TAR_FILE '0'
#define TAR_LINK '1'
#define TAR_SYMLINK '2'
#define TAR_DIR '5'

#define PHAR_ENT_PERM_MASK 0777
#define PHAR_G(persist) (0)
#define PHAR_FP (0)
#define PHAR_GLOBALS ((phar_globals *)0)
#define FAILURE (-1)
#define SUCCESS 0

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C

#define WORDS_BIGENDIAN 0

typedef unsigned int php_uint32;
typedef int zend_bool;
typedef long off_t;

struct _phar_globals {
    void *phar_fname_map;
    void *phar_alias_map;
};

struct _phar_archive_data {
    int is_persistent;
    int is_tar;
    int is_data;
    int flags;
    int is_temporary_alias;
    size_t fname_len;
    size_t alias_len;
    size_t ext_len;
    char *fname;
    char *alias;
    char *ext;
    void *manifest;
    void *mounted_dirs;
    void *virtual_dirs;
    void *fp;
    php_uint32 sig_flags;
    char *signature;
    size_t sig_len;
};

struct _phar_entry_info {
    int is_tar;
    int is_crc_checked;
    int is_dir;
    int is_persistent;
    int tar_type;
    int fp_type;
    int flags;
    size_t filename_len;
    size_t uncompressed_filesize;
    size_t compressed_filesize;
    size_t offset;
    size_t offset_abs;
    size_t manifest_pos;
    time_t timestamp;
    char *filename;
    char *link;
    phar_archive_data *phar;
};

struct _tar_header {
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
};

struct _old_tar_header {
    char name[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char checksum[8];
    char linkflag;
    char linkname[100];
};

typedef struct _php_stream php_stream;

void *pecalloc(size_t nmemb, size_t size, int persistent);
void *pemalloc(size_t size, int persistent);
char *pestrndup(const char *s, size_t length, int persistent);
void pefree(void *ptr, int persistent);
void *zend_hash_init(void *ht, uint nSize, uint (*pHashFunction)(const void *), void (*pDestructor)(void *), zend_bool persistent);
int zend_hash_add(void *ht, const char *arKey, uint nKeyLength, void *pData, uint nDataSize, void **pDest);
int zend_hash_exists(void *ht, const char *arKey, uint nKeyLength);
int zend_hash_find(void *ht, const char *arKey, uint nKeyLength, void **pData);
void zend_hash_del(void *ht, const char *arKey, uint nKeyLength);
uint zend_get_hash_value(const void *arKey);
void destroy_phar_manifest_entry(void *pDest);
void phar_destroy_phar_data(phar_archive_data *phar TSRMLS_DC);
int phar_verify_signature(php_stream *fp, off_t end_of_phar, int sig_type, char *sig, int sig_len, char *fname, char **signature, size_t *signature_length, char **error TSRMLS_DC);
int phar_tar_process_metadata(phar_entry_info *entry, php_stream *fp TSRMLS_DC);
int phar_validate_alias(char *alias, int alias_len);
void phar_add_virtual_dirs(phar_archive_data *phar, char *filename, int filename_len TSRMLS_DC);
void phar_set_inode(phar_entry_info *entry TSRMLS_DC);
int phar_free_alias(phar_archive_data *phar, char *alias, int alias_len TSRMLS_DC);
void phar_request_initialize();
void phar_unixify_path_separators(char *fname, int fname_len);
php_uint32 phar_tar_number(char *buf, int len);
php_uint32 phar_tar_checksum(char *buf, int len);
off_t php_stream_tell(php_stream *stream);
size_t php_stream_read(php_stream *stream, char *buf, size_t count);
int php_stream_seek(php_stream *stream, off_t offset, int whence);
int php_stream_close(php_stream *stream);
char *spprintf(char **message, size_t max_len, const char *format, ...);
char *estrdup(const char *s);
void efree(void *ptr);