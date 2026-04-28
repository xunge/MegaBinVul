#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define MAY_READ 1
#define MAY_WRITE 2
#define MAY_EXEC 4
#define CAP_DAC_OVERRIDE 1
#define CAP_DAC_READ_SEARCH 2
#define EACCES 13
#define S_IXUGO (S_IXUSR | S_IXGRP | S_IXOTH)

struct inode {
    mode_t i_mode;
};

extern int acl_permission_check(struct inode *inode, int mask);
extern int inode_capable(struct inode *inode, int cap);