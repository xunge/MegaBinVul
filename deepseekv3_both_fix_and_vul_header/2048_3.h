#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>

typedef uint32_t php_uint32;
typedef int zend_bool;

struct _php_stream;
typedef struct _php_stream php_stream;

typedef struct _phar_entry_info {
    int is_tar;
    int is_crc_checked;
    struct _phar_archive_data *phar;
    char *filename;
    size_t filename_len;
    php_uint32 uncompressed_filesize;
    php_uint32 compressed_filesize;
    char tar_type;
    off_t offset;
    off_t offset_abs;
    int fp_type;
    php_uint32 flags;
    php_uint32 timestamp;
    int is_persistent;
    int is_dir;
    char *link;
    int manifest_pos;
} phar_entry_info;

typedef struct _phar_archive_data {
    int is_persistent;
    int is_tar;
    int is_data;
    php_uint32 flags;
    char *fname;
    size_t fname_len;
    char *alias;
    size_t alias_len;
    int is_temporary_alias;
    php_stream *fp;
    char *ext;
    size_t ext_len;
    php_uint32 sig_flags;
    char *signature;
    int sig_len;
    void *manifest;
    void *mounted_dirs;
    void *virtual_dirs;
} phar_archive_data;

typedef struct _tar_header {
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
    char padding[12];
} tar_header;

typedef struct _old_tar_header {
    char name[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char checksum[8];
    char linkflag;
    char linkname[100];
    char padding[255];
} old_tar_header;

typedef struct _phar_globals {
    void *phar_fname_map;
    void *phar_alias_map;
    int require_hash;
} phar_globals;

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C

#define PHAR_G(v) (v)
#define PHAR_ENT_PERM_MASK 0777
#define PHAR_FP 1
#define TAR_FILE '0'
#define TAR_LINK '1'
#define TAR_SYMLINK '2'
#define TAR_DIR '5'
#define WORDS_BIGENDIAN 0

#define FAILURE -1
#define SUCCESS 0

int persist = 0;
phar_globals *PHAR_GLOBALS = NULL;
int require_hash = 0;

void php_stream_seek(php_stream *stream, off_t offset, int whence);
off_t php_stream_tell(php_stream *stream);
size_t php_stream_read(php_stream *stream, char *buf, size_t count);
void php_stream_close(php_stream *stream);

void *pecalloc(size_t nmemb, size_t size, int persistent);
void *pemalloc(size_t size, int persistent);
char *pestrndup(const char *s, size_t length, int persistent);
void pefree(void *ptr, int persistent);
void efree(void *ptr);
char *estrdup(const char *s);
int spprintf(char **str, size_t max_len, const char *format, ...);

void zend_hash_init(void *ht, uint nSize, uint (*pHashFunction)(const char *arKey, uint nKeyLength), void (*pDestructor)(void *pData), zend_bool persistent);
int zend_hash_add(void *ht, const char *arKey, uint nKeyLength, void *pData, uint nDataSize, void **pDest);
int zend_hash_exists(void *ht, const char *arKey, uint nKeyLength);
int zend_hash_find(void *ht, const char *arKey, uint nKeyLength, void **pData);
int zend_hash_del(void *ht, const char *arKey, uint nKeyLength);
uint zend_get_hash_value(const char *arKey, uint nKeyLength);

void phar_destroy_phar_data(phar_archive_data *phar TSRMLS_DC);
void phar_add_virtual_dirs(phar_archive_data *phar, char *filename, int filename_len TSRMLS_DC);
void phar_set_inode(phar_entry_info *entry TSRMLS_DC);
int phar_tar_process_metadata(phar_entry_info *entry, php_stream *fp TSRMLS_DC);
int phar_verify_signature(php_stream *fp, off_t end_of_phar, int sig_type, char *sig, int sig_len, char *fname, char **signature, int *signature_length, char **error TSRMLS_DC);
int phar_free_alias(phar_archive_data *phar, char *alias, int alias_len TSRMLS_DC);
int phar_validate_alias(char *alias, int alias_len);
void phar_unixify_path_separators(char *path, int path_len);
void phar_request_initialize(TSRMLS_D);

php_uint32 phar_tar_number(char *buf, int len);
php_uint32 phar_tar_checksum(char *buf, int len);
void destroy_phar_manifest_entry(void *pData);

#ifndef S_ISDIR
#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#endif