#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

struct shmid64_ds {
    struct ipc_perm shm_perm;
    size_t shm_segsz;
    time_t shm_atime;
    time_t shm_dtime;
    time_t shm_ctime;
    pid_t shm_cpid;
    pid_t shm_lpid;
    unsigned long shm_nattch;
};

static inline unsigned long copy_to_user(void *buf, const void *src, size_t size) {
    memcpy(buf, src, size);
    return 0;
}

static inline void ipc64_perm_to_ipc_perm(const struct ipc_perm *in, struct ipc_perm *out) {
    *out = *in;
}

#define IPC_64 1
#define IPC_OLD 0
#define EINVAL 22
#define __user