#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

enum de_op {
    DE_CREATE,
    DE_MKDIR,
    DE_LINK,
    DE_RENAME
};

struct tmount;
struct tmpnode;
struct tdirent;
struct vattr;
struct cred;

#define MAXLINK 32767
#define VDIR 1
#define VWRITE 2
#define EACCES 13
#define ENOENT 2
#define EMLINK 31
#define EEXIST 17
#define EINVAL 22
#define EBUSY 16

#define RW_WRITER 1
#define RW_WRITE_HELD(lock) (1)
#define ASSERT(expr) ((void)0)
#define VN_HOLD(vp) ((void)0)
#define VN_RELE(vp) ((void)0)
#define TNTOV(tp) ((void *)(tp))

extern unsigned int tmpfs_rename_loops;
extern unsigned int tmpfs_rename_backoff_tries;
extern unsigned int tmpfs_rename_backoff_delay;

struct tmpnode {
    int tn_type;
    int tn_nlink;
    struct timespec tn_ctime;
    void *tn_rwlock;
    void *tn_tlock;
};

struct tdirent;
struct vattr;
struct cred;
typedef struct {
    int dummy;
} caller_context_t;

void panic(const char *str);
void rw_enter(void *lock, int type);
void rw_exit(void *lock);
int rw_tryenter(void *lock, int type);
void mutex_enter(void *lock);
void mutex_exit(void *lock);
void delay(unsigned int ticks);

int tmpfs_hash_lookup(char *name, struct tmpnode *dir, int create, struct tmpnode **found);
int tdircheckpath(struct tmpnode *tp, struct tmpnode *dir, struct cred *cred);
int tdirrename(struct tmpnode *fromparent, struct tmpnode *tp, struct tmpnode *dir, 
              char *name, struct tmpnode *found, struct tdirent *tdp, struct cred *cred);
void tmpnode_rele(struct tmpnode *tp);
int tmp_taccess(struct tmpnode *dir, int mode, struct cred *cred);
int tdirmaketnode(struct tmpnode *dir, struct tmount *tm, struct vattr *va, 
                 enum de_op op, struct tmpnode **tp, struct cred *cred);
int tdiraddentry(struct tmpnode *dir, struct tmpnode *tp, char *name, 
                enum de_op op, struct tmpnode *fromparent);
void tdirtrunc(struct tmpnode *tp);
void gethrestime(struct timespec *ts);
void vnevent_rename_dest(void *vp, void *dvp, char *name, 
                        caller_context_t *ctp);

#define DECR_COUNT(countp, lockp) do { \
    (void)(lockp); \
    (*(countp))--; \
} while (0)