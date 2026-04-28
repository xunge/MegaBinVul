#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

typedef uint32_t php_uint32;

typedef struct _php_stream php_stream;
typedef unsigned char zend_bool;

typedef struct _phar_entry_info {
    char *filename;
    size_t filename_len;
    uint32_t flags;
    uint32_t timestamp;
    uint32_t uncompressed_filesize;
    uint32_t compressed_filesize;
    uint32_t crc32;
    off_t offset;
    off_t offset_abs;
    char *link;
    unsigned char is_dir;
    unsigned char is_tar;
    unsigned char is_crc_checked;
    unsigned char is_persistent;
    unsigned char fp_type;
    unsigned char tar_type;
    unsigned char manifest_pos;
    struct _phar_archive_data *phar;
} phar_entry_info;

typedef struct _phar_archive_data {
    char *fname;
    size_t fname_len;
    char *alias;
    size_t alias_len;
    char *signature;
    size_t sig_len;
    uint32_t sig_flags;
    uint32_t flags;
    unsigned char is_tar;
    unsigned char is_data;
    unsigned char is_persistent;
    unsigned char is_temporary_alias;
    char *ext;
    size_t ext_len;
    php_stream *fp;
    void *manifest;
    void *mounted_dirs;
    void *virtual_dirs;
} phar_archive_data;

typedef struct _phar_globals {
    void *phar_fname_map;
    void *phar_alias_map;
} phar_globals;

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C
#define FAILURE (-1)
#define SUCCESS 0
#define PHAR_G(v) (0)
#define PHAR_ENT_PERM_MASK (0777)
#define PHAR_FP (1)
#define PHAR_GLOBALS ((phar_globals*)0)
#define WORDS_BIGENDIAN (0)

#define TAR_FILE ('\0')
#define TAR_LINK ('1')
#define TAR_SYMLINK ('2')
#define TAR_DIR ('5')
#define TAR_GLOBAL_HDR ('g')
#define TAR_FILE_HDR ('x')

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

void zend_hash_init(void*, size_t, void*, void*, int);
int zend_hash_add(void*, const char*, size_t, void*, size_t, void**);
int zend_hash_exists(void*, const char*, size_t);
int zend_hash_find(void*, const char*, size_t, void**);
int zend_hash_del(void*, const char*, size_t);
void* zend_get_hash_value(const char*, size_t);
void destroy_phar_manifest_entry(void*);
void* pecalloc(size_t, size_t, int);
void* pemalloc(size_t, int);
char* pestrndup(const char*, size_t, int);
void pefree(void*, int);
void phar_destroy_phar_data(phar_archive_data* TSRMLS_DC);
void phar_set_inode(phar_entry_info* TSRMLS_DC);
void phar_add_virtual_dirs(phar_archive_data*, const char*, size_t TSRMLS_DC);
int phar_tar_process_metadata(phar_entry_info*, php_stream* TSRMLS_DC);
int phar_verify_signature(php_stream*, off_t, uint32_t, const char*, size_t, const char*, char**, size_t*, char** TSRMLS_DC);
int phar_free_alias(phar_archive_data*, const char*, size_t TSRMLS_DC);
void phar_request_initialize(TSRMLS_D);
void phar_unixify_path_separators(char*, size_t);
int phar_validate_alias(const char*, size_t);
uint32_t phar_tar_number(const char*, size_t);
uint32_t phar_tar_checksum(const char*, size_t);
char* spprintf(char**, size_t, const char*, ...);
char* estrdup(const char*);
void efree(void*);
int php_stream_seek(php_stream*, off_t, int);
off_t php_stream_tell(php_stream*);
size_t php_stream_read(php_stream*, void*, size_t);
int php_stream_close(php_stream*);