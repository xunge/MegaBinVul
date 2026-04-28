#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define ARCHIVE_WRITE_DISK_MAGIC 0xbadb0c5
#define ARCHIVE_STATE_HEADER 1
#define ARCHIVE_STATE_DATA 2

#define TODO_TIMES 0x0001
#define TODO_MODE_BASE 0x0002
#define TODO_ACLS 0x0004
#define TODO_FFLAGS 0x0008
#define TODO_MAC_METADATA 0x0010

#ifndef O_BINARY
#define O_BINARY 0
#endif

struct archive {
    int magic;
    int state;
};

struct archive_write_disk {
    struct archive archive;
    struct fixup_entry *fixup_list;
    void *pst;
};

struct archive_acl {
    int dummy;
};

struct fixup_entry {
    char *name;
    mode_t mode;
    time_t atime;
    long atime_nanos;
    time_t birthtime;
    long birthtime_nanos;
    time_t mtime;
    long mtime_nanos;
    time_t ctime;
    long ctime_nanos;
    unsigned int fflags_set;
    void *mac_metadata;
    size_t mac_metadata_size;
    struct archive_acl acl;
    int fixup;
    struct fixup_entry *next;
};

int archive_check_magic(struct archive *, int, int, const char *);
int _archive_write_disk_finish_entry(struct archive *);
struct fixup_entry *sort_dir_list(struct fixup_entry *);
void set_times(struct archive_write_disk *, int, mode_t, const char *,
    time_t, long, time_t, long, time_t, long, time_t, long);
int archive_write_disk_set_acls(struct archive *, int, const char *,
    struct archive_acl *, mode_t);
int set_fflags_platform(struct archive_write_disk *, int, const char *,
    mode_t, unsigned int, int);
int set_mac_metadata(struct archive_write_disk *, const char *, void *, size_t);
void archive_acl_clear(struct archive_acl *);