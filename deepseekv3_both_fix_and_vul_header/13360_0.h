#include <stdlib.h>

typedef struct bin_section_data {
    void *align;
    void *valign;
    void *start;
    void *vstart;
    char *follows;
    char *vfollows;
    void *istart;
    void *ivstart;
    void *length;
} bin_section_data;

void yasm_xfree(void *ptr);
void yasm_expr_destroy(void *expr);
void yasm_intnum_destroy(void *intnum);