#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef struct i_ctx_s i_ctx_t;
typedef struct ref_s ref;
typedef struct gs_memory_s gs_memory_t;

extern gs_memory_t *imemory;

struct ref_stack_s;
extern struct ref_stack_s e_stack;

enum {
    t_null,
    t_operator,
    t_struct,
    t_astruct,
    t_array,
    t_shortarray,
    t_mixedarray
};

enum {
    a_executable,
    a_readonly,
    avm_foreign
};

typedef uint32_t uint;
typedef uint8_t byte;

struct ref_s {
    unsigned short type;
    unsigned short attrs;
    union {
        ref *refs;
        void *pstruct;
    } value;
};

typedef ref *os_ptr;
extern os_ptr osp;

unsigned int r_size(os_ptr op);
const ref *ref_stack_index(const struct ref_stack_s *pstk, long idx);
bool r_has_type_attrs(const ref *pr, unsigned int type, unsigned int attrs);
void ref_assign_old(os_ptr op, ref *prto, const ref *prfrom, const char *cname);
unsigned int r_type(const ref *pr);
unsigned int op_index(const ref *pr);
const void *op_index_def(unsigned int opidx);
bool op_def_is_internal(const void *pdef);
void r_clear_attrs(ref *pr, unsigned int attrs);
const char *gs_struct_type_name_string(unsigned int type);
unsigned int gs_object_type(gs_memory_t *mem, void *pstruct);
void make_const_string(ref *pr, unsigned int attrs, unsigned int length, const byte *chars);
int errorexec_find(i_ctx_t *i_ctx_p, ref *pr);
void make_null(ref *pr);
void pop(int n);