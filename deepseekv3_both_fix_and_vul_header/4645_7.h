#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

typedef uint32_t php_uint32;
typedef struct _php_stream php_stream;
typedef struct _phar_archive_data phar_archive_data;
typedef struct _phar_entry_info phar_entry_info;
typedef struct _zend_hash_table {
    int dummy;
} HashTable;
typedef unsigned char zend_bool;

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C
#define PHAR_G(v) (v)
#define PHAR_ENT_PERM_MASK 0777
#define WORDS_BIGENDIAN 0
#define FAILURE -1
#define SUCCESS 0
#define TAR_GLOBAL_HDR 'g'
#define TAR_FILE_HDR 'x'
#define TAR_FILE '\0'
#define TAR_DIR '5'
#define TAR_LINK '1'
#define TAR_SYMLINK '2'
#define TAR_LINKNAME 'K'
#define TAR_LONGLINK 'L'
#define PHAR_FP 1
#define UINT_MAX 4294967295U

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
    char pad[255];
} old_tar_header;

struct _phar_archive_data {
    int is_persistent;
    int is_tar;
    int is_data;
    int flags;
    int is_temporary_alias;
    size_t fname_len;
    size_t alias_len;
    size_t sig_len;
    php_uint32 sig_flags;
    char *fname;
    char *alias;
    char *signature;
    char *ext;
    size_t ext_len;
    php_stream *fp;
    HashTable manifest;
    HashTable mounted_dirs;
    HashTable virtual_dirs;
};

struct _phar_entry_info {
    int is_tar;
    int is_crc_checked;
    int is_dir;
    int is_persistent;
    int fp_type;
    int flags;
    int tar_type;
    size_t filename_len;
    size_t uncompressed_filesize;
    size_t compressed_filesize;
    size_t offset;
    size_t offset_abs;
    time_t timestamp;
    char *filename;
    char *link;
    phar_archive_data *phar;
    unsigned int manifest_pos;
};

#ifndef S_ISDIR
#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#endif

#define zend_hash_init(ht, nSize, pHashFunction, pDestructor, persistent) (0)
#define zend_hash_add(ht, str, len, pData, nDataSize, pDest) (0)
#define zend_hash_exists(ht, str, len) (0)
#define zend_hash_find(ht, str, len, pData) (0)
#define zend_hash_del(ht, str, len) (0)
#define zend_get_hash_value(str, len) (0)
#define spprintf(buf, max_len, format, ...) (0)
#define pecalloc(n, size, persistent) calloc(n, size)
#define pemalloc(size, persistent) malloc(size)
#define pefree(ptr, persistent) free(ptr)
#define pestrndup(str, len, persistent) strndup(str, len)
#define phar_tar_number(str, len) (0)
#define phar_tar_checksum(buf, len) (0)
#define phar_add_virtual_dirs(phar, filename, len) (0)
#define phar_set_inode(entry) (0)
#define phar_destroy_phar_data(phar) (0)
#define phar_verify_signature(fp, offset, flags, sig, sig_len, fname, signature, sig_len_out, error) (0)
#define phar_tar_process_metadata(entry, fp) (0)
#define phar_validate_alias(alias, alias_len) (1)
#define phar_free_alias(phar, alias, alias_len) (0)
#define phar_unixify_path_separators(fname, len) (0)
#define efree(ptr) free(ptr)
#define estrndup(str, len) strndup(str, len)
#define PHAR_GLOBALS ((void*)0)
#define destroy_phar_manifest_entry NULL

static int persist = 0;
static int require_hash = 0;

static int php_stream_seek(php_stream *fp, long offset, int whence) { return 0; }
static long php_stream_tell(php_stream *fp) { return 0; }
static size_t php_stream_read(php_stream *fp, void *buf, size_t count) { return 0; }
static int php_stream_close(php_stream *fp) { return 0; }

static void phar_request_initialize(void) {}