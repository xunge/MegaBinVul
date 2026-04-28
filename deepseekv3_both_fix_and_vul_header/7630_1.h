#include <stdio.h>
#include <ctype.h>

typedef unsigned char uchar;

typedef struct {
    uchar *name;
    int page;
    float top;
} link_t;

typedef struct {
    int outpage;
    float bottom;
} page_t;

extern int num_links;
extern link_t *links;
extern int num_objects;
extern int names_object;
extern int pages_object;
extern page_t *pages;

int pdf_start_object(FILE *out);
void pdf_end_object(FILE *out);
void write_string(FILE *out, uchar *str, int flag);
void pspdf_transform_coords(page_t *page, float x, float y);