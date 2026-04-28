#include <stddef.h>

struct cmnd_info;

enum {
    UNSPEC,
    DENY,
    ALLOW,
    ALL,
    COMMAND,
    ALIAS,
    CMNDALIAS,
    SUDOERS_DEBUG_MATCH
};

struct sudoers_parse_tree {
    void *ctx;
};

struct member {
    int type;
    char *name;
    int negated;
};

struct sudo_command {
    char *cmnd;
    char *args;
    void *digests;
};

struct alias {
    struct member *members;
};

int command_matches(void *ctx, char *cmnd, char *args, const char *runchroot, struct cmnd_info *info, void *digests);
int cmndlist_matches(const struct sudoers_parse_tree *parse_tree, struct member **members, const char *runchroot, struct cmnd_info *info);
struct alias *alias_get(const struct sudoers_parse_tree *parse_tree, char *name, int type);
void alias_put(struct alias *a);

#define debug_decl(func, level)
#define debug_return_int(val) return (val)