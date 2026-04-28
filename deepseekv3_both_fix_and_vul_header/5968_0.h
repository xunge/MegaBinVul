#include <stdbool.h>

struct cil_perm {
    void *classperms;
};

#define CIL_FALSE false

void cil_list_destroy(void **list, bool destroy_data);