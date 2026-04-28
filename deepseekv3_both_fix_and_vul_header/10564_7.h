#include <stddef.h>
#include <stdlib.h>

typedef unsigned char byte;

typedef struct dict {
    struct dict *pdict;
    void *(*memory)(struct dict *);
} dict;

typedef struct gs_memory_s {
    void *non_gc_memory;
} gs_memory_t;

typedef struct ref_s {
    int type;
    void *value;
} ref;

typedef struct i_ctx_s {
    void *ctx;
} i_ctx_t;

typedef struct os_ptr_s {
    dict value;
} *os_ptr;

typedef struct dsc_data_s {
    int document_level;
    void *dsc_data_ptr;
} dsc_data_t;

extern const byte dsc_dict_name[];
extern const byte st_dsc_data_t;
extern os_ptr osp;

void *dsc_init_with_alloc(void *, void *(*)(void *, size_t), void (*)(void *, void *), void *);
void dsc_set_error_function(void *, void (*)(void *, const char *));
void dsc_error_handler(void *, const char *);
void *zDSC_memalloc(void *, size_t);
void zDSC_memfree(void *, void *);
int idict_put_string(os_ptr, const byte *, const ref *);
void make_astruct(ref *, int, byte *);
void *dict_memory(dict *);
int pop(int);
void *gs_alloc_struct(gs_memory_t *, size_t, const byte *, const char *);

#define check_read_type(a, b) 
#define return_error(a) (a)
#define a_readonly 0
#define r_space(a) 0
#define t_dictionary 0
#define gs_error_VMerror 0

#define gs_alloc_struct(mem, type, st, desc) gs_alloc_struct(mem, sizeof(type), st, desc)