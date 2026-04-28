#include <stdint.h>

typedef uint32_t __u32;
typedef uint32_t __be32;
#define __force

struct task_struct {
    int pid;
};

extern unsigned long jiffies;
extern struct task_struct *current;
extern uint32_t get_cycles(void);
extern int get_random_int_hash;

struct keydata {
    __u32 secret[4];
};

extern struct keydata *get_keyptr(void);
extern __u32 *get_cpu_var(int);
extern void put_cpu_var(int);
extern unsigned int half_md4_transform(__u32 *, __u32 *);
extern unsigned int secure_ip_id(__be32);