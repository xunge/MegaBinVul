#include <stdint.h>
#include <stddef.h>

typedef uint8_t byte;
#define NYT 256

typedef struct node_s {
    struct node_s *parent;
    struct node_s *next;
    struct node_s *prev;
    struct node_s *left;
    struct node_s *right;
    int weight;
    int symbol;
} node_t;

typedef struct {
    node_t *tree;
    node_t *lhead;
    node_t *nodeList[768];
    node_t *loc[257];
    int blocNode;
} huff_t;

typedef struct {
    byte *data;
    int cursize;
} msg_t;

extern int bloc;
extern void Com_Memset(void *dest, int val, size_t count);
extern void Com_Memcpy(void *dest, const void *src, size_t count);
extern void Huff_transmit(huff_t *huff, int ch, byte *seq, ...);
extern void Huff_addRef(huff_t *huff, byte ch);