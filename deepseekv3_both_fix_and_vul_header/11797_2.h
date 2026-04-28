#include <stdbool.h>
#include <stdint.h>

typedef unsigned long ulong;
typedef unsigned int uint;

typedef struct i_ctx_s {
    bool LockFilePermissions;
} i_ctx_t;

typedef struct os_ptr_s {
    struct {
        ulong saveid;
    } value;
} *os_ptr;

typedef struct alloc_save_s alloc_save_t;
typedef struct vm_save_s {
    void *gsave;
} vm_save_t;

extern os_ptr osp;
extern void *idmemory;
extern void *imemory;
extern void *igs;
extern int I_VALIDATE_BEFORE_RESTORE;
extern int I_VALIDATE_AFTER_RESTORE;

extern os_ptr o_stack;
extern os_ptr e_stack;
extern os_ptr d_stack;

enum {
    avm_local
};

extern uint icurrent_space;

void *alloc_save_client_data(alloc_save_t *asave);
int restore_check_operand(os_ptr op, alloc_save_t **asave, void *idmemory);
void ivalidate_clean_spaces(i_ctx_t *i_ctx_p);
int restore_check_stack(i_ctx_t *i_ctx_p, os_ptr *stack, alloc_save_t *asave, bool flag);
void restore_fix_stack(i_ctx_t *i_ctx_p, os_ptr *stack, alloc_save_t *asave, bool flag);
alloc_save_t *alloc_save_current(void *idmemory);
void gs_grestoreall_for_restore(void *igs, void *gsave);
int alloc_restore_step_in(void *idmemory, alloc_save_t *asave);
void ifree_object(vm_save_t *vmsave, const char *str);
void dict_set_top(void);
void ialloc_set_space(void *idmemory, uint space);
void if_debug2m(char c, void *imemory, const char *fmt, ...);