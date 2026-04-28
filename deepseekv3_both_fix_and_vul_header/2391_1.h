#include <stdbool.h>
#include <stddef.h>

#define KEY_FLAG_USER_CONSTRUCT 0
#define KEY_FLAG_NEGATIVE 1

struct key {
    unsigned long flags;
    int reject_error;
};

#define TASK_INTERRUPTIBLE 1
#define TASK_UNINTERRUPTIBLE 0
#define ERESTARTSYS 512

extern int wait_on_bit(unsigned long *, int, int);
extern int test_bit(int, const unsigned long *);
extern int key_validate(struct key *);
extern void smp_rmb(void);