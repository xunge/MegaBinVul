#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef const char *client_name_t;

typedef struct gs_memory_t gs_memory_t;
typedef struct gs_ref_memory_t gs_ref_memory_t;
typedef struct obj_header_t obj_header_t;

extern const void st_bytes;
extern const int ALLOC_DIRECT;

extern bool alloc_array_check_size(uint num_elements, uint elt_size, ulong *lsize);
extern obj_header_t *alloc_obj(gs_ref_memory_t *imem, ulong lsize, const void *st_bytes, int alloc_direct, client_name_t cname);
extern int alloc_trace_space(gs_ref_memory_t *imem);
extern const char *client_name_string(client_name_t cname);
extern void if_debug6m(char c, gs_memory_t *mem, const char *format, ...);