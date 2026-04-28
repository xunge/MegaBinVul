#include <stddef.h>

struct lys_iffeature {
    void *expr;
    void **features;
};

int resolve_iffeature_recursive(struct lys_iffeature *expr, int *index_e, int *index_f);