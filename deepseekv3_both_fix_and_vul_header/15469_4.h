#include <sys/types.h>
#include <sys/queue.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <stdbool.h>
#include <stdint.h>

#define ROOT_UID 0
#define DENY 0
#define ALLOW 1
#define UNSPEC -1
#define FLAG_NO_CHECK (1U << 0)
#define VALIDATE_ERROR (1U << 1)
#define VALIDATE_SUCCESS (1U << 2)
#define VALIDATE_FAILURE (1U << 3)
#define FLAG_CHECK_USER (1U << 4)
#define SUDOERS_DEBUG_PARSER 0

#define SET(x, y) ((x) |= (y))

enum def_tuple {
    never,
    any,
    all,
    always
};

struct sudo_defs_types {
    union {
        enum def_tuple tuple;
    } sd_un;
};

struct cmndtag {
    bool nopasswd;
};

struct member_list {
    void *members;
};

struct sudo_parse_tree {
    TAILQ_HEAD(, userspec) userspecs;
};

struct defaults {
    char *var;
    bool op;
    TAILQ_ENTRY(defaults) entries;
};

struct cmndspec {
    struct cmndtag tags;
    int notbefore;
    int notafter;
    char *cmnd;
    char *runchroot;
    TAILQ_ENTRY(cmndspec) entries;
};

struct privilege {
    TAILQ_HEAD(, cmndspec) cmndlist;
    TAILQ_HEAD(, defaults) defaults;
    struct member_list hostlist;
    TAILQ_ENTRY(privilege) entries;
};

struct userspec {
    TAILQ_HEAD(, privilege) privileges;
    struct member_list users;
    TAILQ_ENTRY(userspec) entries;
};

struct sudo_nss {
    int (*query)(void *, struct sudo_nss *, struct passwd *);
    struct sudo_parse_tree *parse_tree;
    TAILQ_ENTRY(sudo_nss) entries;
};

struct sudo_nss_list {
    struct sudo_nss *tqh_first;
    struct sudo_nss **tqh_last;
};

struct sudoers_context {
    struct {
        uid_t uid;
        struct passwd *pw;
    } user;
    struct {
        struct passwd *list_pw;
    } runas;
};

typedef int (*sudoers_lookup_callback_fn_t)(void *, struct userspec *, int, struct privilege *, int, struct cmndspec *, int, int, int, void *);

extern struct sudo_defs_types sudo_defs_table[];
extern char *def_runchroot;
extern bool def_authenticate;
extern const char *U_(const char *);

struct passwd *sudo_getpwuid(uid_t uid);
void sudo_pw_delref(struct passwd *pw);
bool sudo_nss_can_continue(struct sudo_nss *nss, int match);
int userlist_matches(void *parse_tree, struct passwd *pw, void *users);
int hostlist_matches(void *parse_tree, struct passwd *pw, void *hostlist);
int runas_matches_pw(void *parse_tree, struct cmndspec *cs, struct passwd *pw);
int cmnd_matches(void *parse_tree, void *cmnd, char *runchroot, void *args);
int cmnd_matches_all(void *parse_tree, void *cmnd, char *runchroot, void *args);
void debug_decl(const char *func, int level);
unsigned int debug_return_uint(unsigned int ret);
void sudo_warnx(const char *fmt, ...);