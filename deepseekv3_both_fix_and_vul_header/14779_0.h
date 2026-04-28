#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <linux/limits.h>

struct lxc_rootfs {
    char *mount;
};

struct lxc_console {
    int master;
    char *name;
};

#define MAXPATHLEN PATH_MAX
#define F_OK 0
#define MS_BIND 4096

#define ERROR(fmt, ...) 
#define WARN(fmt, ...) 
#define INFO(fmt, ...) 
#define SYSERROR(fmt, ...)