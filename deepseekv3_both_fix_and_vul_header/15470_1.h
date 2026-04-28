#include <sys/types.h>
#include <sys/queue.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

#define ALLOW 1
#define DENY 0
#define UNSPEC -1
#define MYSELF 1

#define FLAG_NO_USER 0x01
#define FLAG_NO_HOST 0x02

#define SUDOERS_DEBUG_PARSER 0x01
#define SUDO_DEBUG_DEBUG 0x02
#define SUDO_DEBUG_LINENO 0x04

#define CLR(v, f) ((v) &= ~(f))

struct sudo_nss;
struct sudoers_context;
struct cmnd_info;
struct cmndspec;
struct privilege;
struct userspec;
struct member;
struct sudo_pw;

struct defaults_list {
    /* empty structure */
};

typedef void (*sudoers_lookup_callback_fn_t)(void *, void *, int, void *, int, void *, int, int, int, void *);

TAILQ_HEAD(userspec_list, userspec);
TAILQ_HEAD(privilege_list, privilege);
TAILQ_HEAD(cmndspec_list, cmndspec);

struct sudo_nss {
    struct {
        struct userspec_list userspecs;
    } *parse_tree;
};

struct sudoers_context {
    struct {
        struct sudo_pw *pw;
    } user;
    struct {
        struct sudo_pw *pw;
    } runas;
};

struct cmnd_info {
    char *cmnd_path;
};

struct cmndspec {
    time_t notbefore;
    time_t notafter;
    char *cmnd;
    char *runchroot;
    struct member *runasuserlist;
    struct member *runasgrouplist;
    TAILQ_ENTRY(cmndspec) entries;
    struct defaults_list defaults;
};

struct privilege {
    struct member *hostlist;
    struct cmndspec_list cmndlist;
    struct defaults_list defaults;
    TAILQ_ENTRY(privilege) entries;
};

struct userspec {
    struct member *users;
    struct privilege_list privileges;
    char *file;
    int line;
    int column;
    TAILQ_ENTRY(userspec) entries;
};

struct member {
    int type;
    TAILQ_ENTRY(member) entries;
};

static void debug_decl(const char *func, int flags);
static int debug_return_int(int ret);
static void init_cmnd_info(struct sudoers_context *ctx, struct cmnd_info *info);
static int userlist_matches(void *parse_tree, struct sudo_pw *pw, struct member **users);
static int hostlist_matches(void *parse_tree, struct sudo_pw *pw, struct member **hostlist);
static int runaslist_matches(void *parse_tree, struct member *runasuserlist, struct member *runasgrouplist, struct member **matching_user, void *unused);
static int cmnd_matches(void *parse_tree, char *cmnd, char *runchroot, struct cmnd_info *info);
static void sudo_pw_delref(struct sudo_pw *pw);
static void sudo_pw_addref(struct sudo_pw *pw);
static void sudo_debug_printf(int flags, const char *fmt, ...);