#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t ut64;
#define UT64_MAX UINT64_MAX
#define PFMT64x PRIx64

typedef struct RVecAnalRef RVecAnalRef;
typedef struct RAnalRef {
    ut64 addr;
    ut64 at;
} RAnalRef;

typedef struct RCore {
    void *anal;
} RCore;

int compare_ref(const void *a, const void *b);
const char *axtm_name(RCore *core, ut64 addr);
int r_cons_printf(const char *fmt, ...);

#define R_VEC_FOREACH(vec, item) for((item) = (vec)->data; (item) < (vec)->data + (vec)->len; (item)++)

struct RVecAnalRef {
    RAnalRef *data;
    size_t len;
};

static inline bool RVecAnalRef_empty(RVecAnalRef *vec) { return vec->len == 0; }
static inline void RVecAnalRef_free(RVecAnalRef *vec) { free(vec->data); }
static inline void RVecAnalRef_sort(RVecAnalRef *vec, int (*cmp)(const void*, const void*)) { 
    qsort(vec->data, vec->len, sizeof(RAnalRef), cmp); 
}