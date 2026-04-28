#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

typedef unsigned long ulong;
typedef unsigned int fmode_t;

#define EINVAL 22
#define EACCES 13
#define ENOMEM 12

#define SHM_RDONLY 010000
#define SHM_RND    020000
#define SHM_REMAP  040000
#define SHM_EXEC   0100000

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))

#define S_IRUGO (S_IRUSR|S_IRGRP|S_IROTH)
#define S_IWUGO (S_IWUSR|S_IWGRP|S_IWOTH)
#define S_IXUGO (S_IXUSR|S_IXGRP|S_IXOTH)

#define FMODE_READ O_RDONLY
#define FMODE_WRITE O_WRONLY

#define GFP_KERNEL 0

struct file_operations {
    // minimal definition
};

struct file_operations shm_file_operations;
struct file_operations shm_file_operations_huge;

struct dentry {
    void *d_inode;
};

struct path {
    struct dentry *dentry;
};

struct file {
    struct path f_path;
    fmode_t f_mode;
    void *private_data;
    void *f_mapping;
    const struct file_operations *f_op;
};

struct shmid_kernel {
    struct {
        int id;
    } shm_perm;
    struct file *shm_file;
    unsigned long shm_nattch;
};

struct ipc_namespace {
    struct shm_ids *shm_ids;
};

struct shm_ids {
    void *rwsem;
};

struct shm_file_data {
    int id;
    struct ipc_namespace *ns;
    struct file *file;
    void *vm_ops;
};

struct mm_struct {
    unsigned long start_stack;
    void *mmap_sem;
};

struct task_struct {
    struct {
        struct ipc_namespace *ipc_ns;
    } *nsproxy;
    struct mm_struct *mm;
};

extern struct task_struct *current;

#define __user

// Dummy function declarations
void rcu_read_lock(void);
void rcu_read_unlock(void);
struct shmid_kernel *shm_obtain_object_check(struct ipc_namespace *ns, int shmid);
int IS_ERR(const void *ptr);
long PTR_ERR(const void *ptr);
int ipcperms(struct ipc_namespace *ns, void *perm, int mode);
int security_shm_shmat(struct shmid_kernel *shp, char *shmaddr, int shmflg);
void ipc_lock_object(void *perm);
void path_get(struct path *path);
unsigned long i_size_read(void *inode);
void ipc_unlock_object(void *perm);
void *kzalloc(size_t size, int flags);
void path_put(struct path *path);
struct file *alloc_file(struct path *path, fmode_t mode, const struct file_operations *ops);
int is_file_hugepages(struct file *file);
void kfree(void *ptr);
struct ipc_namespace *get_ipc_ns(struct ipc_namespace *ns);
int security_mmap_file(struct file *file, unsigned long prot, unsigned long flags);
void down_write(void *sem);
int find_vma_intersection(struct mm_struct *mm, unsigned long start, unsigned long end);
unsigned long do_mmap_pgoff(struct file *file, unsigned long addr, unsigned long len,
                           unsigned long prot, unsigned long flags,
                           unsigned long pgoff, unsigned long *populate);
int IS_ERR_VALUE(unsigned long x);
void up_write(void *sem);
void mm_populate(unsigned long addr, unsigned long len);
void fput(struct file *file);
struct shm_ids *shm_ids(struct ipc_namespace *ns);
struct shmid_kernel *shm_lock(struct ipc_namespace *ns, int id);
void BUG_ON(int condition);
int shm_may_destroy(struct ipc_namespace *ns, struct shmid_kernel *shp);
void shm_destroy(struct ipc_namespace *ns, struct shmid_kernel *shp);
void shm_unlock(struct shmid_kernel *shp);

// Fix for shm_ids access
#define shm_ids(ns) (*(ns)->shm_ids)