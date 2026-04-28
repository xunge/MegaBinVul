#include <stdbool.h>

struct bigben_device {
    int lock;
    bool removed;
    int worker;
};