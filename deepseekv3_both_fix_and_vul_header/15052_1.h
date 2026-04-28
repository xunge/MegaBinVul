#include <stdlib.h>
#include <string.h>

#define GFP_KERNEL 0
#define ENOMEM 12

struct posix_ace_state {
    int dummy;
};

struct posix_user_ace_state {
    int dummy;
};

struct posix_ace_state_array {
    int count;
    union {
        struct posix_ace_state *ace_entries;
        struct posix_user_ace_state *user_entries;
    };
};

struct posix_acl_state {
    int empty;
    struct posix_ace_state_array *users;
    struct posix_ace_state_array *groups;
};

void *kzalloc(size_t size, int flags);
void kfree(void *ptr);