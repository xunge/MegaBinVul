#include <stddef.h>

typedef struct mrb_state mrb_state;
typedef struct mrb_gc mrb_gc;

struct mrb_gc {
    unsigned int out_of_memory;
};

struct mrb_state {
    struct mrb_gc gc;
};

#define MRB_API
#define TRUE 1
#define FALSE 0

void* mrb_realloc_simple(mrb_state *mrb, void *p, size_t len);
void mrb_free(mrb_state *mrb, void *p);
void mrb_raise_nomemory(mrb_state *mrb);