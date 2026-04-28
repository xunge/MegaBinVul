#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATH_MAX 4096
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef char *GETCWD_RETURN_TYPE;

struct __stat64_t64 {
    dev_t st_dev;
    ino_t st_ino;
    mode_t st_mode;
};

struct dirent64 {
    ino_t d_ino;
    char d_name[256];
};

#define HAVE_OPENAT_SUPPORT 1
#define HAVE_MINIMALLY_WORKING_GETCWD 1
#define HAVE_PARTLY_WORKING_GETCWD 1

#define AT_FDCWD -100
#define AT_SYMLINK_NOFOLLOW 0x100

#define MATCHING_INO(d, ino) ((d)->d_ino == (ino))
#define _D_EXACT_NAMLEN(d) strlen((d)->d_name)
#define _D_ALLOC_NAMLEN(d) (strlen((d)->d_name) + 1)

extern char *getcwd_system(char *, size_t);
extern int __openat64(int, const char *, int);
extern int __fstat64_time64(int, struct __stat64_t64 *);
extern int __lstat64_time64(const char *, struct __stat64_t64 *);
extern int __fstatat64_time64(int, const char *, struct __stat64_t64 *, int);
extern DIR *__fdopendir(int);
extern DIR *__opendir(const char *);
extern struct dirent64 *__readdir64(DIR *);
extern int __closedir(DIR *);
extern void __rewinddir(DIR *);
extern int __close_nocancel_nostatus(int);
extern void __set_errno(int);