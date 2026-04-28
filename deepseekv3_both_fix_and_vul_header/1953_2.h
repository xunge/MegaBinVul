#include <stdint.h>

typedef uint32_t __u32;

struct keydata {
    __u32 secret[16];
};

extern __u32 random_int_secret[16];
extern __u32 jiffies;
extern __u32 get_random_int_hash;
extern struct task_struct *current;
extern uint64_t get_cycles(void);
extern struct keydata *get_keyptr(void);
extern __u32 *get_cpu_var(__u32 *);
extern void put_cpu_var(__u32 *);
extern void md5_transform(__u32 *, __u32 *);
extern int half_md4_transform(__u32 *, __u32 *);

struct task_struct {
    int pid;
};