#include <stdlib.h>

typedef void* gpointer;

typedef struct {
    gpointer cookie;
} nlm_msg_res_unmatched_data;

void g_free(gpointer mem);