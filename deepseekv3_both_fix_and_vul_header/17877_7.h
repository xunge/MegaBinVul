#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define ENOMEM 12
#define EFAULT 14
#define RPC_TASK_ASYNC 1

struct list_head {
    struct list_head *next, *prev;
};

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
};

struct inode {
    struct super_block *i_sb;
};

struct super_block {
    char s_id[32];
};

struct cred;
struct page;
struct rw_semaphore {
    long count;
};
struct vm_area_struct;

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct nfs_fh {
    unsigned char data[64];
};

struct nfs_fattr {
    unsigned long dummy;
};

struct nfs_writeverf {
    unsigned char data[8];
};

struct nfs_direct_req {
    struct nfs_open_context *ctx;
    struct list_head rewrite_list;
};

struct nfs_open_context {
    struct path path;
    struct cred *cred;
};

struct rpc_task {
    pid_t tk_pid;
};

struct nfs_write_data {
    unsigned int npages;
    struct page **pagevec;
    struct list_head pages;
    struct nfs_page *req;
    struct inode *inode;
    struct cred *cred;
    struct nfs_fattr fattr;
    struct nfs_writeverf verf;
    struct {
        struct nfs_fh fh;
        struct nfs_open_context *context;
        loff_t offset;
        unsigned int pgbase;
        struct page **pages;
        size_t count;
        int stable;
    } args;
    struct {
        struct nfs_fattr *fattr;
        size_t count;
        struct nfs_writeverf *verf;
    } res;
    struct rpc_task task;
};

struct rpc_message {
    struct cred *rpc_cred;
    void *rpc_argp;
    void *rpc_resp;
};

struct rpc_client;
struct rpc_call_ops;
struct rpc_task_setup {
    struct rpc_task *task;
    void *callback_data;
    struct rpc_client *rpc_client;
    struct rpc_message *rpc_message;
    const struct rpc_call_ops *callback_ops;
    struct workqueue_struct *workqueue;
    unsigned int flags;
};

struct workqueue_struct;
struct nfs_client;
struct nfs_server {
    size_t wsize;
};
struct nfs_protocol {
    void (*write_setup)(struct nfs_write_data *, struct rpc_message *);
};
struct nfs_page;

struct task_struct {
    struct mm_struct *mm;
};

struct mm_struct {
    struct rw_semaphore mmap_sem;
};

#define min(a,b) ((a)<(b)?(a):(b))
#define unlikely(x) (x)
#define IS_ERR(x) (0)
#define BUG_ON(x)

extern struct workqueue_struct *nfsiod_workqueue;
extern const struct rpc_call_ops nfs_write_direct_ops;
extern struct task_struct *current;

static inline struct nfs_client *NFS_CLIENT(struct inode *inode) { return (struct nfs_client *)NULL; }
static inline struct nfs_server *NFS_SERVER(struct inode *inode) { return (struct nfs_server *)NULL; }
static inline struct nfs_fh NFS_FH(struct inode *inode) { struct nfs_fh fh = {{0}}; return fh; }
static inline struct nfs_protocol *NFS_PROTO(struct inode *inode) { return (struct nfs_protocol *)NULL; }
static inline long long NFS_FILEID(struct inode *inode) { return 0; }

static inline struct nfs_open_context *get_nfs_open_context(struct nfs_open_context *ctx) { return ctx; }
static inline void get_dreq(struct nfs_direct_req *dreq) {}
static inline struct nfs_write_data *nfs_writedata_alloc(size_t len) { return NULL; }
static inline void nfs_writedata_release(struct nfs_write_data *data) {}
static inline void nfs_direct_release_pages(struct page **pages, int npages) {}
static inline size_t nfs_page_array_len(unsigned int pgbase, size_t bytes) { return 0; }

static inline void down_read(struct rw_semaphore *sem) {}
static inline void up_read(struct rw_semaphore *sem) {}
static inline int get_user_pages(void *task, void *mm, unsigned long addr, 
                               int nr_pages, int write, int force, 
                               struct page **pages, struct vm_area_struct **vmas) { return 0; }

static inline struct rpc_task *rpc_run_task(struct rpc_task_setup *setup) { return NULL; }
static inline void rpc_put_task(struct rpc_task *task) {}
static inline void list_move_tail(struct list_head *list, struct list_head *head) {}
static inline void dprintk(const char *fmt, ...) {}