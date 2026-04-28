#include <stdbool.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define VAR_FIXED 0
#define VAR_DICT 1
#define VAR_LIST 2
#define FAIL 1

typedef struct callback_T {
    char *cb_name;
} callback_T;

typedef struct qf_list_T {
    callback_T qf_qftf_cb;
    int qf_id;
} qf_list_T;

typedef struct list_T {
    int lv_refcount;
} list_T;

typedef struct dict_T {
    int dv_refcount;
} dict_T;

typedef struct typval_T {
    int v_type;
    union {
        dict_T *v_dict;
        list_T *v_list;
    } vval;
} typval_T;

extern callback_T qftf_cb;

#define IS_QF_LIST(qfl) ((qfl) != NULL)

static int call_callback(callback_T *cb, int arg1, typval_T *rettv, int arg3, typval_T args[]);
static dict_T *dict_alloc_lock(int type);
static void dict_add_number(dict_T *d, const char *key, long value);
static void dict_unref(dict_T *d);
static void clear_tv(typval_T *tv);