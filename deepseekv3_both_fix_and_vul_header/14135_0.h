#include <string.h>

typedef struct stbi__jpeg stbi__jpeg;
typedef struct stbi__huffman stbi__huffman;

struct stbi__jpeg {
    int spec_end;
    int code_bits;
    int succ_high;
    int succ_low;
    struct {
        int dc_pred;
    } img_comp[4];
};

int stbi__err(const char *str1, const char *str2);
int stbi__grow_buffer_unsafe(stbi__jpeg *j);
int stbi__jpeg_huff_decode(stbi__jpeg *j, stbi__huffman *h);
int stbi__extend_receive(stbi__jpeg *j, int n);
int stbi__jpeg_get_bit(stbi__jpeg *j);