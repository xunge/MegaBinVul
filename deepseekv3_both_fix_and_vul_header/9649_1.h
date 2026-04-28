#define VM_ACCOUNT 0
#define VM_ACCT(x) (x)
#define PAGE_CACHE_SIZE 4096

static int security_vm_enough_memory(unsigned long pages) { return 0; }