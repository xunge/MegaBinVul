#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef const char *client_name_t;

typedef struct gs_memory_s gs_memory_t;
typedef struct gs_ref_memory_s gs_ref_memory_t;
typedef struct obj_header_s obj_header_t;

#define MEMENTO
#define Memento_failThisEvent() (0)
#define ALLOC_IMMOVABLE 0
#define ALLOC_DIRECT 0
static int st_bytes = 0;

bool alloc_array_check_size(uint num_elements, uint elt_size, ulong *lsize);
obj_header_t *alloc_obj(gs_ref_memory_t *imem, ulong lsize, int *st, int flags, client_name_t cname);
int alloc_trace_space(gs_ref_memory_t *imem);
const char *client_name_string(client_name_t cname);
void if_debug6m(char c, gs_memory_t *mem, const char *fmt, ...);