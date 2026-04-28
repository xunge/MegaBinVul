#include <string.h>

typedef unsigned char byte;

typedef struct ref_s {
    int type;
    struct {
        void *pstruct;
    } value;
} ref;

typedef struct i_ctx_s i_ctx_t;
typedef ref *os_ptr;

#define osp ((os_ptr)0)
#define imemory NULL
#define r_btype(x) 0
#define r_has_type(x, y) 0
#define r_set_attrs(x, y) 
#define ref_assign(x, y) 
#define check_op(x) 
#define pop(x) 
#define return_error(x) x

#define t_name 0
#define a_executable 0
#define gs_error_stackunderflow 0

const char *gs_struct_type_name_string(int type);
int gs_object_type(void *memory, void *pstruct);
int array_get(void *memory, os_ptr op, long index, ref *pref);
int name_ref(void *memory, const byte *str, int len, ref *pref, int attrs);