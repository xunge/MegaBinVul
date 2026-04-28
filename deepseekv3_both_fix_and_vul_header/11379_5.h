#include <stdint.h>
#include <immintrin.h>

#define BLOCK_SIZE 16

enum {
    ERR_NULL = -1,
    ERR_NR_ROUNDS = -2,
    ERR_NOT_ENOUGH_DATA = -3
};

typedef struct BlockBase BlockBase;

struct block_state {
    unsigned rounds;
    __m128i drk[14+1];
};

typedef struct {
    struct block_state algo_state;
} AESNI_State;

#pragma GCC target("aes")