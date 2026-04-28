#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

struct dentry;
struct iattr {
    unsigned int ia_valid;
    uid_t ia_uid;
};
struct socket {
    struct {
        uid_t sk_uid;
    } *sk;
};
struct inode;

#define ATTR_UID (1<<0)
#define SOCKET_I(i) ((struct socket *)(i))
#define d_inode(d) ((struct inode *)(d))
#define simple_setattr(d, i) (0)