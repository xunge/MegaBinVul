#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>

typedef struct _phar_archive_data {
    int is_persistent;
    size_t metadata_len;
    void *metadata;
    void *manifest;
    void *mounted_dirs;
    void *virtual_dirs;
    char *fname;
    int fname_len;
    char *version;
    long internal_file_start;
    long halt_offset;
    unsigned int flags;
    char *ext;
    int ext_len;
    char *alias;
    int alias_len;
    unsigned int sig_flags;
    void *fp;
    int sig_len;
    char *signature;
    int is_temporary_alias;
    long min_timestamp;
    long max_timestamp;
} phar_archive_data;

typedef struct _phar_entry_info {
    phar_archive_data *phar;
    int fp_type;
    int is_persistent;
    int manifest_pos;
    unsigned int filename_len;
    char *filename;
    int is_dir;
    unsigned int uncompressed_filesize;
    unsigned int timestamp;
    unsigned int compressed_filesize;
    unsigned int crc32;
    unsigned int flags;
    size_t metadata_len;
    void *metadata;
    long offset;
    long offset_abs;
    int is_crc_checked;
} phar_entry_info;

typedef struct _php_stream {
    // Stream implementation details would go here
} php_stream;

#define PHAR_G(v) (phar_globals.v)
#define PHAR_GLOBALS (&phar_globals)
#define PHAR_HDR_COMPRESSION_MASK 0x0000F000
#define PHAR_FILE_COMPRESSION_MASK 0x0000000F
#define PHAR_HDR_SIGNATURE 0x00010000
#define PHAR_ENT_COMPRESSION_MASK 0x0000000F
#define PHAR_ENT_COMPRESSED_GZ 1
#define PHAR_ENT_COMPRESSED_BZ2 2
#define PHAR_ENT_PERM_DEF_DIR 0x00000010
#define PHAR_SIG_OPENSSL 0x0001
#define PHAR_SIG_SHA512 0x0002
#define PHAR_SIG_SHA256 0x0003
#define PHAR_SIG_SHA1 0x0004
#define PHAR_SIG_MD5 0x0005
#define PHAR_API_VER_MASK 0xFFF0
#define PHAR_API_MIN_READ 0x0100
#define PHAR_API_MIN_DIR 0x0100
#define PHAR_HASH_OK 1
#define PHAR_FP 1

#define SUCCESS 0
#define FAILURE -1
#define MAPPHAR_ALLOC_FAIL(msg)
#define MAPPHAR_FAIL(msg)

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C

typedef int zend_bool;
typedef unsigned long php_uint32;
typedef unsigned short php_uint16;

struct _phar_globals {
    int persist;
    int has_zlib;
    int has_bz2;
    int require_hash;
    void *phar_alias_map;
    void *phar_fname_map;
} phar_globals;

void *emalloc(size_t size);
void efree(void *ptr);
void *pecalloc(size_t nmemb, size_t size, int persist);
char *pestrndup(const char *s, size_t length, int persist);
void pefree(void *ptr, int persist);
int phar_verify_signature(php_stream *fp, size_t end_of_phar, int sig_type, char *sig, int sig_len, char *fname, char **signature, int *sig_len_out, char **error TSRMLS_DC);
int phar_parse_metadata(char **buffer, void **metadata, int len TSRMLS_DC);
void phar_set_inode(phar_entry_info *entry TSRMLS_DC);
int phar_free_alias(phar_archive_data *fd, char *alias, int alias_len TSRMLS_DC);
int phar_validate_alias(char *alias, int alias_len);
void phar_add_virtual_dirs(phar_archive_data *mydata, char *buffer, int filename_len TSRMLS_DC);
void phar_request_initialize(TSRMLS_D);
void phar_unixify_path_separators(char *fname, int fname_len);
void zend_hash_init(void *hash, int size, void *hash_func, void *destructor, zend_bool persistent);
int zend_hash_add(void *hash, char *key, int key_len, void *data, int data_size, void **dest);
int zend_hash_find(void *hash, char *key, int key_len, void **data);
void zend_get_hash_value(void *key, int key_len);
void destroy_phar_manifest_entry(void *pDest);
void zval_ptr_dtor(void *zval_ptr);
int php_stream_seek(php_stream *stream, off_t offset, int whence);
int php_stream_read(php_stream *stream, char *buf, size_t count);
int php_stream_getc(php_stream *stream);
void php_stream_close(php_stream *stream);
off_t php_stream_tell(php_stream *stream);
int spprintf(char **message, size_t max_len, const char *format, ...);