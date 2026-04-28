#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <sys/ptrace.h>

#define YR_API
#define ERROR_SUCCESS 0
#define YR_CONFIG_MAX_PROCESS_MEMORY_CHUNK 0
#define PT_VM_ENTRY 0

typedef struct YR_MEMORY_BLOCK {
    uint64_t base;
    uint64_t size;
} YR_MEMORY_BLOCK;

typedef struct YR_MEMORY_BLOCK_ITERATOR {
    void* context;
    int last_error;
} YR_MEMORY_BLOCK_ITERATOR;

typedef struct YR_PROC_ITERATOR_CTX {
    YR_MEMORY_BLOCK current_block;
    void* proc_info;
} YR_PROC_ITERATOR_CTX;

typedef struct YR_PROC_INFO {
    int pid;
    struct {
        char* pve_path;
        size_t pve_pathlen;
        uint64_t pve_start;
        uint64_t pve_end;
    } vm_entry;
} YR_PROC_INFO;

uint64_t yr_min(uint64_t a, uint64_t b);
void yr_get_configuration(int config, void* value);