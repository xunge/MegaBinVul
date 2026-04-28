#include <stdbool.h>

struct bpf_verifier_env {
    bool strict_alignment;
};

struct bpf_reg_state {
    int type;
};

enum {
    PTR_TO_PACKET,
    PTR_TO_PACKET_META,
    PTR_TO_MAP_VALUE,
    PTR_TO_CTX,
    PTR_TO_STACK
};

int check_pkt_ptr_alignment(struct bpf_verifier_env *env,
                           const struct bpf_reg_state *reg,
                           int off, int size, bool strict);
int check_generic_ptr_alignment(struct bpf_verifier_env *env,
                               const struct bpf_reg_state *reg,
                               const char *pointer_desc,
                               int off, int size, bool strict);