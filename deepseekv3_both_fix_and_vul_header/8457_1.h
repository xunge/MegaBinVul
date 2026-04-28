#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DR_length_offset 0
#define DR_name_len_offset 32
#define DR_extent_offset 2
#define DR_size_offset 10
#define DR_size_size 4
#define DR_date_offset 18
#define DR_name_offset 33
#define DR_flags_offset 25
#define DR_volume_sequence_number_offset 28
#define DR_file_unit_size_offset 26
#define DR_interleave_offset 27
#define DR_ext_attr_length_offset 24

#define AE_IFDIR 0040000
#define AE_IFREG 0100000
#define AE_IFLNK 0120000
#define AE_IFMT 0170000

#define ARCHIVE_OK 0
#define ARCHIVE_ERRNO_MISC (-1)
#define ARCHIVE_ERRNO_FILE_FORMAT (-2)
#define ENOMEM 12

struct archive_read {
    struct {
        struct {
            void *data;
        } *format;
        struct archive *archive;
    };
};

struct archive {
    int dummy;
};

struct iso9660 {
    void *format;
    size_t logical_block_size;
    uint32_t volume_block;
    int seenJoliet;
    int opt_support_rockridge;
    int seenSUSP;
    int suspOffset;
    int seenRockridge;
    struct file_info *rr_moved;
};

struct file_info {
    struct file_info *parent;
    uint64_t offset;
    uint64_t size;
    time_t mtime;
    time_t ctime;
    time_t atime;
    struct {
        void *first;
        void **last;
    } rede_files;
    char *utf16be_name;
    size_t utf16be_bytes;
    struct {
        char *s;
    } name;
    mode_t mode;
    int multi_extent;
    int64_t number;
    int name_continues;
    int symlink_continues;
    int nlinks;
    int subdirs;
    int rr_moved;
    int rr_moved_has_re_only;
    int re;
    int re_descendant;
    int cl_offset;
};

static uint32_t archive_le32dec(const unsigned char *);
static uint64_t toi(const unsigned char *, int);
static time_t isodate7(const unsigned char *);
static void archive_strncpy(struct { char *s; } *, const char *, size_t);
static int parse_rockridge(struct archive_read *, struct file_info *, const unsigned char *, const unsigned char *);
static void register_file(struct iso9660 *, struct file_info *);
static void archive_set_error(struct archive *, int, const char *);