#include <stddef.h>
#include <sys/types.h>

#define LOCK_PREFIX ""
#define _ASM_PTR ".quad"

#define VERIFY_WRITE 1
#define EFAULT 14

#define access_ok(type, addr, size) (1)

#define __user