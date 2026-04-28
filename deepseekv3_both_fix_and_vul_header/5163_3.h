#include <stddef.h>
#include <stdint.h>

typedef int reg_errcode_t;
typedef int reg_syntax_t;
typedef int Idx;
typedef unsigned long int bitset_word_t;

typedef struct bin_tree_t bin_tree_t;
typedef struct re_string_t re_string_t;
typedef struct re_token_t re_token_t;
typedef struct re_dfa_t re_dfa_t;
typedef struct regex_t regex_t;

struct re_token_t {
    int type;
};

struct re_dfa_t {
    bitset_word_t completed_bkref_map;
};

struct regex_t {
    re_dfa_t *buffer;
};

struct bin_tree_t {
    bin_tree_t *left;
    bin_tree_t *right;
    int type;
};

#define BE(expr, neg) (expr)
#define OP_ALT 0
#define END_OF_RE 0
#define OP_CLOSE_SUBEXP 0
#define REG_NOERROR 0
#define REG_ESPACE 0
#define RE_CARET_ANCHORS_HERE 0

static bin_tree_t *parse_branch(re_string_t *regexp, regex_t *preg, re_token_t *token, reg_syntax_t syntax, Idx nest, reg_errcode_t *err) { return NULL; }
static void postorder(bin_tree_t *tree, void (*callback)(bin_tree_t *, void *), void *arg) {}
static void free_tree(bin_tree_t *tree, void *arg) {}
static bin_tree_t *create_tree(re_dfa_t *dfa, bin_tree_t *left, bin_tree_t *right, int type) { return NULL; }
static void fetch_token(re_token_t *token, re_string_t *regexp, reg_syntax_t syntax) {}