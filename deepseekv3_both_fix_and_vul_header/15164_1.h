#include <stddef.h>
#include <errno.h>

#define __user
#define VERIFY_READ 0
#define VERIFY_WRITE 1
#define EFAULT 14
#define EPERM 1
#define EINVAL 22
#define ENOMEM 12
#define SS_DISABLE 2
#define SS_ONSTACK 1
#define MINSIGSTKSZ 2048

typedef struct {
    void __user *ss_sp;
    size_t ss_size;
    int ss_flags;
} stack_t;

struct task_struct {
    unsigned long sas_ss_sp;
    size_t sas_ss_size;
};

extern struct task_struct *current;

int access_ok(int type, const void __user *addr, unsigned long size);
int __get_user(void *val, const void __user *addr);
int __put_user(const void *val, void __user *addr);
int on_sig_stack(unsigned long sp);
int sas_ss_flags(unsigned long sp);
int copy_to_user(void __user *to, const void *from, unsigned long n);