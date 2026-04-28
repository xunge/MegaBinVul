#include <stddef.h>
#include <stdlib.h>

typedef struct stream_s stream;
typedef struct os_ptr_s *os_ptr;
typedef struct i_ctx_s i_ctx_t;

struct ref {
    struct {
        int intval;
    } value;
};

struct cmm_profile {
    int num_comps;
    void *profile_handle;
    void *buffer;
    size_t buffer_size;
    void *memory;
    int data_cs;
};

typedef struct ref ref;
typedef struct cmm_profile cmm_profile_t;

enum {
    t_dictionary,
    t_integer
};

enum {
    gsCIEXYZ,
    gsCIELAB,
    gsRGB,
    gsGRAY,
    gsCMYK,
    gsNCHANNEL,
    gsNAMED,
    gsUNDEFINED
};

enum {
    gs_error_undefined,
    gs_error_typecheck,
    gs_error_VMerror
};

extern int igs;
extern os_ptr osp;

#define check_type(a, b)
#define check_dict_read(a)
#define dict_find_string(a, b, c) 0
#define r_type(a) t_integer
#define return_error(a) 0
#define gs_note_error(a) 0
#define check_read_file(a, b, c)
#define gsicc_profile_new(a, b, c, d) NULL
#define gs_gstate_memory(a) NULL
#define gs_throw(a, b) 0
#define gsicc_get_profile_handle_buffer(a, b, c) NULL
#define rc_decrement(a, b)
#define make_int(a, b)
#define gscms_get_profile_data_space(a, b) 0