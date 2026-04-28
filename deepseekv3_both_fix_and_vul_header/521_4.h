#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xref_t {
    int version;
    long start;
    long end;
    int is_linear;
} xref_t;

typedef struct pdf_t {
    int n_xrefs;
    xref_t *xrefs;
} pdf_t;

#define SAFE_F(fp, expr) ((expr) ? 1 : (fclose(fp), -1))
#define SAFE_E(actual, expected, msg) ((actual) == (expected) ? 0 : (fprintf(stderr, msg), -1))
#define ERR(msg) fprintf(stderr, msg)

long get_next_eof(FILE *fp);
void get_xref_linear_skipped(FILE *fp, xref_t *xref);
int is_valid_xref(FILE *fp, pdf_t *pdf, xref_t *xref);
void load_xref_entries(FILE *fp, xref_t *xref);
void resolve_linearized_pdf(pdf_t *pdf);
void load_creator(FILE *fp, pdf_t *pdf);