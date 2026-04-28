#include <sys/queue.h>
#include <string.h>
#include <pwd.h>

#define UNSPEC -1
#define DENY 0
#define ALLOW 1
#define FALLTHROUGH
#define SUDOERS_DEBUG_MATCH 0

#define RUNASALIAS 0
#define RUNAS_USER_SPECIFIED (1 << 0)
#define RUNAS_GROUP_SPECIFIED (1 << 1)

#define ISSET(x, y) ((x) & (y))
#define debug_decl(func, level)
#define debug_return_int(x) return (x)

struct sudoers_parse_tree;
struct member;
struct alias;

struct member_list {
    struct member *tqh_first;
    struct member **tqh_last;
};

struct member {
    int type;
    char *name;
    int negated;
    TAILQ_ENTRY(member) entries;
};

struct alias {
    struct member_list members;
};

struct sudoers_context {
    struct {
        struct passwd *pw;
        char *host;
        char *shost;
    } runas;
    struct {
        char *name;
    } user;
    struct {
        int flags;
    } settings;
};

struct sudoers_parse_tree {
    struct sudoers_context *ctx;
    char *lhost;
    char *shost;
    void *nss;
};

TAILQ_HEAD(member_list_head, member);

enum {
    ALL,
    NETGROUP,
    USERGROUP,
    ALIAS,
    WORD,
    MYSELF
};

extern int def_netgroup_tuple;
extern int netgr_matches(void *nss, const char *name, const char *lhost, const char *shost, const char *user);
extern int usergr_matches(const char *name, const char *user, struct passwd *pw);
extern int userpw_matches(const char *name, const char *user, struct passwd *pw);
extern struct alias *alias_get(const struct sudoers_parse_tree *parse_tree, const char *name, int type);
extern void alias_put(struct alias *a);