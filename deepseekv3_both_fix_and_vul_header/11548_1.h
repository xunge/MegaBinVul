#include <stddef.h>

struct posix_acl;
struct inode {
    struct {
        struct posix_acl *(*get_acl)(struct inode *, int);
    } *i_op;
};

struct inode *ovl_inode_real(struct inode *inode);
#define IS_POSIXACL(inode) (0)
#define ENOENT 2
#define ERR_PTR(err) ((void *)(long)(err))