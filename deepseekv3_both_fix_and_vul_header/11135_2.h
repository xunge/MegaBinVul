#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

#define S_ISGID 02000
#define S_IXGRP 00010
#define CAP_FSETID 4

typedef unsigned int umode_t;

struct inode {
    umode_t i_mode;
    uid_t i_uid;
    gid_t i_gid;
};

uid_t current_fsuid(void);
gid_t current_fsgid(void);
int in_group_p(gid_t gid);
int capable_wrt_inode_uidgid(const struct inode *inode, int cap);