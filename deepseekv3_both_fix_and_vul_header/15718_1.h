#include <stdbool.h>
#include <stdint.h>

#define MAX_BPF_STACK 512
#define EACCES 13

enum bpf_access_type {
    BPF_READ,
    BPF_WRITE
};

struct bpf_verifier_env {
    bool allow_uninit_stack;
};

struct bpf_func_state {
    int allocated_stack;
};

typedef int64_t s64;