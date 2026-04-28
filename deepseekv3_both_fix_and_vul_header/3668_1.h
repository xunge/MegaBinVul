#include <sys/types.h>

typedef unsigned int kuid_t;
typedef unsigned int umode_t;

struct inode {
    umode_t i_mode;
    kuid_t i_uid;
};

#define S_ISVTX 0001000
#define CAP_FOWNER 3

static inline int uid_eq(kuid_t left, kuid_t right) {
    return left == right;
}

static inline kuid_t current_fsuid(void) {
    return 0;
}

static inline int inode_capable(const struct inode *inode, int cap) {
    return 0;
}