#include <sys/mount.h>
#include <sys/statvfs.h>
#include <errno.h>
#include <string.h>

#define MS_REMOUNT 0
#define MS_BIND 0
#define MS_RDONLY 0
#define MS_NOSUID 0
#define MS_NODEV 0
#define MS_NOEXEC 0
#define HAVE_STATVFS 1

#define DEBUG(fmt, ...)
#define INFO(fmt, ...)
#define SYSERROR(fmt, ...)