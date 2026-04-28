#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/mount.h>

#define PATH_MAX _POSIX_PATH_MAX
#define SBINDIR "/sbin"
#define WARN(fmt, ...) 
#define INFO(fmt, ...) 
#define SYSERROR(fmt, ...) 

struct lxc_conf {
    struct {
        char *mount;
    } rootfs;
};

char *choose_init(char *mount);
int file_exists(const char *path);