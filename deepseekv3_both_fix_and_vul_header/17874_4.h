#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/uio.h>

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define ENOMEM 12
#define EFAULT 14
#define RPC_TASK_ASYNC 1

struct nfs_direct_req {
    struct nfs_open_context *ctx;
};

struct nfs_open_context {
    struct {
        struct {
            struct inode *d_inode;
        } *dentry;
    } path;
    void *cred;
};

struct inode {
    struct {
        char *s_id;
    } *i_sb;
    long dummy;
};

struct nfs_server {
    size_t rsize;
};

struct nfs_read_data {
    unsigned int npages;
    void *pagevec;
    struct nfs_page *req;
    struct inode *inode;
    void *cred;
    struct {
        void *fh;
        void *context;
        loff_t offset;
        unsigned int pgbase;
        void *pages;
        size_t count;
    } args;
    struct {
        void *fattr;
        int eof;
        size_t count;
    } res;
    struct {
        int tk_pid;
    } task;
    void *fattr;
};

struct rpc_message {
    void *rpc_cred;
    void *rpc_argp;
    void *rpc_resp;
};

struct rpc_task_setup {
    void *rpc_client;
    struct rpc_message *rpc_message;
    const void *callback_ops;
    void *workqueue;
    int flags;
    void *task;
    void *callback_data;
};

struct rpc_task;

struct mm_struct {
    void *mmap_sem;
};

struct task_struct {
    struct mm_struct *mm;
};

extern struct task_struct *current;
extern struct workqueue_struct *nfsiod_workqueue;
extern const struct rpc_call_ops nfs_read_direct_ops;

static inline struct nfs_server *NFS_SERVER(struct inode *inode) {
    return (struct nfs_server *)(long)inode->dummy;
}

static inline void *NFS_CLIENT(struct inode *inode) {
    return (void *)(long)inode->dummy;
}

static inline void *NFS_FH(struct inode *inode) {
    return (void *)(long)inode->dummy;
}

static inline struct {
    void (*read_setup)(struct nfs_read_data *, struct rpc_message *);
} *NFS_PROTO(struct inode *inode) {
    return (void *)(long)inode->dummy;
}

static inline long long NFS_FILEID(struct inode *inode) {
    return inode->dummy;
}

static inline int min(int a, int b) { return a < b ? a : b; }
static inline int unlikely(int x) { return x; }
static inline void get_dreq(struct nfs_direct_req *dreq) {}
static inline void *get_nfs_open_context(void *ctx) { return ctx; }
static inline void dprintk(const char *fmt, ...) {}
static inline void BUG_ON(int condition) {}
static inline void down_read(void *sem) {}
static inline void up_read(void *sem) {}
static inline int get_user_pages(void *task, void *mm, unsigned long addr,
                               int nr_pages, int write, int force,
                               void **pages, void **vmas) { return 0; }
static inline struct nfs_read_data *nfs_readdata_alloc(size_t len) { return 0; }
static inline size_t nfs_page_array_len(unsigned int pgbase, size_t len) { return 0; }
static inline void nfs_readdata_release(struct nfs_read_data *data) {}
static inline void nfs_direct_release_pages(void **pages, int npages) {}
static inline struct rpc_task *rpc_run_task(struct rpc_task_setup *setup) { return 0; }
static inline int IS_ERR(const void *ptr) { return 0; }
static inline void rpc_put_task(struct rpc_task *task) {}