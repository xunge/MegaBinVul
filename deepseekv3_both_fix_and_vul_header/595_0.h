#include <stdint.h>

typedef struct {
    uint8_t *start;
    uint8_t *tail;
    uint32_t bufa;
    uint32_t bufb;
    int bits_left;
    int bytes_left;
    int buffer_size;
    int error;
} bitfile;

uint32_t getdword(uint8_t **p);
uint32_t getdword_n(uint8_t *p, int n);