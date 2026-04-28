#include <stdio.h>
#include <stdlib.h>

typedef unsigned long BITCODE_UMC;

typedef struct {
    // Add necessary fields for Bit_Chain structure
    // For example:
    FILE *file;
    unsigned char buffer;
    int bit_count;
} Bit_Chain;

void bit_write_RC(Bit_Chain *dat, unsigned char val);