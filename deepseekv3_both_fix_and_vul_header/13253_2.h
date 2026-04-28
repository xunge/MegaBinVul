#include <stdbool.h>

struct sk_buff;
struct tcf_result;

struct tcf_proto {
    int (*classify)(struct sk_buff *, const struct tcf_proto *, struct tcf_result *);
};

extern bool tc_skip_wrapper;

#define static_branch_likely(x) (*(x))
#define IS_BUILTIN(x) false