#include <stdint.h>
#include <string.h>

struct pico_tree;
struct pico_tree_node;
struct pico_frame;

#define frag_dbg(msg)

struct pico_frame {
    uint8_t *buffer;
    uint8_t *net_hdr;
    uint16_t net_len;
    uint8_t *transport_hdr;
    uint16_t transport_len;
    void *dev;
};

struct pico_tree_node {
    void *keyValue;
};

#define pico_tree_foreach_safe(index, tree, tmp) \
    for ((index) = pico_tree_firstNode(tree), (tmp) = pico_tree_nextNode(index); \
         (index) != NULL; \
         (index) = (tmp), (tmp) = pico_tree_nextNode(index))

uint16_t pico_fragments_get_header_length(uint8_t net);
struct pico_frame *pico_tree_first(struct pico_tree *tree);
struct pico_tree_node *pico_tree_firstNode(struct pico_tree *tree);
struct pico_tree_node *pico_tree_nextNode(struct pico_tree_node *node);
void pico_tree_delete(struct pico_tree *tree, struct pico_frame *f);
void pico_frame_discard(struct pico_frame *f);
int pico_transport_receive(struct pico_frame *f, uint8_t proto);
struct pico_frame *pico_frame_alloc(uint16_t size);