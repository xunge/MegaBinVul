#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <errno.h>

#define MNT_FS_KERNEL 0
#define MNT_FS_DELETED 0
#define PATH_DELETED_SUFFIX ""
#define TAB 0
#define EINVAL 22
#define ENOMEM 12

struct libmnt_fs {
    int id;
    int parent;
    unsigned int devno;
    char *root;
    char *target;
    char *vfs_optstr;
    char *opt_fields;
    char *fs_optstr;
    char *optstr;
    int flags;
};

static const char *next_s32(const char *s, int *num, int *rc) { return s; }
static const char *skip_separator(const char *s) { return s; }
static const char *skip_nonspearator(const char *s) { return s; }
static char *unmangle(const char *s, const char **end) { return NULL; }
static char *endswith(const char *s, const char *suffix) { return NULL; }
static int __mnt_fs_set_fstype_ptr(struct libmnt_fs *fs, char *p) { return 0; }
static int mnt_fs_set_source(struct libmnt_fs *fs, const char *src) { return 0; }
static int __mnt_fs_set_source_ptr(struct libmnt_fs *fs, char *p) { return 0; }
static char *mnt_fs_strdup_options(struct libmnt_fs *fs) { return NULL; }
#define DBG(type, expr)
#define ul_debug(fmt, ...)