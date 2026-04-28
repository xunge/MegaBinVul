#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define XCOPY_NAA_IEEE_REGEX_LEN 16
#define EINVAL 22

struct percpu_ref {
    int dummy;
};

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct se_lun {
    struct percpu_ref lun_ref;
    struct se_device *lun_se_dev;
};

struct se_device {
    void *dev_group;
};

struct se_dev_entry {
    struct se_lun *se_lun;
    struct hlist_node link;
};

struct se_node_acl {
    struct hlist_head lun_entry_hlist;
};

struct se_session {
    struct se_node_acl *se_node_acl;
};

struct xcopy_dev_search_info {
    const unsigned char *dev_wwn;
    struct se_device *found_dev;
};

#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define pr_debug_ratelimited(fmt, ...) printf(fmt, ##__VA_ARGS__)

#define hlist_for_each_entry_rcu(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

#define rcu_read_lock()
#define rcu_read_unlock()
#define rcu_dereference(p) (p)
#define rcu_dereference_raw(p) (p)

static inline int percpu_ref_tryget_live(struct percpu_ref *ref) {
    return 1;
}

static int target_xcopy_locate_se_dev_e4_iter(struct se_device *dev, const unsigned char *dev_wwn) {
    return 0;
}

static int target_for_each_device(int (*func)(struct se_device *, const unsigned char *), 
                                struct xcopy_dev_search_info *info) {
    return 0;
}