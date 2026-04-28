#include <stdint.h>

#define L_ABSOLUTE 0

struct result {
    uint32_t flags;
    int value;
};

void checktype(struct result* r, int type);