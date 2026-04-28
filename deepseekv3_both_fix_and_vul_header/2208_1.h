#include <stdint.h>
#include <stddef.h>

typedef struct DviContext DviContext;
typedef int32_t Int32;

Int32 dugetn(DviContext *dvi, int n);
void dread(DviContext *dvi, char *s, Int32 arg);
void mdvi_do_special(DviContext *dvi, char *s);
void *mdvi_malloc(size_t size);
void mdvi_free(void *ptr);
#define SHOWCMD(args)

#define DVI_XXX1 0