#include <errno.h>

struct devlink {
    int reload_failed;
};

struct devlink_param {
    int (*get)(struct devlink *, unsigned int, struct devlink_param_gset_ctx *);
    unsigned int id;
};

struct devlink_param_gset_ctx;