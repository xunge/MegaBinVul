#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef struct _phar {
    char *fname;
    FILE *fp;
    FILE *ufp;
} phar;

typedef struct _phar_entry_info {
    char *filename;
    size_t filename_len;
    uint32_t flags;
    uint32_t uncompressed_filesize;
    time_t timestamp;
    char *link;
    char tar_type;
    uint32_t crc32;
    size_t header_offset;
    phar *phar;
    FILE *fp;
    int fp_type;
    int fp_refcount;
    int is_modified;
    int is_mounted;
    int is_deleted;
    size_t offset;
    size_t offset_abs;
} phar_entry_info;

typedef struct _phar_pass_tar_info {
    FILE *new;
    char **error;
    int free_fp;
    int free_ufp;
} phar_pass_tar_info;

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

#define ZEND_HASH_APPLY_KEEP 0
#define ZEND_HASH_APPLY_REMOVE 1
#define ZEND_HASH_APPLY_STOP 2

#define PHAR_ENT_PERM_MASK 0777
#define PHAR_FP 1
#define PHAR_UFP 2
#define PHAR_MOD 3

#define SUCCESS 0
#define FAILURE -1

static int phar_add_virtual_dirs(phar *phar, char *filename, size_t filename_len) { return 0; }
static int phar_tar_octal(char *buf, size_t val, size_t len) { return 0; }
static uint32_t phar_tar_checksum(char *buf, size_t len) { return 0; }
static long php_stream_tell(FILE *stream) { return 0; }
static size_t php_stream_write(FILE *stream, char *buf, size_t len) { return 0; }
static int phar_open_entry_fp(phar_entry_info *entry, char **error, int mode) { return 0; }
static int phar_seek_efp(phar_entry_info *entry, long offset, int whence, int mode, int set) { return 0; }
static FILE *phar_get_efp(phar_entry_info *entry, int mode) { return NULL; }
static int php_stream_copy_to_stream_ex(FILE *src, FILE *dest, size_t len, size_t *written) { return 0; }
static void php_stream_close(FILE *stream) {}
static int spprintf(char **str, size_t max_len, const char *format, ...) { return 0; }