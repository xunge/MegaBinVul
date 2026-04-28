#include <stddef.h>
#include <stdint.h>

#define YR_API
#define ERROR_SUCCESS 0
#define YR_CONFIG_MAX_PROCESS_MEMORY_CHUNK 0
#define KERN_SUCCESS 0
#define KERN_INVALID_ADDRESS 1
#define VM_REGION_BASIC_INFO 0
#define VM_REGION_BASIC_INFO_COUNT_64 0

typedef int kern_return_t;
typedef unsigned int mach_msg_type_number_t;
typedef unsigned int mach_port_t;
typedef unsigned long vm_address_t;
typedef unsigned long vm_size_t;

typedef struct {
    int dummy;
} vm_region_basic_info_data_64_t;
typedef void* vm_region_info_t;

typedef struct YR_MEMORY_BLOCK {
    size_t base;
    size_t size;
} YR_MEMORY_BLOCK;

typedef struct YR_MEMORY_BLOCK_ITERATOR {
    void* context;
    int last_error;
} YR_MEMORY_BLOCK_ITERATOR;

typedef struct YR_PROC_INFO {
    mach_port_t task;
} YR_PROC_INFO;

typedef struct YR_PROC_ITERATOR_CTX {
    YR_PROC_INFO* proc_info;
    YR_MEMORY_BLOCK current_block;
} YR_PROC_ITERATOR_CTX;

void yr_get_configuration(int config, void* value);