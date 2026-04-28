#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>

#define ARCHIVE_OK 0
#define ARCHIVE_WARN 1
#define ARCHIVE_ERRNO_FILE_FORMAT (-1)

#define MTREE_HAS_NOCHANGE 0x01
#define MTREE_HAS_OPTIONAL 0x02
#define MTREE_HAS_DEVICE 0x04
#define MTREE_HAS_FFLAGS 0x08
#define MTREE_HAS_GID 0x10
#define MTREE_HAS_GNAME 0x20
#define MTREE_HAS_PERM 0x40
#define MTREE_HAS_NLINK 0x80
#define MTREE_HAS_MTIME 0x100
#define MTREE_HAS_TYPE 0x200
#define MTREE_HAS_UID 0x400
#define MTREE_HAS_UNAME 0x800

#define AE_IFBLK S_IFBLK
#define AE_IFCHR S_IFCHR
#define AE_IFDIR S_IFDIR
#define AE_IFIFO S_IFIFO
#define AE_IFREG S_IFREG
#define AE_IFLNK S_IFLNK

struct archive_read {
    struct {
        int dummy;
    } archive;
};

struct archive_entry {
    int dummy;
};

struct mtree {
    char *contents_name;
};

struct mtree_option {
    char *value;
};

static void archive_set_error(void *archive, int error, const char *fmt, ...) {}
static int parse_device(dev_t *dev, void *archive, const char *val) { return ARCHIVE_OK; }
static void parse_escapes(char *val, const char *dummy) {}
static long mtree_atol8(char **p) { return 0; }
static int64_t mtree_atol10(char **p) { return 0; }
static void archive_strcpy(char **dest, const char *src) {}
static int64_t get_time_t_max(void) { return INT64_MAX; }
static int64_t get_time_t_min(void) { return INT64_MIN; }
static void archive_entry_set_rdev(struct archive_entry *entry, dev_t dev) {}
static void archive_entry_copy_fflags_text(struct archive_entry *entry, const char *val) {}
static void archive_entry_set_gid(struct archive_entry *entry, int64_t gid) {}
static void archive_entry_copy_gname(struct archive_entry *entry, const char *val) {}
static void archive_entry_set_ino(struct archive_entry *entry, int64_t ino) {}
static void archive_entry_copy_symlink(struct archive_entry *entry, const char *val) {}
static void archive_entry_set_perm(struct archive_entry *entry, mode_t perm) {}
static void archive_entry_set_nlink(struct archive_entry *entry, unsigned int nlink) {}
static void archive_entry_set_dev(struct archive_entry *entry, dev_t dev) {}
static void archive_entry_set_size(struct archive_entry *entry, int64_t size) {}
static void archive_entry_set_mtime(struct archive_entry *entry, time_t mtime, long ns) {}
static void archive_entry_set_filetype(struct archive_entry *entry, mode_t type) {}
static void archive_entry_set_uid(struct archive_entry *entry, int64_t uid) {}
static void archive_entry_copy_uname(struct archive_entry *entry, const char *val) {}