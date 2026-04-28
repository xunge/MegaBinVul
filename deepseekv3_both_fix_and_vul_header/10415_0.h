#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef unsigned int uint;

typedef struct ref {
    int type;
    struct {
        uint size;
        uint *bytes;
    } value;
} ref;

typedef ref *os_ptr;

typedef struct i_ctx_t i_ctx_t;
typedef struct gs_memory_s gs_memory_t;
typedef struct ref_stack_t {
    int dummy;
} ref_stack_t;

extern gs_memory_t *imemory;
extern os_ptr osp;
extern ref_stack_t o_stack;

#define a_readonly 0
#define t_name 1
#define t_dictionary 2
#define t_null 3
#define gs_error_typecheck (-1)
#define gs_error_rangecheck (-2)
#define gs_error_stackunderflow (-3)

int dict_find_string(os_ptr op, const char *str, ref **ppref);
bool r_is_array(const ref *pref);
bool r_has_type(const ref *pref, int type);
void make_empty_array(ref *pref, int attrs);
void make_array(ref *pref, int attrs, uint size, const ref *pvalues);
uint r_size(const ref *pref);
void array_get(gs_memory_t *mem, const ref *parray, long index, ref *pelem);
void name_string_ref(gs_memory_t *mem, const ref *pname, ref *pstr);
int dict_int_param(os_ptr op, const char *kstr, int minval, int maxval, int defval, int *pvalue);
int dict_bool_param(os_ptr op, const char *kstr, bool defaultval, bool *pvalue);
void push(int n);
void make_null(os_ptr op);
int return_error(int code);
int ref_stack_count(ref_stack_t *stack);