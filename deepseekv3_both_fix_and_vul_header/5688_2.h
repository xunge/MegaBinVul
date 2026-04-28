#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>

typedef unsigned char zend_bool;
typedef intptr_t php_int_t;
typedef uintptr_t php_uint_t;
typedef php_uint_t php_uint32;
typedef uint16_t php_uint16;

typedef struct _php_stream {
    void *opaque;
} php_stream;

typedef struct _phar_entry_info {
    char *filename;
    uint32_t filename_len;
    uint32_t uncompressed_filesize;
    uint32_t compressed_filesize;
    uint32_t timestamp;
    uint32_t crc32;
    uint32_t flags;
    uint32_t metadata_len;
    void *metadata;
    long offset;
    long offset_abs;
    uint32_t manifest_pos;
    zend_bool is_persistent;
    zend_bool is_dir;
    zend_bool is_crc_checked;
    struct _phar_archive_data *phar;
    int fp_type;
} phar_entry_info;

typedef struct _phar_archive_data {
    char *fname;
    uint32_t fname_len;
    char *alias;
    uint32_t alias_len;
    char *ext;
    uint32_t ext_len;
    char version[16];
    uint32_t flags;
    uint32_t sig_flags;
    uint32_t sig_len;
    char *signature;
    long halt_offset;
    long internal_file_start;
    uint32_t min_timestamp;
    uint32_t max_timestamp;
    uint32_t metadata_len;
    void *metadata;
    void *manifest;
    void *mounted_dirs;
    void *virtual_dirs;
    php_stream *fp;
    zend_bool is_persistent;
    zend_bool is_temporary_alias;
} phar_archive_data;

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C
#define SEEK_SET 0
#define EOF (-1)
#define FAILURE (-1)
#define SUCCESS 0
#define PHAR_FP 1

#define PHAR_G(v) (phar_globals.v)
#define PHAR_GET_32(p, var) \
    do { \
        var = (php_uint32) (((unsigned char*)p)[0] << 24 | ((unsigned char*)p)[1] << 16 | ((unsigned char*)p)[2] << 8 | ((unsigned char*)p)[3]); \
        p += 4; \
    } while (0)

#define PHAR_HDR_SIGNATURE (1<<0)
#define PHAR_HDR_COMPRESSION_MASK (0xf000)
#define PHAR_FILE_COMPRESSION_MASK (0xf000)
#define PHAR_ENT_COMPRESSION_MASK (0xf000)
#define PHAR_ENT_COMPRESSED_GZ (1<<12)
#define PHAR_ENT_COMPRESSED_BZ2 (2<<12)
#define PHAR_ENT_PERM_DEF_DIR (1<<13)
#define PHAR_SIG_OPENSSL (1<<0)
#define PHAR_SIG_SHA1 (1<<1)
#define PHAR_SIG_SHA256 (1<<2)
#define PHAR_SIG_SHA512 (1<<3)
#define PHAR_SIG_MD5 (1<<4)
#define PHAR_API_VER_MASK 0xFFF0
#define PHAR_API_MIN_READ 0x0100
#define PHAR_API_MIN_DIR 0x0100

struct _phar_globals {
    int persist;
    int has_zlib;
    int has_bz2;
    int require_hash;
    struct {
        void *phar_alias_map;
        void *phar_fname_map;
    } *GLOBALS;
} phar_globals;

#define PHAR_GLOBALS phar_globals.GLOBALS
#define MAPPHAR_ALLOC_FAIL(msg)
#define MAPPHAR_FAIL(msg)
#define PHAR_HASH_OK 1

static void *emalloc(size_t size) { return malloc(size); }
static void efree(void *ptr) { free(ptr); }
static void *pecalloc(size_t nmemb, size_t size, int persistent) { return calloc(nmemb, size); }
static char *pestrndup(const char *s, size_t len, int persistent) { return strndup(s, len); }
static void pefree(void *ptr, int persistent) { free(ptr); }
static int php_stream_seek(php_stream *stream, long offset, int whence) { return 0; }
static size_t php_stream_read(php_stream *stream, char *buf, size_t count) { return 0; }
static int php_stream_getc(php_stream *stream) { return 0; }
static int php_stream_close(php_stream *stream) { return 0; }
static long php_stream_tell(php_stream *stream) { return 0; }
static int phar_verify_signature(php_stream *fp, size_t end_of_phar, int sig_type, char *sig, size_t sig_len, char *fname, char **signature, int *sig_len_out, char **error) { return 0; }
static int phar_parse_metadata(char **buffer, void **metadata, uint32_t metadata_len) { return 0; }
static void zend_hash_init(void *ht, uint32_t nSize, void *pHashFunction, void *pDestructor, zend_bool persistent) {}
static void zend_hash_add(void *ht, const char *arKey, uint32_t nKeyLength, void *pData, uint32_t nDataSize, void **pDest) {}
static int zend_hash_find(void *ht, const char *arKey, uint32_t nKeyLength, void **pData) { return 0; }
static void phar_add_virtual_dirs(phar_archive_data *phar, char *filename, uint32_t filename_len) {}
static void phar_set_inode(phar_entry_info *entry) {}
static int phar_validate_alias(char *alias, uint32_t alias_len) { return 0; }
static int phar_free_alias(phar_archive_data *phar, char *alias, uint32_t alias_len) { return 0; }
static void phar_request_initialize(void) {}
static int spprintf(char **message, size_t max_len, const char *format, ...) { return 0; }
static void zval_ptr_dtor(void *zval_ptr) {}
static void *zend_get_hash_value(const char *arKey, uint32_t nKeyLength) { return NULL; }
static void destroy_phar_manifest_entry(void *pDest) {}