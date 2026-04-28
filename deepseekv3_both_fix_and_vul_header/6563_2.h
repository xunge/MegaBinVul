#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef uint32_t u32;

struct bpf_verifier_env {
    struct bpf_insn_aux_data *insn_aux_data;
};

struct bpf_insn_aux_data {
    bool seen;
};

#define ENOMEM 12
#define vzalloc malloc
#define vfree free