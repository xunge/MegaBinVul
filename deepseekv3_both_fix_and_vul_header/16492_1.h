#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/param.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/syslog.h>

#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <grp.h>
#include <limits.h>
#include <paths.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _PW_BUF_LEN 1024

struct rule {
    int options;
    const char *cmd;
};

#define NOPASS 0x01
#define PERSIST 0x02

extern char *__progname;
#define setprogname(x) (__progname = (x))

size_t strlcpy(char *dst, const char *src, size_t siz);
size_t strlcat(char *dst, const char *src, size_t siz);
void errc(int status, int code, const char *fmt, ...);