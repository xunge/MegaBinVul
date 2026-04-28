#include <stdio.h>

#define MAX_HUFFMAN_CODE_LEN 16

typedef struct {
    int *input;
    int *first;
    int *huftab;
    int *index;
} HUFCODEC;

int bitstr_getb(int *input);