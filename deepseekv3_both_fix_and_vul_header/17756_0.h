#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct _slot *Slot;
struct _slot {
    int64_t hash;
    int klen;
    const char *key;
    Slot next;
};

#define AGOO_MALLOC malloc

extern int64_t calc_hash(const char *key, int *len);
extern Slot *get_bucketp(int64_t h);