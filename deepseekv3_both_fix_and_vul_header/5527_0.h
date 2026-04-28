#include <sys/types.h>
#include <errno.h>

#define ARCHIVE_OK 0
#define ARCHIVE_FAILED (-1)
#define ARCHIVE_ERRNO_MISC EINVAL
#define ARCHIVE_EXTRACT_SECURE_NOABSOLUTEPATHS (1 << 0)
#define ARCHIVE_EXTRACT_SECURE_NODOTDOT (1 << 1)

struct archive {
    int error;
};

struct archive_write_disk {
    struct archive archive;
    char *name;
    int flags;
};

void archive_set_error(struct archive *, int, const char *);