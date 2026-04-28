#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#define YR_API
#define ERROR_SUCCESS 0
#define YR_CONFIG_MAX_PROCESS_MEMORY_CHUNK 0
#define CTL_KERN 1
#define KERN_PROC_VMMAP 2

typedef int pid_t;

typedef struct YR_MEMORY_BLOCK {
    uint64_t base;
    size_t size;
} YR_MEMORY_BLOCK;

typedef struct YR_MEMORY_BLOCK_ITERATOR {
    void* context;
    int last_error;
} YR_MEMORY_BLOCK_ITERATOR;

typedef struct YR_PROC_ITERATOR_CTX {
    YR_MEMORY_BLOCK current_block;
    void* proc_info;
} YR_PROC_ITERATOR_CTX;

typedef struct kinfo_vmentry {
    uint64_t kve_start;
    uint64_t kve_end;
} kinfo_vmentry;

typedef struct YR_PROC_INFO {
    pid_t pid;
    uint64_t old_end;
    struct kinfo_vmentry vm_entry;
} YR_PROC_INFO;

size_t yr_min(size_t a, size_t b);
void yr_get_configuration(int config, void* value);
int sysctl(int* name, unsigned int namelen, void* oldp, size_t* oldlenp, void* newp, size_t newlen);