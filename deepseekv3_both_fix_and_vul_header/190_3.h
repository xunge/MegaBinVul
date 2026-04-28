#include <stdint.h>
#include <string.h>

typedef struct i_ctx_s i_ctx_t;
typedef struct ref_s {
    union {
        int intval;
        unsigned char *bytes;
    } value;
} ref;
typedef ref *os_ptr;
typedef ref *es_ptr;
typedef struct file_enum_s file_enum;
typedef struct gx_io_device_s {
    const char *dname;
    struct {
        unsigned int (*enumerate_next)(file_enum *, char *, unsigned int);
    } procs;
} gx_io_device;

extern es_ptr esp;
extern os_ptr osp;
extern void *imemory;

#define r_ptr(p, t) ((t *)(p))
#define r_size(p) (0)
#define return_error(e) (e)
#define o_pop_estack 0
#define o_push_estack 0
#define push(n) 
#define ref_assign(dst, src) 
#define r_set_size(p, s) 
#define push_op_estack(f) 

#define gs_error_rangecheck 1

typedef unsigned int uint;

extern gx_io_device *iodev_default(void *);
extern int check_file_permissions_reduced(i_ctx_t *, char *, unsigned int, gx_io_device *, const char *);