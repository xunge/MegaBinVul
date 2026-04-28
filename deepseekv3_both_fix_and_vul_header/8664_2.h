#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

struct oabi_flock64 {
    short l_type;
    short l_whence;
    off_t l_start;
    off_t l_len;
    pid_t l_pid;
};

struct flock64 {
    short l_type;
    short l_whence;
    off_t l_start;
    off_t l_len;
    pid_t l_pid;
};

#define USER_DS ((mm_segment_t)0)
#define KERNEL_DS ((mm_segment_t)-1UL)
typedef unsigned long mm_segment_t;

#define F_OFD_GETLK 36
#define F_OFD_SETLK 37
#define F_OFD_SETLKW 38

#define __user
#define asmlinkage

extern int sys_fcntl64(unsigned int, unsigned int, unsigned long);
extern mm_segment_t get_fs(void);
extern void set_fs(mm_segment_t);
extern int copy_from_user(void *, const void __user *, unsigned long);
extern int copy_to_user(void __user *, const void *, unsigned long);