#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAFE_F(fp, cond) (cond)
#define SAFE_E(expr, sz, msg) if ((expr) != (sz)) { fprintf(stderr, "%s", msg); exit(1); }

typedef struct {
    int version;
    long start;
    long end;
} xref_entry;

typedef struct {
    xref_entry *xrefs;
    int n_xrefs;
} pdf_t;

char *get_object(FILE *fp, int id, xref_entry *xref, void *arg, int *dummy);
void load_kids(FILE *fp, int id, xref_entry *xref);