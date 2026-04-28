#include <sys/types.h>
#include <time.h>

#define ATTR_UID    (1 << 0)
#define ATTR_GID    (1 << 1)
#define ATTR_ATIME  (1 << 2)
#define ATTR_MTIME  (1 << 3)
#define ATTR_CTIME  (1 << 4)
#define ATTR_MODE   (1 << 5)

#define S_ISGID     02000
#define CAP_FSETID  0

typedef unsigned int umode_t;

struct iattr {
    unsigned int ia_valid;
    uid_t ia_uid;
    gid_t ia_gid;
    struct timespec ia_atime;
    struct timespec ia_mtime;
    struct timespec ia_ctime;
    umode_t ia_mode;
};

struct inode {
    uid_t i_uid;
    gid_t i_gid;
    struct timespec i_atime;
    struct timespec i_mtime;
    struct timespec i_ctime;
    umode_t i_mode;
    struct {
        unsigned s_time_gran;
    } *i_sb;
};

struct timespec timespec_trunc(struct timespec t, unsigned gran);
int in_group_p(gid_t gid);
int inode_capable(struct inode *inode, int cap);