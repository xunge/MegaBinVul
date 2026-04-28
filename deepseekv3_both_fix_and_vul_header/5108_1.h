#include <stdbool.h>

struct bpf_verifier_env;
struct bpf_verifier_state {
    int curframe;
    bool speculative;
    struct bpf_func_state **frame;
};

struct bpf_func_state {
    int callsite;
};

bool func_states_equal(struct bpf_func_state *a, struct bpf_func_state *b);