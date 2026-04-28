#include <stdbool.h>
#include <stddef.h>

struct S {
    void (*clear)(void);
    bool successful;
};

extern struct S s;
extern bool inverted;

#define likely(x) __builtin_expect(!!(x), 1)