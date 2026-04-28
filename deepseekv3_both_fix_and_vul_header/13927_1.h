#include <stddef.h>

typedef unsigned char byte;
#define NYT 256

typedef struct node_t node_t;
typedef struct huff_t {
    node_t *loc[257];
} huff_t;

void add_bit(char bit, byte *fout);
void send(node_t *node, void *null, byte *fout, ...);