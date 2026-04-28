#include <sys/types.h>
#include <stddef.h>

#define ERR_PTR(err) ((void *)((long)(err)))
#define ENOMEM 12
#define I_NEW 0x00000080

typedef unsigned short umode_t;

struct p9_qid {
    unsigned char type;
    unsigned int version;
    unsigned long long path;
};

struct p9_wstat {
    unsigned short size;
    unsigned short type;
    unsigned int dev;
    struct p9_qid qid;
    unsigned int mode;
    unsigned int atime;
    unsigned int mtime;
    unsigned int length;
    char *name;
    char *uid;
    char *gid;
    char *muid;
};

struct super_block {
    void *s_fs_info;
};

struct inode {
    unsigned long i_ino;
    unsigned int i_state;
};

struct v9fs_session_info {
    // minimal definition
};

extern int v9fs_test_new_inode(struct inode *, void *);
extern int v9fs_test_inode(struct inode *, void *);
extern int v9fs_set_inode(struct inode *, void *);
extern unsigned long v9fs_qid2ino(struct p9_qid *);
extern umode_t p9mode2unixmode(struct v9fs_session_info *, struct p9_wstat *, dev_t *);
extern int v9fs_init_inode(struct v9fs_session_info *, struct inode *, umode_t, dev_t);
extern void v9fs_stat2inode(struct p9_wstat *, struct inode *, struct super_block *, ...);
extern void v9fs_cache_inode_get_cookie(struct inode *);
extern struct inode *iget5_locked(struct super_block *, unsigned long, int (*)(struct inode *, void *), int (*)(struct inode *, void *), void *);
extern void unlock_new_inode(struct inode *);
extern void iget_failed(struct inode *);