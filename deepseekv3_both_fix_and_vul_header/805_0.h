#include <stdlib.h>
#include <string.h>

typedef struct HuffmanTree HuffmanTree;
struct HuffmanTree {
    unsigned* lengths;
    unsigned maxbitlen;
    unsigned numcodes;
};

unsigned lodepng_huffman_code_lengths(unsigned* lengths, const unsigned* frequencies, size_t numcodes, unsigned maxbitlen);
unsigned HuffmanTree_makeFromLengths2(HuffmanTree* tree);