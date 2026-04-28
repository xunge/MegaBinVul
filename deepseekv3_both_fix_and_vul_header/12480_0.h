#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct new_cpio_header {
    unsigned long c_hdr[13];
    size_t c_namesize;
    char *c_name;
    off_t c_filesize;
};

extern char *progname;
extern void *xmalloc(size_t size);
extern void tape_buffered_read(void *buf, int fd, size_t count);
extern void tape_skip_padding(int fd, size_t bytes);