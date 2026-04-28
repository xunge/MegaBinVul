#include <stdint.h>
#include <stddef.h>

typedef struct _YR_MEMORY_BLOCK {
    size_t base;
    size_t size;
} YR_MEMORY_BLOCK;

typedef struct _YR_MEMORY_BLOCK_ITERATOR {
    void* context;
    int last_error;
} YR_MEMORY_BLOCK_ITERATOR;

typedef struct _YR_PROC_ITERATOR_CTX {
    void* proc_info;
    YR_MEMORY_BLOCK current_block;
} YR_PROC_ITERATOR_CTX;

typedef struct _YR_PROC_INFO {
    void* hProcess;
    struct {
        void* lpMaximumApplicationAddress;
    } si;
} YR_PROC_INFO;

typedef struct _MEMORY_BASIC_INFORMATION {
    void* BaseAddress;
    size_t RegionSize;
    unsigned long State;
    unsigned long Protect;
} MEMORY_BASIC_INFORMATION;

#define YR_API
#define YR_CONFIG_MAX_PROCESS_MEMORY_CHUNK 0
#define ERROR_SUCCESS 0
#define MEM_COMMIT 0x1000
#define PAGE_NOACCESS 0x01

int VirtualQueryEx(void* hProcess, void* lpAddress, MEMORY_BASIC_INFORMATION* lpBuffer, size_t dwLength);
void yr_get_configuration(int config, void* value);