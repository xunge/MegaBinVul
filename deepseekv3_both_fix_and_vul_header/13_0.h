#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef unsigned int uint;

typedef struct ref {
    int type;
    union {
        int intval;
        const byte *const_bytes;
    } value;
    struct {
        size_t rsize;
    } tas;
    size_t size;
} ref;

typedef struct ref_colorspace {
    struct {
        struct {
            struct {
                ref index_proc;
            } special;
        } procs;
    };
} ref_colorspace;

typedef struct ref_stack_t {
    int count;
    ref_colorspace colorspace[1];
} ref_stack_t;

typedef enum gs_color_space_index {
    gs_color_space_index_Separation,
    gs_color_space_index_DeviceN
} gs_color_space_index;

typedef struct gs_indexed_map {
    struct {
        int (*lookup_index)(void);
    } proc;
} gs_indexed_map;

typedef struct gs_color_space_type_s {
    const char *name;
} gs_color_space_type_s;

typedef struct gs_color_space {
    struct gs_color_space *base_space;
    struct {
        struct {
            int hival;
            int n_comps;
            int use_proc;
            union {
                struct {
                    byte *data;
                    size_t size;
                } table;
                gs_indexed_map *map;
            } lookup;
        } indexed;
    } params;
} gs_color_space;

typedef struct gs_icc_manager_s {
    void *device_named;
} gs_icc_manager_s;

typedef struct gs_state_s {
    ref_colorspace colorspace[1];
    gs_icc_manager_s *icc_manager;
} gs_state_s;

typedef struct gs_memory_s {
} gs_memory_s;

typedef struct i_ctx_t {
    int language_level;
    gs_state_s *state;
    gs_memory_s *memory;
} i_ctx_t;

const gs_color_space_type_s gs_color_space_type_Indexed = {0};
const gs_color_space_type_s gs_color_space_type_Indexed_Named = {0};
gs_state_s *igs = NULL;
gs_memory_s *imemory = NULL;
ref_stack_t e_stack = {0};
ref_stack_t *istate = NULL;

enum {
    t_string = 0,
    gs_error_undefined,
    gs_error_rangecheck,
    gs_error_VMerror
};

#define r_has_type(r, t) ((r)->type == (t))
#define make_null(r) ((r)->type = 0)
#define rc_increment_cs(p)
#define rc_decrement(p, s)
#define rc_decrement_only_cs(p, s)
#define check_read(r)
#define r_size(r) ((r)->size)
#define return_error(e) (e)
#define o_push_estack 0

static int array_get(gs_memory_s *mem, ref *arr, int index, ref *result) { return 0; }
static int cs_num_components(gs_color_space *pcs) { return 0; }
static int zcs_begin_map(i_ctx_t *i_ctx_p, gs_indexed_map **map, ref *lookup, int count, gs_color_space *pcs, int (*cont)(void)) { return 0; }
static int lookup_indexed_map(void) { return 0; }
static int indexed_cont(void) { return 0; }
static int gs_setcolorspace(gs_state_s *pgs, gs_color_space *pcs) { return 0; }
static gs_color_space *gs_currentcolorspace(gs_state_s *pgs) { return NULL; }
static gs_color_space *gs_cspace_alloc(gs_memory_s *mem, const gs_color_space_type_s *pcstype) { return NULL; }
static gs_color_space_index gs_color_space_get_index(gs_color_space *pcs) { return 0; }
static int ref_stack_count(ref_stack_t *pstack) { return 0; }
static void ref_stack_pop_to(ref_stack_t *pstack, uint depth) {}
static byte *ialloc_string(size_t size, const char *name) { return NULL; }