#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int ut32;

typedef struct RBuffer RBuffer;

typedef struct RList {
    void (*free)(void *);
    // other members would be needed for a complete implementation
} RList;

typedef struct pyc_object {
    RList *data;
} pyc_object;

typedef void (*RListFree)(void *);

void free_object(pyc_object *obj);
pyc_object *get_object(RBuffer *buffer);

#define R_NEW0(x) calloc(1, sizeof(x))

RList *r_list_newf(RListFree free);
bool r_list_append(RList *list, void *data);
void r_list_free(RList *list);