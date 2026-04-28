#include <string.h>

typedef struct ref_s {
    int type;
    void *value;
} ref;

typedef ref *os_ptr;
typedef ref *es_ptr;

typedef struct gs_color_space_s {
    int dummy;
} gs_color_space;

typedef struct gs_client_color_s {
    void *pattern;
    struct {
        float values[16];
    } paint;
} gs_client_color;

typedef struct gs_pattern_instance_s {
    int dummy;
} gs_pattern_instance_t;

typedef struct PS_colour_space_s {
    int (*validatecomponents)(void *, ref *, float *, int);
} PS_colour_space_t;

typedef struct i_ctx_s {
    int dummy;
} i_ctx_t;

typedef struct {
    struct {
        ref array;
    } colorspace[1];
    ref pattern[1];
} istate_t;

extern gs_color_space *gs_currentcolorspace(void *igs);
extern int cs_num_components(const gs_color_space *pcs);
extern int pattern_instance_uses_base_space(gs_pattern_instance_t *pattern);
extern int float_params(ref *op, int n_numeric_comps, float *values);
extern int gs_setcolor(void *igs, gs_client_color *cc);
extern int dict_find_string(ref *op, const char *key, ref **pImpl);
extern int array_get(void *imemory, ref *pImpl, int index, ref *pPatInst);
extern int get_space_object(i_ctx_t *i_ctx_p, ref *array, PS_colour_space_t **space);
extern int validate_spaces(i_ctx_t *i_ctx_p, ref *array, int *depth);
extern void check_estack(int size);
extern void make_int(ref *ep, int value);
extern void push_op_estack(int (*cont)(i_ctx_t *));
extern int o_push_estack;
extern int setcolor_cont(i_ctx_t *i_ctx_p);
extern int r_has_type(ref *op, int type);
extern int r_is_struct(ref *op);
extern int r_has_stype(ref *op, void *imemory, int stype);
extern void *r_ptr(ref *r, void *type);
extern int return_error(int code);

#define t_dictionary 1
#define st_pattern1_instance 1
#define st_pattern2_instance 2
#define gs_pattern_instance_t ((void *)0x1)
#define gs_error_typecheck 1

static istate_t *istate;
static void *igs;
static void *imemory;
static ref *osp;
static ref *esp;