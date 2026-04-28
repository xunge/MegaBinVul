#include <stdlib.h>

struct object {
    int dummy;
};

struct commit {
    struct object object;
};

void mark_object(struct object *obj, void *arg1, ...);