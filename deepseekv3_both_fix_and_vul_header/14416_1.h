#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define likely(x) __builtin_expect(!!(x), 1)

typedef struct hb_bit_set_invertible_t {
    uint32_t s;
    bool inverted;
} hb_bit_set_invertible_t;

typedef struct {
    void (*set)(uint32_t);
    bool successful;
} s_type;

s_type s;
bool inverted;