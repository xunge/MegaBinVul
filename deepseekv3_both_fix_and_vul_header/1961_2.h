#include <sys/sem.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

struct oabi_sembuf {
    unsigned short sem_num;
    short sem_op;
    short sem_flg;
};

#define SEMOPM 32
#define GFP_KERNEL 0
#define KERNEL_DS ((mm_segment_t)0)
#define __user
#define asmlinkage
#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)

typedef unsigned long mm_segment_t;

static inline mm_segment_t get_fs(void) { return 0; }
static inline void set_fs(mm_segment_t fs) { }
static inline long sys_semtimedop(int semid, struct sembuf *sops, unsigned nsops, const struct timespec *timeout) { return 0; }
static inline int __get_user_error(int val, void *ptr, int err) { return 0; }
static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }