#include <pwd.h>
#include <stddef.h>

#define UNSPEC -1
#define DENY 0
#define ALLOW 1
#define FALLTHROUGH
#define SUDOERS_DEBUG_MATCH 0

struct sudoers_parse_tree {
    const struct sudoers_context *ctx;
    const char *lhost;
    const char *shost;
    void *nss;
};

struct sudoers_context {
    struct {
        const char *host;
        const char *shost;
    } runas;
};

struct member {
    int type;
    int negated;
    const char *name;
};

struct alias {
    struct member members;
    const char *name;
};

enum {
    ALL,
    NETGROUP,
    USERGROUP,
    ALIAS,
    WORD,
    USERALIAS
};

extern int def_netgroup_tuple;
extern int netgr_matches(void *nss, const char *name, const char *lhost, const char *shost, const char *user);
extern int usergr_matches(const char *name, const char *user, const struct passwd *pw);
extern int userpw_matches(const char *name, const char *user, const struct passwd *pw);
extern struct alias *alias_get(const struct sudoers_parse_tree *parse_tree, const char *name, int type);
extern void alias_put(struct alias *a);
extern int userlist_matches(const struct sudoers_parse_tree *parse_tree, const struct passwd *pw, const struct member *m);
extern void debug_decl(const char *func, int level);
extern int debug_return_int(int ret);