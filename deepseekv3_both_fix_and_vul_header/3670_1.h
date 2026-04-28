#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

typedef uid_t kuid_t;
struct inode {
    kuid_t i_uid;
};

#define CAP_FOWNER 0

static inline bool uid_eq(kuid_t left, kuid_t right) {
    return left == right;
}

uid_t current_fsuid(void);
bool inode_capable(const struct inode *inode, int cap);