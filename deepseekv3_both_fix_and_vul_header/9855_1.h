#include <stdint.h>
#include <stddef.h>

typedef struct DviContext DviContext;

int32_t dugetn(DviContext *dvi, int n);
void dread(DviContext *dvi, char *s, int32_t arg);
void mdvi_do_special(DviContext *dvi, char *s);
void *mdvi_malloc(size_t size);
void mdvi_free(void *ptr);
#define SHOWCMD(x) 
#define DVI_XXX1 0

typedef int32_t Int32;