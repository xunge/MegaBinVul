#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <assert.h>
#include <stddef.h>

#define PATH_MAX 4096
#define _STAT_VER 0
#define __eloop_threshold() 40

struct stat64 {
    unsigned long long st_dev;
    unsigned char __pad0[4];
    unsigned long __st_ino;
    unsigned int st_mode;
    unsigned int st_nlink;
    unsigned int st_uid;
    unsigned int st_gid;
    unsigned long long st_rdev;
    unsigned char __pad3[4];
    long long st_size;
    unsigned long st_blksize;
    unsigned long long st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    unsigned long long st_ino;
};

extern char *__rawmemchr(const char *, int);
extern char *__mempcpy(void *dest, const void *src, size_t n);
extern int __getcwd(char *buf, size_t size);
extern int __lxstat64(int ver, const char *path, struct stat64 *buf);
extern int __readlink(const char *path, char *buf, size_t bufsiz);
extern void *__alloca(size_t size);
extern void __set_errno(int errno_val);