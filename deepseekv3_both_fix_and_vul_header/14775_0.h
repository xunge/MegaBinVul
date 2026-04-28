#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/mount.h>

#define MAXPATHLEN 4096
#define SYSERROR(fmt, ...) 
#define ERROR(fmt, ...) 
#define INFO(fmt, ...) 

struct lxc_rootfs {
    char *mount;
};

struct lxc_console {
    char *name;
    int master;
};