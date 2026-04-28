#include <stddef.h>

struct bpf_program {
    size_t sec_idx;
    size_t sec_insn_off;
};

struct bpf_object {
    struct bpf_program *programs;
    int nr_programs;
};

static int prog_contains_insn(const struct bpf_program *prog, size_t insn_idx);