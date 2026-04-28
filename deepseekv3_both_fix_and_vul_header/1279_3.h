#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct archive {
    int dummy;
};

struct archive_write_disk {
    struct archive archive;
    struct fixup_entry *fixup_list;
};

struct fixup_entry {
    struct fixup_entry *next;
    int fixup;
    int mode;
    char *name;
};

void archive_set_error(struct archive *, int, const char *);