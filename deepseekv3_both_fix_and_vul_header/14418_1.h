#include <stddef.h>
#include <stdint.h>

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

typedef struct {
    int successful;
    bool inverted;
} hb_bit_set_invertible_t;

typedef enum {
    hb_bitwise_or,
    hb_bitwise_and, 
    hb_bitwise_lt,
    hb_bitwise_gt
} hb_bitwise_op_t;

extern bool inverted;
extern hb_bit_set_invertible_t s;

void process(hb_bitwise_op_t op, const hb_bit_set_invertible_t &other);