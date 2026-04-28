#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned long spinlock_t;

struct rb_root {
    void *rb_node;
};

struct delayed_work {
    void *work;
    unsigned long timer;
};

struct super_block {
    long s_maxbytes;
    int s_time_gran;
};

struct nls_table {
    // Minimal definition
    char *charset;
};

struct cifs_sb_info {
    struct nls_table *local_nls;
    unsigned int mnt_cifs_flags;
    char *prepath;
    int prepathlen;
    char *mountdata;
    int rsize;
    int wsize;
    struct tcon_link *master_tlink;
    spinlock_t tlink_tree_lock;
    struct rb_root tlink_tree;
    struct delayed_work prune_tlinks;
};

struct smb_vol {
    int nullauth;
    char *username;
    char *iocharset;
    struct nls_table *local_nls;
};

struct TCP_Server_Info {
    int maxBuf;
};

struct cifsSesInfo {
    unsigned int capabilities;
    uid_t linux_uid;
    struct TCP_Server_Info *server;
};

struct cifsTconInfo {
    int ipc;
    int unix_ext;
    struct cifsSesInfo *ses;
};

struct tcon_link {
    unsigned long tl_flags;
    uid_t tl_uid;
    struct cifsTconInfo *tl_tcon;
    unsigned long tl_time;
};

struct dfs_info3_param {
    // Minimal definition
    char *path_name;
};

#define CONFIG_CIFS_DFS_UPCALL
#define MAX_NESTED_LINKS 8
#define MAX_LFS_FILESIZE LLONG_MAX
#define MAX_NON_LFS ((1ULL<<31)-1)
#define CAP_LARGE_FILES 0x00000004
#define CAP_UNIX 0x00800000
#define CAP_LARGE_WRITE_X 0x00000008
#define CAP_LARGE_READ_X 0x00000010
#define CIFS_MOUNT_POSIX_PATHS 0x00000001
#define CIFS_MOUNT_MAP_SPECIAL_CHR 0x00000002
#define TCON_LINK_MASTER 0
#define TCON_LINK_IN_TREE 1
#define MAX_CIFS_HDR_SIZE 128
#define CIFS_DIR_SEP(cifs_sb) '/'
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define ELIBACC 83
#define EREMOTE 66
#define ELOOP 40
#define EOPNOTSUPP 95
#define DBG2 2
#define TLINK_IDLE_EXPIRE 0

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-1000)
#define PTR_ERR(x) ((long)(x))

static void *system_nrt_wq;
static unsigned long jiffies;

static inline int GetXid(void) { return 0; }
static inline void FreeXid(int xid) {}
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *p) { free(p); }
static inline int min(int a, int b) { return a < b ? a : b; }
static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline void set_bit(int nr, unsigned long *addr) {}
static inline void tlink_rb_insert(struct rb_root *root, struct tcon_link *tlink) {}
static inline void queue_delayed_work(void *wq, struct delayed_work *work, unsigned long delay) {}