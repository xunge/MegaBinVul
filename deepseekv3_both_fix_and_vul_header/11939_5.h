#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <stdint.h>

#define ARCHIVE_OK 0
#define ARCHIVE_WARN 1
#define ARCHIVE_FATAL 2
#define ARCHIVE_ERRNO_FILE_FORMAT 3

#define FHD_SOLID 0x0001
#define FHD_PASSWORD 0x0004
#define FHD_LARGE 0x0100
#define FHD_UNICODE 0x0200
#define FHD_SALT 0x0400
#define FHD_EXTTIME 0x1000

#define NEWSUB_HEAD 0x7a

#define OS_MSDOS 0
#define OS_OS2 1
#define OS_WIN32 2
#define OS_UNIX 3
#define OS_MAC_OS 4
#define OS_BEOS 5

#define FILE_ATTRIBUTE_DIRECTORY 0x10
#define AE_IFDIR 0040000
#define AE_IFREG 0100000
#define AE_IFMT 0170000
#define AE_IFLNK 0120000
#define S_IRUSR 0400
#define S_IWUSR 0200
#define S_IRGRP 0040
#define S_IROTH 0004
#define S_IXUSR 0100
#define S_IXGRP 0010
#define S_IXOTH 0001

#define UNP_BUFFER_SIZE 0x40000

struct archive {
    int archive;
};

struct archive_read {
    struct {
        void *data;
    } *format;
    struct {
        int64_t position;
    } *filter;
    struct archive archive;
};

struct archive_entry;
struct archive_string_conv;

struct rar_header {
    char crc[2];
    char type;
    char flags[2];
    char size[2];
};

struct rar_file_header {
    char pack_size[4];
    char unp_size[4];
    char host_os;
    char file_crc[4];
    char file_time[4];
    char unp_ver;
    char method;
    char name_size[2];
    char file_attr[4];
};

struct rar {
    void *opt_sconv;
    int init_default_conversion;
    void *sconv_default;
    unsigned file_flags;
    unsigned compression_method;
    int64_t packed_size;
    int64_t unp_size;
    time_t mtime;
    time_t ctime;
    time_t atime;
    time_t arctime;
    mode_t mode;
    char salt[8];
    int ansec;
    int cnsec;
    int mnsec;
    int arcnsec;
    unsigned file_crc;
    int has_encrypted_entries;
    size_t filename_allocated;
    char *filename;
    char *filename_save;
    size_t filename_save_size;
    int filename_must_match;
    void *sconv_utf16be;
    void *sconv_utf8;
    int64_t bytes_remaining;
    int cursor;
    int nodes;
    struct rar_dbo *dbo;
    int64_t offset;
    int64_t offset_seek;
    size_t dictionary_size;
    int64_t offset_outgoing;
    struct {
        unsigned cache_avail;
        unsigned avail_in;
    } br;
    int crc_calculated;
    int entry_eof;
    int valid;
    int is_ppmd_block;
    int start_new_table;
    unsigned char *unp_buffer;
    size_t unp_offset;
    size_t unp_buffer_size;
    unsigned char lengthtable[0x400];
    void *ppmd7_context;
    int ppmd_valid;
    int ppmd_eod;
    int bytes_uncopied;
    int bytes_unconsumed;
    struct {
        int position;
    } lzss;
};

struct rar_dbo {
    int64_t header_size;
    int64_t start_offset;
    int64_t end_offset;
};

struct archive_ppmd7_functions {
    void (*Ppmd7_Free)(void *ppmd7_context);
};

static struct archive_ppmd7_functions __archive_ppmd7_functions;

static unsigned long crc32(unsigned long crc, const unsigned char *buf, unsigned len) {
    return 0;
}

static time_t get_time(int ttime) {
    return 0;
}

static int read_exttime(const char *p, struct rar *rar, const char *endp) {
    return 0;
}

static int read_symlink_stored(struct archive_read *a, struct archive_entry *entry, struct archive_string_conv *sconv) {
    return 0;
}

static void * __archive_read_ahead(struct archive_read *a, size_t size, ssize_t *avail) {
    return NULL;
}

static void __archive_read_consume(struct archive_read *a, size_t size) {
}

static uint16_t archive_le16dec(const void *p) {
    return 0;
}

static uint32_t archive_le32dec(const void *p) {
    return 0;
}

static uint64_t archive_le64dec(const void *p) {
    return 0;
}

static void archive_set_error(struct archive *a, int error, const char *fmt, ...) {
}

static void archive_entry_set_is_data_encrypted(struct archive_entry *entry, int is_encrypted) {
}

static void archive_entry_set_mtime(struct archive_entry *entry, time_t mtime, long mtime_nsec) {
}

static void archive_entry_set_ctime(struct archive_entry *entry, time_t ctime, long ctime_nsec) {
}

static void archive_entry_set_atime(struct archive_entry *entry, time_t atime, long atime_nsec) {
}

static void archive_entry_set_size(struct archive_entry *entry, int64_t size) {
}

static void archive_entry_set_mode(struct archive_entry *entry, mode_t mode) {
}

static int archive_entry_copy_pathname_l(struct archive_entry *entry, const char *pathname, size_t len, struct archive_string_conv *sc) {
    return 0;
}

static struct archive_string_conv *archive_string_default_conversion_for_read(struct archive *a) {
    return NULL;
}

static struct archive_string_conv *archive_string_conversion_from_charset(struct archive *a, const char *charset, int best_effort) {
    return NULL;
}

static const char *archive_string_conversion_charset_name(struct archive_string_conv *sc) {
    return NULL;
}