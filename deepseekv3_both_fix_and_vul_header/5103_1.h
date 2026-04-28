#include <stdlib.h>
#include <stdbool.h>

struct bpf_verifier_state {
    bool speculative;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    struct bpf_verifier_stack_elem *head;
    int stack_size;
};

struct bpf_verifier_stack_elem {
    int insn_idx;
    int prev_insn_idx;
    struct bpf_verifier_state st;
    struct bpf_verifier_stack_elem *next;
};

#define GFP_KERNEL 0
#define BPF_COMPLEXITY_LIMIT_STACK 1000

void *kzalloc(size_t size, int flags);
void verbose(struct bpf_verifier_env *env, const char *fmt);
int copy_verifier_state(struct bpf_verifier_state *dst, struct bpf_verifier_state *src);
void free_verifier_state(struct bpf_verifier_state *state, bool free_self);
bool pop_stack(struct bpf_verifier_env *env, int *insn_idx, int *prev_insn_idx);