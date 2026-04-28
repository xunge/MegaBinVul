#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mount.h>

#define MAXPATHLEN 4096

struct lxc_rootfs {
    char *path;
    char *mount;
};

struct lxc_devs {
    char *name;
    mode_t mode;
    unsigned int maj;
    unsigned int min;
};

static struct lxc_devs lxc_devs[] = {
    {"null", S_IFCHR | 0666, 1, 3},
    {"zero", S_IFCHR | 0666, 1, 5},
    {"full", S_IFCHR | 0666, 1, 7},
    {"random", S_IFCHR | 0666, 1, 8},
    {"urandom", S_IFCHR | 0666, 1, 9},
    {"tty", S_IFCHR | 0666, 5, 0},
    {NULL, 0, 0, 0}
};

extern int dir_exists(const char *path);
#define INFO(fmt, ...) 
#define ERROR(fmt, ...) 
#define SYSERROR(fmt, ...)