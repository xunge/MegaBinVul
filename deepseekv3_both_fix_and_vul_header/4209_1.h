#include <stdio.h>

struct object;
struct strbuf;

struct rev_list_info {
    unsigned int flags;
};

#define REV_LIST_QUIET (1 << 0)

void finish_object(struct object *obj, ...);
void show_object_with_name(FILE *fp, struct object *obj, ...);