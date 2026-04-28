#include <sys/statvfs.h>
#include <stddef.h>

struct nlist {
    struct nlist *next;
    char *name;
    char *def;
};

int seen_before_hash(struct nlist **DFhashvector, char *device);
int seen_before_single(char *device);