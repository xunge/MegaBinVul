#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 4096
#define WB_SYNC_ALL 0
#define ENOSYS 38
#define EFAULT 14
#define EINTR 4
#define EAGAIN 11
#define ENOMEM 12
#define CIFS_MOUNT_RWPIDFORWARD (1 << 0)

typedef unsigned long long __u64;

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct list_head {
    struct list_head *next, *prev;
};

struct path {
    struct dentry *dentry;
};

struct file {
    struct path f_path;
    void *private_data;
};

struct dentry {
    struct super_block *d_sb;
};

struct super_block;

struct cifsFileInfo {
    void *tlink;
    pid_t pid;
};

struct cifs_tcon {
    struct {
        struct {
            struct {
                struct {
                    int (*async_writev)(void);
                } *ops;
            } *server;
        } *ses;
    };
};

struct cifs_sb_info {
    unsigned long mnt_cifs_flags;
    unsigned long wsize;
};

struct cifs_writedata {
    struct list_head list;
    int refcount;
    int done;
    void **pages;
    unsigned int nr_pages;
    __u64 offset;
    struct cifsFileInfo *cfile;
    pid_t pid;
    size_t bytes;
    unsigned int pagesz;
    unsigned int tailsz;
    int sync_mode;
    int result;
};

struct iov_iter {
    const struct iovec *iov;
    unsigned long nr_segs;
    size_t count;
    size_t iov_offset;
};

struct task_struct {
    pid_t tgid;
};
extern struct task_struct *current;

static void cifs_uncached_writev_complete(struct cifs_writedata *wdata) {}

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)), \
         n = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = n, n = (typeof(*pos)*)((char*)n->member.next - offsetof(typeof(*pos), member)))

static inline size_t iov_length(const struct iovec *iov, unsigned long nr_segs) {
    size_t len = 0;
    while (nr_segs--) {
        len += iov->iov_len;
        iov++;
    }
    return len;
}

static inline int generic_write_checks(struct file *file, loff_t *pos, size_t *count, int isblk) {
    return 0;
}

static inline struct cifs_sb_info *CIFS_SB(struct super_block *sb) {
    return (struct cifs_sb_info *)sb;
}

static inline struct cifs_tcon *tlink_tcon(void *tlink) {
    return (struct cifs_tcon *)tlink;
}

static inline void iov_iter_init(struct iov_iter *i, const struct iovec *iov,
                unsigned long nr_segs, size_t count, size_t written) {
    i->iov = iov;
    i->nr_segs = nr_segs;
    i->count = count;
    i->iov_offset = written;
}

static inline unsigned long get_numpages(unsigned long wsize, size_t len, size_t *cur_len) {
    *cur_len = len;
    return (len + PAGE_SIZE - 1) / PAGE_SIZE;
}

static inline struct cifs_writedata *cifs_writedata_alloc(unsigned long nr_pages,
                void (*complete)(struct cifs_writedata *)) {
    return malloc(sizeof(struct cifs_writedata));
}

static inline int cifs_write_allocate_pages(void **pages, unsigned long nr_pages) {
    return 0;
}

static inline size_t iov_iter_copy_from_user(void *page, struct iov_iter *i,
                unsigned offset, size_t bytes) {
    return bytes;
}

static inline void iov_iter_advance(struct iov_iter *i, size_t bytes) {
    i->count -= bytes;
}

static inline void put_page(void *page) {}

static inline void kfree(void *obj) {
    free(obj);
}

static inline void kref_put(int *refcount, void (*release)(struct cifs_writedata *)) {}

static inline struct cifsFileInfo *cifsFileInfo_get(struct cifsFileInfo *cfile) {
    return cfile;
}

static inline int cifs_uncached_retry_writev(struct cifs_writedata *wdata) {
    return 0;
}

static inline void cifs_uncached_writedata_release(struct cifs_writedata *wdata) {
    free(wdata);
}

static inline void cifs_stats_bytes_written(struct cifs_tcon *tcon, ssize_t bytes) {}

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))