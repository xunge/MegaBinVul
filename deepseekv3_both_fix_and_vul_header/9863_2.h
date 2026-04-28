#include <stdint.h>

#define FUTEX_OP_SET 0
#define FUTEX_OP_ADD 1
#define FUTEX_OP_OR 2
#define FUTEX_OP_ANDN 3
#define FUTEX_OP_XOR 4

#define FUTEX_OP_CMP_EQ 0
#define FUTEX_OP_CMP_NE 1
#define FUTEX_OP_CMP_LT 2
#define FUTEX_OP_CMP_GE 3
#define FUTEX_OP_CMP_LE 4
#define FUTEX_OP_CMP_GT 5

#define FUTEX_OP_OPARG_SHIFT 8
#define ENOSYS 38
#define EFAULT 14

#define VERIFY_WRITE 1
#define LOCK_PREFIX "\n\tlock; "

struct cpuinfo_x86 {
    int x86;
};

extern struct cpuinfo_x86 boot_cpu_data;

typedef int* user_ptr_int;
#define __user

static inline int access_ok(int type, user_ptr_int addr, unsigned long size) { return 1; }
static inline void pagefault_disable(void) {}
static inline void pagefault_enable(void) {}
static inline void __futex_atomic_op1(const char *asm_instr, int *ret, int oldval, user_ptr_int uaddr, int oparg) {}
static inline void __futex_atomic_op2(const char *asm_instr, int *ret, int oldval, user_ptr_int uaddr, int oparg) {}