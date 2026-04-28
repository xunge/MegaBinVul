#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#define PAGE_SIZE 4096
#define PAGE_SHIFT 12

struct ipc_namespace {
    unsigned long shm_tot;
};

struct shmid_kernel {
    size_t shm_segsz;
    struct file *shm_file;
    void *mlock_user;
};

struct file;
struct inode {
    loff_t i_size;
};

void shm_rmid(struct ipc_namespace *ns, struct shmid_kernel *shp);
void shm_unlock(struct shmid_kernel *shp);
int is_file_hugepages(struct file *file);
void shmem_lock(struct file *file, int lock, void *user);
void user_shm_unlock(loff_t size, void *user);
struct inode *file_inode(struct file *file);
void fput(struct file *file);
void ipc_rcu_putref(void *ptr, void (*func)(void *ptr));
void shm_rcu_free(void *ptr);