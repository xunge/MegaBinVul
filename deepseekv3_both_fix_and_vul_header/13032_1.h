#include <stddef.h>
#include <stdbool.h>

typedef unsigned char char_u;
typedef struct typval_S typval_T;
typedef struct evalarg_S evalarg_T;
typedef struct class_S class_T;
typedef struct object_S object_T;
typedef struct ufunc_S ufunc_T;
typedef struct ocmember_S ocmember_T;
typedef struct funcexe_S funcexe_T;

#define VAR_CLASS 1
#define VAR_OBJECT 2
#define VAR_UNKNOWN 0
#define FAIL 0
#define OK 1
#define MAX_FUNC_ARGS 20
#define FCERR_NONE 0
#define FNE_CHECK_START 1
#define TRUE true
#define FALSE false
#define NUL '\0'

#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define UNUSED
#define CLEAR_FIELD(x) memset(&(x), 0, sizeof(x))
#define STRNCMP(a, b, n) strncmp((const char *)(a), (const char *)(b), (n))

static const char *e_no_white_space_allowed_after_str_str = "";
static const char *e_using_null_object = "";
static const char *e_incomplete_type = "";
static const char *e_method_not_found_on_class_str_str = "";
static const char *e_cannot_access_private_member_str = "";
static const char *e_member_not_found_on_object_str_str = "";
static const char *e_member_not_found_on_class_str_str = "";

struct typval_S {
    int v_type;
    union {
        class_T *v_class;
        object_T *v_object;
    } vval;
};

struct evalarg_S {
    int dummy;
};

struct class_S {
    char *class_name;
    int class_class_function_count;
    int class_obj_method_count;
    int class_obj_member_count;
    int class_class_member_count;
    ufunc_T **class_class_functions;
    ufunc_T **class_obj_methods;
    ocmember_T *class_obj_members;
    ocmember_T *class_class_members;
    typval_T *class_members_tv;
};

struct object_S {
    class_T *obj_class;
    int obj_refcount;
};

struct ufunc_S {
    char uf_name[4];
};

struct ocmember_S {
    char *ocm_name;
};

struct funcexe_S {
    bool fe_evaluate;
    object_T *fe_object;
    int fe_found_var;
};

void semsg(const char *, ...);
void emsg(const char *);
char_u *find_name_end(char_u *, char_u **, char_u **, int);
int get_func_arguments(char_u **, evalarg_T *, int, typval_T *, int *);
int call_user_func_check(ufunc_T *, int, typval_T *, typval_T *, funcexe_T *, void *);
void clear_tv(typval_T *);
void copy_tv(typval_T *, typval_T *);
void object_unref(object_T *);
void class_unref(class_T *);
void user_func_error(int, const char *, int);
const char *printable_func_name(ufunc_T *);
const char *_(const char *);