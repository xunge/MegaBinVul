#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define ACL_TYPE_ACCESS 0x8000

struct inode {
    mode_t i_mode;
    time_t i_ctime;
};

struct posix_acl;

int posix_acl_equiv_mode(struct posix_acl *, mode_t *);
time_t current_time(struct inode *);
void set_cached_acl(struct inode *, int, struct posix_acl *);