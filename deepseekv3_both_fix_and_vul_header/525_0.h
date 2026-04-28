#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int obj_id;
} pdf_entry_t;

typedef struct {
    int version;
    int is_linear;
    int end;
    int n_entries;
    pdf_entry_t *entries;
} pdf_xref_t;

typedef struct {
    char *name;
    int n_xrefs;
    pdf_xref_t *xrefs;
    int has_xref_streams;
} pdf_t;

typedef int pdf_flag_t;

#define PDF_FLAG_QUIET (1 << 0)

char* pdf_get_object_status(const pdf_t *pdf, int i, int j);
char* get_type(FILE *fp, int obj_id, const pdf_xref_t *xref);
#define ERR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)