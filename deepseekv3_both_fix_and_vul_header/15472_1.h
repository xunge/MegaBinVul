#include <sys/types.h>
#include <pwd.h>
#include <stddef.h>

#define UNSPEC -1
#define DENY 0
#define ALLOW 1
#define FALLTHROUGH
#define true 1
#define false 0

struct sudoers_parse_tree {
    void *nss;
};

struct member {
    int type;
    int negated;
    char *name;
};

struct alias {
    struct member members;
};

enum {
    ALL,
    NETGROUP,
    NTWKADDR,
    ALIAS,
    WORD,
    HOSTALIAS
};

#define SUDOERS_DEBUG_MATCH 0
#define SUDO_DEBUG_DEBUG 0

extern int def_netgroup_tuple;
extern int netgr_matches(void *nss, const char *name, const char *lhost, const char *shost, const char *user);
extern int addr_matches(const char *name);
extern int hostname_matches(const char *shost, const char *lhost, const char *name);
extern int hostlist_matches_int(const struct sudoers_parse_tree *parse_tree, const struct passwd *pw, const char *lhost, const char *shost, const struct member *m);
extern struct alias *alias_get(const struct sudoers_parse_tree *parse_tree, const char *name, int type);
extern void alias_put(struct alias *a);
extern void sudo_debug_printf(int level, const char *fmt, ...);
extern void debug_decl(const char *func, int level);
extern int debug_return_int(int ret);