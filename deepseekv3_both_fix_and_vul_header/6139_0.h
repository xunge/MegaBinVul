#include <stdlib.h>
#include <string.h>

struct nlist {
    char *name;
    struct nlist *next;
};

extern unsigned int DFhash(const char *);
extern struct nlist *DFhashvector[];