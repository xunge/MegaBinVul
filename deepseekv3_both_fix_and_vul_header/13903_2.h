#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct gs_memory_s gs_memory_t;
typedef struct gs_ref_memory_s gs_ref_memory_t;
typedef struct obj_header_s obj_header_t;
typedef const char *client_name_t;

typedef struct gs_memory_type_s {
    unsigned int ssize;
} gs_memory_type_t;
typedef gs_memory_type_t *gs_memory_type_ptr_t;

typedef uint32_t uint;
typedef uint64_t ulong;

#define ALLOC_IMMOVABLE 0
#define ALLOC_DIRECT 0
#define MEMENTO
#define Memento_failThisEvent() 0
#define ALLOC_CHECK_SIZE(mem, pstype)
#define if_debug7m(code, mem, format, a1, a2, a3, a4, a5, a6, a7)
#define alloc_trace_space(imem) 0
#define client_name_string(cname) ""
#define struct_type_name_string(pstype) ""

static bool alloc_array_check_size(uint num_elements, uint ssize, ulong *lsize);
static obj_header_t *alloc_obj(gs_ref_memory_t *imem, ulong lsize, gs_memory_type_ptr_t pstype, int flags, client_name_t cname);