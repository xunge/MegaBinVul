#include <stdint.h>

struct k_itimer {
    struct {
        struct {
            uint64_t expires;
            uint64_t incr;
        } cpu;
    } it;
    int it_overrun;
};

typedef uint64_t u64;