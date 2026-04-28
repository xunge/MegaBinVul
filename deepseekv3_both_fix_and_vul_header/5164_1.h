#include <stdbool.h>
#include <string.h>

typedef int Idx;

typedef struct {
    int rm_so;
    int rm_eo;
} regmatch_t;

typedef struct re_node_set {
    Idx *elems;
    Idx nelem;
} re_node_set;

typedef struct re_string_t {
    char *buffer;
    Idx valid_len;
} re_string_t;

typedef struct re_dfa_t {
    struct {
        int type;
        int accept_mb;
        struct {
            int idx;
        } opr;
    } *nodes;
    re_node_set *edests;
    Idx *nexts;
} re_dfa_t;

typedef struct re_match_context_t {
    const re_dfa_t *dfa;
    re_string_t input;
    Idx match_last;
    struct {
        re_node_set nodes;
    } **state_log;
} re_match_context_t;

struct re_fail_stack_t;

#define IS_EPSILON_NODE(type) 0

typedef enum {
    OP_BACK_REF
} re_token_type_t;

static bool re_node_set_insert(re_node_set *set, Idx elem);
static bool re_node_set_contains(const re_node_set *set, Idx elem);
static void re_node_set_empty(re_node_set *set);
static bool push_fail_stack(struct re_fail_stack_t *fs, Idx pidx, Idx candidate, Idx nregs, regmatch_t *regs, re_node_set *eps_via_nodes);
static Idx check_node_accept_bytes(const re_dfa_t *dfa, Idx node, const re_string_t *input, Idx pidx);
static bool check_node_accept(const re_match_context_t *mctx, const void *node, Idx pidx);
static char *re_string_get_buffer(const re_string_t *input);