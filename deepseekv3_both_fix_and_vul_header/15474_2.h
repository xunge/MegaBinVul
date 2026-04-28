#include <stdbool.h>
#include <stddef.h>

#define UNSPEC -1
#define DENY 0
#define ALLOW 1
#define SUDOERS_DEBUG_MATCH 0

#define ALL 1
#define ALIAS 2
#define CMNDALIAS 3

struct sudo_command {
    char *cmnd;
    char *args;
    void *digests;
};

struct member {
    int type;
    char *name;
    bool negated;
    struct {
        struct member *tqe_next;
        struct member **tqe_prev;
    } entries;
};

struct member_list {
    struct member *tqh_first;
    struct member **tqh_last;
};

struct alias {
    struct member_list members;
};

struct sudoers_parse_tree {
    void *ctx;
};

struct cmnd_info;

#define TAILQ_FIRST(head) ((head)->tqh_first)
#define TAILQ_NEXT(elm, field) ((elm)->field.tqe_next)
#define TAILQ_LAST(head, headname) \
    (*(((struct headname *)((head)->tqh_last))->tqh_last))
#define TAILQ_PREV(elm, headname, field) \
    (*(((struct headname *)((elm)->field.tqe_prev))->tqh_last))

#define TAILQ_FOREACH_REVERSE(var, head, headname, field) \
    for ((var) = TAILQ_LAST((head), headname); \
        (var) != NULL; \
        (var) = TAILQ_PREV((var), headname, field))

void debug_decl(const char *, int);
int debug_return_int(int);
int command_matches(void *, char *, char *, const char *, struct cmnd_info *, void **);
struct alias *alias_get(const struct sudoers_parse_tree *, char *, int);
void alias_put(struct alias *);