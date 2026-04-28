#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAFE_F(fp, expr) (expr)
#define SAFE_E(expr, val, msg) do { if ((expr) != (val)) { fprintf(stderr, msg); exit(EXIT_FAILURE); } } while (0)
#define ERR(msg) fprintf(stderr, msg)

typedef struct _xref_entry {
    int obj_id;
    long offset;
    int gen_num;
    char f_or_n;
} xref_entry_t;

typedef struct {
    long start;
    long end;
    int n_entries;
    xref_entry_t *entries;
} xref_t;