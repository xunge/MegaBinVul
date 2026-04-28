#include <stdbool.h>

struct {
    void (*reset)(void);
} s;

bool inverted;