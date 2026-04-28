#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct {
    int version;
} xref_t;

typedef struct {
    char *name;
    xref_t *xrefs;
    int n_xrefs;
} pdf_t;

typedef enum {
    PDF_FLAG_DISP_CREATOR = 1,
    PDF_FLAG_QUIET = 2
} pdf_flag_t;

void usage();
void ERR(const char *fmt, ...);
int pdf_is_pdf(FILE *fp);
pdf_t *init_pdf(FILE *fp, char *name);
void pdf_delete(pdf_t *pdf);
void write_version(FILE *fp, char *name, char *dname, xref_t *xref);
void pdf_summarize(FILE *fp, pdf_t *pdf, char *dname, pdf_flag_t flags);
void scrub_document(FILE *fp, pdf_t *pdf);
void display_creator(FILE *fp, pdf_t *pdf);