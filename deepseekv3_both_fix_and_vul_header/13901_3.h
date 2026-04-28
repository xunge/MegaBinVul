#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct gs_memory_s gs_memory_t;
typedef struct gs_ref_memory_s gs_ref_memory_t;
typedef struct gs_memory_type_s {
    const char *sname;
    unsigned int ssize;
    int (*enum_ptrs)(void);
} *gs_memory_type_ptr_t;
typedef const char *client_name_t;
typedef struct obj_header_s obj_header_t;
typedef unsigned int uint;
typedef unsigned long ulong;

int Memento_failThisEvent(void);

#define MEMENTO
#define DEBUG
#define ALLOC_CHECK_SIZE(mem, pstype)
#define basic_enum_ptrs 0
#define dmprintf2(mem, fmt, sname, cname)
#define alloc_array_check_size(num_elements, ssize, lsize) false
#define alloc_obj(imem, lsize, pstype, alloc_type, cname) NULL
#define if_debug7m(code, mem, fmt, trace_space, cname_str, struct_type_str, size, num_elements, ssize, obj_addr)
#define alloc_trace_space(imem) 0
#define client_name_string(cname) ""
#define struct_type_name_string(pstype) ""
#define ALLOC_DIRECT 0