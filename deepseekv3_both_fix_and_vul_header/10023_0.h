#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef int32_t jpc_fix_t;

typedef struct {
    int numrows;
    int numcols;
} jas_matrix_t;

#define JAS_ABS(x) ((x) < 0 ? -(x) : (x))
#define JAS_CAST(type, x) ((type)(x))

void jas_eprintf(const char *format, ...);
int jas_matrix_numrows(jas_matrix_t *matrix);
int jas_matrix_numcols(jas_matrix_t *matrix);
jpc_fix_t jas_matrix_get(jas_matrix_t *matrix, int i, int j);
void jas_matrix_set(jas_matrix_t *matrix, int i, int j, jpc_fix_t val);