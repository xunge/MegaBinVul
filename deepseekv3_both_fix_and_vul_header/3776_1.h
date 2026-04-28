#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef unsigned int uint;
typedef uint8_t byte;

typedef struct ref_s {
    byte *bytes;
} ref_t;

typedef struct tas_s {
    uint type_attrs;
    uint rsize;
} tas_t;

typedef struct os_ptr_s {
    tas_t tas;
    ref_t value;
} *os_ptr;

extern os_ptr osp;

#define r_size(op) ((op)->tas.rsize)
#define r_set_size(op, sz) ((op)->tas.rsize = (sz))
#define make_false(op) ((op)->tas.type_attrs = 0)
#define make_true(op) ((op)->tas.type_attrs = 1)
#define check_read_type(op, type) (void)0
#define push(n) (void)0
#define t_string 0

typedef struct i_ctx_s i_ctx_t;