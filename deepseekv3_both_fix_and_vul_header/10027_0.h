#include <stdlib.h>

typedef long jas_seqent_t;

typedef struct {
    int flags_;
    int numrows_;
    int numcols_;
    int maxrows_;
    size_t datasize_;
    jas_seqent_t **rows_;
    jas_seqent_t *data_;
    int xstart_;
    int ystart_;
    int xend_;
    int yend_;
} jas_matrix_t;

void *jas_malloc(size_t size);
void *jas_alloc2(size_t num, size_t size);
void jas_matrix_destroy(jas_matrix_t *matrix);