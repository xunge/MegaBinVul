#include <stddef.h>

typedef void* gpointer;

struct rlc_seqlist {
    void *list;
};

void g_list_free(void *list);