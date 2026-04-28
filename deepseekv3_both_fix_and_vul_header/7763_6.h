#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t ut64;
#define R_API
#define PFMT64x "lx"
#define PFMT64d "ld"

typedef struct RVTableContext {
    int word_size;
} RVTableContext;

typedef struct RVTableMethodInfo {
    ut64 addr;
    ut64 vtable_offset;
} RVTableMethodInfo;

typedef struct RVTableMethodVector {
    RVTableMethodInfo *methods;
    size_t length;
} RVTableMethodVector;

typedef struct RVTableInfo {
    ut64 saddr;
    RVTableMethodVector methods;
} RVTableInfo;

typedef struct RAnal RAnal;
typedef struct RAnalFunction {
    const char *name;
} RAnalFunction;

typedef struct RListIter {
    void *data;
    struct RListIter *n;
} RListIter;

typedef struct RList {
    RListIter *head;
} RList;

typedef struct PJ PJ;

void r_anal_vtable_begin(RAnal *anal, RVTableContext *context);
RList *r_anal_vtable_search(RVTableContext *context);
ut64 r_anal_vtable_info_get_size(RVTableContext *context, RVTableInfo *table);
RAnalFunction *r_anal_get_fcn_in(RAnal *anal, ut64 addr, int type);
const char *r_str_get_fail(const char *str, const char *fail);
void r_cons_println(const char *str);
void r_cons_printf(const char *fmt, ...);
void r_cons_newline(void);
PJ *pj_new(void);
void pj_free(PJ *pj);
void pj_a(PJ *pj);
void pj_o(PJ *pj);
void pj_kN(PJ *pj, const char *key, ut64 value);
void pj_ka(PJ *pj, const char *key);
void pj_ks(PJ *pj, const char *key, const char *value);
void pj_end(PJ *pj);
char *pj_string(PJ *pj);
void r_list_free(RList *list);

#define r_list_foreach(list, iter, item) \
    for((iter) = (list)->head; (iter) && ((item) = (iter)->data); (iter) = (iter)->n)

#define r_vector_foreach(vec, iter) \
    RVTableMethodVector *v = (vec); \
    for((iter) = v->methods; (iter) < v->methods + v->length; (iter)++)