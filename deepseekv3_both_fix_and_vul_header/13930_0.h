#include <stdint.h>

typedef unsigned char byte;

typedef struct node_t {
    int symbol;
    struct node_t *left;
    struct node_t *right;
} node_t;

#define INTERNAL_NODE (-1)

extern int bloc;

static int get_bit(byte *fin) {
    return (fin[bloc >> 3] >> (bloc++ & 7)) & 1;
}