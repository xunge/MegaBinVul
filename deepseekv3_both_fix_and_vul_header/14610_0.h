#include <stdbool.h>

struct bpf_map {
    unsigned int map_flags;
    bool frozen;
};

#define BPF_F_RDONLY_PROG (1U << 0)