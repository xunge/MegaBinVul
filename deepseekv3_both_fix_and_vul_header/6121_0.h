#include <stdlib.h>
#include <string.h>

struct digest {
    // placeholder for digest structure
};

extern int digest_length(struct digest *d);
extern int digest_final(struct digest *d, unsigned char *tmp);
extern void *xmalloc(size_t size);

#define EINVAL 22