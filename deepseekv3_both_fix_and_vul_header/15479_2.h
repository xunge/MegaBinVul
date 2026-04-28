#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <stddef.h>

#define UNSPEC -1
#define DENY 0
#define ALLOW 1
#define RUNASALIAS 2
#define SUDOERS_DEBUG_MATCH 0

enum member_type {
    ALL,
    ALIAS,
    WORD
};

struct member {
    enum member_type type;
    char *name;
    int negated;
    struct {
        struct member *tqe_prev;
    } entries;
};

struct member_list {
    struct member *tqh_first;
    struct member **tqh_last;
};

struct alias {
    struct member_list members;
};

struct sudoers_context {
    struct {
        struct passwd *pw;
        struct group *gr;
    } runas;
};

struct sudoers_parse_tree {
    struct sudoers_context *ctx;
};

struct gid_list {
    int ngids;
    gid_t *gids;
};

#define TAILQ_FOREACH_REVERSE(var, head, headname, field) \
    for ((var) = ((head)->tqh_last ? *(head)->tqh_last : NULL); \
         (var); \
         (var) = (var)->field.tqe_prev)

#define FALLTHROUGH
#define debug_decl(func, level)
#define debug_return_int(val) return (val)

static int group_matches(const char *name, const struct group *gr);
static struct alias *alias_get(const struct sudoers_parse_tree *parse_tree, const char *name, int type);
static void alias_put(struct alias *a);
static struct gid_list *runas_getgroups(const struct sudoers_context *ctx);
static void sudo_gidlist_delref(struct gid_list *runas_groups);