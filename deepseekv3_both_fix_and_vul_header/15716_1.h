#include <stdlib.h>

#define BPF_REG_SIZE 8
#define ENOMEM 12

struct bpf_stack_state {
    // dummy definition to make sizeof work
    char data[64];
};

struct bpf_func_state {
    size_t allocated_stack;
    struct bpf_stack_state *stack;
    int subprogno;
};

struct bpf_subprog_info {
    int stack_depth;
};

struct bpf_verifier_env {
    struct bpf_subprog_info *subprog_info;
};

void *realloc_array(void *ptr, size_t old_n, size_t new_n, size_t size);