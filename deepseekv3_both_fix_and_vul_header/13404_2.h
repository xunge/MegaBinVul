#include <stddef.h>

typedef struct sqlo_t sqlo_t;
typedef struct df_elt_t df_elt_t;
typedef struct collation_t collation_t;

#define DFE_COLUMN 0
#define BOX_ELEMENTS(arr) (sizeof(arr)/sizeof((arr)[0]))

typedef void* caddr_t;

struct df_elt_t {
    int dfe_type;
    void *dfe_tree;
    union {
        struct {
            struct df_elt_t *right;
        } bin;
        struct {
            struct df_elt_t **args;
        } call;
        struct {
            struct {
                struct {
                    collation_t *sqt_collation;
                } col_sqt;
            } *col;
        } col;
    } _;
};

int cmp_boxes(caddr_t a, caddr_t b, collation_t *coll1, collation_t *coll2);