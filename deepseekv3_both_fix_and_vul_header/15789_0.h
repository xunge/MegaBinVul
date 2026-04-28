#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

struct dump_dir {
    char *dd_dirname;
    int locked;
};

extern void error_msg_and_die(const char *fmt, ...);
extern void perror_msg(const char *fmt, ...);
extern char *concat_path_file(const char *path, const char *filename);