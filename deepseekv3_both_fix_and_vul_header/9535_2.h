#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFSIZE 8192
#define FOPEN_WB "wb"

typedef long bfd_size_type;
typedef long file_ptr;
typedef struct bfd bfd;

extern int verbose;
extern int preserve_dates;
extern FILE *output_file;
extern char *output_filename;
extern void *xmalloc(size_t size);
extern void xexit(int status);
extern void fatal(const char *format, ...);
extern void set_times(const char *filename, const struct stat *buf);
extern int bfd_stat_arch_elt(bfd *abfd, struct stat *buf);
extern const char *bfd_get_filename(bfd *abfd);
extern bfd *bfd_my_archive(bfd *abfd);
extern int bfd_seek(bfd *abfd, file_ptr offset, int whence);
extern bfd_size_type bfd_bread(void *ptr, bfd_size_type size, bfd *abfd);