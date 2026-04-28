#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct dump_dir {
    char *dd_dirname;
};

char *concat_path_file(const char *path, const char *filename);
void perror_msg(const char *fmt, ...);