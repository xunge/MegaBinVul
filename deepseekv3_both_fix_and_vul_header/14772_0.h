#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct lxc_rootfs {
    const char *path;
    const char *mount;
};

#define INFO(fmt, ...) 
#define WARN(fmt, ...) 
#define SYSERROR(fmt, ...) 

static bool dir_exists(const char *path);