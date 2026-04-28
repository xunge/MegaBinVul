#include <stdlib.h>

#define DFHASHSIZE 1

struct nlist {
    char *name;
    struct nlist *next;
};

extern struct nlist *DFhashvector[DFHASHSIZE];