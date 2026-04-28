#include <stdlib.h>

struct cil_list;

struct cil_classpermission {
    struct cil_list *classperms;
};

#define CIL_FALSE 0

void cil_list_destroy(struct cil_list **list, int free_content);