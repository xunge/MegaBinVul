#include <stdbool.h>
#include <stddef.h>

#define likely(x) __builtin_expect(!!(x), 1)

struct {
    bool successful;
} s;

bool inverted;