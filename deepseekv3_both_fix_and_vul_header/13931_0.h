#include <stddef.h>

typedef unsigned char byte;

extern int bloc;

typedef struct huff_s {
    int *loc;
} huff_t;

void send(int loc, void *null, byte *fout, ...);