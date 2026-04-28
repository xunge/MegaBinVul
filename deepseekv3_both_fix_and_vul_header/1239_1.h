#include <stddef.h>

typedef int vartype_T;

typedef struct type {
    vartype_T tt_type;
} type_T;

typedef struct lhs {
    type_T *lhs_type;
} lhs_T;

typedef struct cctx {
    int ctx_skip;
} cctx_T;

typedef struct isn {
    struct {
        vartype_T vartype;
    } isn_arg;
} isn_T;

typedef char char_u;

#define FALSE 0
#define TRUE 1
#define FAIL (-1)
#define OK 0

#define VAR_ANY 0
#define VAR_LIST 1
#define VAR_DICT 2
#define VAR_BLOB 3
#define VAR_SPECIAL 4
#define VAR_NUMBER 5

#define SKIP_YES 1

#define ISN_STORERANGE 0
#define ISN_STOREINDEX 1
#define ISN_UNLETRANGE 2
#define ISN_UNLETINDEX 3

extern type_T t_blob;
extern type_T t_any;
extern type_T t_number;

extern char *_(const char *);
extern void emsg(const char *);
extern void semsg(const char *, char_u *);
extern int compile_assign_index(char_u *, lhs_T *, int *, cctx_T *);
extern int may_generate_2STRING(int, int, cctx_T *);
extern type_T *get_type_on_stack(cctx_T *, int);
extern int need_type(type_T *, type_T *, int, int, cctx_T *, int, int);
extern int compile_load_lhs(lhs_T *, char_u *, type_T *, cctx_T *);
extern isn_T *generate_instr_drop(cctx_T *, int, int);

extern const char *e_cannot_use_range_with_assignment_str;
extern const char *e_cannot_use_range_with_dictionary;
extern const char *e_indexable_type_required;