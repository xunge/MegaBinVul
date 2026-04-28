#include <stdint.h>
#include <stddef.h>

typedef struct {
    int successful;
    bool inverted;
} hb_bit_set_invertible_t;

#define likely(x) __builtin_expect(!!(x), 1)

static inline void process(void (*op)(), const hb_bit_set_invertible_t& other) {}

static inline void hb_bitwise_xor() {}

hb_bit_set_invertible_t s;
bool inverted;