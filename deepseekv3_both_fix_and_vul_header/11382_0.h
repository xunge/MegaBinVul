#include <stddef.h>

struct branch {
    unsigned char opcode;
    unsigned long delta;
};