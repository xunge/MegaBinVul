#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define ENOPARAM (-1)
#define ENOENT (-2)
#define EINVAL (-3)
#define MAX_CGROUP_ROOT_NAMELEN 64
#define CAP_SYS_ADMIN 21

struct fs_context {
    void *user_ns;
};

struct fs_parameter {
    const char *key;
    char *string;
    size_t size;
};

struct fs_parse_result {
    int dummy;
};

struct cgroup_subsys {
    const char *legacy_name;
};

struct cgroup_fs_context {
    bool none;
    bool all_ss;
    unsigned int flags;
    bool cpuset_clone_children;
    char *release_agent;
    char *name;
    unsigned int subsys_mask;
};

struct user_namespace {
    int dummy;
};

extern struct user_namespace init_user_ns;

#define for_each_subsys(ss, i) for (i = 0, ss = NULL; i < 0; i++)

#define invalfc(fc, fmt, ...) (-EINVAL)

enum {
    Opt_none,
    Opt_all,
    Opt_noprefix,
    Opt_clone_children,
    Opt_cpuset_v2_mode,
    Opt_xattr,
    Opt_release_agent,
    Opt_name
};

#define CGRP_ROOT_NOPREFIX (1 << 0)
#define CGRP_ROOT_CPUSET_V2_MODE (1 << 1)
#define CGRP_ROOT_XATTR (1 << 2)

extern int cgroup_no_v1_named;
extern const void *cgroup1_fs_parameters;

static inline int fs_parse(struct fs_context *fc, const void *params, 
                         struct fs_parameter *param, struct fs_parse_result *result)
{
    return -ENOPARAM;
}

static inline struct cgroup_fs_context *cgroup_fc2context(struct fs_context *fc)
{
    return NULL;
}

static inline bool cgroup_ssid_enabled(int ssid)
{
    return false;
}

static inline bool cgroup1_ssid_disabled(int ssid)
{
    return false;
}

static inline int vfs_parse_fs_param_source(struct fs_context *fc, 
                                          struct fs_parameter *param)
{
    return -ENOPARAM;
}

static inline bool capable(int cap)
{
    return false;
}