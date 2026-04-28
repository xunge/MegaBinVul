#include <errno.h>

#define Audit_equal 0
#define EINVAL 22

struct lsm_entry {
    int type;
    void *rule;
};

struct ima_measure_rule_entry {
    struct lsm_entry *lsm;
};

int security_filter_rule_init(int type, int op, char *args, void **rule);