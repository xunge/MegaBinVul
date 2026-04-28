#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

struct msqid64_ds {
    struct ipc_perm msg_perm;
    time_t msg_stime;
    time_t msg_rtime;
    time_t msg_ctime;
    unsigned long msg_cbytes;
    unsigned long msg_qnum;
    unsigned long msg_qbytes;
    pid_t msg_lspid;
    pid_t msg_lrpid;
    unsigned long __unused4;
    unsigned long __unused5;
};

#define IPC_64 0x0100
#define EFAULT 14
#define EINVAL 22

#define __user

/* 确保常量值唯一 */
#define IPC_INFO 3
#define IPC_RMID 0
#define IPC_SET 1
#define IPC_STAT 2
#define MSG_INFO 11
#define MSG_STAT 12

int compat_ipc_parse_version(int *version);
int get_compat_msqid64(struct msqid64_ds *m64, void *uptr);
int get_compat_msqid(struct msqid64_ds *m64, void *uptr);
void *compat_alloc_user_space(size_t size);
int copy_to_user(void *to, const void *from, size_t n);
int copy_from_user(void *to, const void *from, size_t n);
int put_compat_msqid64_ds(struct msqid64_ds *m64, void *uptr);
int put_compat_msqid_ds(struct msqid64_ds *m64, void *uptr);
long sys_msgctl(int first, int second, void *uptr);