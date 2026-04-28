#include <stdint.h>

typedef uint8_t byte;

typedef struct node_t {
    struct node_t *parent;
    struct node_t *right;
} node_t;

extern int bloc;

void add_bit(int bit, byte *fout);