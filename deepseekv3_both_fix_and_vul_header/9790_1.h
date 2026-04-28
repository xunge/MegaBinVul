#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

struct shmid64_ds {
    struct ipc_perm shm_perm;
    size_t shm_segsz;
    time_t shm_atime;
    time_t shm_dtime;
    time_t shm_ctime;
    pid_t shm_cpid;
    pid_t shm_lpid;
    unsigned long shm_nattch;
    unsigned long __unused1;
    unsigned long __unused2;
};

struct shminfo64 {
    unsigned long shmmax;
    unsigned long shmmin;
    unsigned long shmmni;
    unsigned long shmseg;
    unsigned long shmall;
    unsigned long __unused1;
    unsigned long __unused2;
    unsigned long __unused3;
    unsigned long __unused4;
};

#define IPC_64 0x0100
#define IPC_RMID 0
#define IPC_SET 1
#define IPC_STAT 2
#define IPC_INFO 3
#define SHM_LOCK 11
#define SHM_UNLOCK 12
#define SHM_STAT 13
#define SHM_INFO 14

#define EFAULT 14
#define EINVAL 22

#define __user

extern int sys_shmctl(int first, int second, void *uptr);
extern void *compat_alloc_user_space(unsigned long len);
extern int compat_ipc_parse_version(int *second);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int copy_to_user(void *to, const void *from, unsigned long n);
extern int put_compat_shminfo64(struct shminfo64 *smi, void *uptr);
extern int put_compat_shminfo(struct shminfo64 *smi, void *uptr);
extern int get_compat_shmid64_ds(struct shmid64_ds *s64, void *uptr);
extern int get_compat_shmid_ds(struct shmid64_ds *s64, void *uptr);
extern int put_compat_shmid64_ds(struct shmid64_ds *s64, void *uptr);
extern int put_compat_shmid_ds(struct shmid64_ds *s64, void *uptr);
extern int put_compat_shm_info(void *p, void *uptr);