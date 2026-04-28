#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

struct new_cpio_header {
    unsigned int c_filesize;
    char *c_name;
    uid_t c_uid;
    gid_t c_gid;
};

extern char *progname;
extern void *xmalloc(size_t size);
extern void tape_buffered_read(char *buf, int fd, size_t count);
extern void tape_skip_padding(int fd, size_t count);