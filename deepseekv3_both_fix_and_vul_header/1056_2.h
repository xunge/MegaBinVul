#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct fs_context {
    char *source;
};

struct cgroup_fs_context {
    bool none;
    bool all_ss;
    unsigned long subsys_mask;
    unsigned int flags;
    bool cpuset_clone_children;
    char *release_agent;
    char *name;
};

struct cgroup_subsys {
    const char *legacy_name;
};

struct fs_parameter {
    const char *key;
    int type;
    size_t size;
    char *string;
};

struct fs_parse_result {
    int opt;
};

#define fs_value_is_string 1
#define ENOPARAM -1
#define ENOENT -2
#define MAX_CGROUP_ROOT_NAMELEN 64
#define CGRP_ROOT_NOPREFIX (1U << 0)
#define CGRP_ROOT_CPUSET_V2_MODE (1U << 1)
#define CGRP_ROOT_XATTR (1U << 2)

static bool cgroup_no_v1_named;
static bool cgroup_ssid_enabled(int i) { return false; }
static bool cgroup1_ssid_disabled(int i) { return false; }
static int invalf(struct fs_context *fc, const char *fmt, ...) { return -1; }
static int invalfc(struct fs_context *fc, const char *fmt, ...) { return -1; }
static struct cgroup_fs_context *cgroup_fc2context(struct fs_context *fc) { return NULL; }
static int fs_parse(struct fs_context *fc, const void *params, struct fs_parameter *param, struct fs_parse_result *result) { return 0; }
static const void *cgroup1_fs_parameters;

#define for_each_subsys(ss, i) \
    for (i = 0, ss = NULL; i < 0; i++)

enum {
    Opt_none,
    Opt_all,
    Opt_noprefix,
    Opt_clone_children,
    Opt_cpuset_v2_mode,
    Opt_xattr,
    Opt_release_agent,
    Opt_name,
};