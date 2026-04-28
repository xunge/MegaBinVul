#include <stdbool.h>

typedef struct {
    bool inverted;
    bool successful;
} hb_bit_set_invertible_t;

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

typedef void (*hb_bitwise_func_t)(void);

void process(hb_bitwise_func_t func, const hb_bit_set_invertible_t &other);

extern hb_bitwise_func_t hb_bitwise_lt;
extern hb_bitwise_func_t hb_bitwise_gt;
extern hb_bitwise_func_t hb_bitwise_or;
extern hb_bitwise_func_t hb_bitwise_and;

extern bool inverted;
extern hb_bit_set_invertible_t s;