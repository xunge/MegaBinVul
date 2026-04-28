#include <sys/types.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>

struct file {
    void *private_data;
};

struct seq_file {
    void *lock;
    void *private;
};

enum psi_res {
    PSI_CPU,
    PSI_MEM,
    PSI_IO,
    PSI_NONE
};

struct psi_trigger;
struct psi_group;

extern struct psi_group psi_system;
extern int psi_disabled;

#define __user
#define EOPNOTSUPP 95
#define EINVAL 22
#define EFAULT 14
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define static_branch_likely(x) (*(x))
#define min(a, b) ((a) < (b) ? (a) : (b))

int copy_from_user(void *to, const void *from, unsigned long n);
struct psi_trigger *psi_trigger_create(struct psi_group *group, const char *buf, size_t nbytes, enum psi_res res);
void psi_trigger_replace(void **dst, struct psi_trigger *new);
void mutex_lock(void *lock);
void mutex_unlock(void *lock);