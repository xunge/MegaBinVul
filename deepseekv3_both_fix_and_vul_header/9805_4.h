#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <time.h>

struct semid64_ds {
    struct ipc_perm sem_perm;
    time_t sem_otime;
    time_t sem_ctime;
    unsigned long sem_nsems;
};

#define IPC_64 1
#define IPC_OLD 2
#define EINVAL 22

typedef void* user_ptr_t;

static inline unsigned long copy_to_user(user_ptr_t buf, const void *src, unsigned long size) {
    memcpy(buf, src, size);
    return 0;
}

static inline void ipc64_perm_to_ipc_perm(const struct ipc_perm *in, struct ipc_perm *out) {
    *out = *in;
}

#define __user