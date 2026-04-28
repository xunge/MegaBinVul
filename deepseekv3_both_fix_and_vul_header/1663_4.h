#include <stdbool.h>
#include <string.h>
#include <stdint.h>

struct miniflow {
    uint64_t values[1];
};

struct minimask {
    struct miniflow masks;
};

size_t miniflow_n_values(const struct miniflow *);
#define MINIFLOW_VALUES_SIZE(N) ((N) * sizeof(uint64_t))