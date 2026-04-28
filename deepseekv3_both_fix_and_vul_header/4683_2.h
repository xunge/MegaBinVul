#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <fnmatch.h>
#include <sys/stat.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <features.h>
#include <string.h>

typedef struct {
    size_t gl_pathc;
    char **gl_pathv;
    size_t gl_offs;
    int gl_flags;
    int (*gl_stat)(const char *, struct stat *);
    int (*gl_lstat)(const char *, struct stat *);
    void *(*gl_opendir)(const char *);
    struct dirent *(*gl_readdir)(void *);
    void (*gl_closedir)(void *);
} glob_t;

#define GLOB_NOCHECK 0
#define GLOB_NOMAGIC 0
#define GLOB_NOESCAPE 0
#define GLOB_ERR 0
#define GLOB_ABORTED 0
#define GLOB_NOSPACE 0
#define GLOB_NOMATCH 0
#define GLOB_ALTDIRFUNC 0
#define GLOB_PERIOD 0
#define GLOB_ONLYDIR 0
#define GLOB_MAGCHAR 0

struct readdir_result {
    char *name;
    int skip_entry;
};

#define __glob_pattern_type(p, e) 0
#define __libc_use_alloca(s) 0
#define alloca_account(s, u) alloca(s)
#define __builtin_expect(e, v) (e)
#define __stat64(p, s) stat(p, s)
#define dirfd(d) 0
#define COMPILE_GLOB64
#define GL_READDIR(g, s) ((g)->gl_readdir(s))
#define convert_dirent(d) (struct readdir_result){.name = (d)->d_name, .skip_entry = 0}
#define convert_dirent64(d) (struct readdir_result){.name = (d)->d_name, .skip_entry = 0}
#define readdir_result_might_be_dir(d) 0
#define readdir_result_might_be_symlink(d) 0
#define link_exists_p(dfd, dir, dirlen, name, pglob, flags) 0
#define struct_stat64 struct stat
#define __set_errno(e) (errno = (e))
#define __readdir readdir
#define __readdir64 readdir64