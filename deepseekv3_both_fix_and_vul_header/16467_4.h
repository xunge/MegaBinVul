#include <stdio.h>

struct list_head {
    struct list_head *next, *prev;
};

struct config_item {
    const char *ci_name;
    struct list_head ci_entry;
};

struct config_group {
    struct config_item cg_item;
};

struct configfs_group_operation {
    struct config_item cg_item;
};

struct se_device {
    struct configfs_group_operation dev_group;
};

enum xcopy_origin {
    XCOL_SOURCE_RECV_OP
};

struct xcopy_op {
    enum xcopy_origin op_origin;
    struct se_device *src_dev;
    struct se_device *dst_dev;
    void *remote_lun_ref;
};

void target_undepend_item(struct config_item *item);
void percpu_ref_put(void *ref);
void pr_debug(const char *fmt, ...);