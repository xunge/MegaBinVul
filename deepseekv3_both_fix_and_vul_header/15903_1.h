#include <sys/types.h>
#include <sys/stat.h>

typedef unsigned int umode_t;
typedef int kuid_t;

struct inode {
    umode_t i_mode;
    kuid_t i_uid;
};

struct dentry {
    struct inode *d_inode;
};

extern int sysctl_protected_fifos;
extern int sysctl_protected_regular;

#define S_ISFIFO(mode) ((mode) & 0010000)
#define S_ISREG(mode) ((mode) & 0100000)
#define S_ISVTX 0001000

#define likely(x) (x)
#define uid_eq(a, b) ((a) == (b))

kuid_t current_fsuid(void);
int audit_log_path_denied(int type, const char *operation);

#define AUDIT_ANOM_CREAT 1
#define EACCES 13