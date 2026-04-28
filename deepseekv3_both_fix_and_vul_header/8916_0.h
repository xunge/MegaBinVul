#include <stddef.h>

#define LAST_DOTDOT 1
#define LOOKUP_RCU 1

struct nameidata {
    int flags;
};

int follow_dotdot_rcu(struct nameidata *nd);
int follow_dotdot(struct nameidata *nd);