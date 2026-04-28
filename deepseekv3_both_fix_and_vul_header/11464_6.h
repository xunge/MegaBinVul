#include <stdlib.h>
#include <string.h>

typedef struct gs_color_space_s gs_color_space;
typedef struct gs_client_color_s {
    void *pattern;
    union {
        float values[16];
    } paint;
} gs_client_color;
typedef struct gs_pattern_instance_s gs_pattern_instance_t;
typedef struct i_ctx_s i_ctx_t;
typedef struct ref_s {
    int type;
    void *value;
} ref;
typedef ref *os_ptr;
typedef ref *es_ptr;
typedef struct gs_state_s gs_state;
typedef struct PS_colour_space_s {
    int (*validatecomponents)(i_ctx_t *, ref *, float *, int);
} PS_colour_space_t;
typedef struct istate_s {
    struct {
        ref array;
    } colorspace[1];
    ref pattern[1];
} istate_t;

extern gs_state *igs;
extern istate_t *istate;
extern os_ptr osp;
extern es_ptr esp;
extern void *imemory;
extern int o_push_estack;
extern int t_dictionary;

extern int cs_num_components(const gs_color_space *pcs);
extern int r_has_type(os_ptr op, int type);
extern int dict_find_string(os_ptr op, const char *key, ref **ppvalue);
extern int array_get(void *imemory, ref *arr, int index, ref *pvalue);
extern int pattern_instance_uses_base_space(void *pinst);
extern int float_params(os_ptr op, int count, float *values);
extern int get_space_object(i_ctx_t *i_ctx_p, ref *arr, PS_colour_space_t **pspace);
extern int gs_setcolor(gs_state *pgs, const gs_client_color *pcc);
extern int validate_spaces(i_ctx_t *i_ctx_p, ref *arr, int *depth);
extern void check_estack(int add);
extern void make_int(es_ptr ep, int value);
extern void push_op_estack(int (*proc)(i_ctx_t *));
extern void *r_ptr(ref *pr, void *type);
extern const gs_color_space *gs_currentcolorspace(gs_state *pgs);
extern int setcolor_cont(i_ctx_t *i_ctx_p);

#define gs_pattern_instance_t ((void*)0x1)