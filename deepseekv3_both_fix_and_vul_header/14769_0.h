#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/limits.h>

#define MAXPATHLEN PATH_MAX
#define MNT_DETACH 2

#define SYSERROR(fmt, ...) 
#define INFO(fmt, ...)