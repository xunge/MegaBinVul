#include <sys/types.h>

#define VM_ACCOUNT 0
#define VM_ACCT(size) ((size) >> 12)

static int security_vm_enough_memory(unsigned long pages) {
    return 0;
}