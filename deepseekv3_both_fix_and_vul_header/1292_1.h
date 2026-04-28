#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>

#define stringify_value(x) #x
#define ULONG_MAX (~0UL)

struct libmnt_fs {
    const char *fstype;
    const char *fs_options;
};

struct libmnt_context {
    struct libmnt_fs *fs;
};

struct libmnt_ns;

int mnt_optstr_get_option(const char *optstr, const char *name, char **value, size_t *valsz);
const char *mnt_fs_get_fstype(struct libmnt_fs *fs);
const char *mnt_fs_get_fs_options(struct libmnt_fs *fs);
struct libmnt_ns *mnt_context_switch_origin_ns(struct libmnt_context *cxt);
int mnt_context_switch_ns(struct libmnt_context *cxt, struct libmnt_ns *ns);

#define MNT_ERR_NAMESPACE 1