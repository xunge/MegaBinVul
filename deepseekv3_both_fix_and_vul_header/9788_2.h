#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stddef.h>

typedef unsigned int u32;
#define __user
#define compat_ptr(ptr) ((void *)(long)(ptr))
#define IPC_64 0x0100

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
    void *__pad;
};

struct semid64_ds {
    struct ipc_perm sem_perm;
    time_t sem_otime;
    time_t sem_ctime;
    unsigned long sem_nsems;
};

#define IPC_INFO 1
#define IPC_RMID 0
#define SEM_INFO 19
#define GETVAL 12
#define GETPID 11
#define GETNCNT 13
#define GETZCNT 14
#define GETALL 15
#define SETVAL 16
#define SETALL 17
#define IPC_STAT 2
#define SEM_STAT 18
#define IPC_SET 3